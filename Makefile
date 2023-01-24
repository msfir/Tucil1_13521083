all: compile

compile:
	@mkdir -p bin
	gcc src/*.c -o bin/24solver

clean:
	@rm -rf bin
