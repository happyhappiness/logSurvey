
test_expect_success 'R: quiet option results in no stats being output' '
	cat input | git fast-import 2> output &&
	test_must_be_empty output
'

test_expect_success 'R: feature done means terminating "done" is mandatory' '