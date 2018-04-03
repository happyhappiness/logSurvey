    streaming a zip archive, which confused some implementations of unzip.
    (merge 5ea2c84 rs/zip-with-uncompressed-size-in-the-header later to maint).
 
+ * "git clean" showed what it was going to do, but sometimes end up
+   finding that it was not allowed to do so, which resulted in a
+   confusing output (e.g. after saying that it will remove an
+   untracked directory, it found an embedded git repository there
+   which it is not allowed to remove).  It now performs the actions
+   and then reports the outcome more faithfully.
+   (merge f538a91 zk/clean-report-failure later to maint).
+
  * When "git clone --separate-git-dir=$over_there" is interrupted, it
    failed to remove the real location of the $GIT_DIR it created.
    This was most visible when interrupting a submodule update.
