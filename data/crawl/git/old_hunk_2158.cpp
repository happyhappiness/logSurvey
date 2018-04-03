	test_i18ngrep "ignoring dangling symref refs/tags/shadow" err
'

test_expect_success 'update-ref --no-deref -d can delete reference to broken name' '
	printf "ref: refs/heads/broken...ref\n" >.git/refs/heads/badname &&
	test_when_finished "rm -f .git/refs/heads/badname" &&