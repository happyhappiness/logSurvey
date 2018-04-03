
mv expect expect.err

cat >expect.template <<\EOF
boolean: 0
integer: 0
magnitude: 0
timestamp: 0
string: (not set)
abbrev: 7
verbose: -1
quiet: 0
dry run: no
file: (not set)
EOF

check() {
	what="$1" &&
	shift &&
	expect="$1" &&
	shift &&
	sed "s/^$what .*/$what $expect/" <expect.template >expect &&
	test-parse-options $* >output 2>output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
}

check_unknown_i18n() {