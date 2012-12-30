# Author:  Tan Menglong <tanmenglong@gmail.com>
# Date:    Sun Aug 26 17:03:29 2012
#
# Make Target:
# ------------
# The Makefile provides the following targets to make:
#   $ make           compile and link
#   $ make clean     clean objects and the executable file
#
#===========================================================================

.PHONY : all output clean

all : output

output :
	make -C frame
#	make -C strategy
	mkdir -p output/bin output/conf
	cp frame/crawler output/bin
	cp conf/* output/conf

clean :
	rm -rf output
	make clean -C frame
#	make clean -C unittest

help :
	@echo 'Usage: make [TARGET]'
	@echo 'TARGETS:'
	@echo '  all       (=make) compile and link.'
	@echo '  clean     clean objects and the executable file.'
	@echo '  help      print this message.'
	@echo
