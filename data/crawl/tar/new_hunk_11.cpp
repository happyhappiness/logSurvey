.\" This file is part of GNU tar. -*- nroff -*-
.\" Copyright 2013 Free Software Foundation, Inc.
.\"
.\" GNU tar is free software; you can redistribute it and/or modify
.\" it under the terms of the GNU General Public License as published by
.\" the Free Software Foundation; either version 3 of the License, or
.\" (at your option) any later version.
.\"
.\" GNU tar is distributed in the hope that it will be useful,
.\" but WITHOUT ANY WARRANTY; without even the implied warranty of
.\" MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
.\" GNU General Public License for more details.
.\"
.\" You should have received a copy of the GNU General Public License
.\" along with this program.  If not, see <http://www.gnu.org/licenses/>.
.TH TAR 1 "January 27, 2014" "TAR" "GNU TAR Manual"
.SH NAME
tar \- an archiving utility
.SH SYNOPSIS
.SS Traditional usage
\fBtar\fR {\fBA\fR|\fBc\fR|\fBd\fR|\fBr\fR|\fBt\fR|\fBu\fR|\fBx\fR}\
[\fBGnSkUWOmpsMBiajJzZhPlRvwo\fR] [\fIARG\fR...]
.SS UNIX-style usage
.sp
\fBtar\fR \fB\-A\fR [\fIOPTIONS\fR] \fIARCHIVE\fR \fIARCHIVE\fR
.sp
\fBtar\fR \fB\-c\fR [\fB\-f\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIFILE\fR...]
.sp
\fBtar\fR \fB\-d\fR [\fB\-f\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIFILE\fR...]
.sp
\fBtar\fR \fB\-t\fR [\fB\-f\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIMEMBER\fR...]
.sp
\fBtar\fR \fB\-r\fR [\fB\-f\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIFILE\fR...]
.sp
\fBtar\fR \fB\-u\fR [\fB\-f\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIFILE\fR...]
.sp
\fBtar\fR \fB\-x\fR [\fB\-f\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIMEMBER\fR...]
.SS GNU-style usage
.sp
\fBtar\fR {\fB\-\-catenate\fR|\fB\-\-concatenate} [\fIOPTIONS\fR] \fIARCHIVE\fR \fIARCHIVE\fR
.sp
\fBtar\fR \fB\-\-create\fR [\fB\-\-file\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIFILE\fR...]
.sp
\fBtar\fR {\fB\-\-diff\fR|\fB\-\-compare\fR} [\fB\-\-file\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIFILE\fR...]
.sp
\fBtar\fR \fB\-\-delete\fR [\fB\-\-file\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIMEMBER\fR...]
.sp
\fBtar\fR \fB\-\-append\fR [\fB\-f\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIFILE\fR...]
.sp
\fBtar\fR \fB\-\-list\fR [\fB\-f\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIMEMBER\fR...]
.sp
\fBtar\fR \fB\-\-test\-label\fR [\fB\-\-file\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fILABEL\fR...]
.sp
\fBtar\fR \fB\-\-update\fR [\fB\-\-file\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIFILE\fR...]
.sp
\fBtar\fR \fB\-\-update\fR [\fB\-f\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIFILE\fR...]
.sp
\fBtar\fR {\fB\-\-extract\fR|\fB\-\-get\fR} [\fB\-f\fR \fIARCHIVE\fR] [\fIOPTIONS\fR] [\fIMEMBER\fR...]
.SH NOTE
This manpage is a short description of GNU \fBtar\fR.  For a detailed
discussion, including examples and usage recommendations, refer to the
\fBGNU Tar Manual\fR available in texinfo format.  If the \fBinfo\fR
reader and the tar documentation are properly installed on your
system, the command
.PP
.RS +4
.B info tar
.RE
.PP
should give you access to the complete manual.
.PP
You can also view the manual using the info mode in
.BR emacs (1),
or find it in various formats online at
.PP
.RS +4
.B http://www.gnu.org/software/tar/manual
.RE
.PP
If any discrepancies occur between this manpage and the
\fBGNU Tar Manual\fR, the later shall be considered the authoritative
source.
.SH DESCRIPTION
GNU
.B tar
is an archiving program designed to store multiple files in a single
file (an \fBarchive\fR), and to manipulate such archives.  The archive
can be either a regular file or a device (e.g. a tape drive, hence the name
of the program, which stands for \fBt\fRape \fBar\fRchiver), which can
be located either on the local or on a remote machine.
.PP

