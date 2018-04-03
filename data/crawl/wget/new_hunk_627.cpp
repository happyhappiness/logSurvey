2009-07-04  Micah Cowan  <micah@cowan.name>

	* main.c (print_version): Allow localization of the version-info
	labels, eschew attempts at alignment (which is complicated when
	handling translated strings), and avoid using printf() with
	variable-stored format strings that lack conversion
	specifications.
	(format_and_print_line): For similar reasons, don't calculate
	line-continuation tabulation based on the number of bytes in a
	string.

2009-07-03  Micah Cowan  <micah@cowan.name>

	* iri.h (iri_dup): Provide macro definition for when IRIs are
