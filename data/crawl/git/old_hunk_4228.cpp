output.  If <prefix> is specified it is
prepended to the filenames in the archive.

'git-archive' behaves differently when given a tree ID versus when
given a commit ID or tag ID.  In the first case the current time is
used as modification time of each file in the archive.  In the latter
case the commit time as recorded in the referenced commit object is
used instead.  Additionally the commit ID is stored in a global
extended pax header if the tar format is used; it can be extracted
using 'git-get-tar-commit-id'. In ZIP files it is stored as a file
comment.

OPTIONS
-------

--format=<fmt>::
	Format of the resulting archive: 'tar' or 'zip'.  The default
	is 'tar'.

-l::
--list::
