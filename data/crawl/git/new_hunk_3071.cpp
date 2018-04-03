
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

make_patch () {
