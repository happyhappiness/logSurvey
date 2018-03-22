switch to @samp{posix}.

@menu
* Compression::                 Using Less Space through Compression
* Attributes::                  Handling File Attributes
* Portability::                 Making @command{tar} Archives More Portable
* cpio::                        Comparison of @command{tar} and @command{cpio}
@end menu

@node Compression
@section Using Less Space through Compression

@menu
* gzip::                        Creating and Reading Compressed Archives
* sparse::                      Archiving Sparse Files
@end menu

@node gzip
@subsection Creating and Reading Compressed Archives
@cindex Compressed archives
@cindex Storing archives in compressed format

@GNUTAR{} is able to create and read compressed archives.  It supports
@command{gzip} and @command{bzip2} compression programs.  For backward
compatibilty, it also supports @command{compress} command, although
we strongly recommend against using it, since there is a patent
covering the algorithm it uses and you could be sued for patent
infringement merely by running @command{compress}!  Besides, it is less
effective than @command{gzip} and @command{bzip2}.

Creating a compressed archive is simple: you just specify a
@dfn{compression option} along with the usual archive creation
commands.  The compression option is @option{-z} (@option{--gzip}) to
create a @command{gzip} compressed archive, @option{-j}
(@option{--bzip2}) to create a @command{bzip2} compressed archive, and
@option{-Z} (@option{--compress}) to use @command{compress} program.
For example:

@smallexample
$ @kbd{tar cfz archive.tar.gz .}
@end smallexample

Reading compressed archive is even simpler: you don't need to specify
any additional options as @GNUTAR{} recognizes its format
automatically.  Thus, the following commands will list and extract the
archive created in previous example:

@smallexample
# List the compressed archive
$ @kbd{tar tf archive.tar.gz}
# Extract the compressed archive
$ @kbd{tar xf archive.tar.gz}
@end smallexample

The only case when you have to specify a decompression option while
reading the archive is when reading from a pipe or from a tape drive
that does not support random access.  However, in this case @GNUTAR{}
will indicate which option you should use.  For example:

@smallexample
$ @kbd{cat archive.tar.gz | tar tf -}
tar: Archive is compressed.  Use -z option
tar: Error is not recoverable: exiting now
@end smallexample

If you see such diagnostics, just add the suggested option to the
invocation of @GNUTAR{}:

@smallexample
$ @kbd{cat archive.tar.gz | tar tfz -}
@end smallexample

Notice also, that there are several restrictions on operations on
compressed archives.  First of all, compressed archives cannot be
modified, i.e., you cannot update (@option{--update} (@option{-u})) them or delete
(@option{--delete}) members from them.  Likewise, you cannot append
another @command{tar} archive to a compressed archive using
@option{--append} (@option{-r})).  Secondly, multi-volume archives cannot be
compressed.

The following table summarizes compression options used by @GNUTAR{}.

@table @option
@opindex gzip
@opindex ungzip
@item -z
@itemx --gzip
@itemx --ungzip
Filter the archive through @command{gzip}.

You can use @option{--gzip} and @option{--gunzip} on physical devices
(tape drives, etc.) and remote files as well as on normal files; data
to or from such devices or remote files is reblocked by another copy
of the @command{tar} program to enforce the specified (or default) record
size.  The default compression parameters are used; if you need to
override them, set @env{GZIP} environment variable, e.g.:

@smallexample
$ @kbd{GZIP=--best tar cfz archive.tar.gz subdir}
@end smallexample

@noindent
Another way would be to avoid the @option{--gzip} (@option{--gunzip}, @option{--ungzip}, @option{-z}) option and run
@command{gzip} explicitly:

@smallexample
$ @kbd{tar cf - subdir | gzip --best -c - > archive.tar.gz}
@end smallexample

@cindex corrupted archives
About corrupted compressed archives: @command{gzip}'ed files have no
redundancy, for maximum compression.  The adaptive nature of the
compression scheme means that the compression tables are implicitly
spread all over the archive.  If you lose a few blocks, the dynamic
construction of the compression tables becomes unsynchronized, and there
is little chance that you could recover later in the archive.

There are pending suggestions for having a per-volume or per-file
compression in @GNUTAR{}.  This would allow for viewing the
contents without decompression, and for resynchronizing decompression at
every volume or file, in case of corrupted archives.  Doing so, we might
lose some compressibility.  But this would have make recovering easier.
So, there are pros and cons.  We'll see!

@opindex bzip2
@item -j
@itemx --bzip2
Filter the archive through @code{bzip2}.  Otherwise like @option{--gzip}.

@opindex compress
@opindex uncompress
@item -Z
@itemx --compress
@itemx --uncompress
Filter the archive through @command{compress}.  Otherwise like @option{--gzip}.

The @acronym{GNU} Project recommends you not use
@command{compress}, because there is a patent covering the algorithm it
uses.  You could be sued for patent infringement merely by running
@command{compress}.

@opindex use-compress-program
@item --use-compress-program=@var{prog}
Use external compression program @var{prog}.  Use this option if you
have a compression program that @GNUTAR{} does not support.  There
are two requirements to which @var{prog} should comply:

First, when called without options, it should read data from standard
input, compress it and output it on standard output.

Secondly, if called with @option{-d} argument, it should do exactly
the opposite, i.e., read the compressed data from the standard input
and produce uncompressed data on the standard output.
@end table

