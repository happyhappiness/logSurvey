	test_cmp typo.err output.err
'

test_expect_success 'keep some options as arguments' '
	test-parse-options --expect="arg 00: --quux" --quux
'

cat >expect <<\EOF
