```bash

gcc -fno-stack-protector daas.c -o daas


docker build . -t daas
docker run -dp 4501:8000 daas

docker exec -it ... /bin/ash

```