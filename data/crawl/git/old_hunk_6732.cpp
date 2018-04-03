The diffcore mechanism is fed a list of such comparison results
(each of which is called "filepair", although at this point each
of them talks about a single file), and transforms such a list
into another list.  There are currently 6 such transformations:

- diffcore-break
- diffcore-rename
- diffcore-merge-broken
- diffcore-pickaxe
- diffcore-order

These are applied in sequence.  The set of filepairs 'git-diff-{asterisk}'
commands find are used as the input to diffcore-pathspec, and
the output from diffcore-pathspec is used as the input to the
next transformation.  The final result is then passed to the
output routine and generates either diff-raw format (see Output
format sections of the manual for 'git-diff-{asterisk}' commands) or
diff-patch format.


diffcore-pathspec: For Ignoring Files Outside Our Consideration

The first transformation in the chain is diffcore-pathspec, and
is controlled by giving the pathname parameters to the
'git-diff-{asterisk}' commands on the command line.  The pathspec is used
to limit the world diff operates in.  It removes the filepairs
outside the specified set of pathnames.  E.g. If the input set
of filepairs included:

:100644 100644 bcd1234... 0123456... M junkfile

but the command invocation was `git diff-files myfile`, then the
junkfile entry would be removed from the list because only "myfile"
is under consideration.

Implementation note.  For performance reasons, 'git-diff-tree'
uses the pathname parameters on the command line to cull set of
filepairs it feeds the diffcore mechanism itself, and does not
use diffcore-pathspec, but the end result is the same.


diffcore-break: For Splitting Up "Complete Rewrites"
----------------------------------------------------

