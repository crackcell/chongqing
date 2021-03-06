# Author:  Tan Menglong <tanmenglong@gmail.com>
# Date:    Sun Aug 26 17:04:21 2012
#
# Make Target:
# ------------
# The Makefile provides the following targets to make:
#   $ make           compile and link
#   $ make clean     clean objects and the executable file
#
#===========================================================================

include ../Makefile.env

MODULE = bs
VERSION = $(shell git log --name-status HEAD^..HEAD | grep commit | cut -f 2 -d " ")

BS_ROOT = ../

BUILD_TARGETS = bs bs_d

INC = -I$(BS_ROOT)
LIB = -lpthread

SRC = $(wildcard */*.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
OBJ_DEBUG = $(patsubst %.cpp, %_d.o, $(SRC))

.PHONY : all clean check

all : $(BUILD_TARGETS)

check : all
	valgrind --leak-check=full --show-reachable=yes ./bs -d ./ -f conf/bs.conf

bs : $(OBJ)
	$(CXX) -o $@ $^ $(LIB)

bs_d : $(OBJ_DEBUG)
	$(CXX) -o $@ $^ $(LIB)

clean :
	rm -rf $(OBJ) $(OBJ_DEBUG) $(BUILD_TARGETS)
