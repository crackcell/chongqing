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

MODULE = da
VERSION = 1.0.0.0

CQ_ROOT = ../..
DA_ROOT = ../

BUILD_TARGETS = da da_d

INC = -I$(DA_ROOT) -I$(ZHUHAI)/output/include
LIB = -L$(ZHUHAI)/output/lib -lzhuhai \
	-lpthread -ltbb

SRC = $(wildcard */*.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
OBJ_DEBUG = $(patsubst %.cpp, %_d.o, $(SRC))

.PHONY : all clean check

all : $(BUILD_TARGETS)

check : all
	valgrind --leak-check=full --show-reachable=yes ./bs -d ./ -f conf/bs.conf

da : $(OBJ)
	$(CXX) -o $@ $^ $(LIB)

da_d : $(OBJ_DEBUG)
	$(CXX) -o $@ $^ $(LIB)

clean :
	rm -rf $(OBJ) $(OBJ_DEBUG) $(BUILD_TARGETS)
