FROM node:16-alpine

RUN mkdir /usr/src

WORKDIR /usr/src

COPY src/package*.json .

RUN npm ci --no-package-lock

CMD ["node", "index.js"]