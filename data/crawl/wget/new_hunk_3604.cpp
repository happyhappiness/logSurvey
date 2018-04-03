2001-08-15  Ian Abbott  <abbotti@mev.co.uk>

	* ftp.c (ftp_loop_internal): Avoid a potential buffer overflow in
	  the call to the 'rate' function by moving it past the error
	  checking for the 'getftp' function return value.

2001-11-16  Hrvoje Niksic  <hniksic@arsdigita.com>

	* html-parse.c (advance_declaration): Use 0x22 instead of '"' or
