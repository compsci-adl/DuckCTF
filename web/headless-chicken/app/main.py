from flask import Flask, redirect, render_template, request, url_for
import jobs
import rq
from validators import encode, url_valid

app = Flask(__name__)
jobs.rq.init_app(app)

# For sake of simplicty, we keep track of the jobs we've launched
# in memory. This will only work as long there is only one python
# process (web server context) and it must not get restarted.
# In advanced use cases you want to keep track of jobs by their ids
# and utilize sessions and redis.
joblist = []

# our index page with custom logic vulnerable to XSS
@app.route('/')
def index():
    if request.args.get("text"):
        text = request.args.get("text")
        new_text = encode(text)
        return render_template("index.html", r_short="Your new shortened secret: {}".format(new_text) if len(
            new_text) < len(text) else "Oops, your text could not be shortened!", value=text)
    else:
        return render_template("index.html")


# example of a 'report to admin' page
@app.route('/report', methods=['GET', 'POST'])
def report():
    if request.method == "POST":
        link = request.form.get("link")

        if url_valid(link):
            jobs.proceed_link.queue(link)
            return render_template("contact.html", result="Thank you for the report, our administrator will review it shortly!")

        return render_template("contact.html", result="Invalid URL!")

    return render_template("contact.html")