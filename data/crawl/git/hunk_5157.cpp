  * We didn't URL decode "file:///path/to/repo" correctly when path/to/repo
    had percent-encoded characters (638794c, 9d2e942).
 
+ * "git commit" did not honor GIT_REFLOG_ACTION environment variable, resulting
+   reflog messages for cherry-pick and revert actions to be recorded as "commit".
+
  * "git clone/fetch/pull" issued an incorrect error message when a ref and
    a symref that points to the ref were updated at the same time.  This
    obviously would update them to the same value, and should not result in
-   an error condition (7223dcaf).
+   an error condition (0e71bc3).
 
  * "git clone" did not configure remote.origin.url correctly for bare
    clones (df61c889).
 
+ * "git diff" inside a tree with many pathnames that have certain
+   characters has become very slow in 1.7.0 by mistake (will merge
+   e53e6b443 to 'maint').
+
  * "git diff --graph" works better with "--color-words" and other options
    (81fa024..4297c0a).
 
  * "git diff" could show ambiguous abbreviation of blob object names on
    its "index" line (3e5a188).
 
- * "git merge --log" used to replace the custom message given by "-m" with
-   the shortlog, instead of appending to it (tc/merge-m-log).
-
  * "git reset --hard" started from a wrong directory and a working tree in
    a nonstandard location is in use got confused (560fb6a1).
 
- * "git show -C -C" and other corner cases lost diff metainfo output
-   in 1.7.0 (296c6bb).
-
 --
 exec >/var/tmp/1
-O=v1.7.1-423-gae391ec
+O=v1.7.1-568-g2c177a1
 echo O=$(git describe HEAD)
 git shortlog --no-merges HEAD ^maint ^$O