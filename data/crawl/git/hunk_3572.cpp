 	EOF
 "
 
+test_expect_success 'test --verbose' '
+	test_must_fail run_sub_test_lib_test \
+		test-verbose "test verbose" --verbose <<-\EOF &&
+	test_expect_success "passing test" true
+	test_expect_success "test with output" "echo foo"
+	test_expect_success "failing test" false
+	test_done
+	EOF
+	mv test-verbose/out test-verbose/out+
+	grep -v "^Initialized empty" test-verbose/out+ >test-verbose/out &&
+	check_sub_test_lib_test test-verbose <<-\EOF
+	> expecting success: true
+	> Z
+	> ok 1 - passing test
+	> Z
+	> expecting success: echo foo
+	> foo
+	> Z
+	> ok 2 - test with output
+	> Z
+	> expecting success: false
+	> Z
+	> not ok 3 - failing test
+	> #	false
+	> Z
+	> # failed 1 among 3 test(s)
+	> 1..3
+	EOF
+'
+
 test_set_prereq HAVEIT
 haveit=no
 test_expect_success HAVEIT 'test runs if prerequisite is satisfied' '
