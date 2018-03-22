
@cindex exit status
@cindex return status
Besides successful exits, @acronym{GNU} @command{tar} may fail for
many reasons.  Some reasons correspond to bad usage, that is, when the
@command{tar} command is improperly written.  Errors may be
encountered later, while encountering an error processing the archive
or the files.  Some errors are recoverable, in which case the failure
is delayed until @command{tar} has completed all its work.  Some
errors are such that it would not meaningful, or at least risky, to
continue processing: @command{tar} then aborts processing immediately.
All abnormal exits, whether immediate or delayed, should always be
clearly diagnosed on @code{stderr}, after a line stating the nature of
the error.

@acronym{GNU} @command{tar} returns only a few exit statuses.  I'm really
aiming simplicity in that area, for now.  If you are not using the
@value{op-compare} option, zero means that everything went well, besides
maybe innocuous warnings.  Nonzero means that something went wrong.
