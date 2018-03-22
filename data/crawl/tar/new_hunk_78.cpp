2008-06-26  Sergey Poznyakoff  <gray@gnu.org.ua>

	* configure.ac, NEWS: Version 1.20.90
	* doc/tar.texi: Document -J, --no-auto-compress, etc.
	* src/buffer.c (ct_tar): New constant.
	(magic): Add lzop support.  Proposed by Kevin Day
	<thekevinday@gmail.com>.
	(check_compressed_archive): Do not use autodetect if the
	compression program was specified explicitly.
	Fall back to analyzing archive name, if the autodetection fails.
	* src/suffix.c: Add .lzo
	* src/tar.c: New options --lzop and --no-auto-compress.
	New short option -J (alias for --lzma).

	* src/buffer.c (try_new_volume): Print more information with error
	diagnostics.
	(_gnu_flush_write): Improve error checking.  Adjust
