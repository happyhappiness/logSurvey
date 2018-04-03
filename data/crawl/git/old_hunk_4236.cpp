	Aside from returning an error code of 1, it will also print an error
	message if '--quiet' was not specified.


	Abbreviate the object name.  When using `--hash`, you do
	not have to say `--hash --abbrev`; `--hash=len` would do.

-q::
--quiet::

	Do not print any results to stdout. When combined with '--verify' this
	can be used to silently check if a reference exists.


	Make 'git-show-ref' act as a filter that reads refs from stdin of the
	form "^(?:<anything>\s)?<refname>(?:\^\{\})?$" and performs the
	following actions on each:
	(1) strip "^{}" at the end of line if any;
