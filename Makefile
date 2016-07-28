# flags #
CC		= gcc
STD		= -std=c99
FLAGS	= -g -Wall -D_DEFAULT_SOURCE -I source/
OFLAGS 	= -c -Wall -fpic -D_DEFAULT_SOURCE

# elf #
EXAM	= example
LIBO	= muselog.o
LIB		= libmuselog.so

# obj #
OEXAM	= source/muselog.c source/muselogmsg.c source/example.c

OLIB	= source/muselog.c
OLIBO	= muselog.o

# phony #
.PHONY : example lib cleano clean

ex:		$(EXAM)
lib:	$(LIBO) $(LIB) cleano

clean:
	rm -f $(EXAM) $(LIBO) $(LIB)

cleano:
	rm -f $(OLIBO)

# actual #
$(EXAM) : $(OEXAM)
	$(CC) -o $(EXAM) $(OEXAM) $(FLAGS) $(STD)

$(LIBO) : $(OLIB)
	$(CC) -o $(LIBO) $(OLIB) $(OFLAGS) $(STD)

$(LIB) : $(OLIBO)
	$(CC) -o $(LIB) $(OLIBO) -shared


