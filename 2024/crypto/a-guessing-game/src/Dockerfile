FROM python:3.9-slim

RUN apt-get update && apt-get install -y socat && pip install pycryptodome

RUN useradd -m ctf
WORKDIR /home/ctf

COPY main.py flag.py ./

USER ctf

ENTRYPOINT ["socat", "TCP-LISTEN:8000,nodelay,reuseaddr,fork", "EXEC:'stdbuf -i0 -o0 -e0 python3 main.py'"]
