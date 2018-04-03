EOF

test_expect_success 'test --parseopt help output' '
	git rev-parse --parseopt -- -h > output < optionspec
	test_cmp expect output
'

cat > expect <<EOF