# Author:  Tan Menglong <tanmenglong@gmail.com>
# Date:    Wed Aug  8 13:44:35 2012
#
# Make Target:
# ------------
# The Makefile provides the following targets to make:
#   $ make           compile and link
#   $ make clean     clean objects and the executable file
#
#===========================================================================

include ../../Makefile.env

MODULE = basic_search
VERSION = 1.0.0.0
BUILD_TARGETS = basic_search basic_search-debug

INC = -I../include -I$(PUBLIC)/include -I./
LIB = 

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

DEBUG_SRC = $(patsubst %.c, %-debug.c, $(SRC))
DEBUG_OBJ = $(patsubst %.c, %.o, $(DEBUG_SRC))

.PHONY : all clean

all : $(BUILD_TARGETS)

basic_search : $(OBJ)
	$(LINK) -o $@ $^ $(LIB)

basic_search-debug : $(DEBUG_OBJ)
	$(LINK) -o $@ $^ $(LIB)

clean:
	rm -rf *.o $(BUILD_TARGETS)
