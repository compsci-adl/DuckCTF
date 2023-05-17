FROM alpine:3.15

WORKDIR /home/

RUN apk --no-cache add socat gcc musl-dev coreutils git perl && \
    git clone https://github.com/tnalpgge/rank-amateur-cowsay.git /tmp/rank-amateur-cowsay && \
    cd /tmp/rank-amateur-cowsay && \
    /tmp/rank-amateur-cowsay/install.sh /usr/local

COPY . .

RUN cp /home/duck.cow /usr/local/share/cows/ && \
    rm /home/daas && \
    gcc -fno-stack-protector /home/daas.c -o /home/daas

USER guest

ENTRYPOINT ["socat", "TCP-LISTEN:8000,nodelay,reuseaddr,fork", "EXEC:'stdbuf -i0 -o0 -e0 /home/daas && kill -9'"]
