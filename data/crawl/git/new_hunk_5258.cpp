
'

test_expect_failure 'bundle --stdin' '

	echo master | git bundle create stdin-bundle.bdl --stdin &&
	git ls-remote stdin-bundle.bdl >output &&
	grep master output

'

test_expect_failure 'bundle --stdin <rev-list options>' '

	echo master | git bundle create hybrid-bundle.bdl --stdin tag &&
	git ls-remote hybrid-bundle.bdl >output &&
	grep master output

'

test_done