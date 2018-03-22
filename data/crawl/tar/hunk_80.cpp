+2008-06-26  Sergey Poznyakoff  <gray@gnu.org.ua>
+
+	* src/buffer.c (try_new_volume): Print more information with error
+	diagnostics.
+	(_gnu_flush_write): Improve error checking.  Adjust
+	real_s_sizeleft before calling new_volume to avoid creating
+	malformed multivolume headers.
+	* tests/delete05.at, tests/gzip.at, tests/ignfail.at,
+	tests/longv7.at, tests/lustar01.at, tests/lustar02.at,
+	tests/shortfile.at: Update to match new diagnostic wording
+	(see 2008-05-06).
+	
+	* NEWS: Update.
+
 2008-06-14  Sergey Poznyakoff  <gray@gnu.org.ua>
 
 	* doc/tar.texi (exclude): Document support for new VCS.
