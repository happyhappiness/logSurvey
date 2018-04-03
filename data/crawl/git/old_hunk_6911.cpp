
case "$no_edit" in
'')
	git-var GIT_AUTHOR_IDENT > /dev/null  || die
	git-var GIT_COMMITTER_IDENT > /dev/null  || die
	git_editor "$GIT_DIR/COMMIT_EDITMSG"
	;;
esac
