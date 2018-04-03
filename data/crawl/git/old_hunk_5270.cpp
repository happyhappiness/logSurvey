	test_cmp tree.missing actual
'

test_expect_failure 'mktree reads ls-tree -r output (1)' '
	git mktree <all >actual &&
	test_cmp tree actual
'

test_expect_failure 'mktree reads ls-tree -r output (2)' '
	git mktree <all.withsub >actual &&
	test_cmp tree.withsub actual
'

test_done