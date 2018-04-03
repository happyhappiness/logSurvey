 +
 Common unit suffixes of 'k', 'm', or 'g' are supported.
 
+core.bigFileThreshold::
+	Files larger than this size are stored deflated, without
+	attempting delta compression.  Storing large files without
+	delta compression avoids excessive memory usage, at the
+	slight expense of increased disk usage.
+Default is 512 MiB on all platforms.  This should be reasonable
+for most projects as source code and other text files can still
+be delta compressed, but larger binary media files won't be.
+Common unit suffixes of 'k', 'm', or 'g' are supported.
+Currently only linkgit:git-fast-import[1] honors this setting.
+
 core.excludesfile::
 	In addition to '.gitignore' (per-directory) and
 	'.git/info/exclude', git looks into this file for patterns
-	of files which are not meant to be tracked.  See
-	linkgit:gitignore[5].
+	of files which are not meant to be tracked.  "{tilde}/" is expanded
+	to the value of `$HOME` and "{tilde}user/" to the specified user's
+	home directory.  See linkgit:gitignore[5].
 
 core.editor::
 	Commands such as `commit` and `tag` that lets you edit
 	messages by launching an editor uses the value of this
 	variable when it is set, and the environment variable
-	`GIT_EDITOR` is not set.  The order of preference is
-	`GIT_EDITOR` environment, `core.editor`, `VISUAL` and
-	`EDITOR` environment variables and then finally `vi`.
+	`GIT_EDITOR` is not set.  See linkgit:git-var[1].
 
 core.pager::
-	The command that git will use to paginate output.  Can be overridden
-	with the `GIT_PAGER` environment variable.
+	The command that git will use to paginate output.  Can
+	be overridden with the `GIT_PAGER` environment
+	variable.  Note that git sets the `LESS` environment
+	variable to `FRSX` if it is unset when it runs the
+	pager.  One can change these settings by setting the
+	`LESS` variable to some other value.  Alternately,
+	these settings can be overridden on a project or
+	global basis by setting the `core.pager` option.
+	Setting `core.pager` has no affect on the `LESS`
+	environment variable behaviour above, so if you want
+	to override git's default settings this way, you need
+	to be explicit.  For example, to disable the S option
+	in a backward compatible manner, set `core.pager`
+	to `less -+$LESS -FRX`.  This will be passed to the
+	shell by git, which will translate the final command to
+	`LESS=FRSX less -+FRSX -FRX`.
 
 core.whitespace::
 	A comma separated list of common whitespace problems to
-	notice.  'git-diff' will use `color.diff.whitespace` to
-	highlight them, and 'git-apply --whitespace=error' will
-	consider them as errors:
+	notice.  'git diff' will use `color.diff.whitespace` to
+	highlight them, and 'git apply --whitespace=error' will
+	consider them as errors.  You can prefix `-` to disable
+	any of them (e.g. `-trailing-space`):
 +
-* `trailing-space` treats trailing whitespaces at the end of the line
+* `blank-at-eol` treats trailing whitespaces at the end of the line
   as an error (enabled by default).
 * `space-before-tab` treats a space character that appears immediately
   before a tab character in the initial indent part of the line as an
   error (enabled by default).
 * `indent-with-non-tab` treats a line that is indented with 8 or more
   space characters as an error (not enabled by default).
+* `blank-at-eof` treats blank lines added at the end of file as an error
+  (enabled by default).
+* `trailing-space` is a short-hand to cover both `blank-at-eol` and
+  `blank-at-eof`.
 * `cr-at-eol` treats a carriage-return at the end of line as
   part of the line terminator, i.e. with it, `trailing-space`
   does not trigger if the character before such a carriage-return
