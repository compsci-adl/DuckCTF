FROM alpine:3.14

WORKDIR /home/

RUN apk --no-cache add socat

COPY . .

CMD ["socat", "TCP-LISTEN:8000,nodelay,reuseaddr,fork", "EXEC:'stdbuf -i0 -o0 -e0 /home/daas'"]