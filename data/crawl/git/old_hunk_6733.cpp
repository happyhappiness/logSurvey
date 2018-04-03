Defining a custom hunk-header
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Each group of changes (called "hunk") in the textual diff output
is prefixed with a line of the form:

	@@ -k,l +n,m @@ TEXT

The text is called 'hunk header', and by default a line that
begins with an alphabet, an underscore or a dollar sign is used,
which matches what GNU 'diff -p' output uses.  This default
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