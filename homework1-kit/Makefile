all: divby7or11 recurse HoopsStats

clean:
	rm -f divby7or11 recurse HoopsStats
	./hw1test.py CLEAN

divby7or11: divby7or11.c
	g++ -g -o $@ $<

recurse: recurse.c
	g++ -g -o $@ $<

HoopsStats: HoopsStats.c
	g++ -g -o $@ $<

