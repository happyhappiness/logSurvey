clearly diagnosed on @code{stderr}, after a line stating the nature of
the error.

Possible exit codes of @GNUTAR{} are summarized in the following
table:

@table @asis
@item 0
@samp{Successful termination}.

@item 1
@samp{Some files differ}.  If tar was invoked with @option{--compare}
(@option{--diff}, @option{-d}) command line option, this means that
some files in the archive differ from their disk counterparts
(@pxref{compare}).  If tar was given @option{--create},
@option{--append} or @option{--update} option, this exit code means
that some files were changed while being archived and so the resulting
archive does not contain the exact copy of the file set.

@item 2
@samp{Fatal error}.  This means that some fatal, unrecoverable error
occurred.
@end table

If @command{tar} has invoked a subprocess and that subprocess exited with a
nonzero exit code, @command{tar} exits with that code as well.
This can happen, for example, if @command{tar} was given some
compression option (@pxref{gzip}) and the external compressor program
failed.  Another example is @command{rmt} failure during backup to the
remote device (@pxref{Remote Tape Server}).

@node using tar options
@section Using @command{tar} Options
