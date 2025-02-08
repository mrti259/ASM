FROM debian:latest

RUN apt update && apt install -y \
    build-essential \
    nasm \
    gdb \
    valgrind \
    wget

RUN wget -P ~ https://git.io/.gdbinit

RUN echo "add-auto-load-safe-path /app" >> ~/.gdbinit

WORKDIR /app

CMD ["bash"]