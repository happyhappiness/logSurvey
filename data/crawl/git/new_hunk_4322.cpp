		-e "s/^Fast[- ]forward /FASTFORWARD /" >resolve.output
'

test_expect_success 'git resolve output' '
	test_i18ncmp resolve.expect resolve.output
'

cat > show-branch2.expect << EOF
