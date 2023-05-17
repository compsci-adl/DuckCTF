#!/bin/bash
docker rm -f web_juggler
docker build -t web_juggler . && \
docker run -dit --name web_juggler --rm -p 5555:80 -it web_juggler
