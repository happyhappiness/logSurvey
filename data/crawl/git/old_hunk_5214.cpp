EOF

test_expect_success 'test --parseopt help output' '
	git rev-parse --parseopt -- -h 2> output.err < optionspec
	test_cmp expect.err output.err
'

cat > expect <<EOF