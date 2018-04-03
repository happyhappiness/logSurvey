
setup_ssh_wrapper () {
	test_expect_success 'setup ssh wrapper' '
		cp "$GIT_BUILD_DIR/test-fake-ssh$X" \
			"$TRASH_DIRECTORY/ssh-wrapper$X" &&
		GIT_SSH="$TRASH_DIRECTORY/ssh-wrapper$X" &&
		export GIT_SSH &&
		export TRASH_DIRECTORY &&
		>"$TRASH_DIRECTORY"/ssh-output
	'
}

copy_ssh_wrapper_as () {
	cp "$TRASH_DIRECTORY/ssh-wrapper$X" "${1%$X}$X" &&
	GIT_SSH="${1%$X}$X" &&
	export GIT_SSH
}

