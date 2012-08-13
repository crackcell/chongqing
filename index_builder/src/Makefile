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

VERSION = index_builder
BUILD_TARGETS = index_builder index_builder-debug

INC = -I../include -I$(PUBLIC)/include -I./
LIB = 

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

DEBUG_SRC = $(patsubst %.c, %-debug.c, $(SRC))
DEBUG_OBJ = $(patsubst %.c, %.o, $(DEBUG_SRC))

.PHONY : all clean

all : $(BUILD_TARGETS)

index_builder : $(OBJ)
	$(LINK) -o $@ $^ $(LIB)

index_builder-debug : $(DEBUG_OBJ)
	$(LINK) -o $@ $^ $(LIB)

clean:
	rm -rf *.o $(BUILD_TARGETS)
