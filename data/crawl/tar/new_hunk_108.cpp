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
Let the size of the sparse member be @var{size}, its block number be
@var{Bs} and the block number of the next member be @var{Bn}.
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

@node Compression
@section Using Less Space through Compression

