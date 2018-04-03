 attempting to read from standard input will usually be a fatal error (a
 @samp{Broken pipe} signal) for most child processes if there are
 several.
+@cindex broken pipe
+@cindex standard input
 
 It is unpredictable which command will have a valid standard input stream
 (which will come from the terminal, or wherever you redirect the standard
