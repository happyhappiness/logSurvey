2001-03-31  Hrvoje Niksic  <hniksic@arsdigita.com>

	* main.c (print_help): Use multiple fputs instead of a single ugly
	printf().
	(main): Consistently assign numbers >128 to options without a
	corresponding character.

2001-03-09  Philipp Thomas  <pthomas@suse.de>

	* safe-ctype.h: New file. Locale independent ctype.h
