	test_cmp expect output
'

test_expect_success 'OPT_BIT() works' '
	test-parse-options --expect="boolean: 6" -bb --or4
'

test_expect_success 'OPT_NEGBIT() works' '
	test-parse-options --expect="boolean: 6" -bb --no-neg-or4
'

test_expect_success 'OPT_COUNTUP() with PARSE_OPT_NODASH works' '
	test-parse-options --expect="boolean: 6" + + + + + +
'

test_expect_success 'OPT_NUMBER_CALLBACK() works' '
	test-parse-options --expect="integer: 12345" -12345
'

cat >expect <<\EOF
