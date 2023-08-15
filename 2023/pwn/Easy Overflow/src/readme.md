```
docker build . -t easy-overflow
docker run --privileged -dp 5000:5000 easy-overflow


docker build . -t easy-overflow
docker run --privileged -dp 30001:1337 easy-overflow


docker tag easy-overflow asia-east1-docker.pkg.dev/duckctf/workshop-challenges/easy-overflow:latest
docker push asia-east1-docker.pkg.dev/duckctf/workshop-challenges/easy-overflow
```
