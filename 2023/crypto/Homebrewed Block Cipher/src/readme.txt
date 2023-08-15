docker build . -t homebrewed-block-cipher
docker run --privileged -dp 5000:5000 homebrewed-block-cipher

docker tag homebrewed-block-cipher asia-east1-docker.pkg.dev/duckctf/workshop-challenges/homebrewed-block-cipher:latest
docker push asia-east1-docker.pkg.dev/duckctf/workshop-challenges/homebrewed-block-cipher
