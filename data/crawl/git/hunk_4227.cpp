 
 NAME
 ----
-git-apply - Apply a patch on a git index file and a working tree
+git-apply - Apply a patch to files and/or to the index
 
 
 SYNOPSIS
 --------
 [verse]
 'git apply' [--stat] [--numstat] [--summary] [--check] [--index]
-	  [--apply] [--no-add] [--build-fake-ancestor <file>] [-R | --reverse]
+	  [--apply] [--no-add] [--build-fake-ancestor=<file>] [-R | --reverse]
 	  [--allow-binary-replacement | --binary] [--reject] [-z]
 	  [-pNUM] [-CNUM] [--inaccurate-eof] [--recount] [--cached]
+	  [--ignore-space-change | --ignore-whitespace ]
 	  [--whitespace=<nowarn|warn|fix|error|error-all>]
-	  [--exclude=PATH] [--directory=<root>] [--verbose] [<patch>...]
+	  [--exclude=PATH] [--include=PATH] [--directory=<root>]
+	  [--verbose] [<patch>...]
 
 DESCRIPTION
 -----------
-Reads supplied 'diff' output and applies it on a git index file
-and a work tree.
+Reads the supplied diff output (i.e. "a patch") and applies it to files.
+With the `--index` option the patch is also applied to the index, and
+with the `--cache` option the patch is only applied to the index.
+Without these options, the command applies the patch only to files,
+and does not require them to be in a git repository.
 
 OPTIONS
 -------
 <patch>...::
-	The files to read patch from.  '-' can be used to read
+	The files to read the patch from.  '-' can be used to read
 	from the standard input.
 
 --stat::
 	Instead of applying the patch, output diffstat for the
 	input.  Turns off "apply".
 
 --numstat::
-	Similar to \--stat, but shows number of added and
-	deleted lines in decimal notation and pathname without
+	Similar to `--stat`, but shows the number of added and
+	deleted lines in decimal notation and the pathname without
 	abbreviation, to make it more machine friendly.  For
 	binary files, outputs two `-` instead of saying
 	`0 0`.  Turns off "apply".
