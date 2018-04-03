	EOF
'

test_expect_success 'rm submodule contents' '
	rm -rf sub/* sub/.git
'