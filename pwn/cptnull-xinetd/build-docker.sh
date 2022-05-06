#!/bin/bash
docker rm -f pwn_cptnull
docker build -t pwn_cptnull . && \
docker run -dit --name pwn_cptnull --rm -p 7777:9999 -it pwn_cptnull
