	echo "edited again" > file7 &&
	git add file7 &&
	test_must_fail git rebase --continue 2>error &&
	test_i18ngrep "You have staged changes in your working tree." error
'

test_expect_success 'rebase a detached HEAD' '