@cindex gpg, using with tar
@cindex gnupg, using with tar
@cindex Using encrypted archives
The @option{--use-compress-program} option, in particular, lets you
implement your own filters, not necessarily dealing with
compression/decomression.  For example, suppose you wish to implement
PGP encryption on top of compression, using @command{gpg} (@pxref{Top,
gpg, gpg ---- encryption and signing tool, gpg, GNU Privacy Guard
Manual}).  The following script does that:  

@smallexample
@group
#! /bin/sh
case $1 in
-d) gpg --decrypt - | gzip -d -c;;
'') gzip -c | gpg -s ;;
*)  echo "Unknown option $1">&2; exit 1;;
esac
@end group
@end smallexample

Suppose you name it @file{gpgz} and save it somewhere in your
@env{PATH}.  Then the following command will create a commpressed
archive signed with your private key:

@smallexample
$ @kbd{tar -cf foo.tar.gpgz --use-compress=gpgz .}
@end smallexample

@noindent
Likewise, the following command will list its contents:

@smallexample
$ @kbd{tar -tf foo.tar.gpgz --use-compress=gpgz .}
@end smallexample

@ignore
The above is based on the following discussion:

     I have one question, or maybe it's a suggestion if there isn't a way
     to do it now.  I would like to use @option{--gzip}, but I'd also like
     the output to be fed through a program like @acronym{GNU}
     @command{ecc} (actually, right now that's @samp{exactly} what I'd like
     to use :-)), basically adding ECC protection on top of compression.
     It seems as if this should be quite easy to do, but I can't work out
     exactly how to go about it.  Of course, I can pipe the standard output
     of @command{tar} through @command{ecc}, but then I lose (though I
     haven't started using it yet, I confess) the ability to have
     @command{tar} use @command{rmt} for it's I/O (I think).

     I think the most straightforward thing would be to let me specify a
     general set of filters outboard of compression (preferably ordered,
     so the order can be automatically reversed on input operations, and
     with the options they require specifiable), but beggars shouldn't be
     choosers and anything you decide on would be fine with me.

     By the way, I like @command{ecc} but if (as the comments say) it can't
     deal with loss of block sync, I'm tempted to throw some time at adding
     that capability.  Supposing I were to actually do such a thing and
     get it (apparently) working, do you accept contributed changes to
     utilities like that?  (Leigh Clayton @file{loc@@soliton.com}, May 1995).
 
  Isn't that exactly the role of the
  @option{--use-compress-prog=@var{program}} option? 
  I never tried it myself, but I suspect you may want to write a
  @var{prog} script or program able to filter stdin to stdout to
  way you want.  It should recognize the @option{-d} option, for when
  extraction is needed rather than creation.

  It has been reported that if one writes compressed data (through the
  @option{--gzip} or @option{--compress} options) to a DLT and tries to use
  the DLT compression mode, the data will actually get bigger and one will
  end up with less space on the tape.
@end ignore

@node sparse
@subsection Archiving Sparse Files
@cindex Sparse Files

Files in the file system occasionally have @dfn{holes}.  A @dfn{hole}
in a file is a section of the file's contents which was never written.
The contents of a hole reads as all zeros.  On many operating systems,
actual disk storage is not allocated for holes, but they are counted
in the length of the file.  If you archive such a file, @command{tar}
could create an archive longer than the original.  To have @command{tar}
attempt to recognize the holes in a file, use @option{--sparse}
(@option{-S}).  When you use this option, then, for any file using
less disk space than would be expected from its length, @command{tar}
searches the file for consecutive stretches of zeros.  It then records
in the archive for the file where the consecutive stretches of zeros
are, and only archives the ``real contents'' of the file.  On
extraction (using @option{--sparse} is not needed on extraction) any
such files have holes created wherever the continuous stretches of zeros
were found.  Thus, if you use @option{--sparse}, @command{tar} archives
won't take more space than the original.

@table @option
@opindex sparse
@item -S
@itemx --sparse
This option istructs @command{tar} to test each file for sparseness
before attempting to archive it.  If the file is found to be sparse it
is treated specially, thus allowing to decrease the amount of space
used by its image in the archive.

This option is meaningful only when creating or updating archives.  It
has no effect on extraction.
@end table

Consider using @option{--sparse} when performing file system backups,
to avoid archiving the expanded forms of files stored sparsely in the
system. 

Even if your system has no sparse files currently, some may be
created in the future.  If you use @option{--sparse} while making file
system backups as a matter of course, you can be assured the archive
will never take more space on the media than the files take on disk
(otherwise, archiving a disk filled with sparse files might take
hundreds of tapes).  @xref{Incremental Dumps}.

However, be aware that @option{--sparse} option presents a serious
drawback.  Namely, in order to determine if the file is sparse
@command{tar} has to read it before trying to archive it, so in total
the file is read @strong{twice}.  So, always bear in mind that the
time needed to process all files with this option is roughly twice
the time needed to archive them without it.
@FIXME{A technical note:

Programs like @command{dump} do not have to read the entire file; by
examining the file system directly, they can determine in advance
exactly where the holes are and thus avoid reading through them.  The
only data it need read are the actual allocated data blocks.
@GNUTAR{} uses a more portable and straightforward
archiving approach, it would be fairly difficult that it does
otherwise.  Elizabeth Zwicky writes to @file{comp.unix.internals}, on
1990-12-10:

@quotation
What I did say is that you cannot tell the difference between a hole and an
equivalent number of nulls without reading raw blocks.  @code{st_blocks} at
best tells you how many holes there are; it doesn't tell you @emph{where}.
Just as programs may, conceivably, care what @code{st_blocks} is (care
to name one that does?), they may also care where the holes are (I have
no examples of this one either, but it's equally imaginable).

I conclude from this that good archivers are not portable.  One can
arguably conclude that if you want a portable program, you can in good
conscience restore files with as many holes as possible, since you can't
get it right.
@end quotation
}

@cindex sparse formats, defined
When using @samp{POSIX} archive format, @GNUTAR{} is able to store
sparse files using in three distinct ways, called @dfn{sparse
formats}.  A sparse format is identified by its @dfn{number},
consisting, as usual of two decimal numbers, delimited by a dot.  By
default, format @samp{1.0} is used.  If, for some reason, you wish to
use an earlier format, you can select it using
@option{--sparse-version} option. 

@table @option
@opindex sparse-version
@item --sparse-version=@var{version}

Select the format to store sparse files in.  Valid @var{version} values
are: @samp{0.0}, @samp{0.1} and @samp{1.0}.  @xref{Sparse Formats},
for a detailed description of each format.
@end table

Using @option{--sparse-format} option implies @option{--sparse}.

@node Attributes
@section Handling File Attributes
@UNREVISED

When @command{tar} reads files, it updates their access times.  To
avoid this, use the @option{--atime-preserve[=METHOD]} option, which can either
reset the access time retroactively or avoid changing it in the first
place.

Handling of file attributes

@table @option
@opindex atime-preserve
@item --atime-preserve
@itemx --atime-preserve=replace
@itemx --atime-preserve=system
Preserve the access times of files that are read.  This works only for
files that you own, unless you have superuser privileges.

@option{--atime-preserve=replace} works on most systems, but it also
restores the data modification time and updates the status change
time.  Hence it doesn't interact with incremental dumps nicely
(@pxref{Incremental Dumps}), and it can set access or data modification times
incorrectly if other programs access the file while @command{tar} is
running.

@option{--atime-preserve=system} avoids changing the access time in
the first place, if the operating system supports this.
Unfortunately, this may or may not work on any given operating system
or file system.  If @command{tar} knows for sure it won't work, it
complains right away.

Currently @option{--atime-preserve} with no operand defaults to
@option{--atime-preserve=replace}, but this is intended to change to
@option{--atime-preserve=system} when the latter is better-supported.

@opindex touch
@item -m
@itemx --touch
Do not extract data modification time.

When this option is used, @command{tar} leaves the data modification times
of the files it extracts as the times when the files were extracted,
instead of setting it to the times recorded in the archive.

This option is meaningless with @option{--list} (@option{-t}).

@opindex same-owner
@item --same-owner
Create extracted files with the same ownership they have in the
archive.

This is the default behavior for the superuser,
so this option is meaningful only for non-root users, when @command{tar}
is executed on those systems able to give files away.  This is
considered as a security flaw by many people, at least because it
makes quite difficult to correctly account users for the disk space
they occupy.  Also, the @code{suid} or @code{sgid} attributes of
files are easily and silently lost when files are given away.

When writing an archive, @command{tar} writes the user id and user name
separately.  If it can't find a user name (because the user id is not
in @file{/etc/passwd}), then it does not write one.  When restoring,
it tries to look the name (if one was written) up in
@file{/etc/passwd}.  If it fails, then it uses the user id stored in
the archive instead. 

@opindex no-same-owner
@item --no-same-owner
@itemx -o
Do not attempt to restore ownership when extracting.  This is the
default behavior for ordinary users, so this option has an effect
only for the superuser.

@opindex numeric-owner
@item --numeric-owner
The @option{--numeric-owner} option allows (ANSI) archives to be written
without user/group name information or such information to be ignored
when extracting.  It effectively disables the generation and/or use
of user/group name information.  This option forces extraction using
the numeric ids from the archive, ignoring the names.

This is useful in certain circumstances, when restoring a backup from
an emergency floppy with different passwd/group files for example.
It is otherwise impossible to extract files with the right ownerships
if the password file in use during the extraction does not match the
one belonging to the file system(s) being extracted.  This occurs,
for example, if you are restoring your files after a major crash and
had booted from an emergency floppy with no password file or put your
disk into another machine to do the restore.

The numeric ids are @emph{always} saved into @command{tar} archives.
The identifying names are added at create time when provided by the
system, unless @option{--old-archive} (@option{-o}) is used.  Numeric ids could be
used when moving archives between a collection of machines using
a centralized management for attribution of numeric ids to users
and groups.  This is often made through using the NIS capabilities.

When making a @command{tar} file for distribution to other sites, it
is sometimes cleaner to use a single owner for all files in the
distribution, and nicer to specify the write permission bits of the
files as stored in the archive independently of their actual value on
the file system.  The way to prepare a clean distribution is usually
to have some Makefile rule creating a directory, copying all needed
files in that directory, then setting ownership and permissions as
wanted (there are a lot of possible schemes), and only then making a
@command{tar} archive out of this directory, before cleaning
everything out.  Of course, we could add a lot of options to
@GNUTAR{} for fine tuning permissions and ownership.
This is not the good way, I think.  @GNUTAR{} is
already crowded with options and moreover, the approach just explained
gives you a great deal of control already.

@xopindex{same-permissions, short description}
@xopindex{preserve-permissions, short description}
@item -p
@itemx --same-permissions
@itemx --preserve-permissions
Extract all protection information.

This option causes @command{tar} to set the modes (access permissions) of
extracted files exactly as recorded in the archive.  If this option
is not used, the current @code{umask} setting limits the permissions
on extracted files.  This option is by default enabled when
@command{tar} is executed by a superuser.


This option is meaningless with @option{--list} (@option{-t}).

@opindex preserve
@item --preserve
Same as both @option{--same-permissions} and @option{--same-order}.

The @option{--preserve} option has no equivalent short option name.
It is equivalent to @option{--same-permissions} plus @option{--same-order}.

@FIXME{I do not see the purpose of such an option.  (Neither I.  FP.)
Neither do I. --Sergey}

@end table

@node Portability
@section Making @command{tar} Archives More Portable

Creating a @command{tar} archive on a particular system that is meant to be
useful later on many other machines and with other versions of @command{tar}
is more challenging than you might think.  @command{tar} archive formats
have been evolving since the first versions of Unix.  Many such formats
are around, and are not always compatible with each other.  This section
discusses a few problems, and gives some advice about making @command{tar}
archives more portable.

One golden rule is simplicity.  For example, limit your @command{tar}
archives to contain only regular files and directories, avoiding
other kind of special files.  Do not attempt to save sparse files or
contiguous files as such.  Let's discuss a few more problems, in turn.

@FIXME{Discuss GNU extensions (incremental backups, multi-volume
archives and archive labels) in GNU and PAX formats.}

@menu
* Portable Names::              Portable Names
* dereference::                 Symbolic Links
* old::                         Old V7 Archives
* ustar::                       Ustar Archives
* gnu::                         GNU and old GNU format archives.
* posix::                       @acronym{POSIX} archives
* Checksumming::                Checksumming Problems
* Large or Negative Values::    Large files, negative time stamps, etc.
* Other Tars::                  How to Extract GNU-Specific Data Using
                                Other @command{tar} Implementations
@end menu

@node Portable Names
@subsection Portable Names

Use portable file and member names.  A name is portable if it contains
only ASCII letters and digits, @samp{/}, @samp{.}, @samp{_}, and
@samp{-}; it cannot be empty, start with @samp{-} or @samp{//}, or
contain @samp{/-}.  Avoid deep directory nesting.  For portability to
old Unix hosts, limit your file name components to 14 characters or
less.

If you intend to have your @command{tar} archives to be read under
MSDOS, you should not rely on case distinction for file names, and you
might use the @acronym{GNU} @command{doschk} program for helping you
further diagnosing illegal MSDOS names, which are even more limited
than System V's.

@node dereference
@subsection Symbolic Links
@cindex File names, using symbolic links
@cindex Symbolic link as file name

@opindex dereference
Normally, when @command{tar} archives a symbolic link, it writes a
block to the archive naming the target of the link.  In that way, the
@command{tar} archive is a faithful record of the file system contents.
@option{--dereference} (@option{-h}) is used with @option{--create} (@option{-c}), and causes
@command{tar} to archive the files symbolic links point to, instead of
the links themselves.  When this option is used, when @command{tar}
encounters a symbolic link, it will archive the linked-to file,
instead of simply recording the presence of a symbolic link.

The name under which the file is stored in the file system is not
recorded in the archive.  To record both the symbolic link name and
the file name in the system, archive the file under both names.  If
all links were recorded automatically by @command{tar}, an extracted file
might be linked to a file name that no longer exists in the file
system.

If a linked-to file is encountered again by @command{tar} while creating
the same archive, an entire second copy of it will be stored.  (This
@emph{might} be considered a bug.)

So, for portable archives, do not archive symbolic links as such,
and use @option{--dereference} (@option{-h}): many systems do not support
symbolic links, and moreover, your distribution might be unusable if
it contains unresolved symbolic links.

@node old
@subsection Old V7 Archives
@cindex Format, old style
@cindex Old style format
@cindex Old style archives
@cindex v7 archive format

Certain old versions of @command{tar} cannot handle additional
information recorded by newer @command{tar} programs.  To create an
archive in V7 format (not ANSI), which can be read by these old
versions, specify the @option{--format=v7} option in
conjunction with the @option{--create} (@option{-c}) (@command{tar} also
accepts @option{--portability} or @option{--old-archive} for this
option).  When you specify it,
@command{tar} leaves out information about directories, pipes, fifos,
contiguous files, and device files, and specifies file ownership by
group and user IDs instead of group and user names.

When updating an archive, do not use @option{--format=v7}
unless the archive was created using this option.

In most cases, a @emph{new} format archive can be read by an @emph{old}
@command{tar} program without serious trouble, so this option should
seldom be needed.  On the other hand, most modern @command{tar}s are
able to read old format archives, so it might be safer for you to
always use @option{--format=v7} for your distributions.  Notice,
however, that @samp{ustar} format is a better alternative, as it is
free from many of @samp{v7}'s drawbacks.

@node ustar
@subsection Ustar Archive Format

@cindex ustar archive format
Archive format defined by @acronym{POSIX}.1-1988 specification is called
@code{ustar}.  Although it is more flexible than the V7 format, it
still has many restrictions (@xref{Formats,ustar}, for the detailed
description of @code{ustar} format).  Along with V7 format,
@code{ustar} format is a good choice for archives intended to be read
with other implementations of @command{tar}.

To create archive in @code{ustar} format, use @option{--format=ustar}
option in conjunction with the @option{--create} (@option{-c}).

@node gnu
@subsection @acronym{GNU} and old @GNUTAR{} format

@cindex GNU archive format
@cindex Old GNU archive format
@GNUTAR{} was based on an early draft of the
@acronym{POSIX} 1003.1 @code{ustar} standard.  @acronym{GNU} extensions to
@command{tar}, such as the support for file names longer than 100
characters, use portions of the @command{tar} header record which were
specified in that @acronym{POSIX} draft as unused.  Subsequent changes in
@acronym{POSIX} have allocated the same parts of the header record for
other purposes.  As a result, @GNUTAR{} format is
incompatible with the current @acronym{POSIX} specification, and with
@command{tar} programs that follow it.

In the majority of cases, @command{tar} will be configured to create
this format by default.  This will change in the future releases, since
we plan to make @samp{POSIX} format the default.

To force creation a @GNUTAR{} archive, use option
@option{--format=gnu}.

@node posix
@subsection @GNUTAR{} and @acronym{POSIX} @command{tar}

@cindex POSIX archive format
@cindex PAX archive format
Starting from version 1.14 @GNUTAR{} features full support for
@acronym{POSIX.1-2001} archives.

A @acronym{POSIX} conformant archive will be created if @command{tar}
was given @option{--format=posix} (@option{--format=pax}) option.  No
special option is required to read and extract from a @acronym{POSIX}
archive. 

@menu
* PAX keywords:: Controlling Extended Header Keywords.
@end menu

@node PAX keywords
@subsubsection Controlling Extended Header Keywords

@table @option
@opindex pax-option
@item --pax-option=@var{keyword-list}
Handle keywords in @acronym{PAX} extended headers.  This option is
equivalent to @option{-o} option of the @command{pax} utility.
@end table

@var{Keyword-list} is a comma-separated
list of keyword options, each keyword option taking one of
the following forms:

@table @code
@item delete=@var{pattern}
When used with one of archive-creation commands,
this option instructs @command{tar} to omit from extended header records
that it produces any keywords matching the string @var{pattern}.

When used in extract or list mode, this option instructs tar
to ignore any keywords matching the given @var{pattern} in the extended
header records.  In both cases, matching is performed using the pattern
matching notation described in @acronym{POSIX 1003.2}, 3.13
(@pxref{wildcards}). For example:

@smallexample
--pax-option delete=security.*
@end smallexample

would suppress security-related information.

@item exthdr.name=@var{string}

This keyword allows user control over the name that is written into the
ustar header blocks for the extended headers.  The name is obtained
from @var{string} after making the following substitutions:

@multitable @columnfractions .25 .55
@headitem Meta-character @tab Replaced By
@item %d @tab  The directory name of the file, equivalent to the
result of the @command{dirname} utility on the translated pathname.
@item %f @tab  The filename of the file, equivalent to the result
of the @command{basename} utility on the translated pathname.
@item %p @tab  The process ID of the @command{tar} process.
@item %% @tab  A @samp{%} character.
@end multitable

Any other @samp{%} characters in @var{string} produce undefined
results.

If no option @samp{exthdr.name=string} is specified, @command{tar}
will use the following default value:

@smallexample
%d/PaxHeaders.%p/%f
@end smallexample

@item globexthdr.name=@var{string}
This keyword allows user control over the name that is written into
the ustar header blocks for global extended header records.  The name
is obtained from the contents of @var{string}, after making
the following substitutions:

@multitable @columnfractions .25 .55
@headitem Meta-character @tab Replaced By
@item %n @tab An integer that represents the
sequence number of the global extended header record in the archive,
starting at 1.
@item %p @tab The process ID of the @command{tar} process.
@item %% @tab A @samp{%} character.
@end multitable

Any other @samp{%} characters in @var{string} produce undefined results.

If no option @samp{globexthdr.name=string} is specified, @command{tar}
will use the following default value:

@smallexample
$TMPDIR/GlobalHead.%p.%n
@end smallexample

@noindent
where @samp{$TMPDIR} represents the value of the @var{TMPDIR}
environment variable.  If @var{TMPDIR} is not set, @command{tar}
uses @samp{/tmp}.

@item @var{keyword}=@var{value}
When used with one of archive-creation commands, these keyword/value pairs
will be included at the beginning of the archive in a global extended
header record.  When used with one of archive-reading commands,
@command{tar} will behave as if it has encountered these keyword/value
pairs at the beginning of the archive in a global extended header
record.

@item @var{keyword}:=@var{value}
When used with one of archive-creation commands, these keyword/value pairs
will be included as records at the beginning of an extended header for
each file.  This is effectively equivalent to @var{keyword}=@var{value}
form except that it creates no global extended header records.

When used with one of archive-reading commands, @command{tar} will
behave as if these keyword/value pairs were included as records at the
end of each extended header; thus, they will override any global or
file-specific extended header record keywords of the same names.
For example, in the command:

@smallexample
tar --format=posix --create \
    --file archive --pax-option gname:=user .
@end smallexample

the group name will be forced to a new value for all files
stored in the archive.
@end table

@node Checksumming
@subsection Checksumming Problems

SunOS and HP-UX @command{tar} fail to accept archives created using
@GNUTAR{} and containing non-ASCII file names, that
is, file names having characters with the eight bit set, because they
use signed checksums, while @GNUTAR{} uses unsigned
checksums while creating archives, as per @acronym{POSIX} standards.  On
reading, @GNUTAR{} computes both checksums and
accept any.  It is somewhat worrying that a lot of people may go
around doing backup of their files using faulty (or at least
non-standard) software, not learning about it until it's time to
restore their missing files with an incompatible file extractor, or
vice versa.

@GNUTAR{} compute checksums both ways, and accept
any on read, so @acronym{GNU} tar can read Sun tapes even with their
wrong checksums.  @GNUTAR{} produces the standard
checksum, however, raising incompatibilities with Sun.  That is to
say, @GNUTAR{} has not been modified to
@emph{produce} incorrect archives to be read by buggy @command{tar}'s.
I've been told that more recent Sun @command{tar} now read standard
archives, so maybe Sun did a similar patch, after all?

The story seems to be that when Sun first imported @command{tar}
sources on their system, they recompiled it without realizing that
the checksums were computed differently, because of a change in
the default signing of @code{char}'s in their compiler.  So they
started computing checksums wrongly.  When they later realized their
mistake, they merely decided to stay compatible with it, and with
themselves afterwards.  Presumably, but I do not really know, HP-UX
has chosen that their @command{tar} archives to be compatible with Sun's.
The current standards do not favor Sun @command{tar} format.  In any
case, it now falls on the shoulders of SunOS and HP-UX users to get
a @command{tar} able to read the good archives they receive.

@node Large or Negative Values
@subsection Large or Negative Values
@cindex large values
@cindex future time stamps
@cindex negative time stamps
@UNREVISED{}

The above sections suggest to use @samp{oldest possible} archive
format if in doubt.  However, sometimes it is not possible.  If you
attempt to archive a file whose metadata cannot be represented using
required format, @GNUTAR{} will print error message and ignore such a
file.  You will than have to switch to a format that is able to
handle such values.  The format summary table (@pxref{Formats}) will
help you to do so.

In particular, when trying to archive files larger than 8GB or with
timestamps not in the range 1970-01-01 00:00:00 through 2242-03-16
12:56:31 @sc{utc}, you will have to chose between @acronym{GNU} and
@acronym{POSIX} archive formats.  When considering which format to
choose, bear in mind that the @acronym{GNU} format uses
two's-complement base-256 notation to store values that do not fit
into standard @acronym{ustar} range.  Such archives can generally be
read only by a @GNUTAR{} implementation.  Moreover, they sometimes
cannot be correctly restored on another hosts even by @GNUTAR{}. For
example, using two's complement representation for negative time
stamps that assumes a signed 32-bit @code{time_t} generates archives
that are not portable to hosts with differing @code{time_t}
representations.

On the other hand, @acronym{POSIX} archives, generally speaking, can
be extracted by any tar implementation that understands older
@acronym{ustar} format.  The only exception are files larger than 8GB.

@FIXME{Describe how @acronym{POSIX} archives are extracted by non
POSIX-aware tars.}

@node Other Tars
@subsection How to Extract GNU-Specific Data Using Other @command{tar} Implementations

In previous sections you became acquainted with various quircks
necessary to make your archives portable.  Sometimes you may need to
extract archives containing GNU-specific members using some
third-party @command{tar} implementation or an older version of
@GNUTAR{}.  Of course your best bet is to have @GNUTAR{} installed,
but if it is for some reason impossible, this section will explain
how to cope without it. 

When we speak about @dfn{GNU-specific} members we mean two classes of
them: members split between the volumes of a multi-volume archive and
sparse members.  You will be able to always recover such members if
the archive is in PAX format.  In addition split members can be
recovered from archives in old GNU format.  The following subsections
describe the required procedures in detail.

@menu
* Split Recovery::       Members Split Between Volumes
* Sparse Recovery::      Sparse Members
@end menu

@node Split Recovery
@subsubsection Extracting Members Split Between Volumes

If a member is split between several volumes of an old GNU format archive
most third party @command{tar} implementation will fail to extract
it.  To extract it, use @command{tarcat} program (@pxref{Tarcat}).
This program is available from
@uref{http://www.gnu.org/@/software/@/tar/@/utils/@/tarcat, @GNUTAR{}
home page}.  It concatenates several archive volumes into a single
valid archive.  For example, if you have three volumes named from
@file{vol-1.tar} to @file{vol-2.tar}, you can do the following to
extract them using a third-party @command{tar}:

@smallexample
$ @kbd{tarcat vol-1.tar vol-2.tar vol-3.tar | tar xf -}
@end smallexample

You could use this approach for many (although not all) PAX
format archives as well.  However, extracting split members from a PAX
archive is a much easier task, because PAX volumes are constructed in
such a way that each part of a split member is extracted as a
different file by @command{tar} implementations that are not aware of
GNU extensions.  More specifically, the very first part retains its
original name, and all subsequent parts are named using the pattern:

@smallexample
%d/GNUFileParts.%p/%f.%n
@end smallexample

@noindent
where symbols preceeded by @samp{%} are @dfn{macro characters} that
have the following meaning:

@multitable @columnfractions .25 .55
@headitem Meta-character @tab Replaced By
@item %d @tab  The directory name of the file, equivalent to the
result of the @command{dirname} utility on its full name.
@item %f @tab  The file name of the file, equivalent to the result
of the @command{basename} utility on its full name.
@item %p @tab  The process ID of the @command{tar} process that
created the archive.
@item %n @tab  Ordinal number of this particular part.
@end multitable

For example, if, a file @file{var/longfile} was split during archive
creation between three volumes, and the creator @command{tar} process
had process ID @samp{27962}, then the member names will be:

@smallexample
var/longfile
var/GNUFileParts.27962/longfile.1
var/GNUFileParts.27962/longfile.2
@end smallexample

When you extract your archive using a third-party @command{tar}, these
files will be created on your disk, and the only thing you will need
to do to restore your file in its original form is concatenate them in
the proper order, for example:

@smallexample
@group
$ @kbd{cd var}
$ @kbd{cat GNUFileParts.27962/longfile.1 \
  GNUFileParts.27962/longfile.2 >> longfile}
$ rm -f GNUFileParts.27962
@end group
@end smallexample

Notice, that if the @command{tar} implementation you use supports PAX
format archives, it will probably emit warnings about unknown keywords
during extraction.  They will lool like this:

@smallexample
@group
Tar file too small
Unknown extended header keyword 'GNU.volume.filename' ignored.
Unknown extended header keyword 'GNU.volume.size' ignored.
Unknown extended header keyword 'GNU.volume.offset' ignored.
@end group
@end smallexample

@noindent
You can safely ignore these warnings.

If your @command{tar} implementation is not PAX-aware, you will get
more warnigns and more files generated on your disk, e.g.:

@smallexample
@group
$ @kbd{tar xf vol-1.tar}
var/PaxHeaders.27962/longfile: Unknown file type 'x', extracted as
normal file 
Unexpected EOF in archive
$ @kbd{tar xf vol-2.tar}
tmp/GlobalHead.27962.1: Unknown file type 'g', extracted as normal file
GNUFileParts.27962/PaxHeaders.27962/sparsefile.1: Unknown file type
'x', extracted as normal file
@end group
@end smallexample

Ignore these warnings.  The @file{PaxHeaders.*} directories created
will contain files with @dfn{extended header keywords} describing the
extracted files.  You can delete them, unless they describe sparse
members.  Read further to learn more about them.

@node Sparse Recovery
@subsubsection Extracting Sparse Members

Any @command{tar} implementation will be able to extract sparse members from a
PAX archive.  However, the extracted files will be @dfn{condensed},
i.e. any zero blocks will be removed from them.  When we restore such
a condensed file to its original form, by adding zero bloks (or
@dfn{holes}) back to their original locations, we call this process
@dfn{expanding} a compressed sparse file.

To expand a file, you will need a simple auxiliary program called
@command{xsparse}.  It is available in source form from
@uref{http://www.gnu.org/@/software/@/tar/@/utils/@/xsparse, @GNUTAR{}
home page}.

Let's begin with archive members in @dfn{sparse format
version 1.0}@footnote{@xref{PAX 1}.}, which are the easiest to expand.
The condensed file will contain both file map and file data, so no
additional data will be needed to restore it.  If the original file
name was @file{@var{dir}/@var{name}}, then the condensed file will be
named @file{@var{dir}/@/GNUSparseFile.@var{n}/@/@var{name}}, where 
@var{n} is a decimal number@footnote{technically speaking, @var{n} is a
@dfn{process ID} of the @command{tar} process which created the
archive (@pxref{PAX keywords}).}.

To expand a version 1.0 file, run @command{xsparse} as follows:

@smallexample
$ @kbd{xsparse @file{cond-file}}
@end smallexample

@noindent
where @file{cond-file} is the name of the condensed file.  The utility
will deduce the name for the resulting expanded file using the
following algorithm:

@enumerate 1
@item If @file{cond-file} does not contain any directories,
@file{../cond-file} will be used;

@item If @file{cond-file} has the form
@file{@var{dir}/@var{t}/@var{name}}, where both @var{t} and @var{name}
are simple names, with no @samp{/} characters in them, the output file
name will be @file{@var{dir}/@var{name}}.

@item Otherwise, if @file{cond-file} has the form
@file{@var{dir}/@var{name}}, the output file name will be
@file{@var{name}}.
@end enumerate

In the unlikely case when this algorithm does not suite your needs,
you can explicitely specify output file name as a second argument to
the command:

@smallexample
$ @kbd{xsparse @file{cond-file}}
@end smallexample

It is often a good idea to run @command{xsparse} in @dfn{dry run} mode
first.  In this mode, the command does not actually expand the file,
but verbosely lists all actions it would be taking to do so.  The dry
run mode is enabled by @option{-n} command line argument:

@smallexample
@group
$ @kbd{xsparse -n /home/gray/GNUSparseFile.6058/sparsefile}
Reading v.1.0 sparse map
Expanding file `/home/gray/GNUSparseFile.6058/sparsefile' to
`/home/gray/sparsefile'
Finished dry run
@end group
@end smallexample

To actually expand the file, you would run:

@smallexample
$ @kbd{xsparse /home/gray/GNUSparseFile.6058/sparsefile}
@end smallexample

@noindent
The program behaves the same way all UNIX utilities do: it will keep
quiet unless it has simething important to tell you (e.g. an error
condition or something).  If you wish it to produce verbose output,
similar to that from the dry run mode, give it @option{-v} option:

@smallexample
@group
$ @kbd{xsparse -v /home/gray/GNUSparseFile.6058/sparsefile}
Reading v.1.0 sparse map
Expanding file `/home/gray/GNUSparseFile.6058/sparsefile' to
`/home/gray/sparsefile'
Done
@end group
@end smallexample

Additionally, if your @command{tar} implementation has extracted the
@dfn{extended headers} for this file, you can instruct @command{xstar}
to use them in order to verify the integrity of the expanded file.
The option @option{-x} sets the name of the extended header file to
use.  Continuing our example:

@smallexample
@group
$ @kbd{xsparse -v -x /home/gray/PaxHeaders.6058/sparsefile \
  /home/gray/GNUSparseFile.6058/sparsefile}
Reading extended header file
Found variable GNU.sparse.major = 1
Found variable GNU.sparse.minor = 0
Found variable GNU.sparse.name = sparsefile
Found variable GNU.sparse.realsize = 217481216
Reading v.1.0 sparse map
Expanding file `/home/gray/GNUSparseFile.6058/sparsefile' to
`/home/gray/sparsefile'
Done
@end group
@end smallexample

An @dfn{extended header} is a special @command{tar} archive header
that precedes an archive member and contains a set of
@dfn{variables}, describing the member properties that cannot be
stored in the standard @code{ustar} header.  While optional for
expanding sparse version 1.0 members, use of extended headers is
mandatory when expanding sparse members in older sparse formats: v.0.0
and v.0.1 (The sparse formats are described in detail in @pxref{Sparse
Formats}).  So, for this format, the question is: how to obtain
extended headers from the archive? 

If you use a @command{tar} implementation that does not support PAX
format, extended headers for each member will be extracted as a 
separate file.  If we represent the member name as
@file{@var{dir}/@var{name}}, then the extended header file will be
named @file{@var{dir}/@/PaxHeaders.@var{n}/@/@var{name}}, where
@var{n} is an integer number.

Things become more difficult if your @command{tar} implementation
does support PAX headers, because in this case you will have to
manually extract the headers.  We recommend the following algorithm:

@enumerate 1
@item 
Consult the documentation for your @command{tar} implementation for an
option that will print @dfn{block numbers} along with the archive
listing (analogous to @GNUTAR{}'s @option{-R} option).  For example,
@command{star} has @option{-block-number}.

@item
Obtain the verbose listing using the @samp{block number} option, and
find the position of the sparse member in question and the member
immediately following it.  For example, running @command{star} on our
archive we obtain:

@smallexample
@group
$ @kbd{star -t -v -block-number -f arc.tar}
@dots{}
star: Unknown extended header keyword 'GNU.sparse.size' ignored.
star: Unknown extended header keyword 'GNU.sparse.numblocks' ignored.
star: Unknown extended header keyword 'GNU.sparse.name' ignored.
star: Unknown extended header keyword 'GNU.sparse.map' ignored.
block        56:  425984 -rw-r--r--  gray/users Jun 25 14:46 2006 GNUSparseFile.28124/sparsefile
block       897:   65391 -rw-r--r--  gray/users Jun 24 20:06 2006 README
@dots{}
@end group
@end smallexample

@noindent
(as usual, ignore the warnings about unknown keywords.)

@item
Let @var{size} be the size of the sparse member, @var{Bs} be its block number
and @var{Bn} be the block number of the next member.
Compute: 

@smallexample
@var{N} = @var{Bs} - @var{Bn} - @var{size}/512 - 2
@end smallexample

@noindent
This number gives the size of the extended header part in tar @dfn{blocks}.
In our example, this formula gives: @code{897 - 56 - 425984 / 512 - 2
= 7}.

@item
Use @command{dd} to extract the headers:

@smallexample
@kbd{dd if=@var{archive} of=@var{hname} bs=512 skip=@var{Bs} count=@var{N}}
@end smallexample

@noindent
where @var{archive} is the archive name, @var{hname} is a name of the
file to store the extended header in, @var{Bs} and @var{N} are
computed in previous steps.

In our example, this command will be

@smallexample
$ @kbd{dd if=arc.tar of=xhdr bs=512 skip=56 count=7}
@end smallexample
@end enumerate

Finally, you can expand the condensed file, using the obtained header:

@smallexample
@group
$ @kbd{xsparse -v -x xhdr GNUSparseFile.6058/sparsefile}
Reading extended header file
Found variable GNU.sparse.size = 217481216
Found variable GNU.sparse.numblocks = 208
Found variable GNU.sparse.name = sparsefile
Found variable GNU.sparse.map = 0,2048,1050624,2048,@dots{}
Expanding file `GNUSparseFile.28124/sparsefile' to `sparsefile'
Done
@end group
@end smallexample

@node cpio
@section Comparison of @command{tar} and @command{cpio}
