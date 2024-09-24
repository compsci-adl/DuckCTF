FROM python:3.9-slim

RUN apt-get update && apt-get install -y socat

RUN useradd -m ctf
WORKDIR /home/ctf

COPY Calculator.py .

ENV FLAG=quack{looC_yreV_sI_hsiloP_esreveR}
USER ctf

ENTRYPOINT ["socat", "TCP-LISTEN:8000,nodelay,reuseaddr,fork", "EXEC:'stdbuf -i0 -o0 -e0 python3 Calculator.py'"]
