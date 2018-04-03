
 - 'git-diff-tree' compares contents of two "tree" objects;

In all of these cases, the commands themselves compare
corresponding paths in the two sets of files.  The result of
comparison is passed from these commands to what is internally
called "diffcore", in a format similar to what is output when
the -p option is not used.  E.g.

------------------------------------------------
in-place edit  :100644 100644 bcd1234... 0123456... M file0
