name := taller-asm
tag := latest

all: build run

build:
	docker build -t $(name):$(tag) .

run:
	docker run -it --rm -v ./borja:/app $(name)