.SS Option styles
Options to GNU \fBtar\fR can be given in three different styles.
In
.BR "traditional style" ,
the first argument is a cluster of option letters and all subsequent
arguments supply arguments to those options that require them.  The
arguments are read in the same order as the option letters.  Any
command line words that remain after all options has been processed
are treated as non-optional arguments: file or archive member names.
.PP
For example, the \fBc\fR option requires creating the archive, the
\fBv\fR option requests the verbose operation, and the \fBf\fR option
takes an argument that sets the name of the archive to operate upon.
The following command, written in the traditional style, instructs tar
to store all files from the directory
.B /etc
into the archive file
.B etc.tar
verbosely listing the files being archived:
.PP
.EX
.B tar cfv a.tar /etc
.EE
.PP
In
.BR "UNIX " or " short-option style" ,
each option letter is prefixed with a single dash, as in other command
line utilities.  If an option takes argument, the argument follows it,
either as a separate command line word, or immediately following the
option.  However, if the option takes an \fBoptional\fR argument, the
argument must follow the option letter without any intervening
whitespace, as in \fB\-g/tmp/snar.db\fR.
.PP
Any number of options not taking arguments can be
clustered together after a single dash, e.g. \fB\-vkp\fR.  Options
that take arguments (whether mandatory or optional), can appear at
the end of such a cluster, e.g. \fB\-vkpf a.tar\fR.
.PP
The example command above written in the
.B short-option style
could look like:
.PP
.EX
.B tar -cvf a.tar /etc
or
.B tar -c -v -f a.tar /etc
.EE
.PP
In
.BR "GNU " or " long-option style" ,
each option begins with two dashes and has a meaningful name,
consisting of lower-case letters and dashes.  When used, the long
option can be abbreviated to its initial letters, provided that
this does not create ambiguity.  Arguments to long options are
supplied either as a separate command line word, immediately following
the option, or separated from the option by an equals sign with no
intervening whitespace.  Optional arguments must always use the latter
method.
.PP
Here are several ways of writing the example command in this style:
.PP
.EX
.B tar --create --file a.tar --verbose /etc
.EE
or (abbreviating some options):
.EX
.B tar --cre --file=a.tar --verb /etc
.EE
.PP
The options in all three styles can be intermixed, although doing so
with old options is not encouraged.
.SS Operation mode
The options listed in the table below tell GNU \fBtar\fR what
operation it is to perform.  Exactly one of them must be given.
Meaning of non-optional arguments depends on the operation mode
requested.
.TP
\fB\-A\fR, \fB\-\-catenate\fR, \fB\-\-concatenate\fR
Append archive to the end of another archive.  The arguments are
treated as the names of archives to append.  All archives must be of
the same format as the archive they are appended to, otherwise the
resulting archive might be unusable with non-GNU implementations of
\fBtar\fR.  Notice also that when more than one archive is given, the
members from archives other than the first one will be accessible in
the resulting archive only if using the \fB\-i\fR
(\fB\-\-ignore\-zeros) option.

Compressed archives cannot be concatenated.
.TP
\fB\-c\fR, \fB\-\-create\fR
Create a new archive.  Arguments supply the names of the files to be
archived.  Directories are archived recursively, unless the
\fB\-\-no\-recursion\fR option is given.
.TP
\fB\-d\fR, \fB\-\-diff\fR, \fB\-\-compare\fR
Find differences between archive and file system.  The arguments are
optional and specify archive members to compare.  If not given, the
current working directory is assumed.
.TP
\fB\-\-delete\fR
Delete from the archive.  The arguments supply names of the archive
members to be removed.  At least one argument must be given.

This option does not operate on compressed archives.  There is no
short option equivalent.
.TP
\fB\-r\fR, \fB\-\-append\fR
Append files to the end of an archive.  Arguments have the same
meaning as for \fB\-c\fR (\fB\-\-create).
.TP
\fB\-t\fR, \fB\-\-list\fR
List the contents of an archive.  Arguments are optional.  When given,
they specify the names of the members to list.
.TP
\fB\-\-test\-label
Test the archive volume label and exit.  When used without arguments,
it prints the volume label (if any) and exits with status \fB0\fR.
When one or more command line arguments are given.
.B tar
compares the volume label with each argument.  It exits with code
\fB0\fR if a match is found, and with code \fB1\fR otherwise.  No
output is displayed, unless used together with the \fB\-v\fR
(\fB\-\-verbose\fR) option.

There is no short option equivalent for this option.
.TP
\fB\-u\fR, \fB\-\-update\fR
Append files which are newer than the corresponding copy in the
archive.  Arguments have the same meaning as with \fB\-c\fR and
\fB\-r\fR options.
.TP
\fB\-x\fR, \fB\-\-extract\fR, \fB\-\-get\fR
Extract files from an archive.  Arguments are optional.  When given,
they specify names of the archive members to be extracted.
.TP
.TP
\fB\-\-show\-defaults\fR
Show built-in defaults for various \fBtar\fR options and exit.  No
arguments are allowed.
.TP
\fB\-?\fR, \fB\-\-help
Display a short option summary and exit.  No arguments allowed.
.TP
\fB\-\-usage\fR
Display a list of available options and exit.  No arguments allowed.
.TP
\fB\-\-version\fR
Print program version and copyright information and exit.
.SH OPTIONS
.SS Operation modifiers
.TP
\fB\-\-check\-device\fR
Check device numbers when creating incremental archives (default).
.TP
\fB\-g\fR, \fB\-\-listed\-incremental\fR=\fIFILE\fR
Handle new GNU-format incremental backups.  \fIFILE\fR is the name of
a \fBsnapshot file\fR, where tar stores additional information which
is used to decide which files changed since the previous incremental
dump and, consequently, must be dumped again.  If \fIFILE\fR does not
exist when creating an archive, it will be created and all files will
be added to the resulting archive (the \fBlevel 0\fR dump).  To create
incremental archives of non-zero level \fBN\fR, create a copy of the
snapshot file created during the level \fBN-1\fR, and use it as
\fIFILE\fR. 

