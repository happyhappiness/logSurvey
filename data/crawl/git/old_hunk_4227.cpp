
NAME
----
git-apply - Apply a patch on a git index file and a working tree


SYNOPSIS
--------
[verse]
'git apply' [--stat] [--numstat] [--summary] [--check] [--index]
	  [--apply] [--no-add] [--build-fake-ancestor <file>] [-R | --reverse]
	  [--allow-binary-replacement | --binary] [--reject] [-z]
	  [-pNUM] [-CNUM] [--inaccurate-eof] [--recount] [--cached]
	  [--whitespace=<nowarn|warn|fix|error|error-all>]
	  [--exclude=PATH] [--directory=<root>] [--verbose] [<patch>...]

DESCRIPTION
-----------
Reads supplied 'diff' output and applies it on a git index file
and a work tree.

OPTIONS
-------
<patch>...::
	The files to read patch from.  '-' can be used to read
	from the standard input.

--stat::
	Instead of applying the patch, output diffstat for the
	input.  Turns off "apply".

--numstat::
	Similar to \--stat, but shows number of added and
	deleted lines in decimal notation and pathname without
	abbreviation, to make it more machine friendly.  For
	binary files, outputs two `-` instead of saying
	`0 0`.  Turns off "apply".
