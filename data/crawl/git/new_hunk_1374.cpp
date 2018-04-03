}

append_todo_help () {
	gettext "
Commands:
 p, pick = use commit
 r, reword = use commit, but edit the commit message
 e, edit = use commit, but stop for amending
 s, squash = use commit, but meld into previous commit
 f, fixup = like \"squash\", but discard this commit's log message
 x, exec = run command (the rest of the line) using shell
 d, drop = remove commit

These lines can be re-ordered; they are executed from top to bottom.
" | git stripspace --comment-lines >>"$todo"

	if test $(get_missing_commit_check_level) = error
	then
		gettext "
Do not remove any line. Use 'drop' explicitly to remove a commit.
" | git stripspace --comment-lines >>"$todo"
	else
		gettext "
If you remove a line here THAT COMMIT WILL BE LOST.
" | git stripspace --comment-lines >>"$todo"
	fi
}

