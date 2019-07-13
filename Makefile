# warn us when we are doing risky/weird things
CFLAGS=-g -O0 -Wall -Wextra

# All mocked libs go in the mock directory
MOCKS=$(wildcard ./mocks/*.h)
# Mocks generate .o (object) files
MOCK_OUTPUT=$(patsubst %.h,%.o,$(MOCKS))

# All tests go in the test directory
TESTS=$(wildcard ./tests/*.cpp)
# Tests generate .test executable files
TEST_OUTPUT=$(patsubst %.cpp,%.test,$(TESTS))

.PRECIOUS: %.o %.test


# By default just compile and upload to the arduino
upload: index.ino Morse.cpp Morse.h
	arduino --upload --verbose --port /dev/ttyUSB0 index.ino

# Verfiy the arduino sketch will compile
verify: index.ino Morse.cpp Morse.h
	arduino --verify --verbose index.ino

%.o: %.cpp $(MOCKS)
	@echo "Building $@..."
	@gcc \
		$(CFLAGS) \
		-c \
		-o $@ \
		-x c++ $<

./Morse.o: ./Morse.cpp
	@echo "Building Morse.o..."
	@gcc \
		$(CFLAGS) \
		-c \
		-o ./Morse.o \
		-I ./mocks \
		-x c++ ./Morse.cpp

%.test: %.cpp $(TESTS) ./Morse.o $(MOCK_OUTPUT)
	@gcc \
		$(CFLAGS) \
		-o $@ \
		-I ./mocks \
		-I ./ \
		$(MOCK_OUTPUT) \
		./Morse.o \
		-x c++ $<
	@valgrind --quiet --error-exitcode=1 --tool=memcheck --leak-check=full $@

test: $(TEST_OUTPUT)
	@echo "+-------------------+"
	@echo "| All tests passing |"
	@echo "+-------------------+"

.PHONY: clean
clean:
	@rm -f ./mocks/*.o ./*.o tests/*.test
