	test_cmp expect output
}

check_i18n() {
	what="$1" &&
	shift &&
	expect="$1" &&
	shift &&
	sed "s/^$what .*/$what $expect/" <expect.template >expect &&
	test-parse-options $* >output 2>output.err &&
	test_must_be_empty output.err &&
	test_i18ncmp expect output
}

check_unknown() {
	case "$1" in
	--*)
		echo error: unknown option \`${1#--}\' >expect ;;
	-*)
		echo error: unknown switch \`${1#-}\' >expect ;;
	esac &&
	cat expect.err >>expect &&
	test_must_fail test-parse-options $* >output 2>output.err &&
	test_must_be_empty output &&
	test_cmp expect output.err
}

check_unknown_i18n() {
	case "$1" in
	--*)