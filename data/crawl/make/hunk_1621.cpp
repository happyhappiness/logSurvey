 that output from all of the commands comes when the commands send it, so
 messages from different commands may be interspersed.
 
-Another problem is that two processes cannot both take input from the same
-device; so to make sure that only one command tries to take input from the
-terminal at once, @code{make} will invalidate the standard input streams of
-all but one running command.  This means that attempting to read from
-standard input, for most child processes if there are several, will usually
-be a fatal error (a @samp{Broken pipe} signal).
+Another problem is that two processes cannot both take input from the
+same device; so to make sure that only one command tries to take input
+from the terminal at once, @code{make} will invalidate the standard
+input streams of all but one running command.  This means that
+attempting to read from standard input will usually be a fatal error (a
+@samp{Broken pipe} signal) for most child processes if there are
+several.
 
 It is unpredictable which command will have a valid standard input stream
 (which will come from the terminal, or wherever you redirect the standard
