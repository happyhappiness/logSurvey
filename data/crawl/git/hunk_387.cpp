 	test_i18ncmp expect actual
 "
 
+test_expect_success 'generate builtin list' '
+	git --list-builtins >builtins
+'
+
+while read builtin
+do
+	test_expect_success "$builtin can handle -h" '
+		test_expect_code 129 git $builtin -h >output 2>&1 &&
+		test_i18ngrep usage output
+	'
+done <builtins
+
 test_done