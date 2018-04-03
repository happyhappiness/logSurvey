
setup_ssh_wrapper () {
	test_expect_success 'setup ssh wrapper' '
		write_script "$TRASH_DIRECTORY/ssh-wrapper" <<-\EOF &&
		echo >>"$TRASH_DIRECTORY/ssh-output" "ssh: $*" &&
		# throw away all but the last argument, which should be the
		# command
		while test $# -gt 1; do shift; done
		eval "$1"
		EOF
		GIT_SSH="$TRASH_DIRECTORY/ssh-wrapper" &&
		export GIT_SSH &&
		export TRASH_DIRECTORY &&
		>"$TRASH_DIRECTORY"/ssh-output
	'
}

copy_ssh_wrapper_as () {
	cp "$TRASH_DIRECTORY/ssh-wrapper" "$1" &&
	GIT_SSH="$1" &&
	export GIT_SSH
}

