 absence of output for a given file meant that it didn't match any
 pattern, or that the output hadn't been generated yet.)
 
+Buffering happens as documented under the `GIT_FLUSH` option in
+linkgit:git[1].  The caller is responsible for avoiding deadlocks
+caused by overfilling an input buffer or reading from an empty output
+buffer.
+
 EXIT STATUS
 -----------
 
