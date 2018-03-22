favor of the tape where the file appears earliest (closest to the
front of the tape).  @xref{backup}.

@node checkpoints
@section Checkpoints
@cindex checkpoints, defined
@opindex checkpoint
@opindex checkpoint-action

A @dfn{checkpoint} is a moment of time before writing @var{n}th record to
the archive (a @dfn{write checkpoint}), or before reading @var{n}th record
from the archive (a @dfn{read checkpoint}).  Checkpoints allow to
periodically execute arbitrary actions.

The checkpoint facility is enabled using the following option:

@table @option
@xopindex{checkpoint, defined}
@item --checkpoint[=@var{n}]
Schedule checkpoints before writing or reading each @var{n}th record.
The default value for @var{n} is 10.
@end table

A list of arbitrary @dfn{actions} can be executed at each checkpoint.
These actions include: pausing, displaying textual messages, and
executing arbitrary external programs.  Actions are defined using
the @option{--checkpoint-action} option.

@table @option
@xopindex{checkpoint-action, defined}
@item --checkpoint-action=@var{action}
Execute an @var{action} at each checkpoint.
@end table

@cindex @code{echo}, checkpoint action
The simplest value of @var{action} is @samp{echo}.  It instructs
@command{tar} to display the default message on the standard error
stream upon arriving at each checkpoint.  The default message is (in
@acronym{POSIX} locale) @samp{Write checkpoint @var{n}}, for write
checkpoints, and @samp{Read checkpoint @var{n}}, for read checkpoints.
Here, @var{n} represents ordinal number of the checkpoint.

In another locales, translated versions of this message are used.

This is the default action, so running:

@smallexample
$ @kbd{tar -c --checkpoint=1000 --checkpoint-action=echo} /var
@end smallexample

@noindent
is equivalent to:

@smallexample
$ @kbd{tar -c --checkpoint=1000} /var
@end smallexample

The @samp{echo} action also allows to supply a customized message.
You do so by placing an equals sign and the message right after it,
e.g.:

@smallexample
--checkpoint-action="echo=Hit %s checkpoint #%u"
@end smallexample

The @samp{%s} and @samp{%u} in the above example are
@dfn{meta-characters}.  The @samp{%s} meta-character is replaced with
the @dfn{type} of the checkpoint: @samp{write} or
@samp{read} (or a corresponding translated version in locales other
than @acronym{POSIX}).  The @samp{%u} meta-character is replaced with
the ordinal number of the checkpoint.  Thus, the above example could
produce the following output when used with the @option{--create}
option:

@smallexample
tar: Hit write checkpoint #10
tar: Hit write checkpoint #20
tar: Hit write checkpoint #30
@end smallexample

Aside from meta-character expansion, the message string is subject to
@dfn{unquoting}, during which the backslash @dfn{escape sequences} are
replaced with their corresponding @acronym{ASCII} characters
(@pxref{escape sequences}).  E.g. the following action will produce an
audible bell and the message described above at each checkpoint:

@smallexample
--checkpoint-action='echo=\aHit %s checkpoint #%u'
@end smallexample

@cindex @code{dot}, checkpoint action
Another available checkpoint action is @samp{dot} (or @samp{.}).  It
instructs @command{tar} to print a single dot on the standard listing
stream, e.g.:

@smallexample
$ @kbd{tar -c --checkpoint=1000 --checkpoint-action=dot} /var
...
@end smallexample

For compatibility with previous @GNUTAR{} versions, this action can
be abbreviated by placing a dot in front of the checkpoint frequency,
as shown in the previous section.

@cindex @code{sleep}, checkpoint action
Yet another action, @samp{sleep}, pauses @command{tar} for a specified
amount of seconds.  The following example will stop for 30 seconds at each
checkpoint: 

@smallexample
$ @kbd{tar -c --checkpoint=1000 --checkpoint-action=sleep=30}
@end smallexample

@cindex @code{exec}, checkpoint action
Finally, the @code{exec} action executes a given external program.
For example:

@smallexample
$ @kbd{tar -c --checkpoint=1000 --checkpoint-action=exec=/sbin/cpoint}
@end smallexample

This program is executed using @command{/bin/sh -c}, with no
additional arguments.  Its exit code is ignored.  It gets a copy of
@command{tar}'s environment plus the following variables:

@table @env
@vrindex TAR_VERSION, checkpoint script environment
@item TAR_VERSION
@GNUTAR{} version number.

@vrindex TAR_ARCHIVE, checkpoint script environment
@item TAR_ARCHIVE
The name of the archive @command{tar} is processing.

@vrindex TAR_CHECKPOINT, checkpoint script environment
@item TAR_CHECKPOINT
The checkpoint number.

@vrindex TAR_SUBCOMMAND, checkpoint script environment
@item TAR_SUBCOMMAND
A short option describing the operation @command{tar} is executing
@xref{Operations}, for a complete list of subcommand options.

@vrindex TAR_FORMAT, checkpoint script environment
@item TAR_FORMAT
Format of the archive being processed. @xref{Formats}, for a complete
list of archive format names.
@end table

Any number of actions can be defined, by supplying several
@option{--checkpoint-action} options in the command line.  For
example, the command below displays two messages, pauses
execution for 30 seconds and executes the @file{/sbin/cpoint} script:

@example
@group
$ @kbd{tar -c -f arc.tar \
       --checkpoint-action='\aecho=Hit %s checkpoint #%u' \
       --checkpoint-action='echo=Sleeping for 30 seconds' \
       --checkpoint-action='sleep=30' \
       --checkpoint-action='exec=/sbin/cpoint'}
@end group
@end example

This example also illustrates the fact that
@option{--checkpoint-action} can be used without
@option{--checkpoint}.  In this case, the default checkpoint frequency
(at each 10th record) is assumed.
       
@node interactive
@section Asking for Confirmation During Operations
@cindex Interactive operation
