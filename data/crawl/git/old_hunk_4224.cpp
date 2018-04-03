+
Common unit suffixes of 'k', 'm', or 'g' are supported.

core.excludesfile::
	In addition to '.gitignore' (per-directory) and
	'.git/info/exclude', git looks into this file for patterns
	of files which are not meant to be tracked.  See
	linkgit:gitignore[5].

core.editor::
	Commands such as `commit` and `tag` that lets you edit
	messages by launching an editor uses the value of this
	variable when it is set, and the environment variable
	`GIT_EDITOR` is not set.  The order of preference is
	`GIT_EDITOR` environment, `core.editor`, `VISUAL` and
	`EDITOR` environment variables and then finally `vi`.

core.pager::
	The command that git will use to paginate output.  Can be overridden
	with the `GIT_PAGER` environment variable.

core.whitespace::
	A comma separated list of common whitespace problems to
	notice.  'git-diff' will use `color.diff.whitespace` to
	highlight them, and 'git-apply --whitespace=error' will
	consider them as errors:
+
* `trailing-space` treats trailing whitespaces at the end of the line
  as an error (enabled by default).
* `space-before-tab` treats a space character that appears immediately
  before a tab character in the initial indent part of the line as an
  error (enabled by default).
* `indent-with-non-tab` treats a line that is indented with 8 or more
  space characters as an error (not enabled by default).
* `cr-at-eol` treats a carriage-return at the end of line as
  part of the line terminator, i.e. with it, `trailing-space`
  does not trigger if the character before such a carriage-return
