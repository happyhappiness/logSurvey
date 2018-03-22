tar -xOzf foo.tgz bigfile1 bigfile2 | process
@end smallexample

Hovewer, @option{--to-command} may be more convenient for use with
multiple files. See the next section.

@node Writing to an External Program
@unnumberedsubsubsec Writing to an External Program

You can instruct @command{tar} to send the contents of each extracted
file to the standard input of an external program:

@table @option
@item --to-program=@var{command}
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
@item --ignore-command-error
Ignore exit codes of subprocesses.  Notice that if the program
exits on signal or otherwise terminates abnormally, the error message
will be printed even if this option is used.

@item --no-ignore-command-error
Cancel the effect of any previous @option{--ignore-command-error}
option. This option is useful if you have set
@option{--ignore-command-error} in @env{TAR_OPTIONS}
(@pxref{TAR_OPTIONS}) and wish to temporarily cancel it.
@end table

@node remove files
@unnumberedsubsubsec Removing Files

