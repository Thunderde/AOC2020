CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -O0

.PHONY: clean

day1: day1.c
	$(CC) $(CFLAGS) -o $@ $<

day2: day2.c
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm *.o day1 day2
