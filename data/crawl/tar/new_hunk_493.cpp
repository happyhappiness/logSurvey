* Deleting Files::              Deleting Files From an Archive
@end menu

@section What @code{tar} Does

The @code{tar} program is used to create and manipulate @code{tar}
archives.  An @dfn{archive} is a single file which contains within it
the contents of many files.  In addition, the archive identifies the
names of the files, their owner, and so forth.

You can use @code{tar} archives in many ways.  Initially, @code{tar}
archives were used to store files conveniently on magnetic tape.  The
name @samp{tar} comes from this use; it stands for Tape ARchiver.
Often, @code{tar} archives are used to store related files for
convenient file transfer over a network.  For example, the GNU Project
distributes its software bundled into @code{tar} archives, so that all
the files relating to a particular program (or set of related programs)
can be transferred as a single unit.

The files inside an archive are called @dfn{members}.  Within this
manual, we use the term @dfn{file} to refer only to files accessible in
the normal ways (by @code{ls}, @code{cat}, and so forth), and the term
@dfn{members} to refer only to the members of an archive.  Similarly, a
@dfn{file name} is the name of a file, as it resides in the filesystem,
and a @dfn{member name} is the name of an archive member within the
archive.

The @code{tar} program provides the ability to create @code{tar}
archives, as well as for various other kinds of manipulation.  The term
@dfn{extraction} is used to refer to the process of copying an archive
member into a file in the filesystem.  One might speak of extracting a
single member.  Extracting all the members of an archive is often called
extracting the archive.  Often the term @dfn{unpack} is used to refer to
the extraction of many or all the members of an archive.

Conventionally, @code{tar} archives are given names ending with
@samp{.tar}.  This is not necessary for @code{tar} to operate properly,
but this manual follows the convention in order to get the reader used
to seeing it.

Occasionally archive members are referred to as files.  For people
familiar with the operation of @code{tar}, this causes no difficulty.
However, this manual consistently uses the terminology above in
referring to files and archive members, to make it easier to learn how
to use @code{tar}.

@section Creating Archives

To create a new archive, use @samp{tar --create}.  You should generally
use the @samp{--file} option to specify the name the tar archive will
have.  Then specify the names of the files you wish to place in the new
archive.  For example, to place the files @file{apple}, @file{angst},
and @file{asparagus} into an archive named @file{afiles.tar}, use the
following command:

@example
tar --create --file=afiles.tar apple angst asparagus
@end example

The order of the arguments is not important.  You could also say:

@example
tar apple --create angst --file=afiles.tar asparagus
@end example

This order is harder to understand however.  In this manual, we will
list the arguments in a reasonable order to make the commands easier to
understand, but you can type them in any order you wish.

If you don't specify the names of any files to put in the archive, then
tar will create an empty archive.  So, the following command will create
an archive with nothing in it:

@example
tar --create --file=empty-archive.tar
@end example

Whenever you use @samp{tar --create}, @code{tar} will erase the current
