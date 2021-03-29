main.exe: ./src/main.c ./src/read_csv.c
	gcc -Iheader -o main.exe ./src/main.c ./src/read_csv.c

main_db.exe: ./src/main.c ./src/read_csv.c
	gcc -g -Iheader -o main_db.exe ./src/main.c ./src/read_csv.c

run: main.exe
	./main.exe

clean:
	del *.exe
	cls