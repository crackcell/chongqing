# Author:  Tan Menglong <tanmenglong@gmail.com>
# Date:    Thu Aug  9 17:46:54 2012
#
# Make Target:
# ------------
# The Makefile provides the following targets to make:
#   $ make           compile and link
#   $ make clean     clean objects and the executable file
#
#===========================================================================

include Makefile.env

.PHONY : all output clean help

all : output

output :
	mkdir -p output
	make -C public

clean :
	rm -rf output
	make -C publi clean

help :
	@echo 'Usage: make [TARGET]'
	@echo 'TARGETS:'
	@echo '  all       (=make) compile and link.'
	@echo '  clean     clean objects and the executable file.'
	@echo '  help      print this message.'
	@echo