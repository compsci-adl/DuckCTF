import subprocess

from flask_rq2 import RQ
from rq import get_current_job

rq = RQ()
rq.redis_url = 'redis://redis:6379/0'

@rq.job(timeout=15)
def proceed_link(link):
    subprocess.run(["node", "xss_bot_pupet.js", link], timeout=15)
