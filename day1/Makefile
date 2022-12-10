build: $(file).c
	$(CC) $(file).c -Wall -W -pedantic -O2 -std=c99 -o $(file)

run: $(file).c
	make build file=$(file) && ./$(file)

clean:
	rm -rf 1 2
