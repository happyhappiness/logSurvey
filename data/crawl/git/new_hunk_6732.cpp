The diffcore mechanism is fed a list of such comparison results
(each of which is called "filepair", although at this point each
of them talks about a single file), and transforms such a list
into another list.  There are currently 5 such transformations:

- diffcore-break
- diffcore-rename
- diffcore-merge-broken
- diffcore-pickaxe
- diffcore-order

These are applied in sequence.  The set of filepairs 'git-diff-{asterisk}'
commands find are used as the input to diffcore-break, and
the output from diffcore-break is used as the input to the
next transformation.  The final result is then passed to the
output routine and generates either diff-raw format (see Output
format sections of the manual for 'git-diff-{asterisk}' commands) or
diff-patch format.


diffcore-break: For Splitting Up "Complete Rewrites"
----------------------------------------------------

