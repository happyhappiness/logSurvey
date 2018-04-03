	test $(cat file1) = Z
'

test_expect_success 'rebase -i error on commits with \ in message' '
	current_head=$(git rev-parse HEAD)
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

test_done