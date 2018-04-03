
test_expect_success 'fails silently when using -q with deleted reflogs' '
	ref=$(git rev-parse HEAD) &&
	: >.git/logs/refs/test &&
	git update-ref -m "message for refs/test" refs/test "$ref" &&
	git reflog delete --updateref --rewrite refs/test@{0} &&
	test_must_fail git rev-parse -q --verify refs/test@{0} >error 2>&1 &&
	test_must_be_empty error
'

test_expect_success 'fails silently when using -q with not enough reflogs' '
	ref=$(git rev-parse HEAD) &&
	: >.git/logs/refs/test2 &&
	git update-ref -m "message for refs/test2" refs/test2 "$ref" &&
	test_must_fail git rev-parse -q --verify refs/test2@{999} >error 2>&1 &&
	test_must_be_empty error
'

test_expect_success 'succeeds silently with -q and reflogs that do not go far back enough in time' '
	ref=$(git rev-parse HEAD) &&
	: >.git/logs/refs/test3 &&
	git update-ref -m "message for refs/test3" refs/test3 "$ref" &&
	git rev-parse -q --verify refs/test3@{1.year.ago} >actual 2>error &&
	test_must_be_empty error &&
	echo "$ref" >expect &&
