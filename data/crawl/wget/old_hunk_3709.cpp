	{
	  /* Would a single s[n]printf() call be faster?  --dan

	     It wouldn't.  sprintf() is horribly slow.  At one point I
	     profiled Wget, and found that a measurable and
	     non-negligible amount of time was lost calling sprintf()
	     in url.c.  Replacing sprintf with inline calls to
	     strcpy() and long_to_string() made a difference.
