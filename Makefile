all:
	gcc mkszfile.c -o mkszfile -O2 -Wall -Wextra -pedantic -Wvla  -g

install:
	cp -v mkszfile /usr/bin

uninstall:
	rm -v /usr/bin/mkszfile 