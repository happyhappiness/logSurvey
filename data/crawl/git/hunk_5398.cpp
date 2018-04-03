 -q::
 --quiet::
 	Pass --quiet to git-fetch-pack and silence any other internally
-	used git commands.
+	used git commands. Progress is not reported to the standard error
+	stream.
 
 -v::
 --verbose::
 	Be verbose.
 endif::git-pull[]
+
+--progress::
+	Progress status is reported on the standard error stream
+	by default when it is attached to a terminal, unless -q
+	is specified. This flag forces progress status even if the
+	standard error stream is not directed to a terminal.
