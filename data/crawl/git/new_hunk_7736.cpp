	The command that git will use to paginate output.  Can be overridden
	with the `GIT_PAGER` environment variable.

core.whitespace::
	A comma separated list of common whitespace problems to
	notice.  `git diff` will use `color.diff.whitespace` to
	highlight them, and `git apply --whitespace=error` will
	consider them as errors:
* `trailing-space` treats trailing whitespaces at the end of the line
  as an error (enabled by default).
* `space-before-tab` treats a space character that appears immediately
  before a tab character in the initial indent part of the line as an
  error (enabled by default).
* `indent-with-non-tab` treats a line that is indented with 8 or more
  space characters that can be replaced with tab characters.

alias.*::
	Command aliases for the gitlink:git[1] command wrapper - e.g.
	after defining "alias.last = cat-file commit HEAD", the invocation
