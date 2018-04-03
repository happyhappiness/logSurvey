 -------
 
 --format=<fmt>::
-	Format of the resulting archive: 'tar' or 'zip'.  The default
-	is 'tar'.
+	Format of the resulting archive: 'tar' or 'zip'. If this option
+	is not given, and the output file is specified, the format is
+	inferred from the filename if possible (e.g. writing to "foo.zip"
+	makes the output to be in the zip format). Otherwise the output
+	format is `tar`.
 
 -l::
 --list::
