CC = g++
CFLAGS = -g -Wall
SOURCEPATH = aoc/days/
BUILDPATH = aoc/builds/
NUMBERS = 01 02 #03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

setup:
	$(foreach num, $(NUMBERS), mkdir -p aoc/builds/day$(num) aoc/resources/day$(num) aoc/days/day$(num) || exit 1;)
	$(foreach num, $(NUMBERS), touch $(SOURCEPATH)day$(num)/day$(num).cpp || exit 1;)
	

all:
	$(foreach num, $(NUMBERS), $(MAKE) day DAY=$(num))

day: $(BUILDPATH)day$(DAY)/day$(DAY).o
	$(CC) $(CFLAGS) $(BUILDPATH)day$(DAY)/day$(DAY).o -o $(BUILDPATH)day$(DAY)/day$(DAY)

$(BUILDPATH)day$(DAY)/day$(DAY).o: $(SOURCEPATH)day$(DAY)/day$(DAY).cpp
	$(CC) $(CFLAGS) -c $(SOURCEPATH)day$(DAY)/day$(DAY).cpp -o $(BUILDPATH)day$(DAY)/day$(DAY).o

runday: $(BUILDPATH)day$(DAY)/day$(DAY)
	./$(BUILDPATH)day$(DAY)/day$(DAY)

clean:
	$(foreach num, $(NUMBERS), rm -f $(SOURCEPATH)day$(num)/day$(num).cpp || exit 1;)
	$(foreach num, $(NUMBERS), rmdir aoc/days/day$(num) || exit 1;)
	$(foreach num, $(NUMBERS), rm -f $(BUILDPATH)day$(num)/day$(num).o),
	$(foreach num, $(NUMBERS), rm -f $(BUILDPATH)day$(num)/day$(num))
	$(foreach num, $(NUMBERS), rmdir $(BUILDPATH)day$(num))
	$(foreach num, $(NUMBERS), rmdir aoc/resources/day$(num))
