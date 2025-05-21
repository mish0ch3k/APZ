FROM gcc:latest

RUN apt-get update && apt-get install -y valgrind

WORKDIR /app
COPY . /app

RUN gcc -g -o program task.c

CMD ["valgrind", "--leak-check=full", "./program"]

