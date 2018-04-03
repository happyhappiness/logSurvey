 All of the fixes in v1.7.3.X maintenance series are included in this
 release, unless otherwise noted.
 
+ * "diff" and friends incorrectly applied textconv filters to symlinks
+   (d391c0ff).
+
+ * "git apply" segfaulted when a bogus input is fed to it (24305cd70).
+
+ * Running "git cherry-pick --ff" on a root commit segfaulted (6355e50).
+
  * "git log --author=me --author=her" did not find commits written by
    me or by her; instead it looked for commits written by me and by
    her, which is impossible.
 
+ * "git merge-file" can be called from within a subdirectory now
+   (55846b9a).
+
+ * "git push --progress" shows progress indicators now.
+
+ * "git repack" places its temporary packs under $GIT_OBJECT_DIRECTORY/pack
+   instead of $GIT_OBJECT_DIRECTORY/ to avoid cross directory renames.
+
+ * "git rev-list --format="...%x00..." incorrectly chopped its output
+   at NUL (9130ac9fe).
+
+ * "git submodule update --recursive --other-flags" passes flags down
+   to its subinvocations.
 
 ---
 exec >/var/tmp/1
-O=v1.7.3
-O=v1.7.3.1-42-g34289ec
+O=v1.7.3.2-245-g03276d9
 echo O=$(git describe master)
 git shortlog --no-merges ^maint ^$O master