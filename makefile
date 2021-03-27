main.exe: ./src/main.c
	gcc -Iheader -o main.exe ./src/main.c ./src/read_csv.c

run: main.exe
	./main.exe

clean:
	del main.exe
	cls