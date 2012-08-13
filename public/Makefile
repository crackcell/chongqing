# Author:  Tan Menglong <tanmenglong@gmail.com>
# Date:    Wed Aug  8 12:01:42 2012
#
# Make Target:
# ------------
# The Makefile provides the following targets to make:
#   $ make           compile and link
#   $ make clean     clean objects and the executable file
#
#===========================================================================

.PHONY : all output test clean help

all : output

output :
	mkdir -p output/include
	cp include/* output/include

test :
	make -C test

clean :
	rm -rf output

help :
	@echo 'Usage: make [TARGET]'
	@echo 'TARGETS:'
	@echo '  all       (=make) compile and link.'
	@echo '  clean     clean objects and the executable file.'
	@echo '  help      print this message.'
	@echo
