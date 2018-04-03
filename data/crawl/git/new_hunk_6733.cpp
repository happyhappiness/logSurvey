Defining a custom hunk-header
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Each group of changes (called a "hunk") in the textual diff output
is prefixed with a line of the form:

	@@ -k,l +n,m @@ TEXT

This is called a 'hunk header'.  The "TEXT" portion is by default a line
that begins with an alphabet, an underscore or a dollar sign; this
matches what GNU 'diff -p' output uses.  This default selection however
is not suited for some contents, and you can use a customized pattern
to make a selection.

First, in .gitattributes, you would assign the `diff` attribute
for paths.

------------------------
*.tex	diff=tex
------------------------

Then, you would define a "diff.tex.funcname" configuration to
specify a regular expression that matches a line that you would
want to appear as the hunk header "TEXT", like this:

------------------------
[diff "tex"]