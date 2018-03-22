+\input texinfo    @c -*-texinfo-*-
+@c %**start of header
+@setfilename tar.info
+@settitle The Tar Manual: DRAFT
+@setchapternewpage odd
+@c %**end of header
+
+@c Note: the edition number and date is listed in *two* places; please update.
+@c subtitle and top node; search for !!set
+
+@c Search for comments marked with !! or <<<  (or >>>)
+
+@c <<< CONVENTIONS: this manual refers to "ordinary files" , "directory
+files" (or "directories"), "archive files", "archive members", and
+various I/O devices (which have names and file names).>>>
+
+@c <<< it's "file name" (not filename) unless we are talking about an
+argument, ie. @var{file-name}.  also, you "use" a "file-name argument"
+to "specify" a "file".>>>
+
+@c <<<  @code{tar} is always lower case, in bold. >>>
+
+@c <<< it's "operations of tar", "options to tar" also, it's " @samp{tar
+operations and options as separate concepts. I disagree --- would be a
+mess to explain otherwise
+
+@c <<< (don't forget to comment these out in final draft)  -ringo
+
+@c <<< please dont' change this without sending me e-mail.  some things
+@c are in progress or waiting to be edited in hardcopy.  -ringo
+@c smallbook
+
+@iftex
+@c finalout
+@end iftex
+
+@ifinfo
+This file documents @code{tar}, a utility used to store, backup, and
+transport files.
+
+Copyright (C) 1992 Free Software Foundation, Inc.  DRAFT!
+@c Need to put distribution information here when ready.
+@end ifinfo
+
+@c !!set    edition number and date here
+@titlepage
+@title @code{tar}
+@subtitle The GNU Tape Archiver
+@subtitle Edition 0.01, for @code{tar} Version 1.10
+@subtitle @today{}   
+@c remove preceding today line when ready
+@sp 1
+@subtitle DRAFT
+@c subtitle   insert month here when ready
+
+@author Amy Gorin and Jay Fenlason
+@c <<<best to have hack read this over and see if anything is left he
+@c wrote.  I don't think so.  -ringo>>>>
+
+@page
+@vskip 0pt plus 1filll
+Copyright @copyright{} 1992 Free Software Foundation, Inc.
+
+@sp 2
+This draft is not yet ready for distribution.
+@end titlepage
+
+@ifinfo
+@node Top, Introduction, (dir), (dir)
+@top @code{tar}
+
+This file documents @code{tar}, a utility used to store, backup, and
+transport files.
+
+@c !!set    edition number and date here
+This is DRAFT Edition 0.01 of the @code{tar} documentation, @today{}, for @code{tar}
+version 1.12.
+@end ifinfo
+
+@c <<< The menus need to be gone over, and node names fixed.
+@menu
+* Introduction::                @code{tar}: The GNU Tape Archiver
+* Invoking @code{tar}::         How to invoke @code{tar}
+* Tutorial::                    Getting started
+* Wizardry::                    Some More Advanced Uses for @code{tar}
+* Archive Structure::           The structure of an archive
+* Reading and Writing::         Reading and writing archives
+* Insuring Accuracy::           How to insure the accuracy of an archive
+* Selecting Archive Members::   How to select archive members
+* User Interaction::            How @code{tar} interacts with people.
+* Backups and Restoration::     How to restore files and perform backups
+* Media::                       Using tapes and other archive media
+* Quick Reference::             A quick reference guide to 
+                                  @code{tar} operations and options
+* Data Format Details::         Details of the archive data format
+* Concept Index::               Concept Index
+@end menu
+
+@node Introduction, Invoking @code{tar}, Top, Top
+@chapter @code{tar}: The GNU Tape Archiver
+
+You can use @code{tar} to create an @dfn{archive}---a single file
+which contains other file's contents as well as a listing of those
+files' characteristics.  You can also use @code{tar} to read, add to,
+or manipulate already existing archives.  Because an archive created
+by @code{tar} is capable of preserving file information and directory
+structure, @code{tar} is ideal for performing full and incremental
+backups, as well as for transferring groups of files between disks and
+over networks.
+
+Despite the utility's name, which comes from the words @samp{T(ape)}
+@samp{AR(chiver)}, @code{tar}'s output can be directed to any
+available device.  For instance, @code{tar} archives can be stored in
+a file or sent to another program via a pipe.
+
+@c <<< this menu will conflict with menu above in info mode.  -ringo
+@menu
+* Invoking @code{tar}::         How to invoke @code{tar} and specify arguments.
+* Tutorial::                    An introduction to @code{tar}.
+* Operations::                  What you can use @code{tar} to do.
+* Options::                     How to change the way @code{tar} behaves.
+* Problems::                    Common problems with @code{tar}.
+@end menu
+
+@node Invoking @code{tar}, Tutorial, Introduction, Top
+@chapter How To Invoke @code{tar}
+
+You can use @code{tar} to store files in an archive, to extract them
+from an archive, and to do other types of archive manipulation.  The
+primary argument to @code{tar}, which is called the @dfn{operation},
+specifies which action to take.  The other arguments to @code{tar} are
+either @dfn{options}, which change the way @code{tar} performs an
+operation, or @dfn{file-names}, which specify the files @code{tar} is
+to act on.  The typical @code{tar} command line syntax is:
+
+@example
+@code{tar} @var{operation} [@var{options}...] [@var{file-names}...]
+@end example
+
+Note: You can actually type in arguments in any order.  In this manual
+the operation is always first, the options second and the file-name
+arguments last, to make examples easier to understand.
+
+@menu
+* Argument Functions::          The Functions of Arguments
+* Argument Form::               The Forms of Arguments
+* Old Syntax for Commands::     An Old, but Still Supported, Syntax 
+                                   for @code{tar} Commands
+@end menu
+
+@node Argument Functions, Argument Form, Invoking @code{tar}, Invoking @code{tar}
+@section The Functions of Arguments
+
+The primary argument to @code{tar} is the @dfn{operation}, which
+specifies what @code{tar} does.  @code{tar} can be used to:
+
+@itemize
+@item
+Add files to an existing archive (@samp{+add-file}, @samp+{append} or
+@samp{-r})
+
+@item
+Compare files in an archive with files in the file system
+(@samp{+compare}, @samp{+diff} or @samp{-d})
+@c !!! is diff still working??  --- yes -ringo
+
+@item
+Add archives to another archive (@samp{+add-archive}, @samp{+catenate}
+or @samp{-A})
+@c was +concatenate.   -ringo
+
+@item
+Create an archive (@samp{+create} or @samp{-c})
+
+@item
+Delete files from an archive (@samp{+delete})
+@c -D should have been removed  -ringo
+
+@item
+Extract files from an archive (@samp{+extract}, @samp{+get} or @samp{-x})
+
+@item
+List the files in an archive (@samp{+list} or @samp{-t})
+
+@item
+Update an archive by appending newer versions of already stored files
+(@samp{+update} or @samp{-u})
+@end itemize
+
+@xref{Reading and Writing}, for more information about these
+operations. 
+
+@dfn{Option} arguments to @code{tar} change details of the operation,
+such as archive format, archive name, or level of user interaction.
+You can specify more than one option.  All options are optional.
+
+@dfn{File-name} arguments specify which files (including directory
+files) to archive, extract, delete or otherwise operate on.
+
+If you don't use any file-name arguments, @samp{+add-file},
+@samp{+update} and @samp{+delete} will do nothing.  The other
+operations of @code{tar} will act on defaults.
+
+When you use a file-name argument to specify a directory file,
+@code{tar} acts on all the files in that directory, including
+sub-directories.
+
+@node Argument Form, Old Syntax for Commands, Argument Functions, Invoking @code{tar}
+@section The Forms of Arguments
+
+Most operations of @code{tar} have a single letter form (a single
+letter preceded by a @samp{-}), and at least one mnemonic form (a
+word or abbreviation preceded by a @samp{+}).  The forms are
+identical in function.  For example, you can use either @samp{tar -t}
+or @samp{tar +list} to list the contents of an archive
+
+Options, like operations, have both single letter and mnemonic forms.
+Options, however, may also incorporate an argument.  Single letter
+options are separated from their arguments by a space.  Mnemonic
+options are separated from their arguments by an @samp{=} sign.  For
+example, to create an an archive file named @file{george}, use either
+@samp{tar +create +file=george} or @samp{tar +create -f george}.  Both
+@samp{+file=@var{archive-name}} and @samp{-f @var{archive-name}}
+denote the option to give the archive a non-default name, which in the
+example is @samp{george}.
+
+You can mix single letter and mnemonic forms in the same command.  You
+could type the above example as @samp{tar -c +file=george} or
+@samp{tar +create -f george}.  However, @code{tar} operations and
+options are case sensitive.  You would not type the above example as
+@samp{tar -C +file=george}, because @samp{-C} is an option that causes
+@code{tar} to change directories, not an operation that creates an
+archive.
+
+File-name arguments are the names of files (including directories).
+These names can be specified on the command line or read from a text
+file in the file system (using the @samp{+files-from} option).  Files
+stored in an archive are called @dfn{archive members}.  The operations
+@samp{+delete}, @samp{+extract}, @samp{+list}, @samp{+compare} and
+@samp{+update} take the names of archive members as file-name
+arguments.  The other operations take the names of files in the file
+system.
+
+@code{tar} interprets relative file names as being relative to the
+working directory.  @code{tar} will make all file names relative (by
+removing leading @samp{/}s when archiving or restoring files), unless
+you specify otherwise (using the @samp{+absolute-paths} option).
+@xref{File Name Interpretation}, for more information about
+@samp{+absolute-paths}.
+@c >>> yet another node name that is probably wrong.
+
+@node Old Syntax for Commands,  , Argument Form, Invoking @code{tar}
+@section An Old, but Still Supported, Syntax for @code{tar} Commands
+
+For historical reasons, GNU @code{tar}  also accepts a syntax for
+commands which splits options that include arguments into two parts.
+That syntax is of the form:
+
+@example
+@code{tar} @var{operation}[@var{option-letters}...] [@var{option-arguments}...] [@var{file-names}...]@refill
+@end example
+
+@noindent
+where arguments to the options appear in the same order as the letters
+to which they correspond, and the operation and all the option letters
+appear as a single argument, without separating spaces.
+
+This command syntax is useful because it lets you type the single
+letter forms of the operation and options as a single argument to
+@code{tar}, without writing preceding @samp{-}s or inserting spaces
+between letters.  @samp{tar cv} or @samp{tar -cv} are equivalent to
+@samp{tar -c -v}.
+
+This old style syntax makes it difficult to match option letters with
+their corresponding arguments, and is often confusing.  In the command
+@samp{tar cvbf 20 /dev/rmt0}, for example, @samp{20} is the argument
+for @samp{-b}, @samp{/dev/rmt0} is the argument for @samp{-f}, and
+@samp{-v} does not have a corresponding argument.  The modern
+syntax---@samp{tar -c -v -b 20 -f /dev/rmt0}---is clearer.
+
+@node Tutorial, Wizardry, Invoking @code{tar}, Top
+@chapter Getting Started With @code{tar}
+
+This chapter guides you through some basic examples of @code{tar}
+operations.  In the examples, the lines you should type are preceded
+by a @samp{%}, which is a typical shell prompt.  We use mnemonic forms
+of operations and options in the examples, and in discussions in the
+text, but short forms produce the same result.
+
+@menu
+* Creating Archives::           Creating Archives
+* Extracting Files::            Extracting Files from an Archive 
+* Listing Archive Contents::    Listing the Contents of an Archive
+* Comparing Files::             Comparing Archives with the File System
+* Adding to Archives::          Adding Files to Existing Archives
+* Concatenate::                 Concatenating Archives 
+* Deleting Files::              Deleting Files From an Archive
+@end menu
+
+@node Creating Archives, Listing Archive Contents, Tutorial, Tutorial
+@section Creating Archives
+
+To create a new archive, use @code{tar +create} (or @code{tar -c}).
+You can use options to specify the name and format of the archive (as
+well as other characteristics), and you can use file-name arguments to
+specify which files to put in the archive.  If you don't use any
+options or file-name arguments, @code{tar} will use default values.
+@xref{Creating Example}, for more information about the @samp{+create}
+operation.
+
+@menu
+* Creating Example::            Creating Archives of Files
+* Subdirectory::                Creating an Archive of a Subdirectory
+@end menu
+
+@node Creating Example, Subdirectory, Creating Archives, Creating Archives
+@subsection Creating Archives of Files
+
+This example shows you how to create an archive file in the working
+directory containing other files in the working directory.  The three
+files you archive in this example are called @file{blues},
+@file{folk}, and @file{jazz}.  The archive file is called
+@file{records}.  While the archive in this example is written to the
+file system, it could also be written to any other device.
+
+(If you want to follow along with this and future examples, create a
+directory called @file{practice} containing files called @file{blues},
+@file{folk} and @file{jazz}.  To create the directory, type
+@samp{mkdir practice} at the system prompt.  It will probably be
+easiest to create the files using a text editor, such as Emacs.)
+
+First, change into the directory containing the files you want to
+archive:
+
+@example
+% cd practice
+@end example
+
+@noindent
+@file{~/practice} is now your working directory.
+
+Then, check that the files to be archived do in fact exist in the
+working directory, and make sure there isn't already a file in the
+working directory with the archive name you intend to use.  If you
+specify an archive file name that is already in use, @code{tar} will
+overwrite the old file and its contents will be lost.
+
+To list the names of files in the working directory, type:
+
+@example
+% ls
+@end example
+
+The system responds:
+
+@example
+blues	folk	jazz
+%
+@end example
+
+@noindent
+Then,
+@itemize @bullet
+@item
+Create a new archive (@samp{tar -c} or @samp{tar +create})
+
+@item
+Explicitly name the archive file being created (@samp{-f
+@var{archive-name}} or @samp{+file=@var{archive-name}}).  If you don't
+use this option @code{tar} will write the archive to the default
+storage device, which varies from system to system. 
+@c <<< this syntax may change.  OK now---check before printing  -ringo
+
+@code{tar} interprets archive file names relative to the working
+directory.  Make sure you have write access to the working directory
+before using @code{tar}.  
+
+@item
+Specify which files to put into the archive (@code{tar} interprets
+file names relative to the working directory).  If you don't use any
+@var{file-name} arguments, @code{tar} will archive everything in the
+working directory.
+@end itemize
+
+@noindent
+Type:
+@example
+% tar +create +file=records blues folk jazz 
+@end example
+
+@noindent
+If you now list the contents of the working directory (@samp{ls}), you
+will find the archive file listed as well as the files you saw
+previously.
+
+@example
+% ls
+blues folk jazz records
+%
+@end example
+
+@menu
+* Listing Files::               Listing files in an archive
+* Verbose::                     Using @code{tar} in Verbose Mode
+@end menu
+
+@node Listing Files, Verbose, Creating Example, Creating Example
+@subsubsection Listing files in an archive
+
+You can list the contents of an archive with another operation of
+@code{tar}---@samp{+list} or @samp{-l}.  To list the contents of the
+archive you just created, type:
+
+@example
+% tar +list +file=records
+@end example
+
+@noindent
+@code{tar} will respond:
+
+@example
+blues folk jazz
+@end example
+
+@xref{Listing Archive Contents}, for a more detailed tutorial of the
+@samp{+list} operation.  @xref{Listing Contents}, for more information
+about the @samp{+list} operation.
+
+@node Verbose,  , Listing Files, Creating Example
+@subsubsection Using @code{tar} in Verbose Mode
+
+If you include the @samp{+verbose} or @samp{-v} option on the command
+line, @code{tar} will list the files it is acting on as it is working.
+In verbose mode, the creation example above would appear as:
+@cindex Verbose mode example
+@findex -v (verbose mode example)
+
+@example
+% tar +create +file=records +verbose blues folk jazz
+blues
+folk
+jazz
+@end example
+
+@noindent
+The first line is the command typed in by the user.  The remaining
+lines are generated by @code{tar}.  In the following examples we
+usually use verbose mode, though it is almost never required.
+
+@node Subdirectory, Changing, Creating Example, Creating Archives
+@subsection Creating an Archive of a Subdirectory
+
+You can store a directory in an archive by using the directory name as
+a file-name argument to @code{tar}.  When you specify a directory
+file, @code{tar} archives the directory file and all the files it
+contains.  The names of the directory and the files it contains are
+stored in the archive relative to the current working directory---when
+the directory is extracted they will be written into the file system
+relative to the working directory at that time.
+@c <<< add an xref to +absolute-paths   -ringo
+
+To archive a directory, first move to its superior directory.  If you
+have been following the tutorial, you should type:
+
+@example
+% cd ..
+%
+@end example
+
+Once in the superior directory, specify the subdirectory using a
+file-name argument.  To store the directory file @file{~/practice} in
+the archive file @file{music}, type:
+
+@example
+% tar +create +verbose +file=music practice
+@end example
+
+@noindent
+@code{tar} should respond:
+
+@example
+practice/
+practice/blues
+practice/folk
+practice/jazz
+practice/records
+@end example
+
+Note that @file{~/practice/records}, another archive file, has
+itself been archived.  @code{tar} will accept any file as a file to be
+archived, even an archive file.
+
+@c >>> symbolic links and changing directories are now in main body, not in
+@c >>> tutorial. -ringo
+
+@node Extracting Files
+@section Extracting Files from an Archive
+
+Creating an archive is only half the job---there would be no point in
+storing files in an archive if you couldn't retrieve them.  To extract
+files from an archive, use the @samp{+extract} or @samp{-x} operation.
+
+To extract specific files, use their names as file-name arguments.  If
+you use a directory name as a file-name argument, @code{tar} extracts
+all the files (including subdirectories) in that directory.  If you
+don't use any file-name arguments, @code{tar} extracts all the files
+in the archive.
+
+Note: @code{tar} will extract an archive member into the file system
+without checking to see if there is already a file with the archive
+member's file name.  If there is a file with that name, @code{tar}
+will @strong{overwrite} that file and its contents will be lost.
+@c <<<xref keep-old   -ringo
+
+@node Extracting Specific Files, , ,
+@subsection Extracting Specific Files
+
+To extract specific files, specify them using file-name arguments.
+
+In an example above, you created the archive file
+@file{~/practice/records}, which contained the files @file{blues},
+@file{folk} and @file{jazz} in the @file{practice} directory.  If, for
+some reason, you were to lose one of those text files (@samp{rm
+~/practice/blues}), you could extract it from the archive file.
+
+First, change into the @file{practice} directory.  Then, 
+
+@itemize @bullet
+@item
+Invoke @code{tar} and specify the @samp{+extract} operation
+(@samp{+extract}, @samp{+get} or @samp{-x})
+
+@item
+Specify the archive that the files will be extracted from
+(@samp{+file=@var{archive-name}} or @samp{-f @var{archive-name}})
+
+@item
+Specify the files to extract, using file-name arguments (if you don't
+specify any files, @code{tar} extracts all the archive members)
+@end itemize
+
+@example
+% tar +extract +file=records blues
+@end example
+
+If you list the contents of the directory, you will see that
+@file{blues} is back:
+
+@example
+% ls
+folk
+jazz
+records
+blues
+@end example
+
+@node Extracting Directories, , ,
+@subsection Extracting Directories
+
+To extract a directory and all the files it contains, use the
+directory's name as a file-name argument in conjunction with @samp{tar
+relative to the working directory.
+
+In a previous example you stored the directory @file{~/practice} in
+the archive file @file{~/music}.  If you delete the contents of
+@file{practice}, you can restore them using @code{tar}.
+
+First, change into the @file{practice} subdirectory (@samp{cd
+~/practice}).  Then, remove all the files in @samp{~/practice}
+(@samp{rm *}).  If you list the contents of the directory, you should
+now see that it is empty:
+
+@example
+%ls
+%
+@end example
+
+@noindent Let's try to restore the contents of @file{practice} by extracting
+them from the archive file @file{~/music}:
+
+@example
+tar +extract +file=~/music practice
+@end example
+
+@noindent Now, list the contents of @file{practice} again:
+
+@example
+%ls 
+practice
+@end example
+
+What happened to the files?  When you created @file{~/music}, your
+working directory was your home directory.  When you extracted
+@file{~/music}, your working directory was @file{~/practice}.
+@code{tar} stored the files in @file{practice} relative to your home
+directory, and then extracted them relative to @file{~/practice}.  The
+files are now in a new subdirectory, called
+@file{~/practice/practice}.
+
+To restore your files to their old positions, delete the new directory
+and its contents, and then redo the example above with your home
+directory as the working directory:
+
+@example
+% rm ~/practice/practice/*
+% rmdir practice
+% cd ..
+% tar +extract +file=music practice
+@end example
+
+@noindent (@code{tar} will report that it is unable to create the
+directory @file{~/practice} because it already exists.  This will not
+effect the extraction of the other archive members.)
+
+@node Listing Archive Contents, Adding to Archives, Creating Archives, Tutorial
+@section Listing the Contents of an Archive
+
+Use @samp{+list} or @samp{-t} to print the names of files stored in an
+archive.  If you use file-name arguments with this operation,
+@code{tar} prints the names of the specified files if they are stored
+in the archive.  If you use a directory name as a file-name argument,
+@code{tar} also prints the names of all underlying files, including
+sub-directories.  If you use no file-name arguments, @code{tar} prints
+the names of all the archive members.
+
+You can use @samp{+list} with the @samp{+verbose} option to print
+archive members' attributes (owner, size, etc.).
+
+@menu
+* Listing names::               Listing the names of stored files
+* Additional File Info::        Getting Additional File Information
+* Specific File::               List A Specific File in an Archive
+* Listing Directories::         Listing the Contents of a Stored Directory
+@end menu
+
+@node Listing names, Additional File Info, Listing Archive Contents, Listing Archive Contents
+@subsection Listing the names of stored files
+
+To list the names of files stored in an archive, use the @samp{+list}
+operation of @code{tar}.  
+
+In a previous example, you created the archive @file{~/music}.  To
+list the contents of @file{music}, while in your home directory:
+
+@itemize @bullet
+@item
+List the contents of an archive (@samp{tar -t} or @samp{tar +list})
+
+@item
+Specify the archive to be listed (@samp{-f @var{archive-name}} or
+@samp{+file=@var{archive-name}}) @refill
+@end itemize
+
+Thus:
+
+@example
+% tar +list +file=music
+practice/
+practice/blues
+practice/folk
+practice/jazz
+practice/records
+@end example
+
+@node Additional File Info, Specific File, Listing names, Listing Archive Contents
+@subsection Listing Additional File Information
+
+To get more information when you list the names of files stored in an
+archive, specify the @samp{+verbose} option in conjunction with
+@samp{tar +list}.  @code{tar} will print archive member's file
+protection, owner and group ID, size, and date and time of creation.
+
+For example:
+
+@example
+% tar +list +verbose +file=music
+drwxrwxrwx myself/user 0 May 31 21:49 1990 practice/
+-rw-rw-rw- myself/user 42 May 21 13:29 1990 practice/blues
+-rw-rw-rw- myself/user 62 May 23 10:55 1990 practice/folk
+-rw-rw-rw- myself/user 40 May 21 13:30 1990 practice/jazz
+-rw-rw-rw- myself/user 10240 May 31 21:49 1990 practice/records
+% 
+@end example
+
+Note that when you use @samp{+verbose} with @samp{+list}, @code{tar}
+doesn't print the names of files as they are being acted on, though
+the @samp{+verbose} option will have this effect when used with all
+other operations.
+
+@node Specific File, Comparing Files, Additional File Info, Listing Archive Contents
+@subsection List A Specific File in an Archive
+
+To to see if a particular file is in an archive, use the name of the
+file in question as a file-name argument while specifying the
+@samp{+list} operation.  For example, to see whether the file
+@file{folk} is in the archive file @file{music}, do the following:
+
+@itemize @bullet
+@item
+Invoke @code{tar}, and specify the @samp{+list} operation
+(@samp{+list} or @samp{-t}).
+
+@item
+Specify the archive file to be acted on (@samp{+file
+@var{archive-name}} or @samp{-f @var{archive-name}}).
+
+@item
+Specify the files to look for, by typing their names as file-name
+arguments.  You have to type the file name as it appears in the
+archive (normally, as it is relative to the relative to the directory
+from which the archive was created).  <<< xref absolute-paths -ringo
+@end itemize
+
+Type:
+
+@example
+% tar +list +file=music practice/folk
+@end example
+
+@noindent 
+@code{tar} responds:
+
+@example
+practice/folk
+@end example
+
+@noindent
+If the file were not stored in the archive (for example, the file
+@file{practice/rock}), the example above would look like:
+
+@example
+% tar +list +file=music practice/rock
+tar: practice/rock not found in archive
+@end example
+
+@noindent
+If you had used @samp{+verbose} mode, the example above would look
+like: 
+
+@example
+% tar +list +file=music practice/folk
+-rw-rw-rw- myself/user 62 May 23 10:55 1990 practice/folk
+@end example
+
+@node Listing Directories, , ,
+@subsection Listing the Contents of a Stored Directory
+
+To get information about the contents of an archived directory, use
+the directory name as a file-name argument in conjunction with
+@samp{+list}.  To find out file attributes, include the
+@samp{+verbose} option.
+
+For example, to find out about files in the directory @file{practice},
+in the archive file @file{music}, type:
+
+@example
+% tar +list +file=music practice
+@end example
+
+@noindent @code{tar} responds:
+
+@example
+drwxrwxrwx myself/user 0 May 31 21:49 1990 practice/
+-rw-rw-rw- myself/user 42 May 21 13:29 1990 practice/blues
+-rw-rw-rw- myself/user 62 May 23 10:55 1990 practice/folk
+-rw-rw-rw- myself/user 40 May 21 13:30 1990 practice/jazz
+-rw-rw-rw- myself/user 10240 May 31 21:49 1990 practice/records
+@end example
+
+When you use a directory name as a file-name argument, @code{tar} acts
+on all the files (including sub-directories) in that directory.
+
+@node Comparing Files, , ,
+@section Comparing Files in an Archive with Files in the File System
+
+To compare the attributes of archive members with the attributes of
+their counterparts in the file system, use the @samp{+compare},
+@samp{+diff}, or @samp{-d}) operation.  While you could use
+@samp{+list +verbose} to manually compare some file attributes, it is
+simpler to have @code{tar} itself compare file attributes and report
+back on file differences.
+@c <<<"manually"?  suggestions?  -ringo
+
+The @samp{+compare} operation, as its name implies, compares archive
+members with files of the same name in the file system, and reports
+back differences in file size, mode, owner and modification date.
+@samp{tar +compare} acts only on archive members---it ignores files in
+the file system that are not stored in the archive.  If you give
+@samp{tar +compare} a file-name argument that does not correspond to
+the name of an archive member, @code{tar} responds with an error
+message.
+
+To compare archive members in the archive file @file{records} with
+files in the @file{~/practice} directory, first change into the
+@file{practice} directory.  Then:
+
+@itemize @bullet
+@item
+Invoke @code{tar} and specify the @samp{+compare} operation.
+(@samp{+compare}, @samp{+diff}, or @samp{-d}).
+
+@item
+Specify the archive where the files to be compared are stored
+(@samp{+file=@var{archive-name}} or @samp{-f @var{archive-name}})
+
+@item
+Specify the archive members to be compared.  (In this example you are
+comparing all the archive members in the archive.  Since this is the
+default, you don't need to use any file-name arguments).
+@end itemize
+
+@example
+% tar +compare +file=records
+%
+@end example
+
+@noindent
+While it looks like nothing has happened, @code{tar} has, in fact,
+done the comparison---and found nothing to report.  
+
+Use the @samp{+verbose} option to list the names of archive members as
+they are being compared with their counterparts of the same name in
+the file system:
+
+@example
+% tar +compare +verbose +file=records
+blues
+folk
+jazz
+%
+@end example
+
+@noindent
+If @code{tar} had had anything to report, it would have done so as it
+was comparing each file.  
+
+If you remove the file @file{jazz} from the file system (@samp{rm
+jazz}), and modify the file @file{blues} (for instance, by adding text
+to it with an editor such as Emacs), the above example would look
+like:
+
+@example
+% tar +compare +verbose +file=records
+blues
+blues: mod time differs
+blues: size differs
+folk
+jazz
+jazz: does not exist
+% 
+@end example
+
+Note again that while @samp{tar +compare} reports the names of archive
+members that do not have counterparts in the file system, @samp{tar
+counterparts in the archive.  To demonstrate this, create a file in
+the @file{practice} directory called @file{rock} (using any text
+editor).  The new file appears when you list the directory's contents:
+
+@example
+% ls
+blues	 folk	  records  rock
+@end example
+
+@noindent
+If you type the @samp{+compare} example again, @code{tar} prints the
+following:
+
+@example
+% tar +compare +verbose +file=records
+blues
+blues: mod time differs
+blues: size differs
+folk
+jazz
+jazz: does not exist
+% 
+@end example
+
+@noindent
+@code{tar} ignores the file @file{rock} because @code{tar} is
+comparing archive members to files in the file system, not vice versa.
+
+If you specify @file{rock} explicitly (using a file-name argument),
+@code{tar} prints an error message:
+
+@example
+% tar +compare +verbose +file=records rock
+tar: rock not found in archive
+% 
+@end example
+
+@menu
+* Comparing Directories::       Using Compare on Directories
+@end menu
+
+@node Comparing Directories,  ,  ,  
+@subsubsection Using Compare on Directories
+
+In addition to using @samp{+compare} to compare text files, you can
+use @samp{+compare} to compare directories.  To illustrate this,
+re-create the examples above using your home directory as the working
+directory, and using the archive file @file{~/music} instead of the
+archive file @file{~/practice/records}.
+
+First, change into your home directory (@samp{cd ~}).  Then, try the
+above example using @file{music} as the specified archive file, and
+@file{practice} as a file-name argument.
+
+@example
+% tar +compare +verbose +file=music practice
+@end example
+
+@noindent
+If you have been following along with the tutorial, @code{tar} will
+respond:
+
+@example
+practice
+practice/blues
+practice/blues: mod time differs
+practice/blues: size differs
+practice/folk
+practice/jazz
+practice/jazz: does not exist
+practice/records
+@end example
+
+@node Adding to Archives, Concatenate, Listing Archive Contents, Tutorial
+@section Adding Files to Existing Archives
+
+@c >>> we want people to use the script for backups, so I an not going to
+@c >>> use backups as an explanation in the tutorial.  (people can still
+@c >>> do it if they really want to)  -ringo
+
+While you can use @code{tar} to create a new archive every time you
+want to store a file, it is more sometimes efficient to add files to
+an existing archive.  
+
+To add new files to an existing archive, use the @samp{+add-file},
+@samp{+append} or @samp{-r} operation.  To add newer versions of
+archive members to an archive, use the @samp{+update} or @samp{-u}
+operation.
+
+@menu
+* Append::                      Appending Files to an Archive
+* Update::                      Updating Files in an Archive
+@end menu
+
+@node Append, Update, Adding to Archives, Adding to Archives
+@subsection Appending Files to an Archive
+
+The simplest method of adding a file to an existing archive is the
+@samp{+add-file}, @samp{-r} or @samp{+append} operation, which writes
+files into the archive without regard to whether or not they are
+already archive members.  When you use @samp{+add-file} you must use
+file-name arguments; there is no default.  If you specify a file that
+is already stored in the archive, @code{tar} adds another copy of the
+file to the archive.
+
+If you have been following the previous examples, you should have a
+text file called @file{~/practice/rock} which has not been stored in
+either the archive file @file{~/practice/records}, or the archive file
+@file{~/music}.  To add @file{rock} to @file{records}, first make
+@file{practice} the working directory (@samp{cd practice}).  Then:
+
+@itemize @bullet
+@item
+Invoke @code{tar} and specify the @samp{+add-file} operation
+(@samp{+add-file}, @samp{-r} or @samp{+append})
+
+@item
+Specify the archive to which the file will be added
+(@samp{+file=@var{archive-name}} or @samp{-f @var{archive-name}})
+
+@item
+Specify the files to be added to the archive, using file-name
+arguments
+@end itemize
+
+@noindent
+For example:
+
+@example
+% tar +add-file +file=records rock
+@end example
+
+@noindent
+If you list the archive members in @file{records}, you will see that
+@file{rock} has been added to the archive:
+
+@example
+% tar +list +file=records
+blues
+folk
+jazz
+rock
+@end example
+
+@c <<<  this should be some kind of node.  
+
+You can use @samp{+add-file} to keep archive members current with
+active files.  Because @samp{+add-file} stores a file whether or not
+there is already an archive member with the same file name, you can
+use @samp{+add-file} to add newer versions of archive members to an
+archive.  When you extract the file, only the version stored last will
+wind up in the file system.  Because @samp{tar +extract} extracts
+files from an archive in sequence, and overwrites files with the same
+name in the file system, if a file name appears more than once in an
+archive the last version of the file will overwrite the previous
+versions which have just been extracted.  
+
+If you recall from the examples using @samp{+compare} above,
+@file{blues} was changed after the archive @file{records} was created.
+It is simple, however, to use @samp{+add-file} to add the new version
+of @file{blues} to @file{records}:
+
+@example
+% tar +add-file +verbose +file=records blues
+blues
+@end example
+
+@noindent
+If you now list the contents of the archive, you will obtain the following:
+
+@example
+% tar +list -f records
+blues
+folk
+jazz
+rock
+blues
+@end example
+
+@noindent
+The newest version of @file{blues} is at the end of the archive.  When
+the files in @file{records} are extracted, the newer version of
+@file{blues} (which has the same name as the older) will overwrite the
+version stored first.  When @samp{tar +extract} is finished, only the
+newer version of @file{blues} is in the file system.  <<<xref
+keep-old-files>>>
+
+@node Update,  , Append, Adding to Archives
+@subsection Updating Files in an Archive
+
+To keep archive members up to date with their counterparts of the same
+name in the file system, use the @samp{+update} or @samp{-u}
+operation.  @samp{tar +update} adds a specified file to an archive if
+no file of that name is already stored in the archive.  If there is
+already an archive member with the same name, @code{tar} checks the
+modification date of the archive member, and adds the file only if its
+modification date is later.  If a file is stored in the archive but no
+longer exists under the same name in the active file system,
+@code{tar} reports an error.
+
+You could use the @samp{+add-file} option to keep an archive current,
+but do so you would either have to use the @samp{+compare} and
+@samp{+list} options to determine what files needed to be re-archived
+(which could waste a lot of time), or you would have to be willing to
+add identical copies of already archived files to the archive (which
+could waste a lot of space).
+
+You must use file-name arguments with the @samp{+update}
+operation---if you don't specify any files, @code{tar} won't act on
+any files. 
+
+To see the @samp{+update} option at work, create a new file,
+@file{~/practice/classical}, and modify the file
+@file{~/practice/blues} (you can use a text editor, such as Emacs, to
+do both these things).  Then, with @file{practice} as your working
+directory, invoke @samp{tar +update} using the names of all the files
+in the practice directory as file-name arguments, and specifying the
+@samp{+verbose} option:
+
+@example
+% tar +update +verbose +file=records blues folk rock classical
+blues
+classical
+%
+@end example
+
+@noindent
+Because you specified verbose mode, @code{tar} printed out the names
+of the files it acted on.  If you now list the archive members of the
+archive, (@samp{tar +list +file=records}), you will see that the file
+@file{classical} and another version of the file @file{blues} have
+been added to @file{records}.
+
+Note: When you update an archive, @code{tar} does not overwrite old
+archive members when it stores newer versions of a file.  This is
+because archive members appear in an archive in the order in which
+they are stored, and some archive devices do not allow writing in the
+middle of an archive.
+
+@node Concatenate, Extracting Files Example, Adding to Archives, Tutorial
+@comment  node-name,  next,  previous,  up
+@section Concatenating Archives 
+
+To concatenate archive files, use @samp{tar +concatenate} or @samp{tar
+-A}.  This operation adds other archives to the end of an archive.
+While it may seem intuitive to concatenate archives using @code{cat},
+the utility for adding files together, archive files which have been
+"catted" together cannot be read properly by @code{tar}.  Archive
+files incorporate an end of file marker---if archives are concatenated
+using @code{cat}, this marker will appear before the end of the new
+archive.  This will interfere with operations on that archive.
+@c <<<xref ignore-zeros>>>
+
+In earlier examples, you stored the @file{~/practice} directory in an
+archive file, @file{~/music}.  If you have been following the
+examples, you have since changed the contents of the @file{~/practice}
+directory.  There is a current version of the files in the
+@file{practice} directory, however, stored in the archive file
+@file{~/practice/records}.
+
+To store current versions of the files in @file{practice} in the
+archive file @file{music}, you can use @samp{tar +concatenate} to add
+the archive file @file{~/practice/records} to @file{music}.  First,
+make sure you are in your home directory (@samp{cd ~}).  Then:
+
+@itemize @bullet
+@item
+Invoke @code{tar}, and specify the @samp{+concatenate} operation
+(@samp{-A} or @samp{+concatenate})
+
+@item
+Specify the archive file to be added to
+(@samp{+file=@var{archive-name}} or @samp{-f @var{archive-name}})
+
+@item
+Specify the archives to be added, using file-name arguments.  In this
+case, the file-name arguments are, unusually, the names of archive
+files.  (Remember to include the path in the archive name, if the
+archive file is not in your working directory.)
+@end itemize
+
+@example
+% cd ~
+% tar +concatenate +file=music practice/records
+@end example
+
+If you now list the contents of the @file{music}, you see it now
+contains the archive members of @file{practice/records}:
+
+@example
+%tar +list +file=music
+blues
+folk
+jazz
+rock
+blues
+practice/blues
+practice/folk
+practice/jazz
+practice/rock
+practice/blues
+practice/classical
+@end example
+
+@node Deleting Files,  ,  , Tutorial
+@comment  node-name,  next,  previous,  up
+@section Deleting Files From an Archive
+
+In some instances, you may want to remove some files from an archive
+stored on disk
+
+@quotation
+@emph{Caution:} you should never delete files from an archive stored
+on tape---because of the linear nature of tape storage, doing this is
+likely to scramble the archive.
+@end quotation
+
+To remove archive members from an archive, use the @samp{+delete}
+operation.  You must specify the names of files to be removed as
+file-name arguments.  All versions of the named file are removed from
+the archive.  
+
+Execution of the @samp{+delete} operation can be very slow.
+
+To delete all versions of the file @file{blues} from the archive
+@file{records} in the @file{practice} directory, make sure you are in
+that directory, and then:
+
+@itemize @bullet
+@item
+List the contents of the archive file @file{records} (see above for
+the steps involved) to insure that the file(s) you wish to delete are
+stored in the archive.  (This step is optional)
+
+@item
+Invoke @code{tar} and specify the @samp{+delete} operation
+(@samp{+delete}).
+
+@item
+Specify the name of the archive file that the file(s) will be deleted
+from (@samp{+file=@var{archive-name}} or @samp{-f @var{archive-name}})
+
+@item
+Specify the files to be deleted, using file-name arguments.
+
+@item
+List the contents of the archive file again---note that the files have
+been removed.  (this step is also optional)
+@end itemize
+
+@example
+% tar +list +file=records
+blues
+folk
+jazz
+% tar +delete +file=records blues
+% tar +list +file=records
+folk
+jazz
+% 
+@end example
+
+@node Wizardry, Archive Structure, Tutorial, Top
+@chapter Wizardry
+
+<<<This section needs to be written  -ringo
+
+@strong{To come:} using Unix file linking capability to recreate directory
+structures---linking files into one subdirectory and then tarring that
+directory.   
+
+@strong{to come:} nice hairy example using absolute-paths, newer, etc.
+
+
+Piping one @code{tar} to another is an easy way to copy a directory's
+contents from one disk to another, while preserving the dates, modes, owners
+and link-structure of all the files therein.
+
+@example
+cd sourcedirectory; tar cf - . | (cd targetdir; tar xf -)
+@end example
+
+@noindent
+or
+
+<<<  the following using standard input/output correct??
+@example
+cd sourcedirectory; tar +create +file=- . | (cd targetdir; tar +extract +file=-)
+@end example
+
+@noindent
+
+Archive files can be used for transporting a group of files from one system
+to another:  put all relevant files into an archive on one computer system,
+transfer the archive to another, and extract the contents there. The basic
+transfer medium might be magnetic tape, Internet FTP, or even electronic
+mail (though you must encode the archive with @code{uuencode} in order to
+transport it properly by mail).  Both machines do not have to use the same
+operating system, as long as they both support the @code{tar} program.
+@findex uuencode
+<<< mention uuencode on a paragraph of its own
+
+<<<<<end construction>>>>>
+
+@node Archive Structure, Reading and Writing, Wizardry, Top
+@chapter The Structure of an Archive
+
+While an archive may contain many files, the archive itself is a
+single ordinary file.  Like any other file, an archive file can be
+written to a storage device such as a tape or disk, sent through a
+pipe or over a network, saved on the active file system, or even
+stored in another archive.  An archive file is not easy to read or
+manipulate without using the @code{tar} utility or Tar mode in Emacs.
+
+
+Physically, an archive consists of a series of file entries terminated
+by an end-of-archive entry, which consists of 512 zero bytes.  A file
+entry usually describes one of the files in the archive (an
+@dfn{archive member}), and consists of a file header and the contents
+of the file.  File headers contain file names and statistics, checksum
+information which @code{tar} uses to detect file corruption, and
+information about file types. 
+
+More than archive member can have the same file name.  One way this
+situation can occur is if more than one version of a file has been
+stored in the archive.  For information about adding new versions of a
+file to an archive, @pxref{Modifying}.
+
+In addition to entries describing archive members, an archive may contain
+entries which @code{tar} itself uses to store information.
+@xref{Archive Label}, for an example of such an archive entry.
+
+@menu
+* Old Style File Information::  Old Style File Information
+* Archive Label::               
+* Format Variations::           
+@end menu
+
+@node Old Style File Information, Archive Label, Archive Structure, Archive Structure
+@section  Old Style File Information
+@cindex Format, old style
+@cindex Old style format
+@cindex Old style archives
+
+Archives record not only an archive member's contents, but also its
+file name or names, its access permissions, user and group, size in
+bytes, and last modification time.  Some archives also record the file
+names in each archived directory, as well as other file and directory
+information.
+
+Certain old versions of @code{tar} cannot handle additional
+information recorded by newer @code{tar} programs.  To create an
+archive which can be read by these old versions, specify the
+@samp{+old-archive} option in conjunction with the @samp{tar +create}
+operation.  When you specify this option, @code{tar} leaves out
+information about directories, pipes, fifos, contiguous files, and
+device files, and specifies file ownership by group and user ids
+instead of names.
+
+The @samp{+old-archive} option is needed only if the archive must be
+readable by an older tape archive program which cannot handle the new format.
+Most @code{tar} programs do not have this limitation, so this option
+is seldom needed.
+
+@table @samp
+@item +old-archive
+@itemx -o
+@itemx +old
+@itemx +portable
+@c has portability been changed to portable?
+Creates an archive that can be read by an old @code{tar} program.
+Used in conjunction with the @samp{tar +create} operation.
+@end table
+
+@node Archive Label, Format Variations, Old Style File Information, Archive Structure
+@section Including a Label in the Archive
+@cindex Labeling an archive
+@cindex Labels on the archive media
+
+@c !! Should the arg to +label be a quoted string??  no - ringo
+To avoid problems caused by misplaced paper labels on the archive
+media, you can include a @dfn{label} entry---an archive member which
+contains the name of the archive---in the archive itself.  Use the
+@samp{+label=@var{archive-label}} option in conjunction with the
+@samp{+create} operation to include a label entry in the archive as it
+is being created. 
+
+If you create an archive using both @samp{+label=@var{archive-label}}
+and @samp{+multi-volume}, each volume of the archive will have an
+archive label of the form @samp{@var{archive-label} Volume @var{n}},
+where @var{n} is 1 for the first volume, 2 for the next, and so on.
+@xref{Multi-Volume Archives}, for information on creating multiple
+volume archives.
+
+If you extract an archive using @samp{+label=@var{archive-label}},
+@code{tar} will print an error if the archive label doesn't match the
+@var{archive-label} specified, and will then not extract the archive.
+You can include a regular expression in @var{archive-label}, in this
+case only.   
+@c >>> why is a reg. exp. useful here?  (to limit extraction to a
+@c >>>specific group?  ie for multi-volume???  -ringo
+
+To find out an archive's label entry (or to find out if an archive has
+a label at all), use @samp{tar +list +verbose}.  @code{tar} will print the
+label first, and then print archive member information, as in the
+example below:
+
+@example
+% tar +verbose +list +file=iamanarchive
+V--------- 0/0        0 Mar  7 12:01 1992 iamalabel--Volume Header--
+-rw-rw-rw- ringo/user 40 May 21 13:30 1990 iamafilename
+@end example
+
+@table @samp
+@item +label=@var{archive-label}
+@itemx -V @var{archive-label}
+Includes an @dfn{archive-label} at the beginning of the archive when
+the archive is being created (when used in conjunction with the
+@samp{tar +create} operation).  Checks to make sure the archive label
+matches the one specified (when used in conjunction with the @samp{tar
+@end table
+@c was +volume
+
+@node Format Variations,  , Archive Label, Archive Structure
+@section Format Variations
+@cindex Format Parameters
+@cindex Format Options
+@cindex Options to specify archive format.
+
+Format parameters specify how an archive is written on the archive
+media.  The best choice of format parameters will vary depending on
+the type and number of files being archived, and on the media used to
+store the archive.
+
+To specify format parameters when accessing or creating an archive,
+you can use the options described in the following sections.  If you
+do not specify any format parameters, @code{tar} uses default
+parameters.  You cannot modify a compressed archive.  If you create an
+archive with the @samp{+block-size} option specified (@pxref{Blocking
+Factor}), you must specify that block-size when operating on the
+archive.  @xref{Matching Format Parameters}, for other examples of
+format parameter considerations.
+
+
+@menu
+* Multi-Volume Archives::       
+* Sparse Files::                
+* Blocking Factor::             
+* Compressed Archives::         
+@end menu
+
+@node Multi-Volume Archives, Sparse Files, Format Variations, Format Variations
+@subsection Archives Longer than One Tape or Disk
+@cindex Multi-volume archives
+
+To create an archive that is larger than will fit on a single unit of
+the media, use the @samp{+multi-volume} option in conjunction with the
+@samp{tar +create} operation (@pxref{Creating Archives}).  A
+@dfn{multi-volume} archive can be manipulated like any other archive
+(provided the @samp{+multi-volume} option is specified), but is stored
+on more than one tape or disk.
+
+When you specify @samp{+multi-volume}, @code{tar} does not report an
+error when it comes to the end of an archive volume (when reading), or
+the end of the media (when writing).  Instead, it prompts you to load
+a new storage volume.  If the archive is on a magnetic tape, you
+should change tapes when you see the prompt; if the archive is on a
+floppy disk, you should change disks; etc.
+
+You can read each individual volume of a multi-volume archive as if it
+were an archive by itself.  For example, to list the contents of one
+volume, use @samp{tar +list}, without @samp{+multi-volume} specified.
+To extract an archive member from one volume (assuming it is described
+that volume), use @samp{tar +extract}, again without
+@samp{+multi-volume}.
+
+If an archive member is split across volumes (ie. its entry begins on
+one volume of the media and ends on another), you need to specify
+@samp{+multi-volume} to extract it successfully.  In this case, you
+should load the volume where the archive member starts, and use
+@samp{tar +extract +multi-volume}---@code{tar} will prompt for later
+volumes as it needs them.  @xref{Extracting From Archives} for more
+information about extracting archives.
+
+@samp{+info-script=@var{program-file}} is like @samp{+multi-volume},
+except that @code{tar} does not prompt you directly to change media
+volumes when a volume is full---instead, @code{tar} runs commands you
+have stored in @var{program-file}.  This option can be used to
+broadcast messages such as @samp{someone please come change my tape}
+when performing unattended backups.  When @var{program-file} is done,
+@code{tar} will assume that the media has been changed.
+
+
+<<< There should be a sample program here, including an exit before
+<<< end.
+
+@table @samp
+@item +multi-volume
+@itemx -M
+Creates a multi-volume archive, when used in conjunction with
+@samp{tar +create}.  To perform any other operation on a multi-volume
+archive, specify @samp{+multi-volume} in conjunction with that
+operation.
+
+@item +info-script=@var{program-file}
+@itemx -F @var{program-file}
+Creates a multi-volume archive via a script. Used in conjunction with
+@samp{tar +create}.
+@end table
+
+@node Sparse Files, Blocking Factor, Multi-Volume Archives, Format Variations
+@subsection Archiving Sparse Files
+@cindex Sparse Files
+
+A file is sparse if it contains blocks of zeros whose existance is
+recorded, but that have no space allocated on disk.  When you specify
+the @samp{+sparse} option in conjunction with the @samp{+create}
+operation, @code{tar} tests all files for sparseness while archiving.
+If @code{tar} finds a file to be sparse, it uses a sparse
+representation of the file in the archive.  @xref{Creating Archives},
+for more information about creating archives.
+
+@samp{+sparse} is useful when archiving files, such as dbm files,
+likely to contain many nulls.  This option dramatically
+decreases the amount of space needed to store such an archive.  
+
+@quotation
+@strong{Please Note:} Always use @samp{+sparse} when performing file
+system backups, to avoid archiving the expanded forms of files stored
+sparsely in the system.@refill
+
+Even if your system has no no sparse files currently, some may be
+created in the future.  If you use @samp{+sparse} while making file
+system backups as a matter of course, you can be assured the archive
+will always take no more space on the media than the files take on
+disk (otherwise, archiving a disk filled with sparse files might take
+hundreds of tapes).@refill
+<<< xref incremental when node name is set.
+@end quotation
+
+@code{tar} ignores the @samp{+sparse} option when reading an archive.
+
+@table @samp
+@item +sparse
+@itemx -S
+Files stored sparsely in the file system are represented sparsely in
+the archive.  Use in conjunction with write operations.
+@end table  
+
+@node Blocking Factor, Compressed Archives, Sparse Files, Format Variations
+@subsection The Blocking Factor of an Archive
+@cindex Blocking Factor
+@cindex Block Size
+@cindex Number of records per block
+@cindex Number of bytes per block
+@cindex Bytes per block
+@cindex Records per block
+
+The data in an archive is grouped into records, which are 512 bytes.
+Records are read and written in whole number multiples called
+@dfn{blocks}.  The number of records in a block (ie. the size of a
+block in units of 512 bytes) is called the @dfn{blocking factor}.  The
+@samp{+block-size=@var{number}} option specifies the blocking factor
+of an archive.  The default blocking factor is typically 20 (ie.@:
+10240 bytes), but can be specified at installation.  To find out the
+blocking factor of an existing archive, use @samp {tar +list
+
+Blocks are seperated by gaps, which waste space on the archive media. 
+If you are archiving on magnetic tape, using a larger blocking factor
+(and therefore larger blocks) provides faster throughput and allows
+you to fit more data on a tape (because there are fewer gaps). If you
+are archiving on cartridge, a very large blocking factor (say 126 or
+more) greatly increases performance. A
+smaller blocking factor, on the other hand, may be usefull when
+archiving small files, to avoid archiving lots of nulls as @code{tar}
+fills out the archive to the end of the block. In general, the ideal block size
+depends on the size of the inter-block gaps on the tape you are using,
+and the average size of the files you are archiving.  @xref{Creating
+Archives}, for information on writing archives.
+
+Archives with blocking factors larger than 20 cannot be read by very
+old versions of @code{tar}, or by some newer versions of @code{tar}
+running on old machines with small address spaces.  With GNU
+@code{tar}, the blocking factor of an archive is limited only by the
+maximum block size of the device containing the archive, or by the
+amount of available virtual memory.
+
+If you use a non-default blocking factor when you create an archive,
+you must specify the same blocking factor when you modify that
+archive.  Some archive devices will also require you to specify the
+blocking factor when reading that archive, however this is not
+typically the case.  Usually, you can use @samp{tar +list} without
+specifying a blocking factor---@code{tar} reports a non-default block
+size and then lists the archive members as it would normally.  To
+extract files from an archive with a non-standard blocking factor
+(particularly if you're not sure what the blocking factor is), you can
+usually use the {+read-full-blocks} option while specifying a blocking
+factor larger then the blocking factor of the archive (ie. @samp{tar
+for more information on the @samp{+list} operation.
+@xref{read-full-blocks} for a more detailed explanation of that
+option.
+
+@table @samp
+@item +block-size=@var{number}
+@itemx -b @var{number}
+Specifies the blocking factor of an archive.  Can be used with any
+operation, but is usually not necessary with @samp{tar +list}.
+@end table
+
+@node Compressed Archives,  , Blocking Factor, Format Variations
+@subsection Creating and Reading Compressed Archives
+@cindex Compressed archives
+@cindex Storing archives in compressed format
+
+@samp{+compress} indicates an archive stored in compressed format.
+The @samp{+compress} option is useful in saving time over networks and
+space in pipes, and when storage space is at a premium.
+@samp{+compress} causes @code{tar} to compress when writing the
+archive, or to uncompress when reading the archive.
+
+To perform compression and uncompression on the archive, @code{tar}
+runs the @code{compress} utility.  @code{tar} uses the default
+compression parameters; if you need to override them, avoid the
+@samp{+compress} option and run the @code{compress} utility
+explicitly.  It is useful to be able to call the @code{compress}
+utility from within @code{tar} because the @code{compress} utility by
+itself cannot access remote tape drives.
+
+The @samp{+compress} option will not work in conjunction with the
+@samp{+multi-volume} option or the @samp{+add-file}, @samp{+update},
+@samp{+add-file} and @samp{+delete} operations.  @xref{Modifying}, for
+more information on these operations.
+
+If there is no compress utility available, @code{tar} will report an
+error.
+
+@samp{+compress-block} is like @samp{+compress}, but when used in
+conjunction with @samp{+create} also causes @code{tar} to pad the last
+block of the archive out to the next block boundary as it is written.
+This is useful with certain devices which require all write operations
+be a multiple of a specific size.
+
+@quotation
+@strong{Please Note:} The @code{compress} program may be covered by a patent,
+and therefore we recommend you stop using it.  We hope to have a
+different compress program in the future.  We may change the name of
+this option at that time.
+@end quotation
+
+@table @samp
+@item +compress
+@itemx +uncompress
+@itemx -z
+@itemx -Z
+When this option is specified, @code{tar} will compress (when writing
+an archive), or uncompress (when reading an archive).  Used in
+conjunction with the @samp{+create}, @samp{+extract}, @samp{+list} and
+@samp{+compare} operations.
+
+@item +compress-block
+@itemx -z -z
+Acts like @samp{+compress}, but pads the archive out to the next block
+boundary as it is written when used in conjunction with the
+@samp{+create} operation.
+@end table
+
+@c >>> MIB -- why not use -Z instead of -z -z ?  -ringo
+
+@node Reading and Writing, Insuring Accuracy, Archive Structure, Top
+@chapter Reading and Writing Archives
+
+The @samp{+create} operation writes a new archive, and the
+@samp{+extract} operation reads files from an archive and writes them
+into the file system.  You can use other @code{tar} operations to
+write new information into an existing archive (adding files to it,
+adding another archive to it, or deleting files from it), and you can
+read a list of the files in an archive without extracting it using the
+@samp{+list} operation.
+
+@menu
+* Archive Name::                The name of an archive 
+* Creating in Detail::          Creating in detail
+* Modifying::                   Modifying archives
+* Listing Contents::            Listing the contents of an archive
+* Extracting From Archives::    Extracting files from an archive 
+@end menu
+
+@node Archive Name, Creating in Detail, Reading and Writing, Reading and Writing
+@section The Name of an Archive 
+@cindex Naming an archive
+@cindex Archive Name
+@cindex Directing output
+@cindex Where is the archive?
+
+An archive can be saved as a file in the file system, sent through a
+pipe or over a network, or written to an I/O device such as a tape or
+disk drive.  To specify the name of the archive, use the
+@samp{+file=@var{archive-name}} option.
+
+An archive name can be the name of an ordinary file or the name of an
+I/O device.  @code{tar} always needs an archive name---if you do not
+specify an archive name, the archive name comes from the environment
+variable @code{TAPE} or, if that variable is not specified, a default
+archive name, which is usually the name of tape unit zero (ie.
+/dev/tu00).
+
+If you use @file{-} as an @var{archive-name}, @code{tar} reads the
+archive from standard input (when listing or extracting files), or
+writes it to standard output (when creating an archive).  If you use
+@file{-} as an @var{archive-name} when modifying an archive,
+@code{tar} reads the original archive from its standard input and
+writes the entire new archive to its standard output.  
+
+@c >>> MIB--does standard input and output redirection work with all
+@c >>> operations?  
+@c >>> need example for standard input and output (screen and keyboard?)
+
+@cindex Standard input and output
+@cindex tar to standard input and output
+
+To specify an archive file on a device attached to a remote machine,
+use the following:
+
+@example
+@end example
+
+@noindent
+@code{tar} will complete the remote connection, if possible, and
+prompt you for a username and password.  If you use
+@samp{+file=@@@var{hostname}:/@var{dev}/@var{file-name}}, @code{tar}
+will complete the remote connection, if possible, using your username
+as the username on the remote machine.  
+
+@c >>>MIB --- is this clear?
+
+@table @samp
+@item +file=@var{archive-name}
+@itemx -f @var{archive-name}
+Names the archive to create or operate on.  Use in conjunction with
+any operation.
+@end table
+
+@node Creating in Detail, Modifying, Archive Name, Reading and Writing
+@section Creating in Detail
+@c operations should probably have examples, not tables.
+@cindex Writing new archives
+@cindex Archive creation
+
+To create an archive, use @samp{tar +create}.  To name the archive,
+use @samp{+file=@var{archive-name}} in conjunction with the
+@samp{+create} operation (@pxref{Archive Name}).  If you do not name
+the archive, @code{tar} uses the value of the environment variable
+@code{TAPE} as the file name for the archive, or, if that is not
+available, @code{tar} uses a default archive name, usually that for tape
+unit zero.  @xref{Archive Name}, for more information about specifying
+an archive name.
+
+The following example creates an archive named @file{stooges},
+containing the files @file{larry}, @file{moe} and @file{curley}:
+
+@example
+tar +create +file=stooges larry moe curley
+@end example
+
+If you specify a directory name as a file-name argument, @code{tar}
+will archive all the files in that directory.  The following example
+creates an archive named @file{hail/hail/fredonia}, containing the
+contents of the directory @file{marx}:
+
+@example
+tar +create +file=hail/hail/fredonia marx
+@end example
+
+If you don't specify files to put in the archive, @code{tar} archives
+all the files in the working directory.  The following example creates
+an archive named @file{home} containing all the files in the working
+directory:
+
+@example
+tar +create +file=home
+@end example
+
+@xref{File Name Lists}, for other ways to specify files to archive.
+
+Note: In the example above, an archive containing all the files in the
+working directory is being written to the working directory.  GNU
+@code{tar} stores files in the working directory in an archive which
+is itself in the working directory without falling into an infinite
+loop.  Other versions of @code{tar} may fall into this trap.
+
+@node Modifying, Listing Contents, Creating in Detail, Reading and Writing
+@section Modifying Archives
+@cindex Modifying archives
+
+Once an archive is created, you can add new archive members to it, add
+the contents of another archive, add newer versions of members already
+stored, or delete archive members already stored.  
+
+To find out what files are already stored in an archive, use @samp{tar
+
+@menu
+* Adding Files::                
+* Appending Archives::          
+* Deleting Archive Files::      Deleting Files From an Archive
+* Matching Format Parameters::  
+@end menu
+
+@node Adding Files, Appending Archives, Modifying, Modifying
+@subsection Adding Files to an Archive
+@cindex Adding files to an archive
+@cindex Updating an archive
+
+To add files to an archive, use @samp{tar +add-file}.  The archive to
+be added to must already exist and be in proper archive format (which
+normally means it was created previously using @code{tar}).  If the
+archive was created with a different block size than now specified,
+@code{tar} will report an error (@pxref{Blocking Factor}).  If the
+archive is not a valid @code{tar} archive, the results will be
+unpredictable.  You cannot add files to a compressed archive, however
+you can add files to the last volume of a multi-volume archive.
+@xref{Matching Format Parameters}.
+
+The following example adds the file @file{shemp} to the archive
+@file{stooges} created above:
+
+@example
+tar +add-file +file=stooges shemp
+@end example
+
+You must specify the files to be added; there is no default.
+
+@samp{tar +update} acts like @samp{tar +add-file}, but does not add
+files to the archive if there is already a file entry with that name
+in the archive that has the same modification time.  
+
+Both @samp{+update} and @samp{+add-file} work by adding to the end of
+the archive.  When you extract a file from the archive, only the
+version stored last will wind up in the file system.  Because
+@samp{tar +extract} extracts files from an archive in sequence, and
+overwrites files with the same name in the file system, if a file name
+appears more than once in an archive the last version of the file will
+overwrite the previous versions which have just been extracted.  You
+should avoid storing older versions of a file later in the archive.
+
+Note:  @samp{+update} is not suitable for performing backups, because
+it doesn't change directory content entries, and because it lengthens
+the archive every time it is used.  
+@c <<< xref to scripted backup, listed incremental, for info on backups.
+
+@node Appending Archives, Deleting Archive Files, Adding Files, Modifying
+@subsection Appending One Archive's Contents to Another Archive
+@cindex Adding archives to an archive
+@cindex Concatenating Archives
+
+To append copies of an archive or archives to the end of another
+archive, use @samp{tar +add-archive}.  The source and target archives
+must already exist and have been created using compatable format
+parameters (@pxref{Matching Format Parameters}).
+
+@code{tar} will stop reading an archive if it encounters an
+end-of-archive marker.  The @code{cat} utility does not remove
+end-of-archive markers, and is therefore unsuitable for concatenating
+archives.  @samp{tar +add-archive} removes the end-of-archive marker
+from the target archive before each new archive is appended.
+@c <<< xref ignore-zeros
+
+You must specify the source archives using
+@samp{+file=@var{archive-name}} (@pxref{Archive Name}).  If you do not
+specify the target archive , @code{tar} uses the value of the
+environment variable @code{TAPE}, or, if this has not been set, the
+default archive name.
+
+The following example adds the contents of the archive
+@file{hail/hail/fredonia} to the archive @file{stooges} (both archives
+were created in examples above):
+
+@example
+tar +add-archive +file=stooges hail/hail/fredonia
+@end example
+
+If you need to retrieve files from an archive that was added to using
+the @code{cat} utility, use the @samp{+ignore-zeros} option
+(@pxref{Archive Reading Options}).
+
+@node Deleting Archive Files, Matching Format Parameters, Appending Archives, Modifying
+@subsection Deleting Files From an Archive
+@cindex Deleting files from an archive
+@cindex Removing files from an archive
+
+To delete archive members from an archive, use @samp{tar +delete}.
+You must specify the file names of the members to be deleted.  All
+archive members with the specified file names will be removed from the
+archive.
+
+The following example removes the file @file{curley} from the archive
+@file{stooges}:
+
+@example
+tar +delete +file=stooges curley
+@end example
+
+You can only use @samp{tar +delete} on an archive if the archive
+device allows you to write to any point on the media.
+
+@quotation
+@strong{Warning:} Don't try to delete an archive member from a
+magnetic tape, lest you scramble the archive.  There is no safe way
+(except by completely re-writing the archive) to delete files from
+most kinds of magnetic tape.
+@end quotation
+
+@c <<< MIB -- how about automatic detection of archive media?  give error
+@c <<< unless the archive device is either an ordinary file or different
+@c <<< input and output (+file=-).
+
+@node Matching Format Parameters,  , Deleting Archive Files, Modifying
+@subsection Matching the Format Parameters
+
+Some format parameters must be taken into consideration when modifying
+an archive:
+
+Compressed archives cannot be modified.  
+
+You have to specify the block size of the archive when modifying an
+archive with a non-default block size.
+
+Multi-volume archives can be modified like any other archive.  To add
+files to a multi-volume archive, you need to only mount the last
+volume of the archive media (and new volumes, if needed).  For all
+other operations, you need to use the entire archive.  
+
+If a multi-volume archive was labeled using @samp{+label}
+(@pxref{Archive Label}) when it was created, @code{tar} will not
+automatically label volumes which are added later.  To label
+subsequent volumes, specify @samp{+label=@var{archive-label}} again in
+conjunction with the @samp{+add-file}, @samp{+update} or
+@samp{+add-archive} operation.
+@cindex Labelling multi-volume archives
+@c <<< example
+
+@c <<< xref somewhere, for more information about format parameters.
+
+@node Listing Contents, Extracting From Archives, Modifying, Reading and Writing
+@section Listing the Contents of an Archive
+@cindex Names of the files in an archive
+@cindex Archive contents, list of
+@cindex Archive members, list of
+
+@samp{tar +list} prints a list of the file names of the archive
+members on the standard output.  If you specify @var{file-name}
+arguments on the command line (or using the @samp{+files-from} option,
+@pxref{File Name Lists}), only the files you specify will be listed,
+and only if they exist in the archive.  Files not specified will be
+ignored, unless they are under a specific directory.
+
+If you include the @samp{+verbose} option, @code{tar} prints an
+@samp{ls -l} type listing for the archive.  @pxref{Additional
+Information}, for a description of the @samp{+verbose} option.
+
+If the blocking factor of the archive differs from the default,
+@code{tar} reports this.  @xref{Blocking Factor}.
+
+@xref{Archive Reading Options} for a list of options which can be used
+to modify @samp{+list}'s operation.  
+
+This example prints a list of the archive members of the archive
+@file{stooges}:
+
+@example
+tar +list +file=stooges
+@end example
+
+@noindent
+@code{tar} responds:
+
+@example
+larry
+moe
+shemp
+marx/julius
+marx/alexander
+marx/karl
+@end example
+
+This example generates a verbose list of the archive members of the
+archive file @file{dwarves}, which has a blocking factor of two:
+
+@example
+tar +list -v +file=blocks
+@end example
+
+@noindent
+@code{tar} responds:
+
+@example
+tar: Blocksize = 2 records
+-rw------- ringo/user 42 May   1 13:29 1990 .bashful
+-rw-rw-rw- ringo/user 42 Oct   4 13:29 1990 doc
+-rw-rw-rw- ringo/user 42 Jul  20 18:01 1969 dopey
+-rw-rw---- ringo/user 42 Nov  26 13:42 1963 grumpy
+-rw-rw-rw- ringo/user 42 May   5 13:29 1990 happy
+-rw-rw-rw- ringo/user 42 May   1 12:00 1868 sleepy
+-rw-rw-rw- ringo/user 42 Jul   4 17:29 1776 sneezy
+@end example
+
+@node Extracting From Archives,  , Listing Contents, Reading and Writing
+@section Extracting Files from an Archive 
+@cindex Extraction
+@cindex Retrieving files from an archive
+@cindex Resurrecting files from an archive
+
+To read archive members from the archive and write them into the file
+system, use @samp{tar +extract}.  The archive itself is left
+unchanged.
+
+If you do not specify the files to extract, @code{tar} extracts all
+the files in the archive.  If you specify the name of a directory as a
+file-name argument, @code{tar} will extract all files which have been
+stored as part of that directory.  If a file was stored with a
+directory name as part of its file name, and that directory does not
+exist under the working directory when the file is extracted,
+@code{tar} will create the directory.  @xref{Selecting Archive
+Members}, for information on specifying files to extract.
+
+The following example shows the extraction of the archive
+@file{stooges} into an empty directory:
+
+@example
+tar +extract +file=stooges
+@end example
+
+@noindent
+Generating a listing of the directory (@samp{ls}) produces:
+
+@example
+larry
+moe
+shemp
+marx
+@end example
+
+@noindent
+The subdirectory @file{marx} contains the files @file{julius},
+@file{alexander} and @file{karl}.
+
+If you wanted to just extract the files in the subdirectory
+@file{marx}, you could specify that directory as a file-name argument
+in conjunction with the @samp{+extract} operation:
+
+@example
+tar +extract +file=stooges marx
+@end example
+
+@quotation
+@strong{Warning:} Extraction can overwrite files in the file system.
+To avoid losing files in the file system when extracting files from
+the archive with the same name, use the @samp{+keep-old-files} option
+(@pxref{File Writing Options}).
+@end quotation
+
+If the archive was created using @samp{+block-size}, @samp{+compress}
+or @samp{+multi-volume}, you must specify those format options again
+when extracting files from the archive (@pxref{Format Variations}).
+
+@menu
+* Archive Reading Options::     
+* File Writing Options::        
+* Scarce Disk Space::           Recovering From Scarce Disk Space
+@end menu
+
+@node Archive Reading Options, File Writing Options, Extracting From Archives, Extracting From Archives
+@subsection Options to Help Read Archives
+@cindex Options when reading archives
+@cindex Reading incomplete blocks
+@cindex Blocks, incomplete
+@cindex End of archive markers, ignoring
+@cindex Ignoring end of archive markers
+@cindex Large lists of file names on small machines
+@cindex Small memory 
+@cindex Running out of space
+
+@c <<< each option wants its own node.  summary after menu
+
+Normally, @code{tar} will request data in full block increments from
+an archive storage device.  If the device cannot return a full block,
+@code{tar} will report an error.  However, some devices do not always
+return full blocks, or do not require the last block of an archive to
+be padded out to the next block boundary.  To keep reading until you
+obtain a full block, or to accept an incomplete block if it contains
+an end-of-archive marker, specify the @samp{+read-full-blocks} option
+in conjunction with the @samp{+extract} or @samp{+list} operations.
+@xref{Listing Contents}.
+
+The @samp{+read-full-blocks} option is turned on by default when
+@code{tar} reads an archive from standard input, or from a remote
+machine.  This is because on BSD Unix systems, attempting to read a
+pipe returns however much happens to be in the pipe, even if it is
+less than was requested.  If this option were not enabled, @code{tar}
+would fail as soon as it read an incomplete block from the pipe.
+
+If you're not sure of the blocking factor of an archive, you can read
+the archive by specifying @samp{+read-full-blocks} and
+@samp{+block-size=@var{n}}, where @var{n} is a blocking factor larger
+than the blocking factor of the archive.  This lets you avoid having
+to determine the blocking factor of an archive.  @xref{Blocking
+Factor}.
+
+@table @samp
+@item +read-full-blocks
+@item -B 
+Use in conjunction with @samp{tar +extract} to read an archive which
+contains incomplete blocks, or one which has a blocking factor less
+than the one specified.
+@end table
+
+Normally @code{tar} stops reading when it encounters a block of zeros
+between file entries (which usually indicates the end of the archive).
+@samp{+ignore-zeros} allows @code{tar} to completely read an archive
+which contains a block of zeros before the end (i.e.@: a damaged
+archive, or one which was created by @code{cat}-ing several archives
+together).
+
+The @samp{+ignore-zeros} option is turned off by default because many
+versions of @code{tar} write garbage after the end of archive entry,
+since that part of the media is never supposed to be read.  GNU
+@code{tar} does not write after the end of an archive, but seeks to
+maintain compatablity among archiving utilities.
+
+@table @samp
+@item +ignore-zeros
+@itemx -i
+To ignore blocks of zeros (ie.@: end-of-archive entries) which may be
+encountered while reading an archive.  Use in conjunction with
+@samp{tar +extract} or @samp{tar +list}.
+@end table
+
+If you are using a machine with a small amount of memory, and you need
+to process large list of file-names, you can reduce the amount of
+space @code{tar} needs to process the list.  To do so, specify the
+@samp{+same-order} option and provide an ordered list of file names.
+This option tells @code{tar} that the @file{file-name} arguments
+(provided on the command line, or read from a file using the
+@samp{+files-from} option) are listed in the same order as the files
+in the archive.
+
+You can create a file containing an ordered list of files in the
+archive by storing the output produced by @samp{tar +list
+on the @samp{+list} operation.
+
+This option is probably never needed on modern computer systems.
+
+@table @samp
+@item +same-order
+@itemx +preserve-order
+@itemx -s
+To process large lists of file-names on machines with small amounts of
+memory.  Use in conjunction with @samp{tar +compare}, @samp{tar +list}
+or @samp{tar +extract}.
+@end table
+
+@c we don't need/want +preserve to exist any more
+
+@node File Writing Options, Scarce Disk Space, Archive Reading Options, Extracting From Archives
+@subsection Changing How @code{tar} Writes Files 
+@c <<< find a better title
+@cindex Overwriting old files, prevention
+@cindex Protecting old files
+@cindex Modification times of extracted files
+@cindex Permissions of extracted files
+@cindex Modes of extracted files
+@cindex Writing extracted files to standard output
+@cindex Standard output, writing extracted files to
+
+Normally, @code{tar} writes extracted files into the file system
+without regard to the files already on the system---files with the
+same name as archive members are overwritten.  To prevent @code{tar}
+from extracting an archive member from an archive, if doing so will
+overwrite a file in the file system, use @samp{+keep-old-files} in
+conjunction with the @samp{+extract} operation.  When this option is
+specified, @code{tar} reports an error stating the name of the files
+in conflict, instead of writing the file from the archive.
+
+@table @samp
+@item +keep-old files
+@itemx -k 
+Prevents @code{tar} from overwriting files in the file system during
+extraction. 
+@end table
+
+Normally, @code{tar} sets the modification times of extracted files to
+the modification times recorded for the files in the archive, but
+limits the permissions of extracted files by the current @code{umask}
+setting.
+
+To set the modification times of extracted files to the time when
+the files were extracted, use the @samp{+modification-time} option in
+conjunction with @samp{tar +extract}.
+
+@table @samp
+@item +modification-time
+@itemx -m
+Sets the modification time of extracted archive members to the time
+they were extracted, not the time recorded for them in the archive.
+Use in conjunction with @samp{+extract}.
+@end table
+
+To set the modes (access permissions) of extracted files to those
+recorded for those files in the archive, use the
+@samp{+preserve-permissions} option in conjunction with the
+@samp{+extract} operation.
+@c <<<mib --- should be aliased to ignore-umask.  
+
+@table @samp
+@item +preserve-permission
+@itemx +same-permission
+@itemx +ignore-umask
+@itemx -p
+Set modes of extracted archive members to those recorded in the
+archive, instead of current umask settings.  Use in conjunction with
+@samp{+extract}. 
+@end table
+
+@c <<< following paragraph needs to be rewritten:
+@c <<< why doesnt' this cat files together, why is this useful.  is it
+@c <<< really useful with more than one file?
+To write the files extracted to the standard output, instead of
+creating the files on the file system, use @samp{+to-stdout} in
+conjunction with @samp{tar +extract}.  This option is useful if you
+are extracting files to send them through a pipe, and do not need to
+preserve them in the file system.
+
+@table @samp
+@item +to-stdout
+@itemx -O
+Writes files to the standard output.  Used in conjunction with
+@samp{+extract}. 
+@end table
+
+@c <<< why would you want to do such a thing, how are files separated on
+@c <<< the standard output? is this useful with more that one file?  are
+@c <<< pipes the real reason?
+
+@node Scarce Disk Space,  , File Writing Options, Extracting From Archives
+@subsection Recovering From Scarce Disk Space
+@cindex Middle of the archive, starting in the
+@cindex Running out of space during extraction
+@cindex Disk space, running out of
+@cindex Space on the disk, recovering from lack of
+
+If a previous attempt to extract files failed due to lack of disk
+space, you can use @samp{+starting-file=@var{file-name}} to start
+extracting only after file @var{file-name} when extracting files from
+the archive.  This assumes, of course, that there is now free space,
+or that you are now extracting into a different file system.
+
+@table @samp
+@item +starting-file=@var{file-name}
+@itemx -K @var{file-name}
+Starts an operation in the middle of an archive.  Use in conjunction
+with @samp{+extract} or @samp{+list}.
+@end table
+
+If you notice you are running out of disk space during an extraction
+operation, you can also suspend @code{tar}, remove unnecessary files
+from the file system, and then restart the same @code{tar} operation.
+In this case, @samp{+starting-file} is not necessary. 
+
+@c <<< xref incremental,  xref +interactive,  xref +exclude
+
+@node Insuring Accuracy, Selecting Archive Members, Reading and Writing, Top
+@chapter Insuring the Accuracy of an Archive
+
+You can insure the accuracy of an archive by comparing files in the
+system with archive members.  @code{tar} can compare an archive to the
+file system as the archive is being written, to verify a write
+operation, or can compare a previously written archive, to insure that
+it is up to date.
+
+@menu
+* Write Verification::          
+* Comparing::                   
+@end menu
+
+@node Write Verification, Comparing, Insuring Accuracy, Insuring Accuracy
+@section Verifying Data as It is Stored
+@cindex Verifying a write operation
+@cindex Double-checking a write operation
+
+To check for discrepancies in an archive immediately after it is
+written, use the @samp{+verify} option in conjunction with the
+@samp{tar +create} operation.  When this option is specified,
+@code{tar} checks archive members against their counterparts in the file
+system, and reports discrepancies on the standard error.  In
+multi-volume archives, each volume is verified after it is written,
+before the next volume is written.
+
+To verify an archive, you must be able to read it from before the end
+of the last written entry.  This option is useful for detecting data
+errors on some tapes.  Archives written to pipes, some cartridge tape
+drives, and some other devices cannot be verified.
+
+@table @samp
+@item +verify
+@itemx -W
+Checks for discrepancies in the archive immediately after it is
+written.  Use in conjunction with @samp{tar +create}.
+@end table
+
+@node Comparing,  , Write Verification, Insuring Accuracy
+@section Comparing an Archive with the File System
+@cindex Verifying the currency of an archive
+
+@samp{tar +compare} compares archive members in an existing archive
+with their counterparts in the file system, and reports differences in
+file size, mode, owner, modification date and contents.  If a file is
+represented in the archive but does not exist in the file system,
+@code{tar} reports a difference.
+
+If you use @var{file-name} arguments in conjunction with @samp{tar
+specified with their counterparts in the file system.  If you specify
+a file that is not in the archive, @code{tar} will report an error.  If
+you don't specify any files, @code{tar} compares all the files in the
+archive.
+
+Because @code{tar} only checks files in the archive against files in
+the file system, and not vice versa, it ignores files in the file
+system that do not exist in the archive.
+
+The following example compares the archive members @file{larry},
+@file{moe} and @file{curly} in the archive @file{stooges} with files
+of the same name in the file system.
+
+@example
+tar +compare +file=stooges larry moe curly
+@end example
+
+@noindent 
+If a file, for example @file{curly}, did not exist in the archive,
+@code{tar} would report an error, as follows:
+
+@example
+curly: does not exist
+@end example
+
+@node Selecting Archive Members, User Interaction, Insuring Accuracy, Top
+@chapter Selecting Archive Members
+@cindex Specifying files to act on
+@cindex Specifying archive members
+
+@dfn{File-name arguments} specify which files in the file system
+@code{tar} operates on, when creating or adding to an archive, or
+which archive members @code{tar} operates on, when reading or
+deleting from an archive.  (@pxref{Reading and Writing}.)
+
+To specify file names, you can include them as the last arguments on
+the command line, as follows:
+@example
+tar @var{operation} [@var{option1} @var{option2} ..] [@var{file-name-1} @var{file-name-2} ...]
+@end example
+
+If you specify a directory name as a file name argument, all the files
+in that directory are operated on by @code{tar}. 
+
+If you do not specify files when @code{tar} is invoked, @code{tar}
+operates on all the non-directory files in the working directory (if
+the operation is @samp{+create}), all the archive members in the
+archive (if a read operation is specified), or does nothing (if any
+other operation is specified).
+
+@menu
+* File Name Lists::             Reading File Names from a File
+* File Name Interpretation::    this needs a better title
+* File Exclusion::              so does this
+@end menu
+
+@node File Name Lists, File Name Interpretation, Selecting Archive Members, Selecting Archive Members
+@section Reading a List of File Names from a File
+@cindex Lists of file names
+@cindex File-name arguments, alternatives
+
+To read file names from a file on the file system, instead of from the
+command line, use the @samp{+files-from=@var{file}} option.  If you
+specify @samp{-} as @var{file}, the file names are read from standard
+input.  Note that using both @samp{+files-from=-} and @samp{+file=-}
+in the same command will not work unless the operation is
+@samp{+create}.  @xref{Archive Name}, for an explanation of the
+@samp{+file} option.
+
+@table @samp
+@item +files-from=@var{file}
+@itemx -T @var{file}
+Reads file-name arguments from a file on the file system, instead of
+from the command line.  Use in conjunction with any operation.
+@end table
+
+@node File Name Interpretation, File Exclusion, File Name Lists, Selecting Archive Members
+@section File Name Interpretation
+@cindex File Names, interpreting
+
+@c <<<<add some text  -ringo
+
+@menu
+* Absolute File Names::         
+* Changing Working Directory::  
+* Archiving with Symbolic Links::  Archiving Using Symbolic Links
+@end menu
+
+@node Absolute File Names, Changing Working Directory, File Name Interpretation, File Name Interpretation
+@subsection Storing and Extracting Files Relative to Root
+
+@c <<< is this what this does, or does it just preserve the slash?  
+@c <<< is it still called +absolute-paths?
+
+@c To archive or extract files relative to the root directory, specify
+@c the @samp{+absolute-paths} option.
+
+@c Normally, @code{tar} acts on files relative to the working
+@c directory---ignoring superior directory names when archiving, and
+@c ignoring leading slashes when extracting.
+
+@c When you specify @samp{+absolute-paths}, @code{tar} stores file names
+@c including all superior directory names, and preserves leading slashes.
+@c If you only invoked @code{tar} from the root directory you would never
+@c need the @samp{+absolute-paths} option, but using this option may be
+@c more convenient than switching to root.
+
+@c >>> should be an example in the tutorial/wizardry section using this
+@c >>> to transfer files between systems.
+
+@c >>>  is write access an issue?
+
+@table @samp
+@item +absolute-paths
+Preserves full file names (inclusing superior dirctory names) when
+archiving files.  Preserves leading slash when extracting files.
+@end table
+
+@node Changing Working Directory, Archiving with Symbolic Links, Absolute File Names, File Name Interpretation
+@subsection Changing the Working Directory Within a List of File-names
+@cindex Directory, changing in mid-stream
+@cindex Working directory, specifying
+
+To change working directory in the middle of a list of file names,
+(either on the command line or in a file specified using
+@samp{+files-from}), use @samp{+directory=@var{directory}}.  This will
+change the working directory to the directory @var{directory} after
+that point in the list.  For example,
+
+@example 
+tar +create iggy ziggy +directory=baz melvin
+@end example
+
+@noindent
+will place the files @file{iggy} and @file{ziggy} from the current
+directory into the archive, followed by the file @file{melvin} from
+the directory @file{baz}.  This option is especially useful when you
+have several widely separated files that you want to store in the same
+directory in the archive.
+
+Note that the file @file{melvin} is recorded in the archive under the
+precise name @file{melvin}, @emph{not} @file{baz/melvin}.  Thus, the
+archive will contain three files that all appear to have come from the
+same directory; if the archive is extracted with plain @samp{tar
+
+Contrast this with the command
+
+@example
+tar -c iggy ziggy bar/melvin
+@end example
+
+@noindent
+which records the third file in the archive under the name
+@file{bar/melvin} so that, if the archive is extracted using @samp{tar
+@file{bar}.
+
+@table @samp
+@item +directory=@file{directory}
+@itemx -C @file{directory}
+Changes the working directory.  
+@end table
+
+@c <<<need to test how extract deals with this, and add an example  -ringo
+
+@node Archiving with Symbolic Links,  , Changing Working Directory, File Name Interpretation
+@subsection Archiving Using Symbolic Links
+@cindex File names, using symbolic links
+@cindex Symbolic link as file name
+
+@samp{+dereference} is used with @samp{tar +create}, and causes
+@code{tar} to archive files which are referenced by a symbolic link,
+using the name of the link as the file name.
+
+<<<this needs to be checked by MIB and then re-written, with an example
+The name under which the file is stored in the file system is not
+recorded in the archive.  To record both the symbolic link name and
+the file name in the system, archive the file under both names.  If
+all links were recorded automatically by @code{tar}, an extracted file
+might be linked to a file name that no longer exists in the file
+system.
+
+@c <<< is the following still true? - ringo
+If a linked-to file is encountered again by @code{tar} while creating
+the same archive, an entire second copy of it will be stored.  This
+could be considered a bug.
+
+@table @samp
+@item +dereference
+@itemx -h
+Stores files referenced by a symbolic link, using the name of the link
+as the file name.  Use in conjunction with any write operation.
+@end table
+
+@node File Exclusion,  , File Name Interpretation, Selecting Archive Members
+@section Selecting Files by Characteristic
+@cindex File names, excluding files by
+@cindex Excluding files by name and pattern
+@cindex Excluding files by file system
+@cindex File system boundaries, not crossing
+@cindex Excluding file by age
+@cindex Modification time, excluding files by
+@cindex Age, excluding files by
+
+To avoid crossing file system boundaries when archiving parts of a
+directory tree, use @samp{+one-file-system}.  This option only affects
+files that are archived because they are in a directory that is being
+archived; files explicitly named on the command line are archived
+regardless of where they reside.
+
+This option is useful for making full or incremental archival backups
+of a file system.
+
+If this option is used in conjunction with @samp{+verbose}, files that
+are excluded are mentioned by name on the standard error.
+
+@table @samp
+@item +one-file-system
+@itemx -l
+Prevents @code{tar} from crossing file system boundaries when
+archiving.  Use in conjunction with any write operation.
+@end table
+
+To avoid operating on files whose names match a particular pattern,
+use the @samp{+exclude=@var{pattern}} or
+@samp{+exclude-from=@var{file}} options.  
+
+When you specify the @samp{+exclude=@var{pattern}} option, @code{tar}
+ignores files which match the @var{pattern}, which can be a single
+file name or a more complex expression.  Thus, if you invoke
+@code{tar} with @samp{tar +create +exclude=*.o}, no files whose names
+end in @file{.o} are included in the archive.  
+@c <<< what other things can you use besides "*"?
+
+@samp{+exclude-from=@var{file}} acts like @samp{+exclude}, but
+specifies a file @var{file} containing a list of patterns.  @code{tar}
+ignores files with names that fit any of these patterns.
+
+You can use either option more than once in a single command.
+
+@table @samp
+@item +exclude=@var{pattern}
+Causes @code{tar} to ignore files that match the @var{pattern}.
+
+@item +exclude-from=@var{file}
+Causes @code{tar} to ignore files that match the patterns listed in
+@var{file}.
+@end table
+@c +exclude-from used to be "+exclude", +exclude didn't used to exist.
+
+To operate only on files with modification or status-change times
+after a particular date, use @samp{+after-date=@var{date}}.  You can
+use this option with @samp{tar +create} or @samp{tar +add-file} to
+insure only new files are archived, or with @samp{tar +extract} to
+insure only recent files are resurrected. @refill
+@c +after-date @var{date} or  +newer @var{date}
+
+@samp{+newer-mtime=@var{date}} acts like @samp{+after-date=@var{date}},
+but tests just the modification times of the files, ignoring
+status-change times.
+
+@c <<<need example of +newer-mtime with quoted argument
+Remember that the entire date argument should be quoted if it contains
+any spaces.
+
+
+@strong{Please Note:} @samp{+after-date} and @samp{+newer-mtime}
+should not be used for incremental backups.  Some files (such as those
+in renamed directories) are not selected up properly by these options.
+@c  xref to incremental backup chapter when node name is decided.
+
+@table @samp
+@item +after-date=@var{date}
+@itemx +newer=@var{date}
+@itemx -N @var{date}
+Acts on files only if their modification or inode-changed times are
+later than @var{date}.  Use in conjunction with any operation.
+@item +newer-mtime=@var{date}
+Acts like @samp{+after-date}, but only looks at modification times.
+@end table
+
+@c <<< following is the getdate date format --- needs to be re-written,
+@c <<< made a sub-node:
+
+Time/Date Formats Accepted by getdate
+(omitting obscure constructions)
+
+The input consists of one or more of: time zone day date year
+in any order.
+
+Those in turn consist of (`|' and `/' mean `or', `[]' means `optional'):
+
+time: H am/pm | H:M [am/pm] | H:M:S [am/pm]
+zone: timezone-name | timezone-name dst
+day: day-name | day-name, | N day-name
+date: M/D | M/D/Y | month-name D | month-name D, Y | D month-name | D month-name Y
+year: Y
+
+am can also be a.m., pm can also be p.m.
+case and spaces around punctuation are not significant.
+month and day names can be abbreviated.  >>>
+
+@node User Interaction, Backups and Restoration, Selecting Archive Members, Top
+@chapter User Interaction
+@cindex Getting more information during the operation
+@cindex Information during operation
+@cindex Feedback from @code{tar}
+
+Once you have typed a @code{tar}command, it is usually performed
+without any further information required of the user, or provided by
+@code{tar}.  The following options allow you to generate progress and
+status information during an operation, or to confirm operations on
+files as they are performed.
+
+@menu
+* Additional Information::      
+* Interactive Operation::       
+@end menu
+
+@node Additional Information, Interactive Operation, User Interaction, User Interaction
+@section Progress and Status Information
+@cindex Progress information
+@cindex Status information
+@cindex Information on progress and status of operations
+@cindex Verbose operation
+@cindex Record number where error occured
+@cindex Error message, record number of
+@cindex Version of the @code{tar} program
+
+Typically, @code{tar} performs most operations without reporting any
+information to the user except error messages.  If you have
+encountered a problem when operating on an archive, however, you may
+need more information than just an error message in order to solve the
+problem.  The following options can be helpful diagnostic tools.
+
+When used with most operations, @samp{+verbose} causes @code{tar} to
+print the file names of the files or archive members it is operating
+on.  When used with @samp{tar +list}, the verbose option causes
+@code{tar} to print out an @samp{ls -l} type listing of the files in
+the archive.
+
+Verbose output appears on the standard output except when an archive
+is being written to the standard output (as with @samp{tar +create
+the standard error stream.
+
+@table @samp
+@item +verbose
+@itemx -v
+Prints the names of files or archive members as they are being
+operated on.  Can be used in conjunction with any operation.   When
+used with @samp{+list}, generates an @samp{ls -l} type listing.
+@end table
+
+To find out where in an archive a message was triggered, use
+@samp{+record-number}.  @samp{+record-number} causes @code{tar} to
+print, along with every message it produces, the record number within
+the archive where the message was triggered.
+
+This option is especially useful when reading damaged archives, since
+it helps pinpoint the damaged sections.  It can also be used with
+@samp{tar +list} when listing a file-system backup tape, allowing you
+to choose among several backup tapes when retrieving a file later, in
+favor of the tape where the file appears earliest (closest to the
+front of the tape).
+@c <<< xref when the node name is set and the backup section written
+
+@table @samp
+@item +record-number
+@itemx -R 
+Prints the record number whenever a message is generated by
+@code{tar}.  Use in conjunction with any operation.
+@end table
+
+@c rewrite below
+To print the version number of the @code{tar} program, use @samp{tar
+error.  For example:
+
+@example
+tar +version
+@end example
+
+@noindent
+might return:
+
+@example
+GNU tar version 1.09
+@end example
+@c used to be an option.  has been fixed.
+
+@node Interactive Operation,  , Additional Information, User Interaction
+@section Asking for Confirmation During Operations
+@cindex Interactive operation
+
+Typically, @code{tar} carries out a command without stopping for
+further instructions.  In some situations however, you
+may want to exclude some files and archive members from the operation
+(for instance if disk or storage space is tight).  You can do this by
+excluding certain files automatically (@pxref{File Exclusion}), or by
+performing an operation interactively, using the @samp{+interactive}
+operation.  
+
+When the @samp{+interactive} option is specified, @code{tar} asks for
+confirmation before reading, writing, or deleting each file it
+encounters while carrying out an operation.  To confirm the action you
+must type a line of input beginning with @samp{y}.  If your input line
+begins with anything other than @samp{y}, @code{tar} skips that file.
+
+Commands which might be useful to perform interactively include
+appending files to an archive, extracting files from an archive,
+deleting a file from an archive, and deleting a file from disk during
+an incremental restore.
+
+If @code{tar} is reading the archive from the standard input,
+@code{tar} opens the file @file{/dev/tty} to support the interactive
+communications.
+<<< this aborts if you won't OK the working directory.  this is a bug. -ringo
+
+@table @samp
+@item +interactive
+@itemx +confirmation
+@itemx -w
+Asks for confirmation before reading, writing or deleting an archive
+member (when listing, comparing or writing an archive or deleting
+archive members), or before writing or deleting a file (when
+extracting an archive).
+@end table
+
+@node Backups and Restoration, Media, User Interaction, Top
+@chapter Performing Backups and Restoring Files
+
+To @dfn{back up} a file system means to create archives that contain
+all the files in that file system.  Those archives can then be used to
+restore any or all of those files (for instance if a disk crashes or a
+file is accidently deleted).  File system @dfn{backups} are also
+called @dfn{dumps}.
+
+@menu
+* Backup Levels::               Levels of backups
+* Backup Scripts::              Using scripts to perform backups
+                                  and restoration
+* incremental and listed-incremental::  The +incremental 
+                                  and +listed-incremental Options
+* Problems::                    Some common problems and their solutions
+@end menu
+
+@node Backup Levels, Backup Scripts, Backups and Restoration, Backups and Restoration
+@section Levels of Backups
+
+An archive containing all the files in the file system is called a
+@dfn{full backup} or @dfn{full dump}.  You could insure your data by
+creating a full dump every day.  This strategy, however, would waste a
+substantial amount of archive media and user time, as unchanged files
+are daily re-archived.
+
+It is more efficient to do a full dump only occasionally.  To back up
+files between full dumps, you can a incremental dump.  A @dfn{level
+one} dump archives all the files that have changed since the last full
+dump.
+
+A typical dump strategy would be to perform a full dump once a week,
+and a level one dump once a day.  This means some versions of files
+will in fact be archived more than once, but this dump strategy makes
+it possible to restore a file system to within one day of accuracy by
+only extracting two archives---the last weekly (full) dump and the
+last daily (level one) dump.  The only information lost would be in
+files changed or created since the last daily backup.  (Doing dumps
+more than once a day is usually not worth the trouble).
+
+@node Backup Scripts, incremental and listed-incremental, Backup Levels, Backups and Restoration
+@section Using Scripts to Perform Backups and Restoration
+
+GNU @code{tar} comes with scripts you can use to do full and level-one
+dumps.  Using scripts (shell programs) to perform backups and
+restoration is a convenient and reliable alternative to typing out
+file name lists and @code{tar} commands by hand.
+
+Before you use these scripts, you need to edit the file
+@file{backup-specs}, which specifies parameters used by the backup
+scripts and by the restore script.  @xref{Script Syntax}.
+Once the backup parameters are set, you can perform backups or
+restoration by running the appropriate script.  
+
+The name of the restore script is @code{restore}. The names of the
+level one and full backup scripts are, respectively, @code{level-1} and
+@code{level-0}.  The @code{level-0} script also exists under the name
+@code{weekly}, and the @code{level-1} under the name
+@code{daily}---these additional names can be changed according to your
+backup schedule.  @xref{Scripted Restoration}, for more information
+on running the restoration script.  @xref{Scripted Backups}, for more
+information on running the backup scripts.
+
+@emph{Please Note:} The backup scripts and the restoration scripts are
+designed to be used together.  While it is possible to restore files
+by hand from an archive which was created using a backup script, and
+to create an archive by hand which could then be extracted using the
+restore script, it is easier to use the scripts.  @xref{incremental
+and listed-incremental}, before making such an attempt.
+
+@c shorten node names
+@menu
+* Backup Parameters::           Setting parameters for backups and restoration
+* Scripted Backups::            Using the backup scripts
+* Scripted Restoration::        Using the restore script
+@end menu
+
+@node Backup Parameters, Scripted Backups, Backup Scripts, Backup Scripts
+@subsection Setting Parameters for Backups and Restoration
+
+The file @file{backup-specs} specifies backup parameters for the
+backup and restoration scripts provided with @code{tar}.  You must
+edit @file{backup-specs} to fit your system configuration and schedule
+before using these scripts.
+
+@c <<< This about backup scripts needs to be written:
+@c <<<BS is a shell script ....  thus ... @file{backup-specs} is in shell
+@c  script syntax.  @xref{Script Syntax}, for an explanation of this
+@c syntax.
+
+@c whats a parameter ....  looked at by the backup scripts ... which will
+@c be expecting to find ... now syntax ... value is linked to lame ...
+@c @file{backup-specs} specifies the following parameters:
+
+
+@table @code
+@item ADMINISTRATOR
+The user name of the backup administrator.
+
+@item BACKUP_HOUR
+The hour at which the backups are done.  This can be a number from 0
+to 23, or the string @samp{now}.
+
+@item TAPE_FILE
+The device @code{tar} writes the archive to.  This device should be
+attached to the host on which the dump scripts are run.
+@c <<< examples for all  ...
+
+@item TAPE_STATUS
+The command to use to obtain the status of the archive device,
+including error count.  On some tape drives there may not be such a
+command; in that case, simply use `TAPE_STATUS=false'.
+
+@item BLOCKING
+The blocking factor @code{tar} will use when writing the dump archive.
+@xref{Blocking Factor}.
+
+@item BACKUP_DIRS
+A list of file systems to be dumped.  You can include any directory
+name in the list---subdirectories on that file system will be
+included, regardless of how they may look to other networked machines.
+Subdirectories on other file systems will be ignored.
+
+The host name specifies which host to run @code{tar} on, and should
+normally be the host that actually contains the file system.  However,
+the host machine must have GNU @code{tar} installed, and must be able
+to access the directory containing the backup scripts and their
+support files using the same file name that is used on the machine
+where the scripts are run (ie. what @code{pwd} will print when in that
+directory on that machine).  If the host that contains the file system
+does not have this capability, you can specify another host as long as
+it can access the file system through NFS.
+
+@item BACKUP_FILES
+A list of individual files to be dumped.  These should be accessible
+from the machine on which the backup script is run.  
+@c <<<same file name, be specific.  through nfs ...
+@end table
+
+@menu
+* backup-specs example::        An Example Text of @file{Backup-specs}
+* Script Syntax::               Syntax for @file{Backup-specs}
+@end menu
+
+@node backup-specs example, Script Syntax, Backup Parameters, Backup Parameters
+@subsubsection An Example Text of @file{Backup-specs}
+
+The following is the text of @file{backup-specs} as it appears at FSF:
+
+@example
+# site-specific parameters for file system backup.
+
+ADMINISTRATOR=friedman
+BACKUP_HOUR=1
+TAPE_FILE=/dev/nrsmt0
+TAPE_STATUS="mts -t $TAPE_FILE"
+BLOCKING=124
+BACKUP_DIRS="
+	albert:/fs/fsf
+	apple-gunkies:/gd
+	albert:/fs/gd2
+	albert:/fs/gp
+	geech:/usr/jla
+	churchy:/usr/roland
+	albert:/
+	albert:/usr
+	apple-gunkies:/
+	apple-gunkies:/usr
+	gnu:/hack
+	gnu:/u
+	apple-gunkies:/com/mailer/gnu
+	apple-gunkies:/com/archive/gnu"
+
+BACKUP_FILES="/com/mailer/aliases /com/mailer/league*[a-z]"
+
+@end example
+
+@node Script Syntax,  , backup-specs example, Backup Parameters
+@subsubsection Syntax for @file{Backup-specs}
+
+@file{backup-specs} is in shell script syntax.  The following
+conventions should be considered when editing the script:
+@c <<<   "conventions?"
+
+A quoted string is considered to be contiguous, even if it is on more
+than one line.  Therefore, you cannot include commented-out lines
+within a multi-line quoted string.  BACKUP_FILES and BACKUP_DIRS are
+the two most likely parameters to be multi-line.
+
+A quoted string typically cannot contain wildcards.  In
+@file{backup-specs}, however, the parameters BACKUP_DIRS and
+BACKUP_FILES can contain wildcards.
+
+@node Scripted Backups, Scripted Restoration, Backup Parameters, Backup Scripts
+@subsection Using the Backup Scripts
+
+The syntax for running a backup script is:
+
+@example
+@file{script-name} [@var{time-to-be-run}]
+@end example
+
+where @var{time-to-be-run} can be a specific system time, or can be
+@kbd{now}.  If you do not specify a time, the script runs at the time
+specified in @file{backup-specs} (@pxref{Script Syntax}).
+
+You should start a script with a tape or disk mounted.  Once you start
+a script, it prompts you for new tapes or disks as it needs them.
+Media volumes don't have to correspond to archive files---a
+multi-volume archive can be started in the middle of a tape that
+already contains the end of another multi-volume archive.  The
+@code{restore} script prompts for media by its archive volume, so to
+avoid an error message you should keep track of which tape (or disk)
+contains which volume of the archive.  @xref{Scripted Restoration}.
+
+@c <<<have file names changed?  -ringo
+The backup scripts write two files on the file system.  The first is a
+record file in @file{/etc/tar-backup/}, which is used by the scripts
+to store and retrieve information about which files were dumped.  This
+file is not meant to be read by humans, and should not be deleted by
+them.  @xref{incremental and listed-incremental}, for a more
+detailed explanation of this file.
+
+The second file is a log file containing the names of the file systems
+and files dumped, what time the backup was made, and any error
+messages that were generated, as well as how much space was left in
+the media volume after the last volume of the archive was written.
+You should check this log file after every backup.  The file name is
+@file{log-@var{mmm-ddd-yyyy}-level-1} or
+@file{log-@var{mmm-ddd-yyyy}-full}.
+
+The script also prints the name of each system being dumped to the
+standard output.
+@c <<<the section on restore scripts is commented out.
+@c <<< a section on non-scripted testore mya be a good idea
+@ignore
+@node Scripted Restoration,  , Scripted Backups, Backup Scripts
+@subsection Using the Restore Script
+@c  subject to change as things develop
+
+To restore files that were archived using a scripted backup, use the
+@code{restore} script.  The syntax for the script is:
+
+
+where ##### are the file systems to restore from, and
+##### is a regular expression which specifies which files to
+restore.  If you specify +all, the script restores all the files
+in the file system.
+
+You should start the restore script with the media containing the
+first volume of the archive mounted.  The script will prompt for other
+volumes as they are needed.  If the archive is on tape, you don't need
+to rewind the tape to to its beginning---if the tape head is
+positioned past the beginning of the archive, the script will rewind
+the tape as needed.  @xref{Media}, for a discussion of tape
+positioning.
+
+If you specify @samp{+all} as the @var{files} argument, the
+@code{restore} script extracts all the files in the archived file
+system into the active file system.  
+
+@quotation
+@strong{Warning:}The script will delete files from the active file
+system if they were not in the file system when the archive was made.
+@end quotation
+
+@xref{incremental and listed-incremental}, for an explanation of how
+the script makes that determination.
+@c this may be an option, not a given
+@end ignore
+
+@node incremental and listed-incremental, Problems, Backup Scripts, Backups and Restoration
+@section The @code{+incremental} and @code{+listed-incremental} Options
+
+@samp{+incremental} is used in conjunction with @samp{+create},
+@samp{+extract} or @samp{+list} when backing up and restoring file
+systems.  An archive cannot be extracted or listed with the
+@samp{+incremental} option specified unless it was created with the
+option specified.  This option should only be used by a script, not by
+the user, and is usually disregarded in favor of
+@samp{+listed-incremental}, which is described below.
+
+@samp{+incremental} in conjunction with @samp{+create} causes
+@code{tar} to write, at the beginning of the archive, an entry for
+each of the directories that will be archived.  The entry for a
+directory includes a list of all the files in the directory at the
+time the archive was created and a flag for each file indicating
+whether or not the file is going to be put in the archive.
+ 
+Note that this option causes @code{tar} to create a non-standard
+archive that may not be readable by non-GNU versions of the @code{tar}
+program.  
+
+@samp{+incremental} in conjunction with @samp{+extract} causes
+@code{tar} to read the lists of directory contents previously stored
+in the archive, @emph{delete} files in the file system that did not
+exist in their directories when the archive was created, and then
+extract the files in the archive.
+
+This behavior is convenient when restoring a damaged file system from
+a succession of incremental backups: it restores the entire state of
+the file system to that which obtained when the backup was made.  If
+@samp{+incremental} isn't specified, the file system will probably
+fill up with files that shouldn't exist any more.
+
+@samp{+incremental} in conjunction with @samp{+list}, causes 
+@code{tar} to print, for each directory in the archive, the list of
+files in that directory at the time the archive was created.  This
+information is put out in a format that is not easy for humans to
+read, but which is unambiguous for a program: each file name is
+preceded by either a @samp{Y} if the file is present in the archive,
+an @samp{N} if the file is not included in the archive, or a @samp{D}
+if the file is a directory (and is included in the archive).  Each
+file name is terminated by a null character.  The last file is followed
+by an additional null and a newline to indicate the end of the data.
+
+@samp{+listed-incremental}=@var{file} acts like @samp{+incremental},
+but when used in conjunction with @samp{+create} will also cause
+@code{tar} to use the file @var{file}, which contains information
+about the state of the file system at the time of the last backup, to
+decide which files to include in the archive being created.  That file
+will then be updated by @code{tar}.  If the file @var{file} does not
+exist when this option is specified, @code{tar} will create it, and
+include all appropriate files in the archive.
+
+The file @var{file}, which is archive independent, contains the date
+it was last modified and a list of devices, inode numbers and
+directory names.  @code{tar} will archive files with newer mod dates
+or inode change times, and directories with an unchanged inode number
+and device but a changed directory name.  The file is updated after
+the files to be archived are determined, but before the new archive is
+actually created.
+
+@c <<< this section needs to be written
+@node Problems,  , incremental and listed-incremental, Backups and Restoration
+@section Some Common Problems and their Solutions
+
+errors from system:
+permission denied
+no such file or directory
+not owner
+
+errors from tar:
+directory checksum error
+header format error
+
+errors from media/system:
+i/o error
+device busy
+
+@node Media, Quick Reference, Backups and Restoration, Top
+@chapter Tapes and Other Archive Media
+
+Archives are usually written on dismountable media---tape cartridges,
+mag tapes, or floppy disks.
+
+The amount of data a tape or disk holds depends not only on its size,
+but also on how it is formatted.  A 2400 foot long reel of mag tape
+holds 40 megabytes of data when formated at 1600 bits per inch.  The
+physically smaller EXABYTE tape cartridge holds 2.3 gigabytes.  
+
+Magnetic media are re-usable---once the archive on a tape is no longer
+needed, the archive can be erased and the tape or disk used over.
+Media quality does deteriorate with use, however.  Most tapes or disks
+should be disgarded when they begin to produce data errors.  EXABYTE
+tape cartridges should be disgarded when they generate an @dfn{error
+count} (number of non-usable bits) of more than 10k.
+
+Magnetic media are written and erased using magnetic fields, and
+should be protected from such fields to avoid damage to stored data.
+Sticking a floppy disk to a filing cabinet using a magnet is probably
+not a good idea.
+
+
+@menu
+* Write Protection::            Write Protection
+* Tape Positioning::            Tape Positions and Tape Marks
+@end menu
+
+@node Write Protection, Tape Positioning, Media, Media
+@section Write Protection
+
+All tapes and disks can be @dfn{write protected}, to protect data on
+them from being changed.  Once an archive is written, you should write
+protect the media to prevent the archive from being accidently
+overwritten or deleted.  (This will protect the archive from being
+changed with a tape or floppy drive---it will not protect it from
+magnet fields or other physical hazards).
+
+The write protection device itself is usually an integral part of the
+physical media, and can be a two position (write enabled/write
+disabled) switch, a notch which can be popped out or covered, a ring
+which can be removed from the center of a tape reel, or some other
+changeable feature.
+
+@node Tape Positioning,  , Write Protection, Media
+@section Tape Positions and Tape Marks
+
+Just as archives can store more than one file from the file system,
+tapes can store more than one archive file.  To keep track of where
+archive files (or any other type of file stored on tape) begin and
+end, tape archive devices write magnetic @dfn{tape marks} on the
+archive media.  Tape drives write one tape mark between files,
+two at the end of all the file entries.
+
+If you think of data as a series of "0000"'s, and tape marks as "x"'s,
+a tape might look like the following:
+
+@example
+0000x000000x00000x00x00000xx-------------------------
+@end example
+
+Tape devices read and write tapes using a read/write @dfn{tape
+head}---a physical part of the device which can only access one point
+on the tape at a time.  When you use @code{tar} to read or write
+archive data from a tape device, the device will begin reading or
+writing from wherever on the tape the tape head happens to be,
+regardless of which archive or what part of the archive the tape head
+is on.  Before writing an archive, you should make sure that no data
+on the tape will be overwritten (unless it is no longer needed).
+Before reading an archive, you should make sure the tape head is at
+the beginning of the archive you want to read.  (The @code{restore}
+script will find the archive automatically.  @xref{Scripted
+Restoration}).  @xref{mt}, for an explanation of the tape moving
+utility.
+
+If you want to add new archive file entries to a tape, you should
+advance the tape to the end of the existing file entries, backspace
+over the last tape mark, and write the new archive file.  If you were
+to add two archives to the example above, the tape might look like the
+following:
+
+@example
+0000x000000x00000x00x00000x000x0000xx----------------
+@end example
+
+@menu
+* mt::                          The @code{mt} Utility
+@end menu
+
+@node mt,  , Tape Positioning, Tape Positioning
+@subsection The @code{mt} Utility
+
+<<< is it true that this only works on non-block devices?  should
+<<< explain the difference, xref to block-size (fixed or variable).
+
+You can use the @code{mt} utility to advance or rewind a tape past a
+specified number of archive files on the tape.  This will allow you to
+move to the beginning of an archive before extracting or reading it,
+or to the end of all the archives before writing a new one.
+@c why isn't there an "advance 'til you find two tape marks together"? 
+
+The syntax of the @code{mt} command is:
+
+@example
+mt [-f @var{tapename}] @var{operation} [@var{number}]
+@end example
+
+where @var{tapename} is the name of the tape device, @var{number} is
+the number of times an operation is performed (with a default of one),
+and @var{operation} is one of the following:
+
+@table @code
+@item eof
+@itemx weof
+Writes @var{number} tape marks at the current position on the tape.
+
+
+@item fsf  
+Moves tape position forward @var{number} files.
+
+
+@item bsf
+Moves tape position back @var{number} files.
+
+
+@item rewind
+Rewinds the tape. (Ignores @var{number}).
+
+
+@item offline
+@itemx rewoff1
+Rewinds the tape and takes the tape device off-line. (Ignores @var{number}).
+
+
+@item status
+Prints status information about the tape unit.
+@end table
+<<< is there a better way to frob the spacing on the list?  -ringo
+
+If you don't specify a @var{tapename}, @code{mt} uses the environment
+variable TAPE; if TAPE does not exist, @code{mt} uses the device
+@file{/dev/rmt12}.
+
+@code{mt} returns a 0 exit status when the operation(s) were
+successful, 1 if the command was unrecognized, and 2 if an operation
+failed.
+
+@c <<< new node on how to find an archive?  -ringo
+If you use @code{tar +extract} with the
+@samp{+label=@var{archive-name}} option specified, @code{tar} will
+read an archive label (the tape head has to be positioned on it) and
+print an error if the archive label doesn't match the
+@var{archive-name} specified.  @var{archive-name} can be any regular
+expression.  If the labels match, @code{tar} extracts the archive.
+@xref{Archive Label}.  @xref{Matching Format Parameters}.
+<<< fix cross references
+
+@code{tar +list +label} will cause @code{tar} to print the label.
+
+@c <<< MIB -- program to list all the labels on a tape?
+
+@node Quick Reference, Data Format Details, Media, Top
+@appendix A Quick Reference Guide to @code{tar} Operations and Options
+@c  put in proper form for appendix.  (unnumbered?)
+
+@menu
+* Operations::                  A Table of Operations
+* Options::                     Table of Options
+@end menu
+
+@node Operations, Options, Quick Reference, Quick Reference
+@appendixsec A Table of Operations
+@c add xrefs, note synonyms
+
+The operation argument to @code{tar} specifies which action you want to
+take.
+
+@table @samp
+@item -A
+Adds copies of an archive or archives to the end of another archive.
+
+@item -c
+Creates a new archive.  
+
+@item -d
+Compares files in the archive with their counterparts in the file
+system, and reports differences in file size, mode, owner,
+modification date and contents.
+
+@item -r
+Adds files to the end of the archive.  
+
+@item -t
+Prints a list of the contents of the archive.
+
+@item -x
+Reads files from the archive and writes them into the active file
+system.
+
+@item -u
+Adds files to the end of the archive, but only if they are newer than
+their counterparts already in the archive, or if they do not already
+exist in the archive.
+
+@item +add-archive
+Adds copies of an archive or archives to the end of another archive.
+
+@item +add-file
+Adds files to the end of the archive.  
+
+@item +append
+Adds files to the end of the archive.  
+
+@item +catenate
+Adds copies of an archive or archives to the end of another archive.
+
+@item +compare
+Compares files in the archive with their counterparts in the file
+system, and reports differences in file size, mode, owner,
+modification date and contents.
+
+@item +concatenate
+Adds copies of an archive or archives to the end of another archive.
+
+@item +create
+Creates a new archive.  
+
+@item +delete
+Deletes files from the archive.  All versions of the files are deleted.
+
+@item +diff
+Compares files in the archive with their counterparts in the file
+system, and reports differences in file size, mode, owner,
+modification date and contents.
+
+@item +extract
+Reads files from the archive and writes them into the active file
+system.
+
+@item +get
+Reads files from the archive and writes them into the active file
+system.
+
+@item +help
+Prints a list of @code{tar} operations and options.
+
+@item +list
+Prints a list of the contents of the archive.
+
+@item +update
+Adds files to the end of the archive, but only if they are newer than
+their counterparts already in the archive, or if they do not already
+exist in the archive.
+
+@item +version
+Prints the version number of the @code{tar} program to the standard
+error.
+@end table
+
+@node Options,  , Operations, Quick Reference
+@appendixsec Table of Options
+
+Options change the way @code{tar} performs an operation.
+
+@table @samp
+@item +absolute-paths   
+WILL BE INPUT WHEN QUESTION IS RESOLVED
+
+@item +after-date=@var{date}
+Limit the operation to files changed after the given date.
+@xref{File Exclusion}.
+
+@item +block-size=@var{number}
+Specify the blocking factor of an archive.  @xref{Blocking Factor}.
+
+@item +compress
+Specify a compressed archive.  @xref{Compressed Archives}.
+
+@item +compress-block. 
+Create a whole block sized compressed archive.  @xref{Compressed Archives}.
+
+@item +confirmation
+Solicit confirmation for each file.  @xref{Interactive Operation}
+<<< +selective should be a synonym. 
+
+@item +dereference
+Treat a symbolic link as an alternate name for the file the link
+points to.  @xref{Symbolic Links}.
+
+@item +directory=@file{directory}
+Change the working directory.  @xref{Changing Working Directory}.
+
+@item +exclude=@var{pattern}
+Exclude files which match the regular expression @var{pattern}.
+@xref{File Exclusion}.
+
+@item +exclude-from=@file{file}
+Exclude files which match any of the regular expressions listed in
+the file @file{file}.  @xref{File Exclusion}.
+
+@item +file=@var{archive-name}
+Name the archive.  @xref{Archive Name}).
+
+@item +files-from=@file{file}
+Read file-name arguments from a file on the file system.
+@xref{File Name Lists}. 
+
+@item +ignore-umask
+Set modes of extracted files to those recorded in the archive.
+@xref{File Writing Options}.
+
+@item +ignore-zeros
+Ignore end-of-archive entries.  @xref{Archive Reading Options}.
+<<< this should be changed to +ignore-end 
+
+@item +listed-incremental=@var{file-name}   (-g)
+Take a file name argument always.  If the file doesn't exist, run a level
+zero dump, creating the file.  If the file exists, uses that file to see
+what has changed.
+
+@item +incremental (-G)
+@c <<<look it up>>>
+
+@item +tape-length=@var{n}  (-L)
+@c <<<alternate way of doing multi archive, will go to that length and
+@c prompts for new tape, automatically turns on multi-volume. >>>
+@c <<< this needs to be written into main body as well -ringo
+
+@item +info-script=@var{program-file}
+Create a multi-volume archive via a script.  @xref{Multi-Volume Archives}.
+
+@item +interactive
+Ask for confirmation before performing any operation on a file or
+archive member.
+
+@item +keep-old-files
+Prevent overwriting during extraction.  @xref{File Writing Options}.
+
+@item +label=@var{archive-label}
+Include an archive-label in the archive being created.  @xref{Archive
+Label}.
+
+@item +modification-time
+Set the modification time of extracted files to the time they were
+extracted.  @xref{File Writing Options}.
+
+@item +multi-volume
+Specify a multi-volume archive.  @xref{Multi-Volume Archives}.
+
+@item +newer=@var{date}
+Limit the operation to files changed after the given date.
+@xref{File Exclusion}.
+
+@item +newer-mtime=@var{date}
+Limit the operation to files modified after the given date.  @xref{File
+Exclusion}.
+
+@item +old
+Create an old format archive.  @xref{Old Style File Information}.
+@c <<< did we agree this should go away as a synonym?
+
+@item +old-archive
+Create an old format archive.  @xref{Old Style File Information}.
+
+@item +one-file-system
+Prevent @code{tar} from crossing file system boundaries when
+archiving.  @xref{File Exclusion}.
+
+@item +portable
+Create an old format archive.  @xref{Old Style File Information}.
+@c <<< was portability, may still need to be changed
+
+@item +preserve-order
+Help process large lists of file-names on machines with small amounts of
+memory.  @xref{Archive Reading Options}.
+
+@item +preserve-permission
+Set modes of extracted files to those recorded in the archive.
+@xref{File Writing Options}.
+
+@item +read-full-blocks
+Read an archive with a smaller than specified block size or which
+contains incomplete blocks.  @xref{Archive Reading Options}).
+@c should be +partial-blocks (!!!)
+ 
+@item +record-number
+Print the record number where a message is generated.
+@xref{Additional Information}.
+
+@item +same-order
+Help process large lists of file-names on machines with small amounts of
+memory.  @xref{Archive Reading Options}.
+
+@item +same-permission
+Set the modes of extracted files to those recorded in the archive.
+@xref{File Writing Options}.
+
+@item +sparse
+Archive sparse files sparsely.  @xref{Sparse Files}.
+
+@item +starting-file=@var{file-name}
+Begin reading in the middle of an archive.  @xref{Scarce Disk Space}.
+
+@item +to-stdout
+Write files to the standard output.  @xref{File Writing Options}.
+
+@item +uncompress
+Specifdo  a compressed archive.  @xref{Compressed Archives}.
+
+@item -V @var{archive-label}
+Include an archive-label in the archive being created.  @xref{Archive
+Label}.
+@c was +volume
+
+@item +verbose
+Print the names of files or archive members as they are being
+operated on.  @xref{Additional Information}.
+
+@item +verify
+Check for discrepancies in the archive immediately after it is
+written.  @xref{Write Verification}.
+
+@item -B 
+Read an archive with a smaller than specified block size or which
+contains incomplete blocks.  @xref{Archive Reading Options}).
+
+@item -K @var{file-name}
+Begin reading in the middle of an archive.  @xref{Scarce Disk Space}.
+
+@item -M
+Specify a multi-volume archive.  @xref{Multi-Volume Archives}.
+
+@item -N @var{date}
+Limit operation to files changed after the given date.  @xref{File Exclusion}.
+
+@item -O
+Write files to the standard output.  @xref{File Writing Options}.
+
+@c <<<<- P is absolute paths, add when resolved.  -ringo>>>
+
+@item -R 
+Print the record number where a message is generated.
+@xref{Additional Information}.
+
+@item -S
+Archive sparse files sparsely.  @xref{Sparse Files}.
+
+@item -T @var{file}
+Read file-name arguments from a file on the file system.
+@xref{File Name Lists}. 
+
+@item -W
+Check for discrepancies in the archive immediately after it is
+written.  @xref{Write Verification}.
+
+@item -Z
+Specify a compressed archive.  @xref{Compressed Archives}.
+
+@item -b @var{number}
+Specify the blocking factor of an archive.  @xref{Blocking Factor}.
+
+@item -f @var{archive-name}
+Name the archive.  @xref{Archive Name}).
+
+@item -h
+Treat a symbolic link as an alternate name for the file the link
+points to.  @xref{Symbolic Links}.
+
+@item -i
+Ignore end-of-archive entries.  @xref{Archive Reading Options}.
+
+@item -k 
+Prevent overwriting during extraction.  @xref{File Writing Options}.
+
+@item -l
+Prevent @code{tar} from crossing file system boundaries when
+archiving.  @xref{File Exclusion}.
+
+@item -m
+Set the modification time of extracted files to the time they were
+extracted.  @xref{File Writing Options}.
+
+@item -o
+Create an old format archive.  @xref{Old Style File Information}.
+
+@item -p
+Set the modes of extracted files to those recorded in the archive.
+@xref{File Writing Options}.
+
+@item -s
+Help process large lists of file-names on machines with small amounts of
+memory.  @xref{Archive Reading Options}.
+
+@item -v
+Print the names of files or archive members they are being operated
+on.  @xref{Additional Information}.
+
+@item -w
+@c <<<see +interactive.  WILL BE INPUT WHEN QUESTIONS ARE RESOLVED.>>>
+
+@item -z
+Specify a compressed archive.  @xref{Compressed Archives}.
+
+@item -z -z
+Create a whole block sized compressed archive.  @xref{Compressed Archives}.
+@c I would rather this were -Z.  it is the only double letter short
+@c form.
+
+@item -C @file{directory}
+Change the working directory.  @xref{Changing Working Directory}.
+
+@item -F @var{program-file}
+Create a multi-volume archive via a script.  @xref{Multi-Volume Archives}.
+
+@item -X @file{file}
+Exclude files which match any of the regular expressions listed in
+the file @file{file}.  @xref{File Exclusion}.
+@end table
+
+@node Data Format Details, Concept Index, Quick Reference, Top
+@appendix Details of the Archive Data Format
+
+This chapter is based heavily on John Gilmore's @i{tar}(5) manual page
+for the public domain @code{tar} that GNU @code{tar} is based on.
+@c it's been majorly edited since, we may be able to lose this.
+
+The archive media contains a series of records, each of which contains
+512 bytes.  Each archive member is represented by a header record,
+which describes the file, followed by zero or more records which
+represent the contents of the file.  At the end of the archive file
+there may be a record consisting of a series of binary zeros, as an
+end-of-archive marker.  GNU @code{tar} writes a record of zeros at the
+end of an archive, but does not assume that such a record exists when
+reading an archive.
+
+Records may be grouped into @dfn{blocks} for I/O operations.  A block
+of records is written with a single @code{write()} operation.  The
+number of records in a block is specified using the @samp{+block-size}
+option.  @xref{Blocking Factor}, for more information about specifying
+block size.  
+
+@menu
+* Header Data::                 The Distribution of Data in the Header
+* Header Fields::               The Meaning of Header Fields
+* Sparse File Handling::        Fields to Handle Sparse Files
+@end menu
+
+@node Header Data, Header Fields, Data Format Details, Data Format Details
+@appendixsec The Distribution of Data in the Header
+
+The header record is defined in C as follows:
+@c I am taking the following code on faith.
+
+@example
+@r{Standard Archive Format - Standard TAR - USTAR}
+
+#define RECORDSIZE  	512
+#define NAMSIZ      	100
+#define TUNMLEN      	32
+#define TGNMLEN      	32
+#define SPARSE_EXT_HDR	21
+#define	SPARSE_IN_HDR	4
+
+struct sparse @{
+	char offset[12];
+	char numbytes[12];
+@};
+
+union record @{
+    char        charptr[RECORDSIZE];
+    struct header @{
+        char    name[NAMSIZ];
+        char    mode[8];
+        char    uid[8];
+        char    gid[8];
+        char    size[12];
+        char    mtime[12];
+        char    chksum[8];
+        char    linkflag;
+        char    linkname[NAMSIZ];
+        char    magic[8];
+        char    uname[TUNMLEN];
+        char    gname[TGNMLEN];
+        char    devmajor[8];
+        char    devminor[8];
+
+@r{The following fields were added by gnu and are not used by other}
+@r{versions of @code{tar}}.
+        char	atime[12];
+        char	ctime[12];
+        char	offset[12];
+        char	longnames[4];
+@r{The next three fields were added by gnu to deal with shrinking down}
+@r{sparse files.}
+        struct	sparse sp[SPARSE_IN_HDR];
+        char	isextended;
+@r{This is the number of nulls at the end of the file, if any.}
+        char	ending_blanks[12];	
+
+    @} header;
+
+    struct extended_header @{
+        struct sparse sp[21];
+        char isextended;
+    @} ext_hdr;
+
+@};
+@c <<< this whole thing needs to be put into better english
+
+@r{The checksum field is filled with this while the checksum is computed.}
+#define    CHKBLANKS    "        "        @r{8 blanks, no null}
+
+@r{Inclusion of this field marks an archive as being in standard}
+@r{Posix format (though GNU tar itself is not Posix conforming).  GNU}
+@r{tar puts "ustar" in this field if uname and gname are valid.}
+#define    TMAGIC    "ustar  "        @r{7 chars and a null}
+
+@r{The magic field is filled with this if this is a GNU format dump entry.}
+#define    GNUMAGIC  "GNUtar "        @r{7 chars and a null}
+
+@r{The linkflag defines the type of file.}
+#define  LF_OLDNORMAL '\0'       @r{Normal disk file, Unix compatible}
+#define  LF_NORMAL    '0'        @r{Normal disk file}
+#define  LF_LINK      '1'        @r{Link to previously dumped file}
+#define  LF_SYMLINK   '2'        @r{Symbolic link}
+#define  LF_CHR       '3'        @r{Character special file}
+#define  LF_BLK       '4'        @r{Block special file}
+#define  LF_DIR       '5'        @r{Directory}
+#define  LF_FIFO      '6'        @r{FIFO special file}
+#define  LF_CONTIG    '7'        @r{Contiguous file}
+
+@r{hhe following are further link types which were defined later.}
+
+@r{This is a dir entry that contains the names of files that were in}
+@r{the dir at the time the dump was made.}
+#define LF_DUMPDIR	'D'		
+
+@r{This is the continuation of a file that began on another volume}
+#define LF_MULTIVOL	'M'		
+
+@r{This is for sparse files}
+#define LF_SPARSE	'S'		
+
+@r{This file is a tape/volume header. Ignore it on extraction.}
+#define LF_VOLHDR	'V'	
+
+@r{These are bits used in the mode field - the values are in octal}
+#define  TSUID    04000        @r{Set UID on execution}
+#define  TSGID    02000        @r{Set GID on execution}
+#define  TSVTX    01000        @r{Save text (sticky bit)}
+
+@r{These are file permissions}
+#define  TUREAD   00400        @r{read by owner}
+#define  TUWRITE  00200        @r{write by owner}
+#define  TUEXEC   00100        @r{execute/search by owner}
+#define  TGREAD   00040        @r{read by group}
+#define  TGWRITE  00020        @r{write by group}
+#define  TGEXEC   00010        @r{execute/search by group}
+#define  TOREAD   00004        @r{read by other}
+#define  TOWRITE  00002        @r{write by other}
+#define  TOEXEC   00001        @r{execute/search by other}
+@end example
+
+
+All characters in headers are 8-bit characters in the local variant of
+ASCII.  Each field in the header is contiguous; that is, there is no
+padding in the header format. 
+
+Data representing the contents of files is not translated in any way
+and is not constrained to represent characters in any character set.
+@code{tar} does not distinguish between text files and binary files.
+
+The @code{name}, @code{linkname}, @code{magic}, @code{uname}, and
+@code{gname} fields contain null-terminated character strings.  All
+other fields contain zero-filled octal numbers in ASCII.  Each numeric
+field of width @var{w} contains @var{w} @minus{} 2 digits, a space, and a
+null, except @code{size} and @code{mtime}, which do not contain the
+trailing null.
+
+@node Header Fields, Sparse File Handling, Header Data, Data Format Details
+@appendixsec The Meaning of Header Fields
+
+The @code{name} field contains the name of the file.
+<<< how big a name before field overflows? 
+
+The @code{mode} field contains nine bits which specify file
+permissions, and three bits which specify the Set UID, Set GID, and
+Save Text (``stick'') modes.  Values for these bits are defined above.
+@xref{File Writing Options}, for information on how file permissions
+and modes are used by @code{tar}.
+
+The @code{uid} and @code{gid} fields contain the numeric user and
+group IDs of the file owners.  If the operating system does not
+support numeric user or group IDs, these fields should be ignored.
+@c but are they?
+
+The @code{size} field contains the size of the file in bytes; this
+field contains a zero if the header describes a link to a file.
+
+The @code{mtime} field contains the modification time of the file.
+This is the ASCII representation of the octal value of the last time
+the file was modified, represented as an integer number of seconds
+since January 1, 1970, 00:00 Coordinated Universal Time.
+@xref{File Writing Options}, for a description of how @code{tar} uses
+this information.
+
+The @code{chksum} field contains the ASCII representation of the octal
+value of the simple sum of all bytes in the header record.  To
+generate this sum, each 8-bit byte in the header is added to an
+unsigned integer, which has been initialized to zero.  The precision
+of the integer is seventeen bits.  When calculating the checksum, the
+@code{chksum} field itself is treated as blank.
+
+The @code{atime} and @code{ctime} fields are used when making
+incremental backups; they store, respectively, the file's access time
+and last inode-change time.
+
+The value in the @code{offset} field is used when making a
+multi-volume archive.  The offset is number of bytes into the file
+that we need to go to pick up where we left off in the previous
+volume, i.e the location that a continued file is continued from.
+
+The @code{longnames} field supports a feature that is not yet
+implemented.  This field should be empty.
+
+The @code{magic} field indicates that this archive was output in the
+P1003 archive format.  If this field contains @code{TMAGIC}, the
+@code{uname} and @code{gname} fields will contain the ASCII
+representation of the owner and group of the file respectively.  If
+found, the user and group IDs are used rather than the values in the
+@code{uid} and @code{gid} fields.
+
+The @code{sp} field is used to archive sparse files efficiently.
+@xref{Sparse File Handling}, for a description of this field, and
+other fields it may imply.
+
+The @code{typeflag} field specifies the file's type.  If a particular
+implementation does not recognize or permit the specified type,
+@code{tar} extracts the file as if it were a regular file, and reports
+the discrepancy on the standard error.  @xref{File Types}.  @xref{GNU
+File Types}.
+
+@menu
+* File Types::                  File Types
+* GNU File Types::              Additional File Types Supported by GNU
+@end menu
+
+@node File Types, GNU File Types, Header Fields, Header Fields
+@appendixsubsec File Types
+
+The following flags are used to describe file types:
+
+@table @code
+@item LF_NORMAL
+@itemx LF_OLDNORMAL
+Indicates a regular file.  In order to be compatible with older
+versions of @code{tar}, a @code{typeflag} value of @code{LF_OLDNORMAL}
+should be silently recognized as a regular file.  New archives should
+be created using @code{LF_NORMAL} for regular files.  For backward
+compatibility, @code{tar} treats a regular file whose name ends with a
+slash as a directory.
+
+@item LF_LINK
+Indicates a link to another file, of any type, which has been
+previously archived.  @code{tar} identifies linked files in Unix by
+matching device and inode numbers.  The linked-to name is specified in
+the @code{linkname} field with a trailing null.
+
+@item LF_SYMLINK
+Indicates a symbolic link to another file.  The linked-to
+name is specified in the @code{linkname} field with a trailing null.  
+@xref{File Writing Options}, for information on archiving files
+referenced by a symbolic link.
+
+@item LF_CHR
+@itemx LF_BLK
+Indicate character special files and block special files,
+respectively.  In this case the @code{devmajor} and @code{devminor}
+fields will contain the major and minor device numbers.  Operating
+systems may map the device specifications to their own local
+specification, or may ignore the entry.
+
+@item LF_DIR
+Indicates a directory or sub-directory.  The directory name in the
+@code{name} field should end with a slash.  On systems where disk
+allocation is performed on a directory basis, the @code{size} field
+will contain the maximum number of bytes (which may be rounded to the
+nearest disk block allocation unit) that the directory can hold.  A
+@code{size} field of zero indicates no size limitations.  Systems that
+do not support size limiting in this manner should ignore the
+@code{size} field.
+
+@item LF_FIFO
+Indicates a FIFO special file.  Note that archiving a FIFO file
+archives the existence of the file and not its contents.
+
+@item LF_CONTIG
+Indicates a contiguous file.  Contiguous files are the same as normal
+files except that, in operating systems that support it, all the
+files' disk space is allocated contiguously.  Operating systems which
+do not allow contiguous allocation should silently treat this type as
+a normal file.
+
+@item 'A' @dots{}
+@itemx 'Z'
+These are reserved for custom implementations.  Some of these are used
+in the GNU modified format, which is described below.  @xref{GNU File
+Types}.  
+@end table
+
+Certain other flag values are reserved for specification in future
+revisions of the P1003 standard, and should not be used by any
+@code{tar} program.
+
+@node GNU File Types,  , File Types, Header Fields
+@appendixsubsec Additional File Types Supported by GNU
+
+GNU @code{tar} uses additional file types to describe new types of
+files in an archive.  These are listed below.
+
+@table @code
+@item LF_DUMPDIR
+@itemx 'D'
+Indicates a directory and a list of files created by the
+@samp{+incremental} option.  The @code{size} field gives the total
+size of the associated list of files.  Each file name is preceded by
+either a @code{'Y'} (the file should be in this archive) or an
+@code{'N'} (the file is a directory, or is not stored in the archive).
+Each file name is terminated by a null.  There is an additional null
+after the last file name.
+
+@item LF_MULTIVOL
+@itemx 'M'
+Indicates a file continued from another volume of a multi-volume
+archive (@pxref{Multi-Volume Archives}).  The original type of the file is not
+given here.  The @code{size} field gives the maximum size of this
+piece of the file (assuming the volume does not end before the file is
+written out).  The @code{offset} field gives the offset from the
+beginning of the file where this part of the file begins.  Thus
+@code{size} plus @code{offset} should equal the original size of the
+file.
+
+@item LF_SPARSE
+@itemx 'S' 
+Indicates a sparse file.  @xref{Sparse Files}.  @xref{Sparse File
+Handling}.
+
+@item LF_VOLHDR
+@itemx 'V'
+Marks an archive label that was created using the @samp{+label} option
+when the archive was created (@pxref{Archive Label}.  The @code{name}
+field contains the argument to the option.  The @code{size} field is
+zero.  Only the first file in each volume of an archive should have
+this type.
+@end table
+
+@node Sparse File Handling,  , Header Fields, Data Format Details
+@appendixsec Fields to Handle Sparse Files
+
+The following header information was added to deal with sparse files
+(@pxref{Sparse Files}):
+
+@c  TALK TO MIB
+The @code{sp} field (fields? something else?) is an array of
+@code{struct sparse}.  Each @code{struct sparse} contains two
+12-character strings, which represent the offset into the file and the
+number of bytes to be written at that offset.  The offset is absolute,
+and not relative to the offset in preceding array elements.
+
+The header can contain four of these @code{struct sparse}; if more are
+needed, they are not stored in the header, instead, the flag
+@code{isextended} is set and the next record is an
+@code{extended_header}.
+@c @code{extended_header} or @dfn{extended_header} ???  the next
+@c record after the header, or in the middle of it.
+
+The @code{isextended} flag is only set for sparse files, and then only
+if extended header records are needed when archiving the file.
+
+Each extended header record can contain an array of 21 sparse
+structures, as well as another @code{isextended} flag.  There is no
+limit (except that implied by the archive media) on the number of
+extended header records that can be used to describe a sparse file.
+
+@c so is @code{extended_header} the right way to write this?
+
+@node Concept Index,  , Data Format Details, Top
+@unnumbered Concept Index
+
+@printindex cp
+
+@summarycontents
+@contents
+@bye
+
+
