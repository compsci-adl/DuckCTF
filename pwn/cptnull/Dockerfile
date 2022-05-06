FROM alpine:3.15

WORKDIR /home/

RUN apk --no-cache add socat gcc musl-dev coreutils

COPY ./challenge .

RUN gcc /home/cptnull.c -o /home/cptnull

USER guest

ENTRYPOINT ["socat", "TCP-LISTEN:8000,nodelay,reuseaddr,fork", "EXEC:'stdbuf -i0 -o0 -e0 /home/cptnull'"]