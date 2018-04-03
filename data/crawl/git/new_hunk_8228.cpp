See gitlink:git[7] for details.


Defining a custom hunk-header
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Each group of changes (called "hunk") in the textual diff output
is prefixed with a line of the form:

	@@ -k,l +n,m @@ TEXT

The text is called 'hunk header', and by default a line that
begins with an alphabet, an underscore or a dollar sign is used,
which matches what GNU `diff -p` output uses.  This default
selection however is not suited for some contents, and you can
use customized pattern to make a selection.

First in .gitattributes, you would assign the `diff` attribute
for paths.

------------------------
*.tex	diff=tex
------------------------

Then, you would define "diff.tex.funcname" configuration to
specify a regular expression that matches a line that you would
want to appear as the hunk header, like this:

------------------------
[diff "tex"]
	funcname = "^\\(\\\\\\(sub\\)*section{.*\\)$"
------------------------

Note.  A single level of backslashes are eaten by the
configuration file parser, so you would need to double the
backslashes; the pattern above picks a line that begins with a
backslash, and zero or more occurences of `sub` followed by
`section` followed by open brace, to the end of line.

There are a few built-in patterns to make this easier, and `tex`
is one of them, so you do not have to write the above in your
configuration file (you still need to enable this with the
attribute mechanism, via `.gitattributes`).  Another built-in
pattern is defined for `java` that defines a pattern suitable
for program text in Java language.


Performing a three-way merge
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
