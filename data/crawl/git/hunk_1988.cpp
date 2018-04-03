 
  * Move from unsigned char[20] to struct object_id continues.
 
+ * Update of "git submodule" to move pieces of logic to C continues.
+
+ * The code for warning_errno/die_errno has been refactored and a new
+   error_errno() reporting helper is introduced.
+   (merge 1da045f nd/error-errno later to maint).
+
+ * Running tests with '-x' option to trace the individual command
+   executions is a useful way to debug test scripts, but some tests
+   that capture the standard error stream and check what the command
+   said can be broken with the trace output mixed in.  When running
+   our tests under "bash", however, we can redirect the trace output
+   to another file descriptor to keep the standard error of programs
+   being tested intact.
+   (merge d88785e jk/test-send-sh-x-trace-elsewhere later to maint).
+
 
 Also contains various documentation updates and code clean-ups.
 
