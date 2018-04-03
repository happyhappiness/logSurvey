 	test_cmp expect actual
 '
 
+test_expect_success 'proper error on directory "files"' '
+	echo "Error (-1) reading configuration file a-directory." >expect &&
+	mkdir a-directory &&
+	test_expect_code 2 test-config configset_get_value foo.bar a-directory 2>output &&
+	grep "^Error" output >actual &&
+	test_cmp expect actual
+'
+
 test_expect_success POSIXPERM,SANITY 'proper error on non-accessible files' '
 	chmod -r .git/config &&
 	test_when_finished "chmod +r .git/config" &&