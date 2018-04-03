output.  If <prefix> is specified it is
prepended to the filenames in the archive.

'git archive' behaves differently when given a tree ID versus when
given a commit ID or tag ID.  In the first case the current time is
used as the modification time of each file in the archive.  In the latter
case the commit time as recorded in the referenced commit object is
used instead.  Additionally the commit ID is stored in a global
extended pax header if the tar format is used; it can be extracted
using 'git get-tar-commit-id'. In ZIP files it is stored as a file
comment.

OPTIONS
-------

--format=<fmt>::
	Format of the resulting archive: 'tar' or 'zip'. If this option
	is not given, and the output file is specified, the format is
	inferred from the filename if possible (e.g. writing to "foo.zip"
	makes the output to be in the zip format). Otherwise the output
	format is `tar`.

-l::
--list::
