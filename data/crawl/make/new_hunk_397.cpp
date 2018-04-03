2013-05-11  Eli Zaretskii  <eliz@gnu.org>

	* job.c (child_out): Output the newline following the message
	before fllush-ing the stream.  Avoids displaying the following
	failure message, which goes to stderr, on the same line.

2013-05-06  Eli Zaretskii  <eliz@gnu.org>

	* gnumake.h (GMK_EXPORT) [_WIN32]: Move the dllexport declaration
