	test_when_finished "git rebase --abort; git reset --hard $current_head; rm -f error" &&
	test_commit TO-REMOVE will-conflict old-content &&
	test_commit "\temp" will-conflict new-content dummy &&
	(
	EDITOR=true &&
	export EDITOR &&
	test_must_fail git rebase -i HEAD^ --onto HEAD^^ 2>error
	) &&
	test_expect_code 1 grep  "	emp" error
'

