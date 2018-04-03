 	Synonym for "-p --stat".
 
 -z::
-	\0 line termination on output
+	NUL-line termination on output.  This affects the --raw
+	output field terminator.  Also output from commands such
+	as "git-log" will be delimited with NUL between commits.
 
 --name-only::
 	Show only names of changed files.