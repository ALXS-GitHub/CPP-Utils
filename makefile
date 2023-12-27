VERSION = 0.0.1

CC = g++

CFLAGS = -Wall -g -std=c++17 -Wall -Wextra

%-test: %-test.o
	$(CC) $(CFLAGS) -o bin/test/$*.exe bin/test/$*.o

%-test.o: test/%.cpp
	$(CC) $(CFLAGS) -c test/$*.cpp -o bin/test/$*.o

zip-release:
	zip -r release/cpp_utils-$(VERSION).zip src/ docs/ README.md

clean:
	ifeq ($(OS),Windows_NT)
		del /S bin\*.exe bin\*.o
	else
		find ./bin -type f \( -name "*.o" -o -name "*.exe" \) -exec rm -f {} \;
	endif
