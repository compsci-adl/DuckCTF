FROM debian:buster-slim

# Install system packages
RUN apt-get update && apt-get install -y lib32z1 xinetd gcc

# Setup user
RUN useradd -m ctf
WORKDIR /home/ctf

# Setup chroot
RUN cp -R /lib* /home/ctf && \
    cp -R /usr/lib* /home/ctf

RUN mkdir /home/ctf/dev && \
    mknod /home/ctf/dev/null c 1 3 && \
    mknod /home/ctf/dev/zero c 1 5 && \
    mknod /home/ctf/dev/random c 1 8 && \
    mknod /home/ctf/dev/urandom c 1 9 && \
    chmod 666 /home/ctf/dev/*

RUN mkdir /home/ctf/bin && \
    cp /bin/sh /home/ctf/bin && \
    cp /bin/ls /home/ctf/bin && \
    cp /bin/cat /home/ctf/bin

# Configure xinetd
COPY ctf.xinetd /etc/xinetd.d/ctf
RUN echo "Blocked by ctf_xinetd" > /etc/banner_fail

# Copy start-up script
COPY start.sh /start.sh
RUN chmod +x /start.sh

# Copy challenge
COPY ./challenge .
RUN gcc /home/ctf/cptnull.c -o /home/ctf/cptnull && rm /home/ctf/cptnull.c

# Setup permissions
RUN chown -R root:ctf /home/ctf && \
    chmod -R 750 /home/ctf && \
    chmod 740 /home/ctf/treasure.txt

CMD ["/start.sh"]

# Expose the challenge port
EXPOSE 9999
