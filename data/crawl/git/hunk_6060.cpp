 	test_cmp expect output
 '
 
+cat > expect <<EOF
+boolean: 0
+integer: 12345
+timestamp: 0
+string: (not set)
+abbrev: 7
+verbose: 0
+quiet: no
+dry run: no
+EOF
+
+test_expect_success 'OPT_NUMBER_CALLBACK() works' '
+	test-parse-options -12345 > output 2> output.err &&
+	test ! -s output.err &&
+	test_cmp expect output
+'
+
 test_done
