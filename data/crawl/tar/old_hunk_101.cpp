clearly diagnosed on @code{stderr}, after a line stating the nature of
the error.

@GNUTAR{} returns only a few exit statuses.  I'm really
aiming simplicity in that area, for now.  If you are not using the
@option{--compare} @option{--diff}, @option{-d}) option, zero means
that everything went well, besides maybe innocuous warnings.  Nonzero
means that something went wrong. Right now, as of today, ``nonzero''
is almost always 2, except for remote operations, where it may be
128.

@node using tar options
@section Using @command{tar} Options
