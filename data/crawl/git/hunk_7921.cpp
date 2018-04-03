 
  * "git-instaweb" no longer fails on Mac OS X.
 
+ * "git-cvsexportcommit" didn't always create new parent directories
+   before trying to create new child directories.  Fixed.
+
+ * "git-fetch" printed a scary (but bogus) error message while
+   fetching a tag that pointed to a tree or blob.  The error did
+   not impact correctness, only user perception.  The bogus error
+   is no longer printed.
+
+ * Git segfaulted when reading an invalid .gitattributes file.  Fixed.
+
  * post-receive-email example hook fixed was fixed for
    non-fast-forward updates.
 