When listing or extracting, the actual contents of \fIFILE\fR is not
inspected, it is needed only due to syntactical requirements.  It is
therefore common practice to use \fB/dev/null\fR in its place.
.TP
\fB\-G\fR, \fB\-\-incremental\fR
Handle old GNU-format incremental backups.
.TP
\fB\-\-ignore\-failed\-read\fR
Do not exit with nonzero on unreadable files.
.TP
\fB\-\-level\fR=\fINUMBER\fR
Set dump level for created listed-incremental archive.  Currently only
\fB\-\-level=0\fR is meaningful: it instructs \fBtar\fR to truncate
the snapshot file before dumping, thereby forcing a level 0 dump.
.TP
\fB\-n\fR, \fB\-\-seek\fR
Assume the archive is seekable.  Normally \fBtar\fR determines
automatically whether the archive can be seeked or not.  This option
is intended for use in cases when such recognition fails.  It takes
effect only if the archive is open for reading (e.g. with
.B \-\-list
or
.B \-\-extract
options).		    
.TP
\fB\-\-no\-check\-device\fR
Do not check device numbers when creating incremental archives.
.TP
\fB\-\-no\-seek\fR
Assume the archive is not seekable.
.TP
\fB\-\-occurrence\fR[=\fIN\fR]
Process only the \fIN\fRth occurrence of each file in the
archive.  This option is valid only when used with one of the
following subcommands: \fB\-\-delete\fR, \fB\-\-diff\fR,
\fB\-\-extract\fR or \fB\-\-list\fR and when a list of files is given
either on the command line or via the \fB\-\fRT option.  The default
\fIN\fR is \fB1\fR.
.TP
\fB\-\-restrict\fR
Disable the use of some potentially harmful options.
.TP
\fB\-\-sparse\-version\fR=\fIMAJOR\fR[.\fIMINOR\fR]
Set version of the sparse format to use (implies \fB\-\-sparse\fR).
This option implies
.BR \-\-sparse .
Valid argument values are
.BR 0.0 ,
.BR 0.1 ", and"
.BR 1.0 .
For a detailed discussion of sparse formats, refer to the \fBGNU Tar
Manual\fR, appendix \fBD\fR, "\fBSparse Formats\fR".  Using \fBinfo\fR
reader, it can be accessed running the following command:
.BR "info tar 'Sparse Formats'" .
.TP
\fB\-S\fR, \fB\-\-sparse\fR
Handle sparse files efficiently.  Some files in the file system may
have segments which were actually never written (quite often these are
database files created by such systems as \fBDBM\fR).  When given this
option, \fBtar\fR attempts to determine if the file is sparse prior to
archiving it, and if so, to reduce the resulting archive size by not
dumping empty parts of the file.
.SS Overwrite control
These options control \fBtar\fR actions when extracting a file over
an existing copy on disk.
.TP
\fB\-k\fR, \fB\-\-keep\-old\-files\fR
Don't replace existing files when extracting.
.TP
\fB\-\-keep\-newer\-files\fR
Don't replace existing files that are newer than their archive copies.
.TP
\fB\-\-no\-overwrite\-dir\fR
Preserve metadata of existing directories.
.TP
\fB\-\-overwrite\fR
Overwrite existing files when extracting.
.TP
\fB\-\-overwrite\-dir\fR
Overwrite metadata of existing directories when extracting (default).
.TP
\fB\-\-recursive\-unlink\fR
Recursively remove all files in the directory prior to extracting it.
.TP
\fB\-\-remove\-files\fR
Remove files from disk after adding them to the archive.
.TP
\fB\-U\fR, \fB\-\-unlink\-first\fR
Remove each file prior to extracting over it.
.TP
\fB\-W\fR, \fB\-\-verify\fR
Verify the archive after writing it.
.SS Output stream selection
.TP
\fB\-\-ignore\-command\-error\fR
.TP
Ignore subprocess exit codes.
.TP
\fB\-\-no\-ignore\-command\-error\fR
Treat non-zero exit codes of children as error (default).
.TP
\fB\-O\fR, \fB\-\-to\-stdout\fR
Extract files to standard output.
.TP
\fB\-\-to\-command\fR=\fICOMMAND\fR
Pipe extracted files to \fICOMMAND\fR.  The argument is the pathname
of an external program, optionally with command line arguments.  The
program will be invoked and the contents of the file being extracted
supplied to it on its standard output.  Additional data will be
supplied via the following environment variables:
.RS
.TP
.B TAR_FILETYPE
Type of the file. It is a single letter with the following meaning:
.sp
.nf
.ta 8n 20n
	f	Regular file
	d	Directory
	l	Symbolic link
	h	Hard link
	b	Block device
	c	Character device
.fi

