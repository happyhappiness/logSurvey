Extras
extra1    line above used to cause a segfault but no longer does
EOF
	test_cmp expect.err output.err
'

test_done