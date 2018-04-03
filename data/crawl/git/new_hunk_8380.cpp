
SYNOPSIS
--------
'git-mailsplit' [-b] [-f<nn>] [-d<prec>] -o<directory> [--] [<mbox>|<Maildir>...]

DESCRIPTION
-----------
Splits a mbox file or a Maildir into a list of files: "0001" "0002" ..  in the
specified directory so you can process them further from there.

IMPORTANT: Maildir splitting relies upon filenames being sorted to output
patches in the correct order.

OPTIONS
-------
<mbox>::
	Mbox file to split.  If not given, the mbox is read from
	the standard input.

<Maildir>::
	Root of the Maildir to split. This directory should contain the cur, tmp
	and new subdirectories.

<directory>::
	Directory in which to place the individual messages.

