	{
	  /* Would a single s[n]printf() call be faster?  --dan

	     Definitely not.  sprintf() is horribly slow.  It's a
	     different question whether the difference between the two
	     affects a program.  Usually I'd say "no", but at one
	     point I profiled Wget, and found that a measurable and
	     non-negligible amount of time was lost calling sprintf()
	     in url.c.  Replacing sprintf with inline calls to
	     strcpy() and long_to_string() made a difference.
