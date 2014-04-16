PREFIX=../..
INCDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib
BINDIR = $(PREFIX)/bin
CC=gcc 
CFLAGS=-c -std=c99 -g -Wall -Werror
CPPFLAGS=-I $(INCDIR)
LDFLAGS=-L $(LIBDIR)
LDLIBS=
OUTFILE=xergStrike
OBJS=xergStrike.o

all: $(OUTFILE)

$(OUTFILE): $(OBJS) 
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@


xergStrike.o:xergStrike.c xergStrike.h
	$(CC) -c $(CPPFLAGS) $(CFLAGS) xergStrike.c -o $@

clean :
	rm -f  $(OUTFILE) $(OBJS)

