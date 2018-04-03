	one <tree-ish>, or '--stdin').  It shows the differences
	from each of the parents to the merge result simultaneously
	instead of showing pairwise diff between a parent and the
	result one at a time (which is what the `-m` option does).
	Furthermore, it lists only files which were modified
	from all parents.

--cc::
	This flag changes the way a merge commit patch is displayed,
	in a similar way to the `-c` option. It implies the `-c`
	and `-p` options and further compresses the patch output
	by omitting uninteresting hunks whose the contents in the parents
	have only two variants and the merge result picks one of them
	without modification.  When all hunks are uninteresting, the commit
