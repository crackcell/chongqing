# Author:  Tan Menglong <tanmenglong@gmail.com>
# Date:    Thu Dec 20 03:50:00 2012
#
# Make Target:
# ------------
# The Makefile provides the following targets to make:
#   $ make           compile and link
#   $ make clean     clean objects and the executable file
#
#===========================================================================

include ../../../Makefile.env

CQ_ROOT = ../../../

MODULE = crawler
VERSION = 1.0.0.0

INC = -I$(ZHUHAI)/include -I../
LIB = -L$(ZHUHAI)/lib -lzhuhai -lpthread

BUILD_TARGETS = crawler

SRC = $(wildcard ./*/*.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

.PHONY : all clean

all : $(BUILD_TARGETS)

$(BUILD_TARGETS) : $(OBJ)
	$(LINK) -o $@ $^ $(LIB)

clean:
	rm -rf $(OBJ) $(BUILD_TARGETS)
