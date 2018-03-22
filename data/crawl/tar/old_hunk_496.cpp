argument.  The modern syntax---@samp{tar -c -v -b 20 -f
/dev/rmt0}---is clearer.

@node Tutorial, Wizardry, Invoking @code{tar}, Top
@chapter Getting Started With @code{tar}

This chapter guides you through some basic examples of @code{tar}
operations.  If you already know how to use some other version of tar,
then you probably don't need to read this chapter.  In the examples,
the lines you should type are preceded by a @samp{%}, which is a
typical shell prompt.  

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

To create a new archive, use @code{tar --create} (or @code{tar -c}).
You can use options to specify the name and format of the archive (as
well as other characteristics), and you can use file-name arguments to
specify which files to put in the archive.  If you don't use any
options or file-name arguments, @code{tar} will use default values.
@xref{Creating Example}, for more information about the
@samp{--create} operation.

@menu
* Creating Example::            Creating Archives of Files
* Subdirectory::                Creating an Archive of a Subdirectory
@end menu

@node Creating Example, Subdirectory, Creating Archives, Creating Archives
@subsection Creating Archives of Files

This example shows you how to create an archive file in the working
directory containing other files in the working directory.  The three
files you archive in this example are called @file{blues},
@file{folk}, and @file{jazz}.  The archive file is called
@file{records}.  While the archive in this example is written to the
file system, it could also be written to any other device.

(If you want to follow along with this and future examples, create a
directory called @file{practice} containing files called @file{blues},
@file{folk} and @file{jazz}.  To create the directory, type
@samp{mkdir practice} at the system prompt.  It will probably be
easiest to create the files using a text editor, such as Emacs.)

First, change into the directory containing the files you want to
archive:

@example
% cd practice
@end example

@noindent
@file{~/practice} is now your working directory.

Then, check that the files to be archived do in fact exist in the
working directory, and make sure there isn't already a file in the
working directory with the archive name you intend to use.  If you
specify an archive file name that is already in use, @code{tar} will
overwrite the old file and its contents will be lost.

To list the names of files in the working directory, type:

@example
% ls
@end example

The system responds:

@example
blues	folk	jazz
%
@end example

@noindent
Then,
@itemize @bullet
@item
Create a new archive (@samp{tar -c} or @samp{tar --create})

@item
Explicitly name the archive file being created (@samp{-f
@var{archive-name}} or @samp{--file=@var{archive-name}}).  If you don't
use this option @code{tar} will write the archive to the default
storage device, which varies from system to system. 
@c <<< this syntax may change.  OK now---check before printing  -ringo

@code{tar} interprets archive file names relative to the working
directory.  Make sure you have write access to the working directory
before using @code{tar}.  

@item
Specify which files to put into the archive (@code{tar} interprets
file names relative to the working directory).  If you don't use any
@var{file-name} arguments, @code{tar} will archive everything in the
working directory.
@end itemize

@noindent
Type:
@example
% tar --create --file=records blues folk jazz 
@end example

@noindent
If you now list the contents of the working directory (@samp{ls}), you
will find the archive file listed as well as the files you saw
previously.

@example
% ls
blues folk jazz records
%
@end example

@menu
* Listing Files::               Listing files in an archive
* Verbose::                     Using @code{tar} in Verbose Mode
@end menu

@node Listing Files, Verbose, Creating Example, Creating Example
@subsubsection Listing files in an archive

You can list the contents of an archive with another operation of
@code{tar}---@samp{--list} or @samp{-l}.  To list the contents of the
archive you just created, type:

@example
% tar --list --file=records
@end example

@noindent
@code{tar} will respond:

@example
blues folk jazz
@end example

@xref{Listing Archive Contents}, for a more detailed tutorial of the
@samp{--list} operation.  @xref{Listing Contents}, for more information
about the @samp{--list} operation.

@node Verbose,  , Listing Files, Creating Example
@subsubsection Using @code{tar} in Verbose Mode

If you include the @samp{--verbose} or @samp{-v} option on the command
line, @code{tar} will list the files it is acting on as it is working.
In verbose mode, the creation example above would appear as:
@cindex Verbose mode example
@findex -v (verbose mode example)

@example
% tar --create --file=records --verbose blues folk jazz
blues
folk
jazz
@end example

