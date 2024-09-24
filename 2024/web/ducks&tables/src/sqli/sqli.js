const sqlite = require("sqlite3");
const express = require('express');
//const crypto = require('node:crypto')
const data = require('./data.json')
var jsonSql = require('json-sql')()
const { rateLimit } = require('express-rate-limit')


console.log(`Loaded ${data.length} ducks`)
ducks = data.map((i)=>{
    //let img = i.image;
    //let path = "/"+new URL(img).pathname;
    //let md = crypto.createHash('md5').update(img).digest('hex');
    //i.image = "https://upload.wikimedia.org/wikipedia/commons/" + md[0] + "/" + md.substr(0,2) + "/" + path.substring(path.lastIndexOf('/')+1);
    i.secret = null;
    return i;
});

ducks[Math.floor(Math.random()*data.length)]["secret"] = "quack{s0_a_bl1nd_duck_w4lks_1nt0_a_t4bl3_4nd_s4y5_wh0_m0v3d_th3_p0nd?}";

//dupliduck = ducks[Math.floor(Math.random()*data.length)];
//dupliduck.secret = "quack{s0_a_bl1nd_duck_w4lks_1nt0_a_t4bl3_4nd_s4y5_wh0_m0v3d_th3_p0nd?}"
//ducks.push(dupliduck)

function initializeDB(db){
    console.log("Reinitialised SQLi DB");
    var sql = jsonSql.build({
        type: 'insert',
        table: 'ducks',
        fields: ['itemLabel', 'itemDescription', 'image', 'secret'],
        values: ducks
    });
    let values = Object.keys(sql.values).reduce((a, c) => (a[`$${c}`] = sql.values[c], a), {});
    
    db.serialize(()=>{
        db.run(`CREATE TABLE ducks (id INTEGER PRIMARY KEY AUTOINCREMENT, itemLabel TEXT, itemDescription TEXT, image TEXT, secret TEXT);`); 
        db.run(sql.query, values);
    });
}

function sqli(app){
    const path = "";

    var globaldb = new sqlite.Database(':memory:');
    globaldb.serialize(() => {
        initializeDB(globaldb);
    });
    
    const limiter = rateLimit({
        windowMs: 1 * 60 * 1000, // 1 minutes
        limit: 1, // Limit each IP to 1 requests per `window` (here, per 15 minutes).
        standardHeaders: 'draft-7', // draft-6: `RateLimit-*` headers; draft-7: combined `RateLimit` header
        legacyHeaders: false, // Disable the `X-RateLimit-*` headers.
    })



    app.use(path, express.static("sqli/static"));
    app.use(path, express.json());

    app.use(path+"/reset", limiter)
    app.get(path+"/reset", (req,res)=>{
        globaldb.close(()=>{
            globaldb = new sqlite.Database(':memory:');
            initializeDB(globaldb);
        });

        res.redirect("/");
    });

    app.post(path+"/duck", (req,res)=>{
        let sql = "SELECT id FROM ducks WHERE itemLabel = \""+req.body.duck+"\" LIMIT 0,1;";
        globaldb.serialize(function() {
        globaldb.all(sql, [], (err, rows) => {
            if (err) {
                res.status(500).json({sql:sql, error:err, output:rows});
                return;
            }

            if(rows.length > 0){
                let sql = "SELECT itemLabel, itemDescription, image FROM ducks WHERE id = "+Number(rows[0].id);
                globaldb.all(sql, [], (err, rows) => {
                    res.status(200).json({sql:sql, error:err, output:rows});
                    return;
                });
                return;
            }
                
            res.status(403).json({sql:sql, error:err, output:rows});
        });
    });
    });

    app.post(path+"/list", (req,res)=>{
        let sql = "SELECT itemLabel FROM ducks;";
        globaldb.all(sql, [], (err, rows) => {
            if (err) {
                res.status(500).json({sql:sql, error:err, output:rows});
                return;
            }

            res.status(200).json({sql:sql, error:err,output:rows});
        });
    });
}

module.exports = sqli;