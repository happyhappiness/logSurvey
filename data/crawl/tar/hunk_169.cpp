+2005-02-05  Sergey Poznyakoff  <gray@Mirddin.farlep.net>
+
+	Initial implementation of --to-command option proposed
+	by Hansjoerg Lipp.
+	
+	* bootstrap: Get setenv module from gnulib
+	* src/buffer.c: Do not use 8-bit chars in comments
+	* src/common.h (to_command_option)
+	(ignore_command_error_option): New globals
+	(sys_exec_command,sys_wait_command): New commands
+	* src/extract.c (extract_file): Handle to_command_option
+	Fix error recovery: decrease `size' by `written', not
+	by `count', otherwise tar misses the next header
+	Do not diagnose write errror if to_command_option
+	is set, since the command may have exited prematurely.
+	It would be better to check for sigpipe, though.
+	(prepare_to_extract): Handle to_command_option
+	* src/misc.c (exec_error, fork_error, dup_error) 
+	(pipe_error): New functions
+	* src/system.c (sys_exec_command)
+	(sys_wait_command): New functions
+	* src/tar.c: Handle new options --to-command,
+	--ignore-command-error
+	* THANKS: Added Hansjoerg Lipp
+
 2005-02-03  Paul Eggert  <eggert@cs.ucla.edu>
 
 	* src/list.c (from_header): New arg OCTAL_ONLY, normally false.
