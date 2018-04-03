 	test_cmp expect output
 '
 
+cat >expect <<EOF
+set -- --foo -- '--' 'arg' '--spam=ham'
+EOF
+
+test_expect_success 'test --parseopt --keep-dashdash --stop-at-non-option with --' '
+	git rev-parse --parseopt --keep-dashdash --stop-at-non-option -- --foo -- arg --spam=ham <optionspec >output &&
+	test_cmp expect output
+'
+
+cat > expect <<EOF
+set -- --foo -- 'arg' '--spam=ham'
+EOF
+
+test_expect_success 'test --parseopt --keep-dashdash --stop-at-non-option without --' '
+	git rev-parse --parseopt --keep-dashdash --stop-at-non-option -- --foo arg --spam=ham <optionspec >output &&
+	test_cmp expect output
+'
+
 test_done