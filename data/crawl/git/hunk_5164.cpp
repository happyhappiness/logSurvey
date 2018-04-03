    minimize the output, but this often was spending too many extra cycles
    for very little gain (582aa00).
 
+ * "git diff --graph" works better with "--color-words" and other options
+   (81fa024..4297c0a).
+
+ * "git diff" could show ambiguous abbreviation of blob object names on
+   its "index" line (3e5a188).
+
+ * "git merge --log" used to replace the custom message given by "-m" with
+   the shortlog, instead of appending to it (tc/merge-m-log).
+
  * "git pull" accepted "--dry-run", gave it to underlying "git fetch" but
    ignored the option itself, resulting in a bogus attempt to merge
    unrelated commit (29609e68).
 
  * "git reset --hard" started from a wrong directory and a working tree in
    a nonstandard location is in use got confused (560fb6a1).
 
+ * "git show -C -C" and other corner cases lost diff metainfo output
+   in 1.7.0 (296c6bb).
+
 --
 exec >/var/tmp/1
-O=v1.7.1-336-g0925c02
-echo O=$(git describe master)
-git shortlog --no-merges master ^maint ^$O
+O=v1.7.1-423-gae391ec
+echo O=$(git describe HEAD)
+git shortlog --no-merges HEAD ^maint ^$O