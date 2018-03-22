current state of files on disk, more than validating the integrity of
the archive media.  For this later goal, @xref{verify}. 

@node quoting styles
@subsection Quoting Member Names

When displaying member names, @command{tar} takes care to avoid
ambiguities caused by certain characters.  This is called @dfn{name
quoting}.  The characters in question are:

@itemize @bullet
@item Non-printable control characters:

@multitable @columnfractions 0.20 0.10 0.60
@headitem Character @tab ASCII @tab Character name
@item \a @tab 7  @tab Audible bell
@item \b @tab 8  @tab Backspace
@item \f @tab 12 @tab Form feed
@item \n @tab 10 @tab New line
@item \r @tab 13 @tab Carriage return
@item \t @tab 9  @tab Horizontal tabulation
@item \v @tab 11 @tab Vertical tabulation
@end multitable

@item Space (ASCII 32)

@item Single and double quotes (@samp{'} and @samp{"})

@item Backslash (@samp{\})
@end itemize

The exact way @command{tar} uses to quote these characters depends on
the @dfn{quoting style}.  The default quoting style, called
@dfn{escape} (see below), uses backslash notation to represent control
characters, space and backslash.  Using this quoting style, control
characters are represented as listed in column @samp{Character} in the
above table, a space is printed as @samp{\ } and a backslash as @samp{\\}.

@GNUTAR{} offers seven distinct quoting styles, which can be selected
using @option{--quoting-style} option:

@table @option
@item --quoting-style=@var{style}
@opindex quoting-style

Sets quoting style.  Valid values for @var{style} argument are:
literal, shell, shell-always, c, escape, locale, clocale.
@end table

These styles are described in detail below.  To illustrate their
effect, we will use an imaginary tar archive @file{arch.tar}
containing the following members:

@smallexample
@group
# 1. Contains horizontal tabulation character.
a       tab
# 2. Contains newline character
a
newline
# 3. Contains a space
a space
# 4. Contains double quotes
a"double"quote
# 5. Contains single quotes
a'single'quote
# 6. Contains a backslash character:
a\backslash
@end group
@end smallexample

Here is how usual @command{ls} command would have listed them, if they
had existed in the current working directory:

@smallexample
@group
$ @kbd{ls}
a\ttab
a\nnewline
a\ space
a"double"quote
a'single'quote
a\\backslash
@end group
@end smallexample

Quoting styles:

@table @samp
@item literal
No quoting, display each character as is:

@smallexample
@group 
$ @kbd{tar tf arch.tar --quoting-style=literal}
./
./a space
./a'single'quote
./a"double"quote
./a\backslash
./a	tab
./a
newline
@end group
@end smallexample

@item shell
Display characters the same way Bourne shell does:
control characters, except @samp{\t} and @samp{\n}, are printed using
backslash escapes, @samp{\t} and @samp{\n} are printed as is, and a
single quote is printed as @samp{\'}.  If a name contains any quoted
characters, it is enclosed in single quotes.  In particular, if a name
contains single quotes, it is printed as several single-quoted strings:

@smallexample
@group
$ @kbd{tar tf arch.tar --quoting-style=shell}
./
'./a space'
'./a'\''single'\''quote'
'./a"double"quote'
'./a\backslash'
'./a	tab'
'./a
newline'
@end group
@end smallexample

@item shell-always
Same as @samp{shell}, but the names are always enclosed in single
quotes:

@smallexample
@group
$ @kbd{tar tf arch.tar --quoting-style=shell-always}
'./'
'./a space'
'./a'\''single'\''quote'
'./a"double"quote'
'./a\backslash'
'./a	tab'
'./a
newline'
@end group
@end smallexample

@item c
Use the notation of the C programming language.  All names are
enclosed in double quotes.  Control characters are quoted using
backslash notations, double quotes are represented as @samp{\"},
backslash characters are represented as @samp{\\}.  Single quotes and
spaces are not quoted:

@smallexample
@group
$ @kbd{tar tf arch.tar --quoting-style=c}
"./"
"./a space"
"./a'single'quote"
"./a\"double\"quote"
"./a\\backslash"
"./a\ttab"
"./a\nnewline"
@end group
@end smallexample

@item escape
Control characters are printed using backslash notation, a space is
printed as @samp{\ } and a backslash as @samp{\\}.  This is the
default quoting style, unless it was changed when configured the
package.

@smallexample
@group
$ @kbd{tar tf arch.tar --quoting-style=escape}
./
./a space
./a'single'quote
./a"double"quote
./a\\backslash
./a\ttab
./a\nnewline
@end group
@end smallexample

@item locale
Control characters, single quote and backslash are printed using
backslash notation.  All names are quoted using left and right
quotation marks, appropriate to the current locale.  If it does not
define quotation marks, use @samp{`} as left and @samp{'} as right
quotation marks.  Any occurrences of the right quotation mark in a
name are escaped with @samp{\}, for example:

For example:

@smallexample
@group
$ @kbd{tar tf arch.tar --quoting-style=locale}
`./'
`./a space'
`./a\'single\'quote'
`./a"double"quote'
`./a\\backslash'
`./a\ttab'
`./a\nnewline'
@end group
@end smallexample

@item clocale
Same as @samp{locale}, but @samp{"} is used for both left and right
quotation marks, if not provided by the currently selected locale:

@smallexample
@group
$ @kbd{tar tf arch.tar --quoting-style=clocale}
"./"
"./a space"
"./a'single'quote"
"./a\"double\"quote"
"./a\\backslash"
"./a\ttab"
"./a\nnewline"
@end group
@end smallexample
@end table

You can specify which characters should be quoted in addition to those
implied by the current quoting style:

@table @option
@item --quote-chars=@var{string}
Always quote characters from @var{string}, even if the selected
quoting style would not quote them.
@end table

For example, using @samp{escape} quoting (compare with the usual
escape listing above): 

@smallexample
@group
$ @kbd{tar tf arch.tar --quoting-style=escape --quote-chars=' "'}
./
./a\ space
./a'single'quote
./a\"double\"quote
./a\\backslash
./a\ttab
./a\nnewline
@end group
@end smallexample

To disable quoting of such additional characters, use the following
option:

@table @option
@item --no-quote-chars=@var{string}
Remove characters listed in @var{string} from the list of quoted
characters set by the previous @option{--quote-chars} option.
@end table

This option is particularly useful if you have added
@option{--quote-chars} to your @env{TAR_OPTIONS} (@pxref{TAR_OPTIONS})
and wish to disable it for the current invocation.

Note, that @option{--no-quote-chars} does @emph{not} disable those
characters that are quoted by default in the selected quoting style.

@node create options
@section Options Used by @option{--create}

@opindex create, additional options
The previous chapter described the basics of how to use
@option{--create} (@option{-c}) to create an archive from a set of files.
@xref{create}.  This section described advanced options to be used with
@option{--create}.

@menu
* Ignore Failed Read::
@end menu

@node Ignore Failed Read
@subsection Ignore Fail Read

@table @option
@item --ignore-failed-read
Do not exit with nonzero on unreadable files or directories.
@end table

@node extract options
@section Options Used by @option{--extract}
@UNREVISED

@opindex extract, additional options
The previous chapter showed how to use @option{--extract} to extract
an archive into the file system.  Various options cause @command{tar} to
extract more information than just file contents, such as the owner,
the permissions, the modification date, and so forth.  This section
presents options to be used with @option{--extract} when certain special
considerations arise.  You may review the information presented in
@ref{extract} for more basic information about the
@option{--extract} operation.

@menu
* Reading::                     Options to Help Read Archives
* Writing::                     Changing How @command{tar} Writes Files
* Scarce::                      Coping with Scarce Resources
@end menu

@node Reading
@subsection Options to Help Read Archives
@cindex Options when reading archives
@UNREVISED

@cindex Reading incomplete records
@cindex Records, incomplete
@opindex read-full-records
Normally, @command{tar} will request data in full record increments from
an archive storage device.  If the device cannot return a full record,
@command{tar} will report an error.  However, some devices do not always
return full records, or do not require the last record of an archive to
be padded out to the next record boundary.  To keep reading until you
obtain a full record, or to accept an incomplete record if it contains
an end-of-archive marker, specify the @option{--read-full-records} (@option{-B}) option
in conjunction with the @option{--extract} or @option{--list} operations.
@xref{Blocking}.

The @option{--read-full-records} (@option{-B}) option is turned on by default when
@command{tar} reads an archive from standard input, or from a remote
machine.  This is because on BSD Unix systems, attempting to read a
pipe returns however much happens to be in the pipe, even if it is
less than was requested.  If this option were not enabled, @command{tar}
would fail as soon as it read an incomplete record from the pipe.

If you're not sure of the blocking factor of an archive, you can
read the archive by specifying @option{--read-full-records} (@option{-B}) and
@option{--blocking-factor=@var{512-size}} (@option{-b
@var{512-size}}), using a blocking factor larger than what the archive
uses.  This lets you avoid having to determine the blocking factor
of an archive.  @xref{Blocking Factor}.

@menu
* read full records::
* Ignore Zeros::
@end menu

@node read full records
@unnumberedsubsubsec Reading Full Records

@FIXME{need sentence or so of intro here}

@table @option
@opindex read-full-records
@item --read-full-records
@item -B
Use in conjunction with @option{--extract} (@option{--get},
@option{-x}) to read an archive which contains incomplete records, or
one which has a blocking factor less than the one specified.
@end table

@node Ignore Zeros
@unnumberedsubsubsec Ignoring Blocks of Zeros

@cindex End-of-archive blocks, ignoring
@cindex Ignoring end-of-archive blocks
@opindex ignore-zeros
Normally, @command{tar} stops reading when it encounters a block of zeros
between file entries (which usually indicates the end of the archive).
@option{--ignore-zeros} (@option{-i}) allows @command{tar} to
completely read an archive which contains a block of zeros before the
end (i.e., a damaged archive, or one that was created by concatenating
several archives together).

The @option{--ignore-zeros} (@option{-i}) option is turned off by default because many
versions of @command{tar} write garbage after the end-of-archive entry,
since that part of the media is never supposed to be read.  @GNUTAR{}
does not write after the end of an archive, but seeks to
maintain compatiblity among archiving utilities.

@table @option
@item --ignore-zeros
@itemx -i
To ignore blocks of zeros (i.e., end-of-archive entries) which may be
encountered while reading an archive.  Use in conjunction with
@option{--extract} or @option{--list}.
@end table

@node Writing
@subsection Changing How @command{tar} Writes Files
@UNREVISED

@FIXME{Introductory paragraph}

@menu
* Dealing with Old Files::
* Overwrite Old Files::
* Keep Old Files::
* Keep Newer Files::
* Unlink First::
* Recursive Unlink::
* Data Modification Times::
* Setting Access Permissions::
* Directory Modification Times and Permissions::
* Writing to Standard Output::
* Writing to an External Program::
* remove files::
@end menu

@node Dealing with Old Files
@unnumberedsubsubsec Options Controlling the Overwriting of Existing Files

@opindex overwrite-dir, introduced
When extracting files, if @command{tar} discovers that the extracted
file already exists, it normally replaces the file by removing it before
extracting it, to prevent confusion in the presence of hard or symbolic
links.  (If the existing file is a symbolic link, it is removed, not
followed.)  However, if a directory cannot be removed because it is
nonempty, @command{tar} normally overwrites its metadata (ownership,
permission, etc.).  The @option{--overwrite-dir} option enables this
default behavior.  To be more cautious and preserve the metadata of
such a directory, use the @option{--no-overwrite-dir} option.

@cindex Overwriting old files, prevention
@opindex keep-old-files, introduced
To be even more cautious and prevent existing files from being replaced, use
the @option{--keep-old-files} (@option{-k}) option.  It causes @command{tar} to refuse
to replace or update a file that already exists, i.e., a file with the
same name as an archive member prevents extraction of that archive
member.  Instead, it reports an error.

@opindex overwrite, introduced
To be more aggressive about altering existing files, use the
@option{--overwrite} option.  It causes @command{tar} to overwrite
existing files and to follow existing symbolic links when extracting.

@cindex Protecting old files
Some people argue that @GNUTAR{} should not hesitate
to overwrite files with other files when extracting.  When extracting
a @command{tar} archive, they expect to see a faithful copy of the
state of the file system when the archive was created.  It is debatable
that this would always be a proper behavior.  For example, suppose one
has an archive in which @file{usr/local} is a link to
@file{usr/local2}.  Since then, maybe the site removed the link and
renamed the whole hierarchy from @file{/usr/local2} to
@file{/usr/local}.  Such things happen all the time.  I guess it would
not be welcome at all that @GNUTAR{} removes the
whole hierarchy just to make room for the link to be reinstated
(unless it @emph{also} simultaneously restores the full
@file{/usr/local2}, of course!)  @GNUTAR{} is indeed
able to remove a whole hierarchy to reestablish a symbolic link, for
example, but @emph{only if} @option{--recursive-unlink} is specified
to allow this behavior.  In any case, single files are silently
removed.

@opindex unlink-first, introduced
Finally, the @option{--unlink-first} (@option{-U}) option can improve performance in
some cases by causing @command{tar} to remove files unconditionally
before extracting them.

@node Overwrite Old Files
@unnumberedsubsubsec Overwrite Old Files

@table @option
@opindex overwrite
@item --overwrite
Overwrite existing files and directory metadata when extracting files
from an archive.

This causes @command{tar} to write extracted files into the file system without
regard to the files already on the system; i.e., files with the same
names as archive members are overwritten when the archive is extracted.
It also causes @command{tar} to extract the ownership, permissions,
and time stamps onto any preexisting files or directories.
If the name of a corresponding file name is a symbolic link, the file
pointed to by the symbolic link will be overwritten instead of the
symbolic link itself (if this is possible).  Moreover, special devices,
empty directories and even symbolic links are automatically removed if
they are in the way of extraction.

Be careful when using the @option{--overwrite} option, particularly when
combined with the @option{--absolute-names} (@option{-P}) option, as this combination
can change the contents, ownership or permissions of any file on your
system.  Also, many systems do not take kindly to overwriting files that
are currently being executed.

@opindex overwrite-dir
@item --overwrite-dir
Overwrite the metadata of directories when extracting files from an
archive, but remove other files before extracting.
@end table

@node Keep Old Files
@unnumberedsubsubsec Keep Old Files

@table @option
@opindex keep-old-files
@item --keep-old-files
@itemx -k
Do not replace existing files from archive.  The
@option{--keep-old-files} (@option{-k}) option prevents @command{tar}
from replacing existing files with files with the same name from the
archive. The @option{--keep-old-files} option is meaningless with
@option{--list} (@option{-t}).  Prevents @command{tar} from replacing
files in the file system during extraction.
@end table

@node Keep Newer Files
@unnumberedsubsubsec Keep Newer Files

@table @option
@opindex keep-newer-files
@item --keep-newer-files
Do not replace existing files that are newer than their archive
copies.  This option is meaningless with @option{--list} (@option{-t}).
@end table

@node Unlink First
@unnumberedsubsubsec Unlink First

@table @option
@opindex unlink-first
@item --unlink-first
@itemx -U
Remove files before extracting over them.
This can make @command{tar} run a bit faster if you know in advance
that the extracted files all need to be removed.  Normally this option
slows @command{tar} down slightly, so it is disabled by default.
@end table

@node Recursive Unlink
@unnumberedsubsubsec Recursive Unlink

@table @option
@opindex recursive-unlink
@item --recursive-unlink
When this option is specified, try removing files and directory hierarchies
before extracting over them.  @emph{This is a dangerous option!}
@end table

If you specify the @option{--recursive-unlink} option,
@command{tar} removes @emph{anything} that keeps you from extracting a file
as far as current permissions will allow it.  This could include removal
of the contents of a full directory hierarchy.

@node Data Modification Times
@unnumberedsubsubsec Setting Data Modification Times

@cindex Data modification times of extracted files
@cindex Modification times of extracted files
Normally, @command{tar} sets the data modification times of extracted
files to the corresponding times recorded for the files in the archive, but
limits the permissions of extracted files by the current @code{umask}
setting.

To set the data modification times of extracted files to the time when
the files were extracted, use the @option{--touch} (@option{-m}) option in
conjunction with @option{--extract} (@option{--get}, @option{-x}).

@table @option
@opindex touch
@item --touch
@itemx -m
Sets the data modification time of extracted archive members to the time
they were extracted, not the time recorded for them in the archive.
Use in conjunction with @option{--extract} (@option{--get}, @option{-x}).
@end table

@node Setting Access Permissions
@unnumberedsubsubsec Setting Access Permissions

@cindex Permissions of extracted files
@cindex Modes of extracted files
To set the modes (access permissions) of extracted files to those
recorded for those files in the archive, use @option{--same-permissions}
in conjunction with the @option{--extract} (@option{--get},
@option{-x}) operation.  

@table @option
@opindex preserve-permission
@opindex same-permission
@item --preserve-permission
@itemx --same-permission
@c @itemx --ignore-umask
@itemx -p
Set modes of extracted archive members to those recorded in the
archive, instead of current umask settings.  Use in conjunction with
@option{--extract} (@option{--get}, @option{-x}).
@end table

@node Directory Modification Times and Permissions
@unnumberedsubsubsec Directory Modification Times and Permissions

After sucessfully extracting a file member, @GNUTAR{} normally
restores its permissions and modification times, as described in the
previous sections.  This cannot be done for directories, because
after extracting a directory @command{tar} will almost certainly
extract files into that directory and this will cause the directory
modification time to be updated.  Moreover, restoring that directory
permissions may not permit file creation within it.  Thus, restoring
directory permissions and modification times must be delayed at least
until all files have been extracted into that directory.  @GNUTAR{}
restores directories using the following approach.

The extracted directories are created with the mode specified in the
archive, as modified by the umask of the user, which gives sufficient
permissions to allow file creation.  The meta-information about the
directory is recorded in the temporary list of directories.  When
preparing to extract next archive member, @GNUTAR{} checks if the
directory prefix of this file contains the remembered directory.  If
it does not, the program assumes that all files have been extracted
into that directory, restores its modification time and permissions
and removes its entry from the internal list.  This approach allows
to correctly restore directory meta-information in the majority of
cases, while keeping memory requirements sufficiently small.  It is
based on the fact, that most @command{tar} archives use the predefined
order of members: first the directory, then all the files and
subdirectories in that directory.

However, this is not always true.  The most important exception are
incremental archives (@pxref{Incremental Dumps}).  The member order in
an incremental archive is reversed: first all directory members are
stored, followed by other (non-directory) members.  So, when extracting
from incremental archives, @GNUTAR{} alters the above procedure.  It
remebers all restored directories, and restores their meta-data
only after the entire archive has been processed.  Notice, that you do
not need to specity any special options for that, as @GNUTAR{}
automatically detects archives in incremental format.

There may be cases, when such processing is required for normal archives
too.  Consider the following example:

@smallexample
@group
$ @kbd{tar --no-recursion -cvf archive \
    foo foo/file1 bar bar/file foo/file2}
foo/
foo/file1
bar/
bar/file
foo/file2
@end group
@end smallexample

During the normal operation, after encountering @file{bar}
@GNUTAR{} will assume that all files from the directory @file{foo}
were already extracted and will therefore restore its timestamp and
permission bits.  However, after extracting @file{foo/file2} the
directory timestamp will be offset again.

To correctly restore directory meta-information in such cases, use
@option{delay-directory-restore} command line option:

@table @option
@opindex delay-directory-restore
@item --delay-directory-restore
Delays restoring of the modification times and permissions of extracted
directories until the end of extraction.  This way, correct
meta-information is restored even if the archive has unusual member
ordering.

@opindex no-delay-directory-restore
@item --no-delay-directory-restore
Cancel the effect of the previous @option{--delay-directory-restore}.
Use this option if you have used @option{--delay-directory-restore} in
@env{TAR_OPTIONS} variable (@pxref{TAR_OPTIONS}) and wish to
temporarily disable it.
@end table

@node Writing to Standard Output
@unnumberedsubsubsec Writing to Standard Output

@cindex Writing extracted files to standard output
@cindex Standard output, writing extracted files to
To write the extracted files to the standard output, instead of
creating the files on the file system, use @option{--to-stdout} (@option{-O}) in
conjunction with @option{--extract} (@option{--get}, @option{-x}).  This option is useful if you are
extracting files to send them through a pipe, and do not need to
preserve them in the file system.  If you extract multiple members,
they appear on standard output concatenated, in the order they are
found in the archive.

@table @option
@opindex to-stdout
@item --to-stdout
@itemx -O
Writes files to the standard output.  Use only in conjunction with
@option{--extract} (@option{--get}, @option{-x}).  When this option is
used, instead of creating the files specified, @command{tar} writes
the contents of the files extracted to its standard output.  This may
be useful if you are only extracting the files in order to send them
through a pipe.  This option is meaningless with @option{--list}
(@option{-t}).
@end table

This can be useful, for example, if you have a tar archive containing
a big file and don't want to store the file on disk before processing
it.  You can use a command like this:

@smallexample
tar -xOzf foo.tgz bigfile | process
@end smallexample

or even like this if you want to process the concatenation of the files:

@smallexample
tar -xOzf foo.tgz bigfile1 bigfile2 | process
@end smallexample

Hovewer, @option{--to-command} may be more convenient for use with
multiple files. See the next section.

@node Writing to an External Program
@unnumberedsubsubsec Writing to an External Program

You can instruct @command{tar} to send the contents of each extracted
file to the standard input of an external program:

@table @option
@opindex to-command
@item --to-command=@var{command}
Extract files and pipe their contents to the standard input of
@var{command}. When this option is used, instead of creating the
files specified, @command{tar} invokes @var{command} and pipes the
contents of the files to its standard output. @var{Command} may
contain command line arguments. The program is executed via
@code{sh -c}. Notice, that @var{command} is executed once for each regular file
extracted. Non-regular files (directories, etc.) are ignored when this
option is used.
@end table

The command can obtain the information about the file it processes
from the following environment variables:

@table @var
@vrindex TAR_FILETYPE, to-command environment
@item TAR_FILETYPE
Type of the file. It is a single letter with the following meaning:

@multitable @columnfractions 0.10 0.90
@item f @tab Regular file
@item d @tab Directory
@item l @tab Symbolic link
@item h @tab Hard link
@item b @tab Block device
@item c @tab Character device
@end multitable

Currently only regular files are supported.

@vrindex TAR_MODE, to-command environment
@item TAR_MODE
File mode, an octal number.

@vrindex TAR_FILENAME, to-command environment
@item TAR_FILENAME
The name of the file.

@vrindex TAR_REALNAME, to-command environment
@item TAR_REALNAME
Name of the file as stored in the archive.

@vrindex TAR_UNAME, to-command environment
@item TAR_UNAME
Name of the file owner.

@vrindex TAR_GNAME, to-command environment
@item TAR_GNAME
Name of the file owner group.

@vrindex TAR_ATIME, to-command environment
@item TAR_ATIME
Time of last access. It is a decimal number, representing seconds
since the epoch.  If the archive provides times with nanosecond
precision, the nanoseconds are appended to the timestamp after a
decimal point.

@vrindex TAR_MTIME, to-command environment
@item TAR_MTIME
Time of last modification.

@vrindex TAR_CTIME, to-command environment
@item TAR_CTIME
Time of last status change.

@vrindex TAR_SIZE, to-command environment
@item TAR_SIZE
Size of the file.

@vrindex TAR_UID, to-command environment
@item TAR_UID
UID of the file owner.

@vrindex TAR_GID, to-command environment
@item TAR_GID
GID of the file owner.
@end table

In addition to these variables, @env{TAR_VERSION} contains the
@GNUTAR{} version number.

If @var{command} exits with a non-0 status, @command{tar} will print
an error message similar to the following:

@smallexample
tar: 2345: Child returned status 1
@end smallexample

Here, @samp{2345} is the PID of the finished process.

If this behavior is not wanted, use @option{--ignore-command-error}:

@table @option
@opindex ignore-command-error
@item --ignore-command-error
Ignore exit codes of subprocesses.  Notice that if the program
exits on signal or otherwise terminates abnormally, the error message
will be printed even if this option is used.

@opindex no-ignore-command-error
@item --no-ignore-command-error
Cancel the effect of any previous @option{--ignore-command-error}
option. This option is useful if you have set
@option{--ignore-command-error} in @env{TAR_OPTIONS}
(@pxref{TAR_OPTIONS}) and wish to temporarily cancel it.
@end table

@node remove files
@unnumberedsubsubsec Removing Files

@FIXME{The section is too terse. Something more to add? An example,
maybe?}

@table @option
@opindex remove-files
@item --remove-files
Remove files after adding them to the archive.
@end table

@node Scarce
@subsection Coping with Scarce Resources
@UNREVISED

@cindex Small memory
@cindex Running out of space

@menu
* Starting File::
* Same Order::
@end menu

@node Starting File
@unnumberedsubsubsec Starting File

@table @option
@opindex starting-file
@item --starting-file=@var{name}
@itemx -K @var{name}
Starts an operation in the middle of an archive.  Use in conjunction
with @option{--extract} (@option{--get}, @option{-x}) or @option{--list} (@option{-t}).
@end table

@cindex Middle of the archive, starting in the
If a previous attempt to extract files failed due to lack of disk
space, you can use @option{--starting-file=@var{name}} (@option{-K
@var{name}}) to start extracting only after member @var{name} of the
archive.  This assumes, of course, that there is now free space, or
that you are now extracting into a different file system.  (You could
also choose to suspend @command{tar}, remove unnecessary files from
the file system, and then restart the same @command{tar} operation.
In this case, @option{--starting-file} is not necessary.
@xref{Incremental Dumps}, @xref{interactive}, and @ref{exclude}.)

@node Same Order
@unnumberedsubsubsec Same Order

@table @option
@cindex Large lists of file names on small machines
@opindex same-order
@opindex preserve-order
@item --same-order
@itemx --preserve-order
@itemx -s
To process large lists of file names on machines with small amounts of
memory.  Use in conjunction with @option{--compare} (@option{--diff},
@option{-d}), @option{--list} (@option{-t}) or @option{--extract}
(@option{--get}, @option{-x}).
@end table

The @option{--same-order} (@option{--preserve-order}, @option{-s}) option tells @command{tar} that the list of file
names to be listed or extracted is sorted in the same order as the
files in the archive.  This allows a large list of names to be used,
even on a small machine that would not otherwise be able to hold all
the names in memory at the same time.  Such a sorted list can easily be
created by running @samp{tar -t} on the archive and editing its output.

This option is probably never needed on modern computer systems.

@node backup
@section Backup options

@cindex backup options

@GNUTAR{} offers options for making backups of files
before writing new versions.  These options control the details of
these backups.  They may apply to the archive itself before it is
created or rewritten, as well as individual extracted members.  Other
@acronym{GNU} programs (@command{cp}, @command{install}, @command{ln},
and @command{mv}, for example) offer similar options.

Backup options may prove unexpectedly useful when extracting archives
containing many members having identical name, or when extracting archives
on systems having file name limitations, making different members appear
has having similar names through the side-effect of name truncation.
(This is true only if we have a good scheme for truncated backup names,
which I'm not sure at all: I suspect work is needed in this area.)
When any existing file is backed up before being overwritten by extraction,
then clashing files are automatically be renamed to be unique, and the
true name is kept for only the last file of a series of clashing files.
By using verbose mode, users may track exactly what happens.

At the detail level, some decisions are still experimental, and may
change in the future, we are waiting comments from our users.  So, please
do not learn to depend blindly on the details of the backup features.
For example, currently, directories themselves are never renamed through
using these options, so, extracting a file over a directory still has
good chances to fail.  Also, backup options apply to created archives,
not only to extracted members.  For created archives, backups will not
be attempted when the archive is a block or character device, or when it
refers to a remote file.

For the sake of simplicity and efficiency, backups are made by renaming old
files prior to creation or extraction, and not by copying.  The original
name is restored if the file creation fails.  If a failure occurs after a
partial extraction of a file, both the backup and the partially extracted
file are kept.

@table @samp
@item --backup[=@var{method}]
@opindex backup
@vindex VERSION_CONTROL
@cindex backups
Back up files that are about to be overwritten or removed.
Without this option, the original versions are destroyed.

Use @var{method} to determine the type of backups made.
If @var{method} is not specified, use the value of the @env{VERSION_CONTROL}
environment variable.  And if @env{VERSION_CONTROL} is not set,
use the @samp{existing} method.

@vindex version-control @r{Emacs variable}
This option corresponds to the Emacs variable @samp{version-control};
the same values for @var{method} are accepted as in Emacs.  This option
also allows more descriptive names.  The valid @var{method}s are:

@table @samp
@item t
@itemx numbered
@cindex numbered @r{backup method}
Always make numbered backups.

@item nil
@itemx existing
@cindex existing @r{backup method}
Make numbered backups of files that already have them, simple backups
of the others.

@item never
@itemx simple
@cindex simple @r{backup method}
Always make simple backups.

@end table

@item --suffix=@var{suffix}
@opindex suffix
@cindex backup suffix
@vindex SIMPLE_BACKUP_SUFFIX
Append @var{suffix} to each backup file made with @option{--backup}.  If this
option is not specified, the value of the @env{SIMPLE_BACKUP_SUFFIX}
environment variable is used.  And if @env{SIMPLE_BACKUP_SUFFIX} is not
set, the default is @samp{~}, just as in Emacs.

@end table

Some people express the desire to @emph{always} use the @option{--backup}
option, by defining some kind of alias or script.  This is not as easy
as one may think, due to the fact that old style options should appear first
and consume arguments a bit unpredictably for an alias or script.  But,
if you are ready to give up using old style options, you may resort to
using something like (a Bourne shell function here):

@smallexample
tar () @{ /usr/local/bin/tar --backup $*; @}
@end smallexample

@node Applications
@section Notable @command{tar} Usages
@UNREVISED

@FIXME{Using Unix file linking capability to recreate directory
structures---linking files into one subdirectory and then
@command{tar}ring that directory.}

@FIXME{Nice hairy example using absolute-names, newer, etc.}

@findex uuencode
You can easily use archive files to transport a group of files from
one system to another: put all relevant files into an archive on one
computer system, transfer the archive to another system, and extract
the contents there.  The basic transfer medium might be magnetic tape,
Internet FTP, or even electronic mail (though you must encode the
archive with @command{uuencode} in order to transport it properly by
mail).  Both machines do not have to use the same operating system, as
long as they both support the @command{tar} program.

For example, here is how you might copy a directory's contents from
one disk to another, while preserving the dates, modes, owners and
link-structure of all the files therein.  In this case, the transfer
medium is a @dfn{pipe}, which is one a Unix redirection mechanism:

@smallexample
$ @kbd{(cd sourcedir; tar -cf - .) | (cd targetdir; tar -xf -)}
@end smallexample

@noindent
You can avoid subshells by using @option{-C} option:

@smallexample
$ @kbd{tar -C sourcedir -cf - . | tar -C targetdir -xf -}
@end smallexample

@noindent
The command also works using short option forms:

@smallexample
$ @kbd{(cd sourcedir; tar --create --file=- . ) \
       | (cd targetdir; tar --extract --file=-)}
# Or:
$ @kbd{tar --directory sourcedir --create --file=- . ) \
       | tar --directory targetdir --extract --file=-}
@end smallexample

@noindent
This is one of the easiest methods to transfer a @command{tar} archive.

@node looking ahead
@section Looking Ahead: The Rest of this Manual

You have now seen how to use all eight of the operations available to
@command{tar}, and a number of the possible options.  The next chapter
explains how to choose and change file and archive names, how to use
files to store names of other files which you can then call as
arguments to @command{tar} (this can help you save time if you expect to
archive the same list of files a number of times), and so forth.
@FIXME{in case it's not obvious, i'm making this up in some sense
based on my limited memory of what the next chapter *really* does.  i
just wanted to flesh out this final section a little bit so i'd
remember to stick it in here. :-)}

If there are too many files to conveniently list on the command line,
you can list the names in a file, and @command{tar} will read that file.
@xref{files}.

There are various ways of causing @command{tar} to skip over some files,
and not archive them.  @xref{Choosing}.

@node Backups
@chapter Performing Backups and Restoring Files
@UNREVISED

@GNUTAR{} is distributed along with the scripts
which the Free Software Foundation uses for performing backups.  There
is no corresponding scripts available yet for doing restoration of
files.  Even if there is a good chance those scripts may be satisfying
to you, they are not the only scripts or methods available for doing
backups and restore.  You may well create your own, or use more
sophisticated packages dedicated to that purpose.

Some users are enthusiastic about @code{Amanda} (The Advanced Maryland
Automatic Network Disk Archiver), a backup system developed by James
da Silva @file{jds@@cs.umd.edu} and available on many Unix systems.
This is free software, and it is available at these places:

@smallexample
http://www.cs.umd.edu/projects/amanda/amanda.html
ftp://ftp.cs.umd.edu/pub/amanda
@end smallexample

@FIXME{

Here is a possible plan for a future documentation about the backuping
scripts which are provided within the @GNUTAR{}
distribution.

@itemize @bullet
@item dumps
 @itemize @minus
 @item what are dumps
 @item different levels of dumps
  @itemize +
  @item full dump = dump everything
  @item level 1, level 2 dumps etc
        A level @var{n} dump dumps everything changed since the last level
        @var{n}-1 dump (?)
  @end itemize
 @item how to use scripts for dumps  (ie, the concept)
  @itemize +
  @item scripts to run after editing backup specs (details)
  @end itemize
 @item Backup Specs, what is it.
  @itemize +
  @item how to customize
  @item actual text of script  [/sp/dump/backup-specs]
  @end itemize
 @item Problems
  @itemize +
   @item rsh doesn't work
   @item rtape isn't installed
   @item (others?)
  @end itemize
 @item the @option{--incremental} option of tar
 @item tapes
  @itemize +
  @item write protection
  @item types of media, different sizes and types, useful for different things
  @item files and tape marks
     one tape mark between files, two at end.
  @item positioning the tape
     MT writes two at end of write,
     backspaces over one when writing again.
  @end itemize
 @end itemize
@end itemize
}

This chapter documents both the provided shell scripts and @command{tar}
options which are more specific to usage as a backup tool.

To @dfn{back up} a file system means to create archives that contain
all the files in that file system.  Those archives can then be used to
restore any or all of those files (for instance if a disk crashes or a
file is accidentally deleted).  File system @dfn{backups} are also
called @dfn{dumps}.

@menu
* Full Dumps::                  Using @command{tar} to Perform Full Dumps
* Incremental Dumps::           Using @command{tar} to Perform Incremental Dumps
* Backup Levels::               Levels of Backups
* Backup Parameters::           Setting Parameters for Backups and Restoration
* Scripted Backups::            Using the Backup Scripts
* Scripted Restoration::        Using the Restore Script
@end menu

@node Full Dumps
@section Using @command{tar} to Perform Full Dumps
@UNREVISED

@cindex full dumps
@cindex dumps, full

@cindex corrupted archives
Full dumps should only be made when no other people or programs
are modifying files in the file system.  If files are modified while
@command{tar} is making the backup, they may not be stored properly in
the archive, in which case you won't be able to restore them if you
have to.  (Files not being modified are written with no trouble, and do
not corrupt the entire archive.)

You will want to use the @option{--label=@var{archive-label}}
(@option{-V @var{archive-label}}) option to give the archive a
volume label, so you can tell what this archive is even if the label
falls off the tape, or anything like that.

Unless the file system you are dumping is guaranteed to fit on
one volume, you will need to use the @option{--multi-volume} (@option{-M}) option.
Make sure you have enough tapes on hand to complete the backup.

If you want to dump each file system separately you will need to use
the @option{--one-file-system} option to prevent
@command{tar} from crossing file system boundaries when storing
(sub)directories.

The @option{--incremental} (@option{-G}) (@pxref{Incremental Dumps})
option is not needed, since this is a complete copy of everything in
the file system, and a full restore from this backup would only be
done onto a completely
empty disk.

Unless you are in a hurry, and trust the @command{tar} program (and your
tapes), it is a good idea to use the @option{--verify} (@option{-W})
option, to make sure your files really made it onto the dump properly.
This will also detect cases where the file was modified while (or just
after) it was being archived.  Not all media (notably cartridge tapes)
are capable of being verified, unfortunately.

@node Incremental Dumps
@section Using @command{tar} to Perform Incremental Dumps

@dfn{Incremental backup} is a special form of @GNUTAR{} archive that
stores additional metadata so that exact state of the file system
can be restored when extracting the archive.

@GNUTAR{} currently offers two options for handling incremental
backups: @option{--listed-incremental=@var{snapshot-file}} (@option{-g
@var{snapshot-file}}) and @option{--incremental} (@option{-G}).

@opindex listed-incremental
The option @option{--listed-incremental} instructs tar to operate on
an incremental archive with additional metadata stored in a standalone
file, called a @dfn{snapshot file}.  The purpose of this file is to help
determine which files have been changed, added or deleted since the
last backup, so that the next incremental backup will contain only
modified files.  The name of the snapshot file is given as an argument
to the option:

@table @option
@item --listed-incremental=@var{file}
@itemx -g @var{file}
  Handle incremental backups with snapshot data in @var{file}.
@end table

To create an incremental backup, you would use
@option{--listed-incremental} together with @option{--create}
(@pxref{create}).  For example:

@smallexample
$ @kbd{tar --create \
           --file=archive.1.tar \
           --listed-incremental=/var/log/usr.snar \
           /usr}
@end smallexample

This will create in @file{archive.1.tar} an incremental backup of
the @file{/usr} file system, storing additional metadata in the file
@file{/var/log/usr.snar}.  If this file does not exist, it will be
created.  The created archive will then be a @dfn{level 0 backup};
please see the next section for more on backup levels.

Otherwise, if the file @file{/var/log/usr.snar} exists, it
determines which files are modified.  In this case only these files will be
stored in the archive.  Suppose, for example, that after running the
above command, you delete file @file{/usr/doc/old} and create
directory @file{/usr/local/db} with the following contents:

@smallexample
$ @kbd{ls /usr/local/db}
/usr/local/db/data
/usr/local/db/index
@end smallexample

Some time later you create another incremental backup.  You will
then see:

@smallexample
$ @kbd{tar --create \
           --file=archive.2.tar \
           --listed-incremental=/var/log/usr.snar \
           /usr}
tar: usr/local/db: Directory is new
usr/local/db/
usr/local/db/data
usr/local/db/index
@end smallexample

@noindent
The created archive @file{archive.2.tar} will contain only these
three members.  This archive is called a @dfn{level 1 backup}.  Notice
that @file{/var/log/usr.snar} will be updated with the new data, so if
you plan to create more @samp{level 1} backups, it is necessary to
create a working copy of the snapshot file before running
@command{tar}.  The above example will then be modified as follows:

@smallexample
$ @kbd{cp /var/log/usr.snar /var/log/usr.snar-1}
$ @kbd{tar --create \
           --file=archive.2.tar \
           --listed-incremental=/var/log/usr.snar-1 \
           /usr}
@end smallexample

Incremental dumps depend crucially on time stamps, so the results are
unreliable if you modify a file's time stamps during dumping (e.g.,
with the @option{--atime-preserve=replace} option), or if you set the clock
backwards.

Metadata stored in snapshot files include device numbers, which,
obviously is supposed to be a non-volatile value.  However, it turns
out that NFS devices have undependable values when an automounter
gets in the picture.  This can lead to a great deal of spurious
redumping in incremental dumps, so it is somewhat useless to compare
two NFS devices numbers over time.  The solution implemented currently
is to considers all NFS devices as being equal when it comes to
comparing directories; this is fairly gross, but there does not seem
to be a better way to go.

Note that incremental archives use @command{tar} extensions and may
not be readable by non-@acronym{GNU} versions of the @command{tar} program.

@opindex listed-incremental, using with @option{--extract}
@opindex extract, using with @option{--listed-incremental}
To extract from the incremental dumps, use
@option{--listed-incremental} together with @option{--extract}
option (@pxref{extracting files}).  In this case, @command{tar} does
not need to access snapshot file, since all the data necessary for
extraction are stored in the archive itself.  So, when extracting, you
can give whatever argument to @option{--listed-incremental}, the usual
practice is to use @option{--listed-incremental=/dev/null}.
Alternatively, you can use @option{--incremental}, which needs no
arguments.  In general, @option{--incremental} (@option{-G}) can be
used as a shortcut for @option{--listed-incremental} when listing or
extracting incremental backups (for more information, regarding this
option, @pxref{incremental-op}).

When extracting from the incremental backup @GNUTAR{} attempts to
restore the exact state the file system had when the archive was
created.  In particular, it will @emph{delete} those files in the file
system that did not exist in their directories when the archive was
created.  If you have created several levels of incremental files,
then in order to restore the exact contents the file system  had when
the last level was created, you will need to restore from all backups
in turn.  Continuing our example, to restore the state of @file{/usr}
file system, one would do@footnote{Notice, that since both archives
were created withouth @option{-P} option (@pxref{absolute}), these
commands should be run from the root file system.}:

@smallexample
$ @kbd{tar --extract \
           --listed-incremental=/dev/null \
           --file archive.1.tar}
$ @kbd{tar --extract \
           --listed-incremental=/dev/null \
           --file archive.2.tar}
@end smallexample

To list the contents of an incremental archive, use @option{--list}
(@pxref{list}), as usual.  To obtain more information about the
archive, use @option{--listed-incremental} or @option{--incremental}
combined with two @option{--verbose} options@footnote{Two
@option{--verbose} options were selected to avoid breaking usual
verbose listing output (@option{--list --verbose}) when using in
scripts.

@opindex incremental, using with @option{--list}
@opindex listed-incremental, using with @option{--list}
@opindex list, using with @option{--incremental}
@opindex list, using with @option{--listed-incremental}
Versions of @GNUTAR{} up to 1.15.1 used to dump verbatim binary
contents of the DUMPDIR header (with terminating nulls) when
@option{--incremental} or @option{--listed-incremental} option was
given, no matter what the verbosity level.  This behavior, and,
especially, the binary output it produced were considered incovenient
and were changed in version 1.16}:

@smallexample
@kbd{tar --list --incremental --verbose --verbose archive.tar}
@end smallexample

This command will print, for each directory in the archive, the list
of files in that directory at the time the archive was created.  This
information is put out in a format which is both human-readable and
unambiguous for a program: each file name is printed as

@smallexample
@var{x} @var{file}
@end smallexample

@noindent
where @var{x} is a letter describing the status of the file: @samp{Y}
if the file  is present in the archive, @samp{N} if the file is not
included in the archive, or a @samp{D} if the file is a directory (and
is included in the archive).@FIXME-xref{dumpdir format}.  Each such
line is terminated by a newline character.  The last line is followed
by an additional newline to indicate the end of the data.

@anchor{incremental-op}The option @option{--incremental} (@option{-G})
gives the same behavior as @option{--listed-incremental} when used
with @option{--list} and @option{--extract} options.  When used with
@option{--create} option, it creates an incremental archive without
creating snapshot file.  Thus, it is impossible to create several
levels of incremental backups with @option{--incremental} option.

@node Backup Levels
@section Levels of Backups

An archive containing all the files in the file system is called a
@dfn{full backup} or @dfn{full dump}.  You could insure your data by
creating a full dump every day.  This strategy, however, would waste a
substantial amount of archive media and user time, as unchanged files
are daily re-archived.

It is more efficient to do a full dump only occasionally.  To back up
files between full dumps, you can use @dfn{incremental dumps}.  A @dfn{level
one} dump archives all the files that have changed since the last full
dump.

A typical dump strategy would be to perform a full dump once a week,
and a level one dump once a day.  This means some versions of files
will in fact be archived more than once, but this dump strategy makes
it possible to restore a file system to within one day of accuracy by
only extracting two archives---the last weekly (full) dump and the
last daily (level one) dump.  The only information lost would be in
files changed or created since the last daily backup.  (Doing dumps
more than once a day is usually not worth the trouble).

@GNUTAR{} comes with scripts you can use to do full
and level-one (actually, even level-two and so on) dumps.  Using
scripts (shell programs) to perform backups and restoration is a
convenient and reliable alternative to typing out file name lists
and @command{tar} commands by hand.

Before you use these scripts, you need to edit the file
@file{backup-specs}, which specifies parameters used by the backup
scripts and by the restore script.  This file is usually located
in @file{/etc/backup} directory.  @xref{Backup Parameters}, for its
detailed description.  Once the backup parameters are set, you can
perform backups or restoration by running the appropriate script.

The name of the backup script is @code{backup}.  The name of the
restore script is @code{restore}.  The following sections describe
their use in detail.

@emph{Please Note:} The backup and restoration scripts are
designed to be used together.  While it is possible to restore files by
hand from an archive which was created using a backup script, and to create
an archive by hand which could then be extracted using the restore script,
it is easier to use the scripts.  @xref{Incremental Dumps}, before
making such an attempt.

@node Backup Parameters
@section Setting Parameters for Backups and Restoration

The file @file{backup-specs} specifies backup parameters for the
backup and restoration scripts provided with @command{tar}.  You must
edit @file{backup-specs} to fit your system configuration and schedule
before using these scripts.

Syntactically, @file{backup-specs} is a shell script, containing
mainly variable assignments.  However, any valid shell construct
is allowed in this file.  Particularly, you may wish to define
functions within that script (e.g., see @code{RESTORE_BEGIN} below).
For more information about shell script syntax, please refer to
@url{http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#ta
g_02, the definition of the Shell Command Language}.  See also
@ref{Top,,Bash Features,bashref,Bash Reference Manual}.

The shell variables controlling behavior of @code{backup} and
@code{restore} are described in the following subsections.

@menu
* General-Purpose Variables::
* Magnetic Tape Control::
* User Hooks::
* backup-specs example::        An Example Text of @file{Backup-specs}
@end menu

@node General-Purpose Variables
@subsection General-Purpose Variables

@defvr {Backup variable} ADMINISTRATOR
The user name of the backup administrator.  @code{Backup} scripts
sends a backup report to this address.
@end defvr

@defvr {Backup variable} BACKUP_HOUR
The hour at which the backups are done.  This can be a number from 0
to 23, or the time specification in form @var{hours}:@var{minutes},
or the string @samp{now}.

This variable is used by @code{backup}.  Its value may be overridden
using @option{--time} option (@pxref{Scripted Backups}).
@end defvr

@defvr {Backup variable} TAPE_FILE

The device @command{tar} writes the archive to.  If @var{TAPE_FILE}
is a remote archive (@pxref{remote-dev}), backup script will suppose
that your @command{mt} is able to access remote devices.  If @var{RSH}
(@pxref{RSH}) is set, @option{--rsh-command} option will be added to
invocations of @command{mt}.
@end defvr

@defvr {Backup variable} BLOCKING

The blocking factor @command{tar} will use when writing the dump archive.
@xref{Blocking Factor}.
@end defvr

@defvr {Backup variable} BACKUP_DIRS

A list of file systems to be dumped (for @code{backup}), or restored
(for @code{restore}).  You can include any directory
name in the list --- subdirectories on that file system will be
included, regardless of how they may look to other networked machines.
Subdirectories on other file systems will be ignored.

The host name specifies which host to run @command{tar} on, and should
normally be the host that actually contains the file system.  However,
the host machine must have @GNUTAR{} installed, and
must be able to access the directory containing the backup scripts and
their support files using the same file name that is used on the
machine where the scripts are run (ie.  what @command{pwd} will print
when in that directory on that machine).  If the host that contains
the file system does not have this capability, you can specify another
host as long as it can access the file system through NFS.

If the list of file systems is very long you may wish to put it
in a separate file.  This file is usually named
@file{/etc/backup/dirs}, but this name may be overridden in
@file{backup-specs} using @code{DIRLIST} variable.
@end defvr

@defvr {Backup variable} DIRLIST

A path to the file containing the list of the file systems to backup
or restore.  By default it is @file{/etc/backup/dirs}.
@end defvr

@defvr {Backup variable} BACKUP_FILES

A list of individual files to be dumped (for @code{backup}), or restored
(for @code{restore}).  These should be accessible from the machine on
which the backup script is run.

If the list of file systems is very long you may wish to store it
in a separate file.  This file is usually named
@file{/etc/backup/files}, but this name may be overridden in
@file{backup-specs} using @code{FILELIST} variable.
@end defvr

@defvr {Backup variable} FILELIST

A path to the file containing the list of the individual files to backup
or restore.  By default it is @file{/etc/backup/files}.
@end defvr

@defvr {Backup variable} MT

Full file name of @command{mt} binary.
@end defvr

@defvr {Backup variable} RSH
@anchor{RSH}
Full file name of @command{rsh} binary or its equivalent.  You may wish to
set it to @code{ssh}, to improve security.  In this case you will have
to use public key authentication.
@end defvr

@defvr {Backup variable} RSH_COMMAND

Full file name of @command{rsh} binary on remote mashines.  This will
be passed via @option{--rsh-command} option to the remote invocation
of @GNUTAR{}.
@end defvr

@defvr {Backup variable} VOLNO_FILE

Name of temporary file to hold volume numbers.  This needs to be accessible
by all the machines which have file systems to be dumped.
@end defvr

@defvr {Backup variable} XLIST

Name of @dfn{exclude file list}.  An @dfn{exclude file list} is a file
located on the remote machine and containing the list of files to
be excluded from the backup.  Exclude file lists are searched in
/etc/tar-backup directory.  A common use for exclude file lists
is to exclude files containing security-sensitive information
(e.g., @file{/etc/shadow} from backups).

This variable affects only @code{backup}.
@end defvr

@defvr {Backup variable} SLEEP_TIME

Time to sleep between dumps of any two successive file systems

This variable affects only @code{backup}.
@end defvr

@defvr {Backup variable} DUMP_REMIND_SCRIPT

Script to be run when it's time to insert a new tape in for the next
volume.  Administrators may want to tailor this script for their site.
If this variable isn't set, @GNUTAR{} will display its built-in prompt
@FIXME-xref{describe it somewhere!}, and will expect confirmation from
the console.
@end defvr

@defvr {Backup variable} SLEEP_MESSAGE

Message to display on the terminal while waiting for dump time.  Usually
this will just be some literal text.
@end defvr

@defvr {Backup variable} TAR

Full file name of the @GNUTAR{} executable.  If this is not set, backup
scripts will search @command{tar} in the current shell path.
@end defvr

@node Magnetic Tape Control
@subsection Magnetic Tape Control

Backup scripts access tape device using special @dfn{hook functions}.
These functions take a single argument -- the name of the tape
device.  Their names are kept in the following variables:

@defvr {Backup variable} MT_BEGIN
The name of @dfn{begin} function.  This function is called before
accessing the drive.  By default it retensions the tape:

@smallexample
MT_BEGIN=mt_begin

mt_begin() @{
    mt -f "$1" retension
@}
@end smallexample
@end defvr

@defvr {Backup variable} MT_REWIND
The name of @dfn{rewind} function.  The default definition is as
follows:

@smallexample
MT_REWIND=mt_rewind

mt_rewind() @{
    mt -f "$1" rewind
@}
@end smallexample

@end defvr

@defvr {Backup variable} MT_OFFLINE
The name of the function switching the tape off line.  By default
it is defined as follows:

@smallexample
MT_OFFLINE=mt_offline

mt_offline() @{
    mt -f "$1" offl
@}
@end smallexample
@end defvr

@defvr {Backup variable} MT_STATUS
The name of the function used to obtain the status of the archive device,
including error count.  Default definition:

@smallexample
MT_STATUS=mt_status

mt_status() @{
    mt -f "$1" status
@}
@end smallexample
@end defvr

@node User Hooks
@subsection User Hooks

@dfn{User hooks} are shell functions executed before and after
each @command{tar} invocation.  Thus, there are @dfn{backup
hooks}, which are executed before and after dumping each file
system, and @dfn{restore hooks}, executed before and
after restoring a file system.  Each user hook is a shell function
taking four arguments:

@deffn {User Hook Function} hook @var{level} @var{host} @var{fs} @var{fsname}
Its arguments are:

@table @var
@item level
Current backup or restore level.

@item host
Name or IP address of the host machine being dumped or restored.

@item fs
Full path name to the file system being dumped or restored.

@item fsname
File system name with directory separators replaced with colons.  This
is useful, e.g., for creating unique files.
@end table
@end deffn

Following variables keep the names of user hook functions

@defvr {Backup variable} DUMP_BEGIN
Dump begin function.  It is executed before dumping the file system.
@end defvr

@defvr {Backup variable} DUMP_END
Executed after dumping the file system.
@end defvr

@defvr {Backup variable} RESTORE_BEGIN
Executed before restoring the file system.
@end defvr

@defvr {Backup variable} RESTORE_END
Executed after restoring the file system.
@end defvr

@node backup-specs example
@subsection An Example Text of @file{Backup-specs}

The following is an example of @file{backup-specs}:

@smallexample
# site-specific parameters for file system backup.

ADMINISTRATOR=friedman
BACKUP_HOUR=1
TAPE_FILE=/dev/nrsmt0

# Use @code{ssh} instead of the less secure @code{rsh}
RSH=/usr/bin/ssh
RSH_COMMAND=/usr/bin/ssh

# Override MT_STATUS function:
my_status() @{
      mts -t $TAPE_FILE
@}
MT_STATUS=my_status

# Disable MT_OFFLINE function
MT_OFFLINE=:

BLOCKING=124
BACKUP_DIRS="
        albert:/fs/fsf
        apple-gunkies:/gd
        albert:/fs/gd2
        albert:/fs/gp
        geech:/usr/jla
        churchy:/usr/roland
        albert:/
        albert:/usr
        apple-gunkies:/
        apple-gunkies:/usr
        gnu:/hack
        gnu:/u
        apple-gunkies:/com/mailer/gnu
        apple-gunkies:/com/archive/gnu"

BACKUP_FILES="/com/mailer/aliases /com/mailer/league*[a-z]"

@end smallexample

@node Scripted Backups
@section Using the Backup Scripts

The syntax for running a backup script is:

@smallexample
backup --level=@var{level} --time=@var{time}
@end smallexample

The @option{level} option requests the dump level.  Thus, to produce
a full dump, specify @code{--level=0} (this is the default, so
@option{--level} may be omitted if its value is @code{0}).
@footnote{For backward compatibility, the @code{backup} will also
try to deduce the requested dump level from the name of the
script itself.  If the name consists of a string @samp{level-}
followed by a single decimal digit, that digit is taken as
the dump level number.  Thus, you may create a link from @code{backup}
to @code{level-1} and then run @code{level-1} whenever you need to
create a level one dump.}

The @option{--time} option determines when should the backup be
run.  @var{Time} may take three forms:

@table @asis
@item @var{hh}:@var{mm}

The dump must be run at @var{hh} hours @var{mm} minutes.

@item @var{hh}

The dump must be run at @var{hh} hours

@item now

The dump must be run immediately.
@end table

You should start a script with a tape or disk mounted.  Once you
start a script, it prompts you for new tapes or disks as it
needs them.  Media volumes don't have to correspond to archive
files --- a multi-volume archive can be started in the middle of a
tape that already contains the end of another multi-volume archive.
The @code{restore} script prompts for media by its archive volume,
so to avoid an error message you should keep track of which tape
(or disk) contains which volume of the archive (@pxref{Scripted
Restoration}).

The backup scripts write two files on the file system.  The first is a
record file in @file{/etc/tar-backup/}, which is used by the scripts
to store and retrieve information about which files were dumped.  This
file is not meant to be read by humans, and should not be deleted by
them.  @xref{Snapshot Files}, for a more detailed explanation of this
file.

The second file is a log file containing the names of the file systems
and files dumped, what time the backup was made, and any error
messages that were generated, as well as how much space was left in
the media volume after the last volume of the archive was written.
You should check this log file after every backup.  The file name is
@file{log-@var{mm-dd-yyyy}-level-@var{n}}, where @var{mm-dd-yyyy}
represents current date, and @var{n} represents current dump level number.

The script also prints the name of each system being dumped to the
standard output.

Following is the full list of options accepted by @code{backup}
script:

@table @option
@item -l @var{level}
@itemx --level=@var{level}
Do backup level @var{level} (default 0).

@item -f
@itemx --force
Force backup even if today's log file already exists.

@item -v[@var{level}]
@itemx --verbose[=@var{level}]
Set verbosity level.  The higher the level is, the more debugging
information will be output during execution.  Devault @var{level}
is 100, which means the highest debugging level.

@item -t @var{start-time}
@itemx --time=@var{start-time}
Wait till @var{time}, then do backup.

@item -h
@itemx --help
Display short help message and exit.

@item -V
@itemx --version
Display information about the program's name, version, origin and legal
status, all on standard output, and then exit successfully.
@end table


@node Scripted Restoration
@section Using the Restore Script

To restore files that were archived using a scripted backup, use the
@code{restore} script.  Its usage is quite straightforward.  In the
simplest form, invoke @code{restore --all}, it will
then restore all the file systems and files specified in
@file{backup-specs} (@pxref{General-Purpose Variables,BACKUP_DIRS}).

You may select the file systems (and/or files) to restore by
giving @code{restore} list of @dfn{patterns} in its command
line.  For example, running

@smallexample
restore 'albert:*'
@end smallexample

@noindent
will restore all file systems on the machine @samp{albert}.  A more
complicated example:

@smallexample
restore 'albert:*' '*:/var'
@end smallexample

@noindent
This command will restore all file systems on the machine @samp{albert}
as well as @file{/var} file system on all machines.

By default @code{restore} will start restoring files from the lowest
available dump level (usually zero) and will continue through
all available dump levels.  There may be situations where such a
thorough restore is not necessary.  For example, you may wish to
restore only files from the recent level one backup.  To do so,
use @option{--level} option, as shown in the example below:

@smallexample
restore --level=1
@end smallexample

The full list of options accepted by @code{restore} follows:

@table @option
@item -a
@itemx --all
Restore all file systems and files specified in @file{backup-specs}

@item -l @var{level}
@itemx --level=@var{level}
Start restoring from the given backup level, instead of the default 0.

@item -v[@var{level}]
@itemx --verbose[=@var{level}]
Set verbosity level.  The higher the level is, the more debugging
information will be output during execution.  Devault @var{level}
is 100, which means the highest debugging level.

@item -h
@itemx --help
Display short help message and exit.

@item -V
@itemx --version
Display information about the program's name, version, origin and legal
status, all on standard output, and then exit successfully.
@end table

You should start the restore script with the media containing the
first volume of the archive mounted.  The script will prompt for other
volumes as they are needed.  If the archive is on tape, you don't need
to rewind the tape to to its beginning---if the tape head is
positioned past the beginning of the archive, the script will rewind
the tape as needed.  @FIXME-xref{Media, for a discussion of tape
positioning.}

@quotation
@strong{Warning:} The script will delete files from the active file
system if they were not in the file system when the archive was made.
@end quotation

@xref{Incremental Dumps}, for an explanation of how the script makes
that determination.

@node Choosing
@chapter Choosing Files and Names for @command{tar}
@UNREVISED

Certain options to @command{tar} enable you to specify a name for your
archive.  Other options let you decide which files to include or exclude
from the archive, based on when or whether files were modified, whether
the file names do or don't match specified patterns, or whether files
are in specified directories.

This chapter discusses these options in detail.

@menu
* file::                        Choosing the Archive's Name
* Selecting Archive Members::
* files::                       Reading Names from a File
* exclude::                     Excluding Some Files
* Wildcards::                   Wildcards Patterns and Matching
* after::                       Operating Only on New Files
* recurse::                     Descending into Directories
* one::                         Crossing File System Boundaries
@end menu

@node file
@section Choosing and Naming Archive Files
@UNREVISED

@cindex Naming an archive
@cindex Archive Name
@cindex Choosing an archive file
@cindex Where is the archive?
By default, @command{tar} uses an archive file name that was compiled when
it was built on the system; usually this name refers to some physical
tape drive on the machine.  However, the person who installed @command{tar}
on the system may not have set the default to a meaningful value as far as
most users are concerned.  As a result, you will usually want to tell
@command{tar} where to find (or create) the archive.  The
@option{--file=@var{archive-name}} (@option{-f @var{archive-name}})
option allows you to either specify or name a file to use as the archive
instead of the default archive file location.

@table @option
@opindex file, short description
@item --file=@var{archive-name}
@itemx -f @var{archive-name}
Name the archive to create or operate on.  Use in conjunction with
any operation.
@end table

For example, in this @command{tar} command,

@smallexample
$ @kbd{tar -cvf collection.tar blues folk jazz}
@end smallexample

@noindent
@file{collection.tar} is the name of the archive.  It must directly
follow the @option{-f} option, since whatever directly follows @option{-f}
@emph{will} end up naming the archive.  If you neglect to specify an
archive name, you may end up overwriting a file in the working directory
with the archive you create since @command{tar} will use this file's name
for the archive name.

An archive can be saved as a file in the file system, sent through a
pipe or over a network, or written to an I/O device such as a tape,
floppy disk, or CD write drive.

@cindex Writing new archives
@cindex Archive creation
If you do not name the archive, @command{tar} uses the value of the
environment variable @env{TAPE} as the file name for the archive.  If
that is not available, @command{tar} uses a default, compiled-in archive
name, usually that for tape unit zero (ie.  @file{/dev/tu00}).

@cindex Standard input and output
@cindex tar to standard input and output
If you use @file{-} as an @var{archive-name}, @command{tar} reads the
archive from standard input (when listing or extracting files), or
writes it to standard output (when creating an archive).  If you use
@file{-} as an @var{archive-name} when modifying an archive,
@command{tar} reads the original archive from its standard input and
writes the entire new archive to its standard output.

The following example is a convenient way of copying directory
hierarchy from @file{sourcedir} to @file{targetdir}.

@smallexample
$ @kbd{(cd sourcedir; tar -cf - .) | (cd targetdir; tar -xpf -)}
@end smallexample

The @option{-C} option allows to avoid using subshells:

@smallexample
$ @kbd{tar -C sourcedir -cf - . | tar -C targetdir -xpf -}
@end smallexample

In both examples above, the leftmost @command{tar} invocation archives
the contents of @file{sourcedir} to the standard output, while the
rightmost one reads this archive from its standard input and
extracts it.  The @option{-p} option tells it to restore permissions
of the extracted files.

@cindex Remote devices
@cindex tar to a remote device
@anchor{remote-dev}
To specify an archive file on a device attached to a remote machine,
use the following:

@smallexample
@kbd{--file=@var{hostname}:/@var{dev}/@var{file-name}}
@end smallexample

@noindent
@command{tar} will complete the remote connection, if possible, and
prompt you for a username and password.  If you use
@option{--file=@@@var{hostname}:/@var{dev}/@var{file-name}}, @command{tar}
will complete the remote connection, if possible, using your username
as the username on the remote machine.

@cindex Local and remote archives
@anchor{local and remote archives}
If the archive file name includes a colon (@samp{:}), then it is assumed
to be a file on another machine.  If the archive file is
@samp{@var{user}@@@var{host}:@var{file}}, then @var{file} is used on the
host @var{host}.  The remote host is accessed using the @command{rsh}
program, with a username of @var{user}.  If the username is omitted
(along with the @samp{@@} sign), then your user name will be used.
(This is the normal @command{rsh} behavior.)  It is necessary for the
remote machine, in addition to permitting your @command{rsh} access, to
have the @file{rmt} program installed (This command is included in
the @GNUTAR{} distribution and by default is installed under
@file{@var{prefix}/libexec/rmt}, were @var{prefix} means your
installation prefix).  If you need to use a file whose name includes a
colon, then the remote tape drive behavior
can be inhibited by using the @option{--force-local} option.

When the archive is being created to @file{/dev/null}, @GNUTAR{}
tries to minimize input and output operations.  The Amanda backup
system, when used with @GNUTAR{}, has an initial sizing pass which
uses this feature. 

@node Selecting Archive Members
@section Selecting Archive Members
@cindex Specifying files to act on
@cindex Specifying archive members

@dfn{File Name arguments} specify which files in the file system
@command{tar} operates on, when creating or adding to an archive, or which
archive members @command{tar} operates on, when reading or deleting from
an archive.  @xref{Operations}.

To specify file names, you can include them as the last arguments on
the command line, as follows:
@smallexample
@kbd{tar} @var{operation} [@var{option1} @var{option2} @dots{}] [@var{file name-1} @var{file name-2} @dots{}]
@end smallexample

If a file name begins with dash (@samp{-}), precede it with
@option{--add-file} option to prevent it from being treated as an
option.

If you specify a directory name as a file name argument, all the files
in that directory are operated on by @command{tar}.

If you do not specify files, @command{tar} behavior differs depending
on the operation mode as described below:

When @command{tar} is invoked with @option{--create} (@option{-c}),
@command{tar} will stop immediately, reporting the following:

@smallexample
@group
$ @kbd{tar cf a.tar}
tar: Cowardly refusing to create an empty archive
Try `tar --help' or `tar --usage' for more information.
@end group
@end smallexample

If you specify either @option{--list} (@option{-t}) or
@option{--extract} (@option{--get}, @option{-x}), @command{tar}
operates on all the archive members in the archive.

If run with @option{--diff} option, tar will compare the archive with
the contents of the current working directory.

If you specify any other operation, @command{tar} does nothing.

By default, @command{tar} takes file names from the command line.  However,
there are other ways to specify file or member names, or to modify the
manner in which @command{tar} selects the files or members upon which to
operate.  In general, these methods work both for specifying the names
of files and archive members. 

@node files
@section Reading Names from a File

@cindex Reading file names from a file
@cindex Lists of file names
@cindex File Name arguments, alternatives
Instead of giving the names of files or archive members on the command
line, you can put the names into a file, and then use the
@option{--files-from=@var{file-of-names}} (@option{-T
@var{file-of-names}}) option to @command{tar}.  Give the name of the
file which contains the list of files to include as the argument to 
@option{--files-from}.  In the list, the file names should be separated by
newlines.  You will frequently use this option when you have generated
the list of files to archive with the @command{find} utility.

@table @option
@opindex files-from
@item --files-from=@var{file-name}
@itemx -T @var{file-name}
Get names to extract or create from file @var{file-name}.
@end table

If you give a single dash as a file name for @option{--files-from}, (i.e.,
you specify either @code{--files-from=-} or @code{-T -}), then the file
names are read from standard input.

Unless you are running @command{tar} with @option{--create}, you can not use
both @code{--files-from=-} and @code{--file=-} (@code{-f -}) in the same
command.

Any number of @option{-T} options can be given in the command line.

The following example shows how to use @command{find} to generate a list of
files smaller than 400K in length and put that list into a file
called @file{small-files}.  You can then use the @option{-T} option to
@command{tar} to specify the files from that file, @file{small-files}, to
create the archive @file{little.tgz}.  (The @option{-z} option to
@command{tar} compresses the archive with @command{gzip}; @pxref{gzip} for
more information.)

@smallexample
$ @kbd{find .  -size -400 -print > small-files}
$ @kbd{tar -c -v -z -T small-files -f little.tgz}
@end smallexample

@noindent
In the file list given by @option{-T} option, any file name beginning
with @samp{-} character is considered a @command{tar} option and is
processed accordingly.@footnote{Versions of @GNUTAR{} up to 1.15.1
recognized only @option{-C} option in file lists, and only if the
option and its argument occupied two consecutive lines.} For example,
the common use of this feature is to change to another directory by
specifying @option{-C} option:

@smallexample
@group
$ @kbd{cat list}
passwd
hosts
libc.a
$ @kbd{tar -c -f foo.tar --files-from list}
@end group
@end smallexample

@noindent
In this example, @command{tar} will first switch to @file{/etc}
directory and add files @file{passwd} and @file{hosts} to the
archive.  Then it will change to @file{/lib} directory and will archive
the file @file{libc.a}.  Thus, the resulting archive @file{foo.tar} will
contain:

@smallexample
@group
$ @kbd{tar tf foo.tar}
passwd
hosts
libc.a
@end group
@end smallexample

@noindent
@opindex directory, using in @option{--files-from} argument
Notice that the option parsing algorithm used with @option{-T} is
stricter than the one used by shell.  Namely, when specifying option
arguments, you should observe the following rules:

@itemize @bullet
@item
When using short (single-letter) option form, its argument must
immediately follow the option letter, without any intervening
whitespace.  For example: @code{-Cdir}.

@item
When using long option form, the option argument must be separated
from the option by a single equal sign.  No whitespace is allowed on
any side of the equal sign.  For example: @code{--directory=dir}.

@item
For both short and long option forms, the option argument can be given
on the next line after the option name, e.g.:

@smallexample
@group
dir
@end group
@end smallexample

@noindent
and

@smallexample
@group
dir
@end group
@end smallexample
@end itemize

@opindex add-file
If you happen to have a file whose name starts with @samp{-},
precede it with @option{--add-file} option to prevent it from
being recognized as an option.  For example: @code{--add-file=--my-file}.

@menu
* nul::
@end menu

@node nul
@subsection @code{NUL} Terminated File Names

@cindex File names, terminated by @code{NUL}
@cindex @code{NUL} terminated file names
The @option{--null} option causes
@option{--files-from=@var{file-of-names}} (@option{-T @var{file-of-names}})
to read file names terminated by a @code{NUL} instead of a newline, so
files whose names contain newlines can be archived using
@option{--files-from}. 

@table @option
@opindex null
@item --null
Only consider @code{NUL} terminated file names, instead of files that
terminate in a newline.
@end table

The @option{--null} option is just like the one in @acronym{GNU}
@command{xargs} and @command{cpio}, and is useful with the
@option{-print0} predicate of @acronym{GNU} @command{find}.  In
@command{tar}, @option{--null} also disables special handling for
file names that begin with dash.

This example shows how to use @command{find} to generate a list of files
larger than 800K in length and put that list into a file called
@file{long-files}.  The @option{-print0} option to @command{find} is just
like @option{-print}, except that it separates files with a @code{NUL}
rather than with a newline.  You can then run @command{tar} with both the
@option{--null} and @option{-T} options to specify that @command{tar} get the
files from that file, @file{long-files}, to create the archive
@file{big.tgz}.  The @option{--null} option to @command{tar} will cause
@command{tar} to recognize the @code{NUL} separator between files.

@smallexample
$ @kbd{find .  -size +800 -print0 > long-files}
$ @kbd{tar -c -v --null --files-from=long-files --file=big.tar}
@end smallexample

@FIXME{say anything else here to conclude the section?}

@node exclude
@section Excluding Some Files
@UNREVISED

@cindex File names, excluding files by
@cindex Excluding files by name and pattern
@cindex Excluding files by file system
To avoid operating on files whose names match a particular pattern,
use the @option{--exclude} or @option{--exclude-from} options.

@table @option
@opindex exclude
@item --exclude=@var{pattern}
Causes @command{tar} to ignore files that match the @var{pattern}.
@end table

@findex exclude
The @option{--exclude=@var{pattern}} option prevents any file or
member whose name matches the shell wildcard (@var{pattern}) from
being operated on. 
For example, to create an archive with all the contents of the directory
@file{src} except for files whose names end in @file{.o}, use the
command @samp{tar -cf src.tar --exclude='*.o' src}.

You may give multiple @option{--exclude} options.

@table @option
@opindex exclude-from
@item --exclude-from=@var{file}
@itemx -X @var{file}
Causes @command{tar} to ignore files that match the patterns listed in
@var{file}.
@end table

@findex exclude-from
Use the @option{--exclude-from} option to read a
list of patterns, one per line, from @var{file}; @command{tar} will
ignore files matching those patterns.  Thus if @command{tar} is
called as @w{@samp{tar -c -X foo .}} and the file @file{foo} contains a
single line @file{*.o}, no files whose names end in @file{.o} will be
added to the archive.

@table @option
@opindex exclude-caches
@item --exclude-caches
Causes @command{tar} to ignore directories containing a cache directory tag.
@end table

@findex exclude-caches
When creating an archive, the @option{--exclude-caches} option causes
@command{tar} to exclude all directories that contain a @dfn{cache
directory tag}. A cache directory tag is a short file with the
well-known name @file{CACHEDIR.TAG} and having a standard header
specified in @url{http://www.brynosaurus.com/cachedir/spec.html}.
Various applications write cache directory tags into directories they
use to hold regenerable, non-precious data, so that such data can be
more easily excluded from backups.

@menu
* problems with exclude::
@end menu

@node problems with exclude
@unnumberedsubsec Problems with Using the @code{exclude} Options

@opindex exclude, potential problems with
Some users find @samp{exclude} options confusing.  Here are some common
pitfalls:

@itemize @bullet
@item
The main operating mode of @command{tar} does not act on a path name
explicitly listed on the command line if one of its file name
components is excluded.  In the example above, if
you create an archive and exclude files that end with @samp{*.o}, but
explicitly name the file @samp{dir.o/foo} after all the options have been
listed, @samp{dir.o/foo} will be excluded from the archive.

@item
You can sometimes confuse the meanings of @option{--exclude} and
@option{--exclude-from}.  Be careful: use @option{--exclude} when files
to be excluded are given as a pattern on the command line.  Use
@option{--exclude-from} to introduce the name of a file which contains
a list of patterns, one per line; each of these patterns can exclude
zero, one, or many files.

@item
When you use @option{--exclude=@var{pattern}}, be sure to quote the
@var{pattern} parameter, so @GNUTAR{} sees wildcard characters
like @samp{*}.  If you do not do this, the shell might expand the
@samp{*} itself using files at hand, so @command{tar} might receive a
list of files instead of one pattern, or none at all, making the
command somewhat illegal.  This might not correspond to what you want.

For example, write:

@smallexample
$ @kbd{tar -c -f @var{archive.tar} --exclude '*.o' @var{directory}}
@end smallexample

@noindent
rather than:

@smallexample
# @emph{Wrong!}
$ @kbd{tar -c -f @var{archive.tar} --exclude *.o @var{directory}}
@end smallexample

@item
You must use use shell syntax, or globbing, rather than @code{regexp}
syntax, when using exclude options in @command{tar}.  If you try to use
@code{regexp} syntax to describe files to be excluded, your command
might fail.

@item
@FIXME{The change in semantics must have occurred before 1.11,
so I doubt if it is worth mentioning at all. Anyway, should at
least specify in which version the semantics changed.} 
In earlier versions of @command{tar}, what is now the
@option{--exclude-from} option was called @option{--exclude} instead.
Now, @option{--exclude} applies to patterns listed on the command
line and @option{--exclude-from} applies to patterns listed in a
file.

@end itemize

@node Wildcards
@section Wildcards Patterns and Matching

@dfn{Globbing} is the operation by which @dfn{wildcard} characters,
@samp{*} or @samp{?} for example, are replaced and expanded into all
existing files matching the given pattern.  @GNUTAR{} can use wildcard
patterns for matching (or globbing) archive members when extracting
from or listing an archive.  Wildcard patterns are also used for
verifying volume labels of @command{tar} archives.  This section has the
purpose of explaining wildcard syntax for @command{tar}.

@FIXME{the next few paragraphs need work.}

A @var{pattern} should be written according to shell syntax, using wildcard
characters to effect globbing.  Most characters in the pattern stand
for themselves in the matched string, and case is significant: @samp{a}
will match only @samp{a}, and not @samp{A}.  The character @samp{?} in the
pattern matches any single character in the matched string.  The character
@samp{*} in the pattern matches zero, one, or more single characters in
the matched string.  The character @samp{\} says to take the following
character of the pattern @emph{literally}; it is useful when one needs to
match the @samp{?}, @samp{*}, @samp{[} or @samp{\} characters, themselves.

The character @samp{[}, up to the matching @samp{]}, introduces a character
class.  A @dfn{character class} is a list of acceptable characters
for the next single character of the matched string.  For example,
@samp{[abcde]} would match any of the first five letters of the alphabet.
Note that within a character class, all of the ``special characters''
listed above other than @samp{\} lose their special meaning; for example,
@samp{[-\\[*?]]} would match any of the characters, @samp{-}, @samp{\},
@samp{[}, @samp{*}, @samp{?}, or @samp{]}.  (Due to parsing constraints,
the characters @samp{-} and @samp{]} must either come @emph{first} or
@emph{last} in a character class.)

@cindex Excluding characters from a character class
@cindex Character class, excluding characters from
If the first character of the class after the opening @samp{[}
is @samp{!} or @samp{^}, then the meaning of the class is reversed.
Rather than listing character to match, it lists those characters which
are @emph{forbidden} as the next single character of the matched string.

Other characters of the class stand for themselves.  The special
construction @samp{[@var{a}-@var{e}]}, using an hyphen between two
letters, is meant to represent all characters between @var{a} and
@var{e}, inclusive.

@FIXME{need to add a sentence or so here to make this clear for those
who don't have dan around.}

Periods (@samp{.}) or forward slashes (@samp{/}) are not considered
special for wildcard matches.  However, if a pattern completely matches
a directory prefix of a matched string, then it matches the full matched
string: thus, excluding a directory also excludes all the files beneath it.

@menu
* controlling pattern-matching::
@end menu

@node controlling pattern-matching
@unnumberedsubsec Controlling Pattern-Matching

For the purposes of this section, we call @dfn{exclusion members} all
member names obtained while processing @option{--exclude} and
@option{--exclude-from} options, and @dfn{inclusion members} those
member names that were given in the command line or read from the file
specified with @option{--files-from} option.

These two pairs of member lists are used in the following operations:
@option{--diff}, @option{--extract}, @option{--list},
@option{--update}.

There are no inclusion members in create mode (@option{--create} and
@option{--append}), since in this mode the names obtained from the
command line refer to @emph{files}, not archive members.

By default, inclusion members are compared with archive members
literally @footnote{Notice that earlier @GNUTAR{} versions used 
globbing for inclusion members, which contradicted to UNIX98
specification and was not documented. @xref{Changes}, for more
information on this and other changes} and exclusion members are
treated as globbing patterns.  For example:

@smallexample
@group
$ @kbd{tar tf foo.tar}
a.c
b.c
a.txt
[remarks]
# @i{Member names are used verbatim:}
$ @kbd{tar -xf foo.tar -v '[remarks]'}
[remarks]
# @i{Exclude member names are globbed:}
$ @kbd{tar -xf foo.tar -v --exclude '*.c'}
a.txt
[remarks]
@end group
@end smallexample

This behavior can be altered by using the following options:

@table @option
@opindex wildcards
@item --wildcards
Treat all member names as wildcards. 

@opindex no-wildcards
@item --no-wildcards
Treat all member names as literal strings.
@end table

Thus, to extract files whose names end in @samp{.c}, you can use:

@smallexample
$ @kbd{tar -xf foo.tar -v --wildcards '*.c'}
a.c
b.c
@end smallexample

@noindent
Notice quoting of the pattern to prevent the shell from interpreting
it.

The effect of @option{--wildcards} option is cancelled by
@option{--no-wildcards}.  This can be used to pass part of
the command line arguments verbatim and other part as globbing
patterns.  For example, the following invocation:

@smallexample
$ @kbd{tar -xf foo.tar --wildcards '*.txt' --no-wildcards '[remarks]'}
@end smallexample

@noindent
instructs @command{tar} to extract from @file{foo.tar} all files whose
names end in @samp{.txt} and the file named @file{[remarks]}.

Normally, a pattern matches a name if an initial subsequence of the
name's components matches the pattern, where @samp{*}, @samp{?}, and
@samp{[...]} are the usual shell wildcards, @samp{\} escapes wildcards,
and wildcards can match @samp{/}.

Other than optionally stripping leading @samp{/} from names
(@pxref{absolute}), patterns and names are used as-is.  For
example, trailing @samp{/} is not trimmed from a user-specified name
before deciding whether to exclude it.

However, this matching procedure can be altered by the options listed
below.  These options accumulate.  For example:

@smallexample
@end smallexample

ignores case when excluding @samp{makefile}, but not when excluding
@samp{readme}.

@table @option
@opindex anchored
@opindex no-anchored
@item --anchored
@itemx --no-anchored
If anchored, a pattern must match an initial subsequence
of the name's components.  Otherwise, the pattern can match any
subsequence.  Default is @option{--no-anchored} for exclusion members
and @option{--anchored} inclusion members.

@opindex ignore-case
@opindex no-ignore-case
@item --ignore-case
@itemx --no-ignore-case
When ignoring case, upper-case patterns match lower-case names and vice versa.
When not ignoring case (the default), matching is case-sensitive.

@opindex wildcards-match-slash
@opindex no-wildcards-match-slash
@item --wildcards-match-slash
@itemx --no-wildcards-match-slash
When wildcards match slash (the default for exclusion members), a
wildcard like @samp{*} in the pattern can match a @samp{/} in the
name.  Otherwise, @samp{/} is matched only by @samp{/}.

@end table

The @option{--recursion} and @option{--no-recursion} options
(@pxref{recurse}) also affect how member patterns are interpreted.  If
recursion is in effect, a pattern matches a name if it matches any of
the name's parent directories.

The following table summarizes pattern-matching default values:

@multitable @columnfractions .3 .7
@headitem Members @tab Default settings
@item Inclusion @tab @option{--no-wildcards --anchored --no-wildcards-match-slash}
@item Exclusion @tab @option{--wildcards --no-anchored --wildcards-match-slash}
@end multitable

@node after
@section Operating Only on New Files
@UNREVISED
