const puppeteer = require('puppeteer');
require('dotenv').config();

const DOMAIN = process.env.DOMAIN;
const FLAG = process.env.FLAG;

const myArgs = process.argv.slice(2);

const url = myArgs[0];

(async () => {
    const browser = await puppeteer.launch({
        args: [
            '--disable-web-security',
            '--ignore-certificate-errors',
            '--no-sandbox',
            '--disable-setuid-sandbox'
        ],
        headless: true,
        ignoreHTTPSErrors: true,
    });
    const page = await browser.newPage();
    await page.setCookie({
        "name": "flag",
        "value": FLAG,
        "url": DOMAIN,
        "httpOnly": false,
        "secure": false,
    });
    await page.goto(url, { waitUntil: 'networkidle0', timeout: 10000});
    console.log("[INFO] Rendered page: " + url);
    await browser.close();
})();