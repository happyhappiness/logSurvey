
SYNOPSIS
--------
'git-mailsplit' [-b] [-f<nn>] [-d<prec>] -o<directory> [--] [<mbox>...]

DESCRIPTION
-----------
Splits a mbox file into a list of files: "0001" "0002" ..  in the specified
directory so you can process them further from there.

OPTIONS
-------
<mbox>::
	Mbox file to split.  If not given, the mbox is read from
	the standard input.

<directory>::
	Directory in which to place the individual messages.

