from itertools import groupby
from urllib.parse import urlparse

import requests

# Run-length encoding function
# https://en.wikipedia.org/wiki/Run-length_encoding
def encode(input_string):
    return "".join(str(len(list(g))) + k for k, g in groupby(input_string))

# Check if the submitted URL is HTTP and points to our domain
def url_valid(link):
    try:
        result = urlparse(link)
        return all(
            [result.scheme in "http", result.netloc == "ctf.csclub.org.au:1337"])
    except ValueError:
        return False