@noindent
The first line is the command typed in by the user.  The remaining
lines are generated by @code{tar}.  In the following examples we
usually use verbose mode, though it is almost never required.

@node Subdirectory, Changing, Creating Example, Creating Archives
@subsection Creating an Archive of a Subdirectory

You can store a directory in an archive by using the directory name as
a file-name argument to @code{tar}.  When you specify a directory
file, @code{tar} archives the directory file and all the files it
contains.  The names of the directory and the files it contains are
stored in the archive relative to the current working directory---when
the directory is extracted they will be written into the file system
relative to the working directory at that time.
@c <<< add an xref to --absolute-paths   -ringo

To archive a directory, first move to its superior directory.  If you
have been following the tutorial, you should type:

@example
% cd ..
%
@end example

Once in the superior directory, specify the subdirectory using a
file-name argument.  To store the directory file @file{~/practice} in
the archive file @file{music}, type:

@example
% tar --create --verbose --file=music practice
@end example

@noindent
@code{tar} should respond:

@example
practice/
practice/blues
practice/folk
practice/jazz
practice/records
@end example

Note that @file{~/practice/records}, another archive file, has
itself been archived.  @code{tar} will accept any file as a file to be
archived, even an archive file.

@c >>> symbolic links and changing directories are now in main body, not in
@c >>> tutorial. -ringo

@node Extracting Files
@section Extracting Files from an Archive

Creating an archive is only half the job---there would be no point in
storing files in an archive if you couldn't retrieve them.  To extract
files from an archive, use the @samp{--extract} or @samp{-x} operation.

To extract specific files, use their names as file-name arguments.  If
you use a directory name as a file-name argument, @code{tar} extracts
all the files (including subdirectories) in that directory.  If you
don't use any file-name arguments, @code{tar} extracts all the files
in the archive.

Note: @code{tar} will extract an archive member into the file system
without checking to see if there is already a file with the archive
member's file name.  If there is a file with that name, @code{tar}
will @strong{overwrite} that file and its contents will be lost.
@c <<<xref keep-old   -ringo

@node Extracting Specific Files, , ,
@subsection Extracting Specific Files

To extract specific files, specify them using file-name arguments.

In an example above, you created the archive file
@file{~/practice/records}, which contained the files @file{blues},
@file{folk} and @file{jazz} in the @file{practice} directory.  If, for
some reason, you were to lose one of those text files (@samp{rm
~/practice/blues}), you could extract it from the archive file.

First, change into the @file{practice} directory.  Then, 

@itemize @bullet
@item
Invoke @code{tar} and specify the @samp{--extract} operation
(@samp{--extract}, @samp{--get} or @samp{-x})

@item
Specify the archive that the files will be extracted from
(@samp{--file=@var{archive-name}} or @samp{-f @var{archive-name}})

@item
Specify the files to extract, using file-name arguments (if you don't
specify any files, @code{tar} extracts all the archive members)
@end itemize

@example
% tar --extract --file=records blues
@end example

If you list the contents of the directory, you will see that
@file{blues} is back:

@example
% ls
folk
jazz
records
blues
@end example

@node Extracting Directories, , ,
@subsection Extracting Directories

To extract a directory and all the files it contains, use the
directory's name as a file-name argument in conjunction with @samp{tar
relative to the working directory.

In a previous example you stored the directory @file{~/practice} in
the archive file @file{~/music}.  If you delete the contents of
@file{practice}, you can restore them using @code{tar}.

First, change into the @file{practice} subdirectory (@samp{cd
~/practice}).  Then, remove all the files in @samp{~/practice}
(@samp{rm *}).  If you list the contents of the directory, you should
now see that it is empty:

@example
%ls
%
@end example

@noindent Let's try to restore the contents of @file{practice} by extracting
them from the archive file @file{~/music}:

@example
tar --extract --file=~/music practice
@end example

@noindent Now, list the contents of @file{practice} again:

@example
%ls 
practice
@end example

What happened to the files?  When you created @file{~/music}, your
working directory was your home directory.  When you extracted
@file{~/music}, your working directory was @file{~/practice}.
@code{tar} stored the files in @file{practice} relative to your home
directory, and then extracted them relative to @file{~/practice}.  The
files are now in a new subdirectory, called
@file{~/practice/practice}.

