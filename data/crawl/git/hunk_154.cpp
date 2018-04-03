 	the background which do not want to cause lock contention with
 	other operations on the repository.  Defaults to `1`.
 
+`GIT_REDIRECT_STDIN`::
+`GIT_REDIRECT_STDOUT`::
+`GIT_REDIRECT_STDERR`::
+	Windows-only: allow redirecting the standard input/output/error
+	handles to paths specified by the environment variables. This is
+	particularly useful in multi-threaded applications where the
+	canonical way to pass standard handles via `CreateProcess()` is
+	not an option because it would require the handles to be marked
+	inheritable (and consequently *every* spawned process would
+	inherit them, possibly blocking regular Git operations). The
+	primary intended use case is to use named pipes for communication
+	(e.g. `\\.\pipe\my-git-stdin-123`).
+Two special values are supported: `off` will simply close the
+corresponding standard handle, and if `GIT_REDIRECT_STDERR` is
+`2>&1`, standard error will be redirected to the same handle as
+standard output.
+
 Discussion[[Discussion]]
 ------------------------
 