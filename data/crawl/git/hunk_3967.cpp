 
 OPTIONS
 -------
-	Specify the type of dates the frontend will supply to
-	fast-import within `author`, `committer` and `tagger` commands.
-	See ``Date Formats'' below for details about which formats
-	are supported, and their syntax.
 
 --force::
 	Force updating modified existing branches, even if doing
 	so would cause commits to be lost (as the new commit does
 	not contain the old commit).
 
-	Maximum size of each output packfile.
-	The default is unlimited.
+--quiet::
+	Disable all non-fatal output, making fast-import silent when it
+	is successful.  This option disables the output shown by
+	\--stats.
 
-	Maximum size of a blob that fast-import will attempt to
-	create a delta for, expressed in bytes.  The default is 512m
-	(512 MiB).  Some importers may wish to lower this on systems
-	with constrained memory.
+--stats::
+	Display some basic statistics about the objects fast-import has
+	created, the packfiles they were stored into, and the
+	memory used by fast-import during this run.  Showing this output
+	is currently the default, but can be disabled with \--quiet.
 
-	Maximum delta depth, for blob and tree deltification.
-	Default is 10.
+Options for Frontends
+~~~~~~~~~~~~~~~~~~~~~
 
-	Maximum number of branches to maintain active at once.
-	See ``Memory Utilization'' below for details.  Default is 5.
+--cat-blob-fd=<fd>::
+	Specify the file descriptor that will be written to
+	when the `cat-blob` command is encountered in the stream.
+	The default behaviour is to write to `stdout`.
+
+--date-format=<fmt>::
+	Specify the type of dates the frontend will supply to
+	fast-import within `author`, `committer` and `tagger` commands.
+	See ``Date Formats'' below for details about which formats
+	are supported, and their syntax.
+
+--done::
+	Terminate with error if there is no `done` command at the end of
+	the stream.  This option might be useful for detecting errors
+	that cause the frontend to terminate before it has started to
+	write a stream.
+
+Locations of Marks Files
+~~~~~~~~~~~~~~~~~~~~~~~~
 
 --export-marks=<file>::
 	Dumps the internal marks table to <file> when complete.
