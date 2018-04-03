	EOF
'

test_expect_success 'test --verbose-only' '
	test_must_fail run_sub_test_lib_test \
		test-verbose-only-2 "test verbose-only=2" \
		--verbose-only=2 <<-\EOF &&
	test_expect_success "passing test" true
	test_expect_success "test with output" "echo foo"
	test_expect_success "failing test" false
	test_done
	EOF
	check_sub_test_lib_test test-verbose-only-2 <<-\EOF
	> ok 1 - passing test
	> Z
	> expecting success: echo foo
	> foo
	> Z
	> ok 2 - test with output
	> Z
	> not ok 3 - failing test
	> #	false
	> # failed 1 among 3 test(s)
	> 1..3
	EOF
'

test_set_prereq HAVEIT
haveit=no
test_expect_success HAVEIT 'test runs if prerequisite is satisfied' '
