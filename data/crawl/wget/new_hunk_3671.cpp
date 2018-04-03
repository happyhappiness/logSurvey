2001-05-08  Hrvoje Niksic  <hniksic@arsdigita.com>

	* http.c (http_loop): Reset no_truncate before deciding whether to
	set it.
	(gethttp): Further clarify "-c conflicts with existing file" error
	message, based on input from Herold Heiko.

2001-05-07  Hrvoje Niksic  <hniksic@arsdigita.com>

	* http.c (http_loop): If restval is set, set no_truncate to 1