To restore your files to their old positions, delete the new directory
and its contents, and then redo the example above with your home
directory as the working directory:

@example
% rm ~/practice/practice/*
% rmdir practice
% cd ..
% tar --extract --file=music practice
@end example

@noindent (@code{tar} will report that it is unable to create the
directory @file{~/practice} because it already exists.  This will not
effect the extraction of the other archive members.)

@node Listing Archive Contents, Adding to Archives, Creating Archives, Tutorial
@section Listing the Contents of an Archive

Use @samp{--list} or @samp{-t} to print the names of files stored in an
archive.  If you use file-name arguments with this operation,
@code{tar} prints the names of the specified files if they are stored
in the archive.  If you use a directory name as a file-name argument,
@code{tar} also prints the names of all underlying files, including
sub-directories.  If you use no file-name arguments, @code{tar} prints
the names of all the archive members.

You can use @samp{--list} with the @samp{--verbose} option to print
archive members' attributes (owner, size, etc.).

@menu
* Listing names::               Listing the names of stored files
* Additional File Info::        Getting Additional File Information
* Specific File::               List A Specific File in an Archive
* Listing Directories::         Listing the Contents of a Stored Directory
@end menu

@node Listing names, Additional File Info, Listing Archive Contents, Listing Archive Contents
@subsection Listing the names of stored files

To list the names of files stored in an archive, use the @samp{--list}
operation of @code{tar}.  

In a previous example, you created the archive @file{~/music}.  To
list the contents of @file{music}, while in your home directory:

@itemize @bullet
@item
List the contents of an archive (@samp{tar -t} or @samp{tar --list})

@item
Specify the archive to be listed (@samp{-f @var{archive-name}} or
@samp{--file=@var{archive-name}}) @refill
@end itemize

Thus:

@example
% tar --list --file=music
practice/
practice/blues
practice/folk
practice/jazz
practice/records
@end example

@node Additional File Info, Specific File, Listing names, Listing Archive Contents
@subsection Listing Additional File Information

To get more information when you list the names of files stored in an
archive, specify the @samp{--verbose} option in conjunction with
@samp{tar --list}.  @code{tar} will print archive member's file
protection, owner and group ID, size, and date and time of creation.

For example:

@example
% tar --list --verbose --file=music
drwxrwxrwx myself/user 0 May 31 21:49 1990 practice/
% 
@end example

Note that when you use @samp{--verbose} with @samp{--list}, @code{tar}
doesn't print the names of files as they are being acted on, though
the @samp{--verbose} option will have this effect when used with all
other operations.

@node Specific File, Comparing Files, Additional File Info, Listing Archive Contents
@subsection List A Specific File in an Archive

To to see if a particular file is in an archive, use the name of the
file in question as a file-name argument while specifying the
@samp{--list} operation.  For example, to see whether the file
@file{folk} is in the archive file @file{music}, do the following:

@itemize @bullet
@item
Invoke @code{tar}, and specify the @samp{--list} operation
(@samp{--list} or @samp{-t}).

@item
Specify the archive file to be acted on (@samp{--file
@var{archive-name}} or @samp{-f @var{archive-name}}).

@item
Specify the files to look for, by typing their names as file-name
arguments.  You have to type the file name as it appears in the
archive (normally, as it is relative to the relative to the directory
from which the archive was created).  <<< xref absolute-paths -ringo
@end itemize

Type:

@example
% tar --list --file=music practice/folk
@end example

@noindent 
@code{tar} responds:

@example
practice/folk
@end example

@noindent
If the file were not stored in the archive (for example, the file
@file{practice/rock}), the example above would look like:

@example
% tar --list --file=music practice/rock
tar: practice/rock not found in archive
@end example

@noindent
If you had used @samp{--verbose} mode, the example above would look
like: 

@example
% tar --list --file=music practice/folk
@end example

@node Listing Directories, , ,
@subsection Listing the Contents of a Stored Directory

To get information about the contents of an archived directory, use
the directory name as a file-name argument in conjunction with
@samp{--list}.  To find out file attributes, include the
@samp{--verbose} option.

For example, to find out about files in the directory @file{practice},
in the archive file @file{music}, type:

@example
% tar --list --file=music practice
@end example

@noindent @code{tar} responds:

@example
drwxrwxrwx myself/user 0 May 31 21:49 1990 practice/
@end example

When you use a directory name as a file-name argument, @code{tar} acts
on all the files (including sub-directories) in that directory.

@node Comparing Files, , ,
@section Comparing Files in an Archive with Files in the File System

To compare the attributes of archive members with the attributes of
their counterparts in the file system, use the @samp{--compare},
@samp{--diff}, or @samp{-d}) operation.  While you could use
@samp{--list --verbose} to manually compare some file attributes, it is
simpler to have @code{tar} itself compare file attributes and report
back on file differences.
@c <<<"manually"?  suggestions?  -ringo

The @samp{--compare} operation, as its name implies, compares archive
members with files of the same name in the file system, and reports
back differences in file size, mode, owner and modification date.
@samp{tar --compare} acts only on archive members---it ignores files in
the file system that are not stored in the archive.  If you give
@samp{tar --compare} a file-name argument that does not correspond to
the name of an archive member, @code{tar} responds with an error
message.

To compare archive members in the archive file @file{records} with
files in the @file{~/practice} directory, first change into the
@file{practice} directory.  Then:

@itemize @bullet
@item
Invoke @code{tar} and specify the @samp{--compare} operation.
(@samp{--compare}, @samp{--diff}, or @samp{-d}).

@item
Specify the archive where the files to be compared are stored
(@samp{--file=@var{archive-name}} or @samp{-f @var{archive-name}})

@item
Specify the archive members to be compared.  (In this example you are
comparing all the archive members in the archive.  Since this is the
default, you don't need to use any file-name arguments).
@end itemize

@example
% tar --compare --file=records
%
@end example

@noindent
While it looks like nothing has happened, @code{tar} has, in fact,
done the comparison---and found nothing to report.  

Use the @samp{--verbose} option to list the names of archive members as
they are being compared with their counterparts of the same name in
the file system:

@example
% tar --compare --verbose --file=records
blues
folk
jazz
%
@end example

@noindent
If @code{tar} had had anything to report, it would have done so as it
was comparing each file.  

If you remove the file @file{jazz} from the file system (@samp{rm
jazz}), and modify the file @file{blues} (for instance, by adding text
to it with an editor such as Emacs), the above example would look
like:

@example
% tar --compare --verbose --file=records
blues
blues: mod time differs
blues: size differs
folk
jazz
jazz: does not exist
% 
@end example

Note again that while @samp{tar --compare} reports the names of archive
members that do not have counterparts in the file system, @samp{tar
counterparts in the archive.  To demonstrate this, create a file in
the @file{practice} directory called @file{rock} (using any text
editor).  The new file appears when you list the directory's contents:

@example
% ls
blues	 folk	  records  rock
@end example

@noindent
If you type the @samp{--compare} example again, @code{tar} prints the
following:

@example
% tar --compare --verbose --file=records
blues
blues: mod time differs
blues: size differs
folk
jazz
jazz: does not exist
% 
@end example

@noindent
@code{tar} ignores the file @file{rock} because @code{tar} is
comparing archive members to files in the file system, not vice versa.

If you specify @file{rock} explicitly (using a file-name argument),
@code{tar} prints an error message:

@example
% tar --compare --verbose --file=records rock
tar: rock not found in archive
% 
@end example

@menu
* Comparing Directories::       Using Compare on Directories
@end menu

@node Comparing Directories,  ,  ,  
@subsubsection Using Compare on Directories

In addition to using @samp{--compare} to compare text files, you can
use @samp{--compare} to compare directories.  To illustrate this,
re-create the examples above using your home directory as the working
directory, and using the archive file @file{~/music} instead of the
archive file @file{~/practice/records}.

First, change into your home directory (@samp{cd ~}).  Then, try the
above example using @file{music} as the specified archive file, and
@file{practice} as a file-name argument.

@example
% tar --compare --verbose --file=music practice
@end example

@noindent
If you have been following along with the tutorial, @code{tar} will
respond:

@example
practice
practice/blues
practice/blues: mod time differs
practice/blues: size differs
practice/folk
practice/jazz
practice/jazz: does not exist
practice/records
@end example

@node Adding to Archives, Concatenate, Listing Archive Contents, Tutorial
@section Adding Files to Existing Archives

@c >>> we want people to use the script for backups, so I an not going to
@c >>> use backups as an explanation in the tutorial.  (people can still
@c >>> do it if they really want to)  -ringo

While you can use @code{tar} to create a new archive every time you
want to store a file, it is more sometimes efficient to add files to
an existing archive.  

To add new files to an existing archive, use the @samp{--add-file},
@samp{--append} or @samp{-r} operation.  To add newer versions of
archive members to an archive, use the @samp{--update} or @samp{-u}
operation.

@menu
* Append::                      Appending Files to an Archive
* Update::                      Updating Files in an Archive
@end menu

@node Append, Update, Adding to Archives, Adding to Archives
@subsection Appending Files to an Archive

The simplest method of adding a file to an existing archive is the
@samp{--add-file}, @samp{-r} or @samp{--append} operation, which writes
files into the archive without regard to whether or not they are
already archive members.  When you use @samp{--add-file} you must use
file-name arguments; there is no default.  If you specify a file that
is already stored in the archive, @code{tar} adds another copy of the
file to the archive.

If you have been following the previous examples, you should have a
text file called @file{~/practice/rock} which has not been stored in
either the archive file @file{~/practice/records}, or the archive file
@file{~/music}.  To add @file{rock} to @file{records}, first make
@file{practice} the working directory (@samp{cd practice}).  Then:

@itemize @bullet
@item
Invoke @code{tar} and specify the @samp{--add-file} operation
(@samp{--add-file}, @samp{-r} or @samp{--append})

@item
Specify the archive to which the file will be added
(@samp{--file=@var{archive-name}} or @samp{-f @var{archive-name}})

@item
Specify the files to be added to the archive, using file-name
arguments
@end itemize

@noindent
For example:

@example
% tar --add-file --file=records rock
@end example

@noindent
If you list the archive members in @file{records}, you will see that
@file{rock} has been added to the archive:

@example
% tar --list --file=records
blues
folk
jazz
rock
@end example

@c <<<  this should be some kind of node.  

You can use @samp{--add-file} to keep archive members current with
active files.  Because @samp{--add-file} stores a file whether or not
there is already an archive member with the same file name, you can
use @samp{--add-file} to add newer versions of archive members to an
archive.  When you extract the file, only the version stored last will
wind up in the file system.  Because @samp{tar --extract} extracts
files from an archive in sequence, and overwrites files with the same
name in the file system, if a file name appears more than once in an
archive the last version of the file will overwrite the previous
versions which have just been extracted.  

If you recall from the examples using @samp{--compare} above,
@file{blues} was changed after the archive @file{records} was created.
It is simple, however, to use @samp{--add-file} to add the new version
of @file{blues} to @file{records}:

@example
% tar --add-file --verbose --file=records blues
blues
@end example

@noindent
If you now list the contents of the archive, you will obtain the following:

@example
% tar --list -f records
blues
folk
jazz
rock
blues
@end example

@noindent
The newest version of @file{blues} is at the end of the archive.  When
the files in @file{records} are extracted, the newer version of
@file{blues} (which has the same name as the older) will overwrite the
version stored first.  When @samp{tar --extract} is finished, only the
newer version of @file{blues} is in the file system.  <<<xref
keep-old-files>>>

@node Update,  , Append, Adding to Archives
@subsection Updating Files in an Archive

To keep archive members up to date with their counterparts of the same
name in the file system, use the @samp{--update} or @samp{-u}
operation.  @samp{tar --update} adds a specified file to an archive if
no file of that name is already stored in the archive.  If there is
already an archive member with the same name, @code{tar} checks the
modification date of the archive member, and adds the file only if its
modification date is later.  If a file is stored in the archive but no
longer exists under the same name in the active file system,
@code{tar} reports an error.

You could use the @samp{--add-file} option to keep an archive current,
but do so you would either have to use the @samp{--compare} and
@samp{--list} options to determine what files needed to be re-archived
(which could waste a lot of time), or you would have to be willing to
add identical copies of already archived files to the archive (which
could waste a lot of space).

You must use file-name arguments with the @samp{--update}
operation---if you don't specify any files, @code{tar} won't act on
any files. 

To see the @samp{--update} option at work, create a new file,
@file{~/practice/classical}, and modify the file
@file{~/practice/blues} (you can use a text editor, such as Emacs, to
do both these things).  Then, with @file{practice} as your working
directory, invoke @samp{tar --update} using the names of all the files
in the practice directory as file-name arguments, and specifying the
@samp{--verbose} option:

@example
% tar --update --verbose --file=records blues folk rock classical
blues
classical
%
@end example

@noindent
Because you specified verbose mode, @code{tar} printed out the names
of the files it acted on.  If you now list the archive members of the
archive, (@samp{tar --list --file=records}), you will see that the file
@file{classical} and another version of the file @file{blues} have
been added to @file{records}.

Note: When you update an archive, @code{tar} does not overwrite old
archive members when it stores newer versions of a file.  This is
because archive members appear in an archive in the order in which
they are stored, and some archive devices do not allow writing in the
middle of an archive.

@node Concatenate, Extracting Files Example, Adding to Archives, Tutorial
@comment  node-name,  next,  previous,  up
@section Concatenating Archives 

To concatenate archive files, use @samp{tar --concatenate} or @samp{tar
While it may seem intuitive to concatenate archives using @code{cat},
the utility for adding files together, archive files which have been
"catted" together cannot be read properly by @code{tar}.  Archive
files incorporate an end of file marker---if archives are concatenated
using @code{cat}, this marker will appear before the end of the new
archive.  This will interfere with operations on that archive.
@c <<<xref ignore-zeros>>>

In earlier examples, you stored the @file{~/practice} directory in an
archive file, @file{~/music}.  If you have been following the
examples, you have since changed the contents of the @file{~/practice}
directory.  There is a current version of the files in the
@file{practice} directory, however, stored in the archive file
@file{~/practice/records}.

To store current versions of the files in @file{practice} in the
archive file @file{music}, you can use @samp{tar --concatenate} to add
the archive file @file{~/practice/records} to @file{music}.  First,
make sure you are in your home directory (@samp{cd ~}).  Then:

@itemize @bullet
@item
Invoke @code{tar}, and specify the @samp{--concatenate} operation
(@samp{-A} or @samp{--concatenate})

@item
Specify the archive file to be added to
(@samp{--file=@var{archive-name}} or @samp{-f @var{archive-name}})

@item
Specify the archives to be added, using file-name arguments.  In this
case, the file-name arguments are, unusually, the names of archive
files.  (Remember to include the path in the archive name, if the
archive file is not in your working directory.)
@end itemize

@example
% cd ~
% tar --concatenate --file=music practice/records
@end example

If you now list the contents of the @file{music}, you see it now
contains the archive members of @file{practice/records}:

@example
%tar --list --file=music
blues
folk
jazz
rock
blues
practice/blues
practice/folk
practice/jazz
practice/rock
practice/blues
practice/classical
@end example

@node Deleting Files,  ,  , Tutorial
@comment  node-name,  next,  previous,  up
@section Deleting Files From an Archive

In some instances, you may want to remove some files from an archive
stored on disk

@quotation
@emph{Caution:} you should never delete files from an archive stored
on tape---because of the linear nature of tape storage, doing this is
likely to scramble the archive.
@end quotation

To remove archive members from an archive, use the @samp{--delete}
operation.  You must specify the names of files to be removed as
file-name arguments.  All versions of the named file are removed from
the archive.  

Execution of the @samp{--delete} operation can be very slow.

To delete all versions of the file @file{blues} from the archive
@file{records} in the @file{practice} directory, make sure you are in
that directory, and then:

@itemize @bullet
@item
List the contents of the archive file @file{records} (see above for
the steps involved) to insure that the file(s) you wish to delete are
stored in the archive.  (This step is optional)

@item
Invoke @code{tar} and specify the @samp{--delete} operation
(@samp{--delete}).

@item
Specify the name of the archive file that the file(s) will be deleted
from (@samp{--file=@var{archive-name}} or @samp{-f @var{archive-name}})

@item
Specify the files to be deleted, using file-name arguments.

@item
List the contents of the archive file again---note that the files have
been removed.  (this step is also optional)
@end itemize

@example
% tar --list --file=records
blues
folk
jazz
% tar --delete --file=records blues
% tar --list --file=records
folk
jazz
% 
@end example

@node Wizardry, Archive Structure, Tutorial, Top
@chapter Wizardry

