 	fi
 }
 
+# test_line_count checks that a file has the number of lines it
+# ought to. For example:
+#
+#	test_expect_success 'produce exactly one line of output' '
+#		do something >output &&
+#		test_line_count = 1 output
+#	'
+#
+# is like "test $(wc -l <output) = 1" except that it passes the
+# output through when the number of lines is wrong.
+
+test_line_count () {
+	if test $# != 3
+	then
+		error "bug in the test script: not 3 parameters to test_line_count"
+	elif ! test $(wc -l <"$3") "$1" "$2"
+	then
+		echo "test_line_count: line count for $3 !$1 $2"
+		cat "$3"
+		return 1
+	fi
+}
 
 # This is not among top-level (test_expect_success | test_expect_failure)
 # but is a prefix that can be used in the test script, like: