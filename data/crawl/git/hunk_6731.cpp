 
  - 'git-diff-tree' compares contents of two "tree" objects;
 
-In all of these cases, the commands themselves compare
-corresponding paths in the two sets of files.  The result of
-comparison is passed from these commands to what is internally
-called "diffcore", in a format similar to what is output when
-the -p option is not used.  E.g.
+In all of these cases, the commands themselves first optionally limit
+the two sets of files by any pathspecs given on their command-lines,
+and compare corresponding paths in the two resulting sets of files.
+
+The pathspecs are used to limit the world diff operates in.  They remove
+the filepairs outside the specified sets of pathnames.  E.g. If the
+input set of filepairs included:
+
+------------------------------------------------
+:100644 100644 bcd1234... 0123456... M junkfile
+------------------------------------------------
+
+but the command invocation was `git diff-files myfile`, then the
+junkfile entry would be removed from the list because only "myfile"
+is under consideration.
+
+The result of comparison is passed from these commands to what is
+internally called "diffcore", in a format similar to what is output
+when the -p option is not used.  E.g.
 
 ------------------------------------------------
 in-place edit  :100644 100644 bcd1234... 0123456... M file0
