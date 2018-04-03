 	test_cmp expect output
 '
 
+cat >expect <<EOF
+boolean: 0
+integer: 0
+timestamp: 0
+string: (not set)
+abbrev: 7
+verbose: 0
+quiet: no
+dry run: no
+file: (not set)
+EOF
+
+test_expect_success 'negation of OPT_NONEG flags is not ambiguous' '
+	test-parse-options --no-ambig >output 2>output.err &&
+	test ! -s output.err &&
+	test_cmp expect output
+'
+
 test_done
