	echo "$*" >&2
}

output () {
	case "$VERBOSE" in
	'')
		"$@" > "$DOTEST"/output 2>&1
		status=$?
		test $status != 0 &&
			cat "$DOTEST"/output
		return $status
	;;
	*)
		"$@"
	esac
}

require_clean_work_tree () {
	# test if working tree is dirty
	git rev-parse --verify HEAD > /dev/null &&
