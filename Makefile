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

.PHONY : all clean

all :
	make -C bs

clean :
	make clean -C bs
