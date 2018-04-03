 	test_cmp file clone/file
 '
 
+test_expect_success 'http remote detects correct HEAD' '
+	git push public master:other &&
+	(cd clone &&
+	 git remote set-head origin -d &&
+	 git remote set-head origin -a &&
+	 git symbolic-ref refs/remotes/origin/HEAD > output &&
+	 echo refs/remotes/origin/master > expect &&
+	 test_cmp expect output
+	)
+'
+
 stop_httpd
 test_done