 	)
 }
 
+sanitize_output () {
+	sed -e "s/$_x40/HASH/" -e "s/$_x40/HASH/" output >output2 &&
+	mv output2 output
+}
+
+
 test_expect_success 'setup' '
 	test_create_repo_with_commit sub &&
 	echo output > .gitignore &&
