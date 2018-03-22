 @command{gzip}, allowing @command{tar} to directly operate on several
 kinds of compressed archives transparently.  @xref{gzip}.
 
+@opindex help, summary
 @item --help
 
 @command{tar} will print out a short message summarizing the operations and
 options to @command{tar} and exit. @xref{help}.
 
+@opindex ignore-case, summary
 @item --ignore-case
 Ignore case when excluding files. @xref{controlling pattern-matching
 with exclude}.
 
+@opindex ignore-command-error, summary
 @item --ignore-command-error
 Ignore exit codes of subprocesses. @xref{Writing to an External Program}.
 
+@opindex ignore-failed-read, summary
 @item --ignore-failed-read
 
 Do not exit unsuccessfully merely because an unreadable file was encountered.
 @xref{Reading}.
 
+@opindex ignore-zeros, summary
 @item --ignore-zeros
 @itemx -i
 
 With this option, @command{tar} will ignore zeroed blocks in the
 archive, which normally signals EOF.  @xref{Reading}.
 
+@opindex incremental, summary
 @item --incremental
 @itemx -G
 
