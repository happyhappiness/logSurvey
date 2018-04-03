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
