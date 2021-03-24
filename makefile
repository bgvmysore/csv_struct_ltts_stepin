main.exe: ./src/main.c
	gcc -o main.exe ./src/main.c

run: main.exe
	./main.exe

clean:
	del main.exe
	cls