Currently only regular files are supported.
.TP
.B TAR_MODE
File mode, an octal number.
.TP
.B TAR_FILENAME
The name of the file.
.TP
.B TAR_REALNAME
Name of the file as stored in the archive.
.TP
.B TAR_UNAME
Name of the file owner.
.TP
.B TAR_GNAME
Name of the file owner group.
.TP
.B TAR_ATIME
Time of last access. It is a decimal number, representing seconds
since the Epoch.  If the archive provides times with nanosecond
precision, the nanoseconds are appended to the timestamp after a
decimal point.
.TP
.B TAR_MTIME
Time of last modification.
.TP
.B TAR_CTIME
Time of last status change.
.TP
.B TAR_SIZE
Size of the file.
.TP
.B TAR_UID
UID of the file owner.
.TP
.B TAR_GID
GID of the file owner.
.RE
.RS

Additionally, the following variables contain information about
\fBtar\fR operation mode and the archive being processed:
.TP
.B TAR_VERSION
GNU \fBtar\fR version number.
.TP
.B TAR_ARCHIVE
The name of the archive \fBtar\fR is processing.
.TP
.B TAR_BLOCKING_FACTOR
Current blocking factor, i.e. number of 512-byte blocks in a record.
.TP
.B TAR_VOLUME
Ordinal number of the volume \fBtar\fR is processing (set if
reading a multi-volume archive).
.TP
.B TAR_FORMAT
Format of the archive being processed.  One of:
.BR gnu ,
.BR oldgnu ,
.BR posix ,
.BR ustar ,
.BR v7 .
.B TAR_SUBCOMMAND
A short option (with a leading dash) describing the operation \fBtar\fR is
executing. 
.RE
.SS Handling of file attributes
.TP
\fB\-\-atime\-preserve\fR[=\fIMETHOD\fR]
Preserve access times on dumped files, either by restoring the times
after reading (\fIMETHOD\fR=\fBreplace\fR, this is the default) or by
not setting the times in the first place (\fIMETHOD\fR=\fBsystem\fR)
.TP
\fB\-\-delay\-directory\-restore\fR
Delay setting modification times and permissions of extracted
directories until the end of extraction.  Use this option when
extracting from an archive which has unusual member ordering.
.TP
\fB\-\-group\fR=\fINAME\fR
Force \fINAME\fR as group for added files.
.TP
\fB\-\-mode\fR=\fICHANGES\fR
Force symbolic mode \fICHANGES\fR for added files.
.TP
\fB\-\-mtime\fR=\fIDATE-OR-FILE\fR
Set mtime for added files.  \fIDATE-OR-FILE\fR is either a date/time
in almost arbitrary formate, or the name of an existing file.  In the
latter case the mtime of that file will be used.
.TP
\fB\-m\fR, \fB\-\-touch\fR
Don't extract file modified time.
.TP
\fB\-\-no\-delay\-directory\-restore\fR
Cancel the effect of the prior \fB\-\-delay\-directory\-restore\fR option.
.TP
\fB\-\-no\-same\-owner\fR
Extract files as yourself (default for ordinary users).
.TP
\fB\-\-no\-same\-permissions\fR
Apply the user's umask when extracting permissions from the archive
(default for ordinary users).
.TP
\fB\-\-numeric\-owner\fR
Always use numbers for user/group names.
.TP
\fB\-\-owner\fR=\fINAME\fR
Force \fINAME\fR as owner for added files.
.TP
\fB\-p\fR, \fB\-\-preserve\-permissions\fR, \fB\-\-same\-permissions\fR
extract information about file permissions (default for superuser)
.TP
\fB\-\-preserve\fR
Same as both \fB\-p\fR and \fB\-s\fR.
.TP
\fB\-\-same\-owner\fR
Try extracting files with the same ownership as exists in the archive
(default for superuser).
.TP
\fB\-s\fR, \fB\-\-preserve\-order\fR, \fB\-\-same\-order\fR
Sort names to extract to match archive
.SS Device selection and switching
.TP
\fB\-f\fR, \fB\-\-file\fR=\fIARCHIVE\fR
Use archive file or device \fIARCHIVE\fR.  If this option is not
given, \fBtar\fR will first examine the environment variable `TAPE'.
If it is set, its value will be used as the archive name.  Otherwise,
\fBtar\fR will assume the compiled-in default.  The default
value can be inspected either using the
.B \-\-show\-defaults
option, or at the end of the \fBtar \-\-help\fR output.

An archive name that has a colon in it specifies a file or device on a
remote machine.  The part before the colon is taken as the machine
name or IP address, and the part after it as the file or device
pathname, e.g.:

.EX
--file=remotehost:/dev/sr0
.EE

An optional username can be prefixed to the hostname, placing a \fB@\fR
sign between them.

By default, the remote host is accessed via the
.BR rsh (1)
command.  Nowadays it is common to use
.BR ssh (1)
instead.  You can do so by giving the following command line option:

.EX
--rsh-command=/usr/bin/ssh
.EE

The remote mashine should have the
.BR rmt (8)
command installed.  If its pathname does not match \fBtar\fR's
default, you can inform \fBtar\fR about the correct pathname using the
.B \-\-rmt\-command
option.
.TP
\fB\-\-force\-local\fR
Archive file is local even if it has a colon.
.TP
\fB\-\fRF, \fB\-\-info\-script\fR=\fICOMMAND\fR, \fB\-\-new\-volume\-script\fR=\fICOMMAND\fR
Run \fICOMMAND\fR at the end of each tape (implies \fB\-M\fR).  The
command can include arguments.  When started, it will inherit \fBtar\fR's
environment plus the following variables:
.RS
.TP
.B TAR_VERSION
GNU \fBtar\fR version number.
.TP
.B TAR_ARCHIVE
The name of the archive \fBtar\fR is processing.
.TP
.B TAR_BLOCKING_FACTOR
Current blocking factor, i.e. number of 512-byte blocks in a record.
.TP
.B TAR_VOLUME
Ordinal number of the volume \fBtar\fR is processing (set if
reading a multi-volume archive).
.TP
.B TAR_FORMAT
Format of the archive being processed.  One of:
.BR gnu ,
.BR oldgnu ,
.BR posix ,
.BR ustar ,
.BR v7 .
.TP
.B TAR_SUBCOMMAND
A short option (with a leading dash) describing the operation \fBtar\fR is
executing.
.TP
.B TAR_FD
File descriptor which can be used to communicate the new volume name
to
.BR tar .  
.RE
.RS

If the info script fails, \fBtar\fR exits; otherwise, it begins writing
the next volume.
.RE
.TP
\fB\-L\fR, \fB\-\-tape\-length\fR=\fN\fR
Change tape after writing \fIN\fRx1024 bytes.  If \fIN\fR is followed
by a size suffix (see the subsection
.B Size suffixes
below), the suffix specifies the multiplicative factor to be used
instead of 1024.

This option implies
.BR \-M .
.TP
\fB\-M\fR, \fB\-\-multi\-volume\fR
Create/list/extract multi-volume archive.
.TP
\fB\-\-rmt\-command\fR=\fICOMMAND\fR
Use \fICOMMAND\fR instead of \fBrmt\fR when accessing remote
archives.  See the description of the
.B \-f
option, above.
.TP
\fB\-\-rsh\-command\fR=\fICOMMAND\fR
Use \fICOMMAND\fR instead of \fBrsh\fR when accessing remote
archives.  See the description of the
.B \-f
option, above.
.TP
\fB\-\-volno\-file\fR=\fIFILE\fR
When this option is used in conjunction with
.BR \-\-multi\-volume ,
.B tar
will keep track of which volume of a multi-volume archive it is
working in \fIFILE\fR. 
.SS Device blocking
.TP
\fB\-b\fR, \fB\-\-blocking\-factor\fR=\fIBLOCKS\fR
Set record size to \fIBLOCKS\fRx\fB512\fR bytes.
.TP
\fB\-B\fR, \fB\-\-read\-full\-records\fR
When listing or extracting, accept incomplete input records after
end-of-file marker.  
.TP
\fB\-i\fR, \fB\-\-ignore\-zeros\fR
Ignore zeroed blocks in archive.  Normally two consecutive 512-blocks
filled with zeroes mean EOF and tar stops reading after encountering
them.  This option instructs it to read further and is useful when
reading archives created with the \fB\-A\fR option.
.TP
\fB\-\-record\-size\fR=\fINUMBER\fR
Set record size.  \fINUMBER\fR is the number of bytes per record.  It
must be multiple of \fB512\fR.  It can can be suffixed with a \fBsize
suffix\fR, e.g. \fB\-\-record-size=10K\fR, for 10 Kilobytes.  See the
subsection
.BR "Size suffixes" ,
for a list of valid suffixes.
.SS Archive format selection
.TP
\fB\-H\fR, \fB\-\-format\fR=\fIFORMAT\fR
Create archive of the given format.  Valid formats are:
.RS
.TP
.B gnu
GNU tar 1.13.x format
.TP
.B oldgnu
GNU format as per tar <= 1.12.
.TP
\fBpax\fR, \fBposix\fR
POSIX 1003.1-2001 (pax) format.
.TP
.B ustar
POSIX 1003.1-1988 (ustar) format.
.TP
.B v7
Old V7 tar format.
.RE
.TP
\fB\-\-old\-archive\fR, \fB\-\-portability\fR
Same as \fB\-\-format=v7\fR.
.TP
\fB\-\-pax\-option\fR=\fIkeyword\fR[[:]=\fIvalue\fR][,\fIkeyword\fR[[:]=\fIvalue\fR]]...
Control pax keywords when creating \fBPAX\fR archives (\fB\-H
pax\fR).  This option is equivalent to the \fB\-o\fR option of the
.BR pax (1) utility.
.TP
\fB\-\-posix\fR
Same as \fB\-\-format=posix\fR.
.TP
\fB\-V\fR, \fB\-\-label\fR=\fITEXT\fR
Create archive with volume name \fITEXT\fR.  If listing or extracting,
use \fITEXT\fR as a globbing pattern for volume name.
.SS Compression options
.TP
\fB\-a\fR, \fB\-\-auto\-compress\fR
Use archive suffix to determine the compression program.
.TP
\fB\-\fRI, \fB\-\-use\-compress\-program\fI=\fICOMMAND\fR
Filter data through \fICOMMAND\fR.  It must accept the \fB\-d\fR
option, for decompression.  The argument can contain command line
options.
.TP
\fB\-j\fR, \fB\-\-bzip2\fR
Filter the archive through
.BR bzip2 (1).
.TP
\fB\-J\fR, \fB\-\-xz\fR
Filter the archive through
.BR xz (1).
.TP
\fB\-\-lzip\fR
Filter the archive through
.BR lzip (1).
.TP
\fB\-\-lzma\fR
Filter the archive through
.BR lzma (1).
.TP
\fB\-\-lzop\fR
Filter the archive through
.BR lzop (1).
.TP
\fB\-\-no\-auto\-compress\fR
Do not use archive suffix to determine the compression program.
.TP
\fB\-z\fR, \fB\-\-gzip\fR, \fB\-\-gunzip\fR, \fB\-\-ungzip\fR
Filter the archive through
.BR gzip (1).
.TP
\fB\-\fRZ, \fB\-\-compress\fR, \fB\-\-uncompress\fR
Filter the archive through
.BR compress (1).
.SS Local file selection
.TP
\fB\-\-add\-file\fR=\fIFILE\fR
Add \fIFILE\fR to the archive (useful if its name starts with a dash).
.TP
\fB\-\-backup\fR[=\fICONTROL\fR]
Backup before removal.  The \fICONTROL\fR argument, if supplied,
controls the backup policy.  Its valid values are:
.RS
.TP
.BR none ", " off
Never make backups.
.TP
.BR t ", " numbered
Make numbered backups.
.TP
.BR nil ", " existing
Make numbered backups if numbered backups exist, simple backups otherwise.
.TP
.BR never ", " simple
Always make simple backups
.RS
.RE

If \fICONTROL\fR is not given, the value is taken from the
.B VERSION_CONTROL
environment variable.  If it is not set, \fBexisting\fR is assumed.
.RE
.TP
\fB\-C\fR, \fB\-\-directory\fR=\fIDIR\fR
Change to directory DIR.
.TP
\fB\-\-exclude\fR=\fIPATTERN\fR
Exclude files matching \fIPATTERN\fR, a
.BR glob (3)-style
wildcard pattern.
.TP
\fB\-\-exclude\-backups\fR
Exclude backup and lock files.
.TP
\fB\-\-exclude\-caches\fR
Exclude contents of directories containing file \fBCACHEDIR.TAG\fR,
except for the tag file itself.
.TP
\fB\-\-exclude\-caches\-all\fR
Exclude directories containing file \fBCACHEDIR.TAG\fR and the file itself.
.TP
\fB\-\-exclude\-caches\-under\fR
Exclude everything under directories containing \fBCACHEDIR.TAG\fR
.TP
\fB\-\-exclude\-tag\fR=\fIFILE\fR
Exclude contents of directories containing \fIFILE\fR, except for
\fIFILE\fR itself.
.TP
\fB\-\-exclude\-tag\-all\fR=\fIFILE\fR
Exclude directories containing \fIFILE\fR.
.TP
\fB\-\-exclude\-tag\-under\fR=\fIFILE\fR
Exclude everything under directories containing \fIFILE\fR.
.TP
\fB\-\-exclude\-vcs\fR
Exclude version control system directories.
.TP
\fB\-h\fR, \fB\-\-dereference\fR
Follow symlinks; archive and dump the files they point to.
.TP
\fB\-\-hard\-dereference\fR
Follow hard links; archive and dump the files they refer to.
.TP
\fB\-K\fR, \fB\-\-starting\-file\fR=\fIMEMBER\fR
Begin at the given member in the archive.
.TP
\fB\-\-newer\-mtime\fR=\fIDATE\fR
Work on files whose data changed after the \fIDATE\fR.  If \fIDATE\fR
starts with \fB/\fR or \fB.\fR it is taken to be a file name; the
mtime of that file is used as the date.
.TP
\fB\-\-no\-null\fR
Disable the effect of the previous \fB\-\-null\fR option.
.TP
\fB\-\-no\-recursion\fR
Avoid descending automatically in directories.
.TP
\fB\-\-no\-unquote\fR
Do not unquote filenames read with \fB\-T\fR.
.TP
\fB\-\-null\fR
Instruct subsequent \fB\-T\fR options to read null-terminated names,
disable handling of the \fB\-C\fR option read from the file.
.TP
\fB\-N\fR, \fB\-\-newer\fR=\fIDATE\fR, \fB\-\-after\-date\fR=\fIDATE\fR
Only store files newer than DATE.  If \fIDATE\fR starts with \fB/\fR
or \fB.\fR it is taken to be a file name; the ctime of that file is
used as the date.
.TP
\fB\-\-one\-file\-system\fR
Stay in local file system when creating archive.
.TP
\fB\-P\fR, \fB\-\-absolute\-names\fR
Don't strip leading slashes from file names when creating archives.
.TP
\fB\-\-recursion\fR
Recurse into directories (default).
.TP
\fB\-\-suffix\fR=\fISTRING\fR
Backup before removal, override usual suffix.  Default suffix is \fB~\fR,
unless overridden by environment variable \fBSIMPLE_BACKUP_SUFFIX\fR.
.TP
\fB\-T\fR, \fB\-\-files\-from\fR=\fIFILE\fR
Get names to extract or create from \fIFILE\fR.
.TP
\fB\-\-unquote\fR
Unquote filenames read with \fB\-T\fR (default).
.TP
\fB\-X\fR, \fB\-\-exclude\-from\fR=\fIFILE\fR
Exclude files matching patterns listed in FILE.
.SS  File name transformations
.TP
\fB\-\-strip\-components\fR=\fINUMBER\fR
Strip \fINUMBER\fR leading components from file names on extraction.
.TP
\fB\-\-transform\fR=\fIEXPRESSION\dR, \fB\-\-xform\fR=\fIEXPRESSION\fR
Use sed replace \fIEXPRESSION\fR to transform file names.
.SS File name matching options
These options affect both exclude and include patterns.
.TP
\fB\-\-anchored\fR
Patterns match file name start.
.TP
\fB\-\-ignore\-case\fR
Ignore case.
.TP
\fB\-\-no\-anchored\fR
Patterns match after any \fB/\fR (default for exclusion).
.TP
\fB\-\-no\-ignore\-case\fR
Case sensitive matching (default).
.TP
\fB\-\-no\-wildcards\fR
Verbatim string matching.
.TP
\fB\-\-no\-wildcards\-match\-slash\fR
Wildcards do not match \fB/\fR.
.TP
\fB\-\-wildcards\fR
Use wildcards (default for exclusion).
.TP
\fB\-\-wildcards\-match\-slash\fR
Wildcards match \fB/\fR (default for exclusion).
.SS Informative output
.TP
\fB\-\-checkpoint\fR[=\fIN\fR]
Display progress messages every \fIN\fRth record (default 10).
.TP
\fB\-\-checkpoint\-action\fR=\fIACTION\fR
Run \fIACTION\fR on each checkpoint.
.TP
\fB\-\-full\-time\fR
Print file time to its full resolution.
.TP
\fB\-\-index\-file\fR=\fIFILE\fR
Send verbose output to \fIFILE\fR.
.TP
\fB\-l\fR, \fB\-\-check\-links\fR
Print a message if not all links are dumped.
.TP
\fB\-\-no\-quote\-chars\fR=\fISTRING\fR
Disable quoting for characters from \fISTRING\fR.
.TP
\fB\-\-quote\-chars\fR=\fISTRING\fR
Additionally quote characters from \fISTRING\fR.
.TP
\fB\-\-quoting\-style\fR=\fISTYLE\fR
Set quoting style for file and member names.  Valid values for
\fISTYLE\fR are
.BR literal ,
.BR shell ,
.BR shell-always ,
.BR c ,
.BR c-maybe ,
.BR escape ,
.BR locale ,
.BR clocale .
.TP
\fB\-R\fR, \fB\-\-block\-number\fR
Show block number within archive with each message.
.TP
\fB\-\-show\-omitted\-dirs\fR
When listing or extracting, list each directory that does not match
search criteria.
.TP
\fB\-\-show\-transformed\-names\fR, \fB\-\-show\-stored\-names\fR
Show file or archive names after transformation by \fB\-\-strip\fR and
\fB\-\-transform\fR options.
.TP
\fB\-\-totals\fR[=\fISIGNAL\fR]
Print total bytes after processing the archive.  If \fISIGNAL\fR is
given, print total bytes when this signal is delivered.  Allowed
signals are:
.BR SIGHUP , 
.BR SIGQUIT ,
.BR SIGINT ,
.BR SIGUSR1 ", and"
.BR SIGUSR2 .
The \fBSIG\fR prefix can be omitted.
.TP
\fB\-\-utc\fR
Print file modification times in UTC.
.TP
\fB\-v\fR, \fB\-\-verbose\fR
Verbosely list files processed.
.TP
\fB\-\-warning\fR=\fIKEYWORD\fR
Enable or disable warning messages identified by \fIKEYWORD\fR.  The
messages are suppressed if \fIKEYWORD\fR is prefixed with \fBno\-\fR
and enabled otherwise.

Multiple \fB\-\-warning\fR messages accumulate.

Keywords controlling general \fBtar\fR operation:
.RS
.TP
.B all
Enable all warning messages.  This is the default.
.TP
.B none
Disable all warning messages.
.TP
.B filename-with-nuls
"%s: file name read contains nul character"
.TP
.B alone-zero-block
"A lone zero block at %s"
.HP
Keywords applicable for \fBtar --create\fR:
.TP
.B cachedir
"%s: contains a cache directory tag %s; %s"
.TP
.B file-shrank
"%s: File shrank by %s bytes; padding with zeros"
.TP
.B xdev
"%s: file is on a different filesystem; not dumped"
.TP
.B file-ignored
"%s: Unknown file type; file ignored"
.br
"%s: socket ignored"
.br
"%s: door ignored"
.TP
.B file-unchanged
"%s: file is unchanged; not dumped"
.TP
.B ignore-archive
"%s: file is the archive; not dumped"
.TP
.B file-removed
"%s: File removed before we read it"
.TP
.B file-changed
"%s: file changed as we read it"
.HP
Keywords applicable for \fBtar --extract\fR:
.TP
.B timestamp
"%s: implausibly old time stamp %s"
.br
"%s: time stamp %s is %s s in the future"
.TP
.B contiguous-cast
"Extracting contiguous files as regular files"
.TP
.B symlink-cast
"Attempting extraction of symbolic links as hard links"
.TP
.B unknown-cast
"%s: Unknown file type '%c', extracted as normal file"
.TP
.B ignore-newer
"Current %s is newer or same age"
.TP
.B unknown-keyword
"Ignoring unknown extended header keyword '%s'"
.TP
.B decompress-program
Controls verbose description of failures occurring when trying to run
alternative decompressor programs.  This warning is disabled by
default (unless \fB\-\-verbose\fR is used).  A common example of what
you can get when using this warning is:

.EX
$ \fBtar --warning=decompress-program -x -f archive.Z
tar (child): cannot run compress: No such file or directory
tar (child): trying gzip
.EE

This means that \fBtar\fR first tried to decompress
\fBarchive.Z\fR using \fBcompress\fR, and, when that
failed, switched to \fBgzip\fR.
.TP
.B record-size
"Record size = %lu blocks"
.HP
Keywords controlling incremental extraction:
.TP
.B rename-directory
"%s: Directory has been renamed from %s"
.br
"%s: Directory has been renamed"
.TP
.B new-directory
"%s: Directory is new"
.TP
.B xdev
"%s: directory is on a different device: not purging"
.TP
.B bad-dumpdir
"Malformed dumpdir: 'X' never used"
.RE
.TP
\fB\-w\fR, \fB\-\-interactive\fR, \fB\-\-confirmation\fR
Ask for confirmation for every action.
.SS Compatibility options
.TP
\fB\-o\fR
When creating, same as \fB\-\-old\-archive\fR.  When extracting, same
as \fB\-\-no\-same\-owner\fR.
.SS Size suffixes
.sp
.nf
.ta 8n 18n 42n
.ul
	Suffix	Units	Byte Equivalent
	b	Blocks	\fISIZE\fR x 512
	B	Kilobytes	\fISIZE\fR x 1024
	c	Bytes	\fISIZE\fR
	G	Gigabytes	\fISIZE\fR x 1024^3
	K	Kilobytes	\fISIZE\fR x 1024
	k	Kilobytes	\fISIZE\fR x 1024
	M	Megabytes	\fISIZE\fR x 1024^2
	P	Petabytes	\fISIZE\fR x 1024^5
	T	Terabytes	\fISIZE\fR x 1024^4
	w	Words	\fISIZE\fR x 2
.fi
.PP
.SH "RETURN VALUE"
Tar exit code indicates whether it was able to successfully perform
the requested operation, and if not, what kind of error occurred.
.TP
.B 0
Successful termination.
.TP
.B 1
.I Some files differ.
If tar was invoked with the \fB\-\-compare\fR (\fB\-\-diff\fR, \fB\-d\fR)
command line option, this means that some files in the archive differ
from their disk counterparts.  If tar was given one of the \fB\-\-create\fR,
\fB\-\-append\fR or \fB\-\-update\fR options, this exit code means
that some files were changed while being archived and so the resulting
archive does not contain the exact copy of the file set.
.TP
.B 2
.I Fatal error.
This means that some fatal, unrecoverable error occurred.
.PP
If a subprocess that had been invoked by
.B tar
exited with a nonzero exit code,
.B tar
itself exits with that code as well.  This can happen, for example, if
a compression option (e.g. \fB\-z\fR) was used and the external
compressor program failed.  Another example is
.B rmt
failure during backup to a remote device.
.SH "SEE ALSO"
.BR bzip2 (1),
.BR compress (1),
.BR gzip (1),
.BR lzma (1),
.BR lzop (1),
.BR rmt (8),
.BR symlink (7),
.BR tar (5),
.BR xz (1).
.PP
Complete \fBtar\fR manual: run
.B info tar
or use
.BR emacs (1)
info mode to read it.
.PP
Online copies of \fBGNU tar\fR documentation in various formats can be
found at:
.PP
.in +4
.B http://www.gnu.org/software/tar/manual
.SH "BUG REPORTS"
Report bugs to <bug\-tar@gnu.org>.
.SH COPYRIGHT
Copyright \(co 2013 Free Software Foundation, Inc.
.br
.na
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
.br
.ad
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
.\" Local variables:
.\" eval: (add-hook 'write-file-hooks 'time-stamp)
.\" time-stamp-start: ".TH [A-Z_][A-Z0-9_.\\-]* [0-9] \""
.\" time-stamp-format: "%:B %:d, %:y"
.\" time-stamp-end: "\""
.\" time-stamp-line-limit: 20
.\" end:

