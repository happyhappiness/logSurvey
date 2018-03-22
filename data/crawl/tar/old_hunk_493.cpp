* Deleting Files::              Deleting Files From an Archive
@end menu

@node Creating Archives, Listing Archive Contents, Tutorial, Tutorial
@section Creating Archives

To create a new archive, use @samp{tar --create}.  You should generally
use the @samp{--file} option to specify the name the tar archive will
have.  Then specify the names of the files you wish to place in the
archive.  For example, to place the files @file{foo}, @file{bar}, and
@file{baz} into an archive named @file{my-archive}, use the following
command:

@example
tar --create --file=my-archive foo bar baz
@end example

The order of the arguments is not important.  You could also say:

@example
tar foo --create --file=my-archive bar baz
@end example

This order is harder to understand however.  In this manual, we will
list the arguments in a reasonable order to make the commands easier to
understand, but you can type them in any order you wish.

If you don't specify the @samp{--file} option, then @code{tar} will use
a default.  Usually this default is some physical tape drive attached to
your machine.  If there is no tape drive attached, or the default is not
meaningful, then tar will print an error message.  This error message
might look roughly like one of the following:

@example
tar: can't open /dev/rmt8 : No such device or address
tar: can't open /dev/rsmt0 : I/O error
@end example

If you get an error like this, mentioning a file you didn't specify
(@file{/dev/rmt8} or @file{/dev/rsmt0} in the examples above), then @code{tar}
is using a default value for @samp{--file}.  You should generally specify a
@samp{--file} argument whenever you use @code{tar}, rather than relying
on a default.

If you don't specify the names of any files to put in the archive, then
tar will create an empty archive.  So, the following command will create
an archive with nothing in it:

@example
tar --create --file=my-empty-archive
@end example

Whenever you use @samp{tar --create}, @code{tar} will erase the current
