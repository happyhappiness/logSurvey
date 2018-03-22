* Problems::                    Common problems with @code{tar}.
@end menu

@node Tutorial, Wizardry, Invoking @code{tar}, Top
@chapter Getting Started With @code{tar}

This chapter guides you through some basic examples of @code{tar}
operations.  If you already know how to use some other version of
@code{tar}, then you probably don't need to read this chapter.  This
chapter omits complicated details about many of the ways @code{tar}
works.  See later chapters for full information.

@menu
* Creating Archives::           Creating Archives
* Extracting Files::            Extracting Files from an Archive 
* Listing Archive Contents::    Listing the Contents of an Archive
* Comparing Files::             Comparing Archives with the File System
* Adding to Archives::          Adding Files to Existing Archives
* Concatenate::                 Concatenating Archives 
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
contents of the file named by @samp{--file} if it exists.  To add files
to an existing archive, you need to use a different option.
@xref{Adding to Archives} for information on how to do this.

The names of the members of an archive are called @dfn{member names}.
When @samp{tar --create} creates an archive, the member names of the
members of the archive are exactly the same as the file names as you
typed them in the @code{tar} command.  So, the member names of
@file{my-archive} (as created by the first example above) are
@file{foo}, @file{bar}, and @file{baz}.  However, suppose the archive
were created with this command instead:

@example
tar --create --file=my-new-archive ./foo bar ./baz
@end example

Then, the same three files would get placed in the archive (because
@file{./} is a synonym for the current directory), but their member
names would now be @file{./foo}, @file{bar}, and @file{./baz}.

If you want to see the progress of tar as it writes files into the
archive, you can use the @samp{--verbose} option.

If one of the files named to @samp{tar --create} is a directory, then
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
--file=my-empty-archive} would produce no output.)

If you use the @samp{--verbose} option with @samp{tar --list}, then tar
will print out a listing reminiscent of @samp{ls -l}, showing owner,
file size, and so forth.

You can also specify member names when using @samp{tar --list}.  In this
case, tar will only list the names of members you identify.  For
example, @samp{tar --list --file=my-archive foo} would only print
@samp{foo}.  It is essential when specifying member names to tar that
you give the exact member names.  For example, @samp{tar --list
--file=my-new-archive foo} would produce no output, because there is no
member named @file{foo}, only one named @file{./foo}.  While the file
names @file{foo} and @file{./foo} name the same file, member names are
compared using a simplistic name comparison, in which an exact match is
necessary.  

@section Extracting Files from an Archive

In order to extract files from an archive, use @samp{tar --extract}.
Specify the name of the archive with @samp{--file}.  To extract specific
archive members, give their member names as arguments.  It essential to
give their exact member name, as printed by @samp{tar --list}.  

Keeping the example of the two archives created at the beginning of this
tutorial, @samp{tar --extract --file=my-archive foo} would create a file
@file{foo} in the current directory with the contents of the archive
member @file{foo}.  It would remove any file named @file{foo} already
present in the directory, but it would not change the archive in any
way.

Remember that specifying the exact member name is important.  @samp{tar
--extract --file=my-new-archive foo} will fail, because there is no
member named @file{foo}.  To extract the member named @file{./foo} you
would need to specify @samp{tar --extract --file=my-new-archive ./foo}.
To find the exact member names of the members of an archive, use
@samp{tar --list}.  @xref{Listing Archives}.

If you do not list any archive member names, then @samp{tar --extract}
will extract all the members of the archive.

If you give the @samp{--verbose} option, then @samp{tar --extract} will
print the names of the archive members as it extracts them.

@section Adding Files to Existing Archives

If you want to add files to an existing archive, then don't use
@samp{tar --create}.  That will erase an archive and create a new one in
its place.  Instead, use @samp{tar --add-file}.  The command @samp{tar
--add-file --file=my-archive qux} would add the file @file{qux} to the
existing archive @file{my-archive}.  It is essential that the archive
exist already in order to use @samp{tar --add-file}.

As with @samp{tar --create}, the member names of the newly added files
will be the exact same as their names given on the command line.  The
@samp{--verbose} option will print out the names of the files as they
are written into the archive.

If you add a file to an archive using @samp{tar --add-file} with the
same name as an archive member already present in the archive, then the
old member is not deleted.  What does happen, however, is somewhat
complex.  @xref{Multiple Members with the Same Name}.  If you want to
replace an archive member, use @samp{tar --delete} first, and then use
@samp{tar --add-file}.

@section Deleting Files from Archives

You can delete files from an archive using @samp{tar --delete}.  Specify
the name of the archive with @samp{--file}.  List the member names of
the files to be deleted.  If you list no member names, then nothing will
be deleted.  The @samp{--verbose} option will cause @code{tar} to print
the names of the members as they are deleted.  As with @samp{tar
--extract}, it is important that you give the exact member names when
using @samp{tar --delete}.  Use @samp{tar --list} to find out the exact
member names in an archive (@pxref{Listing Archives}).

The @samp{tar --delete} command only works with archives stored on disk.
Archives stored on a tape drive cannot be deleted from.

@section Directories 

When the names of files or member names specify directories, the
operation of @code{tar} is more complex.  Generally, when a directory is
named, @code{tar} also operates on all the contents of the directory,
recursively.  Thus, to @code{tar}, the file name @file{/} names the
entire file system.  

To archive the entire contents of a directory, use @samp{tar --create}
(or @samp{tar --add-file}) as usual, and specify the name of the
directory.  For example, to archive all the contents of the current
directory, use @samp{tar --create --file=@var{archive-name} .}.  Doing
this will give the archive members names starting with @samp{./}.  To
archive the contents of a directory named @file{foodir}, use @samp{tar
--create --file=@var{archive-name} foodir}.  In this case, the member
names will all start with @samp{foodir/}.

If you give @code{tar} a command such as @samp{tar --create --file=foo
.}, it will report @samp{tar: foo is the archive; not dumped}.  This
happens because the archive @file{foo} is created before putting any
files into it.  Then, when @code{tar} attempts to add all the files in
the directory @file{.} to the archive, it notices that the file
@file{foo} is the same as the archive, and skips it.  (It makes no sense
to put an archive into itself.)  GNU @code{tar} will continue in this
case, and create the archive as normal, except for the exclusion of that
one file.  Other versions of @code{tar}, however, are not so clever, and
will enter an infinite loop when this happens, so you should not depend
on this behavior.  In general, make sure that the archive is not inside
a directory being dumped.

When extracting files, you can also name directory archive members on
the command line.  In this case, @code{tar} extracts all the archive
members whose names begin with the name of the directory.  As usual,
@code{tar} is not particularly clever about interpreting member names.
The command @samp{tar --extract --file=@var{archive-name} .} will not
extract all the contents of the archive, but only those members whose
member names begin with @samp{./}.


@node Invoking @code{tar}, Tutorial, Introduction, Top
@chapter How To Invoke @code{tar}

