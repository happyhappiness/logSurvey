2005-02-20  Hrvoje Niksic  <hniksic@xemacs.org>

	* mswindows.c (wget_ftello): Wget's replacement for ftello.

	* utils.c (file_size): Use ftello where available.

	* ftp-ls.c (ftp_parse_unix_ls): Use str_to_wgint to parse the file
	size.
	(ftp_parse_winnt_ls): Ditto.

	* ftp-basic.c (ftp_size): Use str_to_wgint to convert number to
	wgint; pass 10 instead of 0 as the BASE argument.

	* ftp.c (ftp_expected_bytes): Use str_to_wgint to parse the file
	size.

	* sysdep.h (LARGE_INT_FMT): Use __int64 as LARGE_INT on
	MSVC/Windows; print it with "%I64".

	* wget.h: Define a `wgint' type, normally aliased to (the possibly
	64-bit variant of) off_t.

	* all: Use `wgint' instead of `long' for numeric variables that
	can hold file sizes.

	* utils.c (number_to_string): Support printing of `wgint'
	argument.
	(number_to_static_string): New function.

	* all: Replace printf("%ld", long_value) with printf("%s",
	number_to_static_string(wgint_value)).

2005-02-18  Mauro Tortonesi <mauro@ferrara.linux.it>

	* main.c: Added the --ftp-passwd command line option.
