+2014-11-04  Tim Ruehsen  <tim.ruehsen@gmx.de>
+
+	* iri.c (do_conversion): fix quote() misuse
+	* iri.c (remote_to_utf8): fix segfault on do_conversion() error
+
+	Reported-by: Mikael Magnusson <mikachu@gmail.com>
+
 2014-10-21  Matthew Atkinson  <mutley456@ntlworld.com> (tiny change)
 
 	* http.c (gethttp): Always send Content-Length header when method is POST,
