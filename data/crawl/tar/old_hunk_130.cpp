@command{gzip}, allowing @command{tar} to directly operate on several
kinds of compressed archives transparently.  @xref{gzip}.

@item --help

@command{tar} will print out a short message summarizing the operations and
options to @command{tar} and exit. @xref{help}.

@item --ignore-case
Ignore case when excluding files. @xref{controlling pattern-matching
with exclude}.

@item --ignore-command-error
Ignore exit codes of subprocesses. @xref{Writing to an External Program}.

@item --ignore-failed-read

Do not exit unsuccessfully merely because an unreadable file was encountered.
@xref{Reading}.

@item --ignore-zeros
@itemx -i

With this option, @command{tar} will ignore zeroed blocks in the
archive, which normally signals EOF.  @xref{Reading}.

@item --incremental
@itemx -G

