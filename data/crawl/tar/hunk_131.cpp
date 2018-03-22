 is taken to be the name of a file whose data modification time specifies
 the date.  @xref{after}.
 
+@opindex newer-mtime, summary
 @item --newer-mtime=@var{date}
 
 Like @option{--newer}, but add only files whose
 contents have changed (as opposed to just @option{--newer}, which will
 also back up files for which any status information has changed).
 
+@opindex no-anchored, summary
 @item --no-anchored
 An exclude pattern can match any subsequence of the name's components.
 @xref{controlling pattern-matching with exclude}.
 
+@opindex no-ignore-case, summary
 @item --no-ignore-case
 Use case-sensitive matching when excluding files.
 @xref{controlling pattern-matching with exclude}.
 
+@opindex no-ignore-command-error, summary
 @item --no-ignore-command-error
 Print warnings about subprocesses terminated with a non-zero exit
 code. @xref{Writing to an External Program}. 
 
+@opindex no-recursion, summary
 @item --no-recursion
 
 With this option, @command{tar} will not recurse into directories.
 @xref{recurse}.
 
+@opindex no-same-owner, summary
 @item --no-same-owner
 @itemx -o
 
