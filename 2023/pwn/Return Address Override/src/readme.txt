docker build . -t return-address-override
docker run --privileged -dp 5000:1337 return-address-override


docker tag return-address-override asia-east1-docker.pkg.dev/duckctf/workshop-challenges/return-address-override:latest
docker push asia-east1-docker.pkg.dev/duckctf/workshop-challenges/return-address-override

