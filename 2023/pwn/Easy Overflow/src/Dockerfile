# FROM ubuntu:20.04 AS app

# FROM pwn.red/jail

# COPY --from=app / /srv

# RUN mkdir /srv/app

# COPY libc.so.6 /lib/x86_64-linux-gnu/

# COPY easy /srv/app/run


FROM ubuntu:20.04 as chroot
RUN apt-get update

RUN /usr/sbin/useradd --no-create-home -u 1000 user
RUN apt-get install build-essential gcc-multilib lib32z1 -y

COPY easy.c /home/user/
COPY Makefile /home/user/
RUN cd /home/user/ && make

FROM gcr.io/kctf-docker/challenge@sha256:d884e54146b71baf91603d5b73e563eaffc5a42d494b1e32341a5f76363060fb

COPY --from=chroot / /chroot

COPY nsjail.cfg /home/user/

CMD chmod 0700 /kctf/.fullproc/proc && \
    kctf_setup && \
    kctf_drop_privs \
    socat \
      TCP-LISTEN:1337,reuseaddr,fork \
      EXEC:"kctf_pow nsjail --config /home/user/nsjail.cfg -- /home/user/easy 'quack{gets_is_vulnerable}'",pty