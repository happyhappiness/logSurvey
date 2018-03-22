the operation of tar is more complicated.  @xref{Tar and Directories},
the last section of this tutorial, for more information.

@section Listing Archives

Use @samp{tar --list} to print the names of members stored in an
archive.  Use a @samp{--file} option just as with @samp{tar --create} to
specify the name of the archive.  For example, the archive
@file{my-archive} created in the last section could be examined with the
command @samp{tar --list --file=my-archive}.  The output of tar would
then be:

@example
foo
bar
baz
@end example

The archive @file{my-new-archive} would list as follows:

@example
./foo
bar
./baz
@end example

Note that, despite the identical contents of the two archives' members,
the member names are different.  (Of course, @samp{tar --list

If you use the @samp{--verbose} option with @samp{tar --list}, then tar
will print out a listing reminiscent of @samp{ls -l}, showing owner,
