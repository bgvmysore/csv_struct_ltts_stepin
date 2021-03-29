main.exe: ./src/main.c ./src/read_csv.c
	gcc -Iheader -o main.exe ./src/main.c ./src/read_csv.c

main_db.exe: ./src/main.c ./src/read_csv.c
	gcc -g -Iheader -o main_db.exe ./src/main.c ./src/read_csv.c

TEST.exe: ./test/test_main.c ./src/read_csv.c ./unity/unity.c
	gcc -Iheader -Iunity ./test/test_main.c ./src/read_csv.c ./unity/unity.c -o TEST.exe

runtest: TEST.exe
	./TEST.exe

run: main.exe
	./main.exe

clean:
	del *.exe
	cls