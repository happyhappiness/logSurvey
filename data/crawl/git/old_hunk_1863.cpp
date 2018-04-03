}

append_todo_help () {
	git stripspace --comment-lines >>"$todo" <<\EOF

Commands:
 p, pick = use commit
 r, reword = use commit, but edit the commit message
 e, edit = use commit, but stop for amending
 s, squash = use commit, but meld into previous commit
 f, fixup = like "squash", but discard this commit's log message
 x, exec = run command (the rest of the line) using shell
 d, drop = remove commit

These lines can be re-ordered; they are executed from top to bottom.

EOF
	if test $(get_missing_commit_check_level) = error
	then
		git stripspace --comment-lines >>"$todo" <<\EOF
Do not remove any line. Use 'drop' explicitly to remove a commit.
EOF
	else
		git stripspace --comment-lines >>"$todo" <<\EOF
If you remove a line here THAT COMMIT WILL BE LOST.
EOF
	fi
}

