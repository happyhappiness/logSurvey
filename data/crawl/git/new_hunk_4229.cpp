unsigned, with 'verbatim', they will be silently exported
and with 'warn', they will be exported, but you will see a warning.

--tag-of-filtered-object=(abort|drop|rewrite)::
	Specify how to handle tags whose tagged object is filtered out.
	Since revisions and files to export can be limited by path,
	tagged objects may be filtered completely.
When asking to 'abort' (which is the default), this program will die
when encountering such a tag.  With 'drop' it will omit such tags from
the output.  With 'rewrite', if the tagged object is a commit, it will
rewrite the tag to tag an ancestor commit (via parent rewriting; see
linkgit:git-rev-list[1])

-M::
-C::
	Perform move and/or copy detection, as described in the
	linkgit:git-diff[1] manual page, and use it to generate
	rename and copy commands in the output dump.
Note that earlier versions of this command did not complain and
produced incorrect results if you gave these options.

--export-marks=<file>::
	Dumps the internal marks table to <file> when complete.
	Marks are written one per line as `:markid SHA-1`. Only marks
