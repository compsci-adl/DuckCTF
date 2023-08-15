FROM python:slim AS app
RUN pip install --no-cache-dir progress

FROM pwn.red/jail
COPY --from=app / /srv
RUN mkdir /srv/app
COPY chall.py /srv/app/run
RUN chmod +x /srv/app/run
ENV JAIL_MEM=20M
