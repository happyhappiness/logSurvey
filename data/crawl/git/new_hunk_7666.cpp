

include::diff-generate-patch.txt[]


other diff formats
------------------

The `--summary` option describes newly added, deleted, renamed and
copied files.  The `--stat` option adds diffstat(1) graph to the
output.  These options can be combined with other options, such as
`-p`, and are meant for human consumption.

When showing a change that involves a rename or a copy, `--stat` output
formats the pathnames compactly by combining common prefix and suffix of
the pathnames.  For example, a change that moves `arch/i386/Makefile` to
`arch/x86/Makefile` while modifying 4 lines will be shown like this:

------------------------------------
arch/{i386 => x86}/Makefile    |   4 +--
------------------------------------

The `--numstat` option gives the diffstat(1) information but is designed
for easier machine consumption.  An entry in `--numstat` output looks
like this:

----------------------------------------
1	2	README
3	1	arch/{i386 => x86}/Makefile
----------------------------------------

That is, from left to right:

. the number of added lines;
. a tab;
. the number of deleted lines;
. a tab;
. pathname (possibly with rename/copy information);
. a newline.

When `-z` output option is in effect, the output is formatted this way:

----------------------------------------
1	2	README NUL
3	1	NUL arch/i386/Makefile NUL arch/x86/Makefile NUL
----------------------------------------

That is:

. the number of added lines;
. a tab;
. the number of deleted lines;
. a tab;
. a NUL (only exists if renamed/copied);
. pathname in preimage;
. a NUL (only exists if renamed/copied);
. pathname in postimage (only exists if renamed/copied);
. a NUL.

The extra `NUL` before the preimage path in renamed case is to allow
scripts that read the output to tell if the current record being read is
a single-path record or a rename/copy record without reading ahead.
After reading added and deleted lines, reading up to `NUL` would yield
the pathname, but if that is `NUL`, the record will show two paths.
