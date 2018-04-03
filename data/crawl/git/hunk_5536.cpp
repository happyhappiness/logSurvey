 
 test_expect_success 'git ls-files --stage' '
 	git ls-files --stage > ls-files.output &&
-	cmp ls-files.expect ls-files.output
+	test_cmp ls-files.expect ls-files.output
 '
 
 cat > ls-files-unmerged.expect << EOF
