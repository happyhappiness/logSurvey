 
 @cindex error (in commands)
 After each shell command returns, @code{make} looks at its exit status.
-If the command completed successfully, the next command line is executed in
-a new shell, or after the last command line is executed, the rule is finished.
+If the command completed successfully, the next command line is executed
+in a new shell; after the last command line is finished, the rule is
+finished. 
 
 If there is an error (the exit status is nonzero), @code{make} gives up on
 the current rule, and perhaps on all rules.
