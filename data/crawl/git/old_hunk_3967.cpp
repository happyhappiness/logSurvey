
OPTIONS
-------
	Specify the type of dates the frontend will supply to
	fast-import within `author`, `committer` and `tagger` commands.
	See ``Date Formats'' below for details about which formats
	are supported, and their syntax.

--force::
	Force updating modified existing branches, even if doing
	so would cause commits to be lost (as the new commit does
	not contain the old commit).

	Maximum size of each output packfile.
	The default is unlimited.

	Maximum size of a blob that fast-import will attempt to
	create a delta for, expressed in bytes.  The default is 512m
	(512 MiB).  Some importers may wish to lower this on systems
	with constrained memory.

	Maximum delta depth, for blob and tree deltification.
	Default is 10.

	Maximum number of branches to maintain active at once.
	See ``Memory Utilization'' below for details.  Default is 5.

--export-marks=<file>::
	Dumps the internal marks table to <file> when complete.
