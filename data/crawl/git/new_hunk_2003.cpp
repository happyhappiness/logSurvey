
mv expect expect.err

check () {
	what="$1" &&
	shift &&
	expect="$1" &&
	shift &&
	test-parse-options --expect="$what $expect" "$@"
}

check_unknown_i18n() {