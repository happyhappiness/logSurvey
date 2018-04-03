 track are contained in this release (see the maintenance releases' notes
 for details).
 
+ * "git mv A B/", when B does not exist as a directory, should error
+   out, but it didn't.
+   (merge c57f628 mm/mv-file-to-no-such-dir-with-slash later to maint).
+
+ * A workaround to an old bug in glibc prior to glibc 2.17 has been
+   retired; this would remove a side effect of the workaround that
+   corrupts system error messages in non-C locales.
+
+ * SSL-related options were not passed correctly to underlying socket
+   layer in "git send-email".
+   (merge 5508f3e tr/send-email-ssl later to maint).
+
+ * "git commit -v" appends the patch to the log message before
+   editing, and then removes the patch when the editor returned
+   control. However, the patch was not stripped correctly when the
+   first modified path was a submodule.
+   (merge 1a72cfd jl/commit-v-strip-marker later to maint).
+
+ * "git fetch --depth=0" was a no-op, and was silently ignored.
+   Diagnose it as an error.
+   (merge 5594bca nd/transport-positive-depth-only later to maint).
+
+ * Remote repository URL expressed in scp-style host:path notation are
+   parsed more carefully (e.g. "foo/bar:baz" is local, "[::1]:/~user" asks
+   to connect to user's home directory on host at address ::1.
+   (merge a2036d7 tb/clone-ssh-with-colon-for-port later to maint).
+
  * "git diff -- ':(icase)makefile'" was unnecessarily rejected at the
    command line parser.
    (merge 887c6c1 nd/magic-pathspec later to maint).