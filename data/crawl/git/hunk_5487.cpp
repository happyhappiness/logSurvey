 
 DESCRIPTION
 -----------
-Reads supplied 'diff' output and applies it on a git index file
-and a work tree.
+Reads the supplied diff output (i.e. "a patch") and applies it to files.
+With the `--index` option the patch is also applied to the index, and
+with the `--cache` option the patch is only applied to the index.
+Without these options, the command applies the patch only to files,
+and does not require them to be in a git repository.
 
 OPTIONS
 -------