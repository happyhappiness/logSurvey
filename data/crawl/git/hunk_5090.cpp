 	test_cmp expect output
 '
 
+test_expect_failure '.git/config ignore=all suppresses submodule summary' '
+	git config --add submodule.subname.ignore all &&
+	git config --add submodule.subname.path sm &&
+	git status > output &&
+	test_cmp expect output &&
+	git config --remove-section submodule.subname
+'
+
 test_done
