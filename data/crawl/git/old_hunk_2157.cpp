	test_i18ngrep "ignoring ref with broken name refs/heads/broken\.\.\.symref" error
'

test_expect_success 'update-ref --no-deref -d can delete reference to broken name' '
	printf "ref: refs/heads/broken...ref\n" >.git/refs/heads/badname &&
	test_when_finished "rm -f .git/refs/heads/badname" &&
	test_path_is_file .git/refs/heads/badname &&
	git update-ref --no-deref -d refs/heads/badname >output 2>error &&
	test_path_is_missing .git/refs/heads/badname &&
	test_must_be_empty output &&
	test_must_be_empty error
'

test_expect_success 'update-ref -d can delete broken name' '
	cp .git/refs/heads/master .git/refs/heads/broken...ref &&
	test_when_finished "rm -f .git/refs/heads/broken...ref" &&
	git update-ref -d refs/heads/broken...ref >output 2>error &&
	test_must_be_empty output &&
	test_must_be_empty error &&
	git branch >output 2>error &&
	! grep -e "broken\.\.\.ref" error &&
	! grep -e "broken\.\.\.ref" output
'

test_expect_success 'update-ref -d cannot delete non-ref in .git dir' '