	grep "^ file1 | 2 +-$" output
'

test_expect_success C_LOCALE_OUTPUT 'multi-squash only fires up editor once' '
	base=$(git rev-parse HEAD~4) &&
	set_fake_editor &&
	FAKE_COMMIT_AMEND="ONCE" FAKE_LINES="1 squash 2 squash 3 squash 4" \
