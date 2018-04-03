 test_expect_success 'git-status honours core.excludesfile' \
 	'diff -u expect output'
 
+test_expect_success 'trailing slash in exclude allows directory match(1)' '
+
+	git ls-files --others --exclude=one/ >output &&
+	if grep "^one/" output
+	then
+		echo Ooops
+		false
+	else
+		: happy
+	fi
+
+'
+
+test_expect_success 'trailing slash in exclude allows directory match (2)' '
+
+	git ls-files --others --exclude=one/two/ >output &&
+	if grep "^one/two/" output
+	then
+		echo Ooops
+		false
+	else
+		: happy
+	fi
+
+'
+
+test_expect_success 'trailing slash in exclude forces directory match (1)' '
+
+	>two
+	git ls-files --others --exclude=two/ >output &&
+	grep "^two" output
+
+'
+
+test_expect_success 'trailing slash in exclude forces directory match (2)' '
+
+	git ls-files --others --exclude=one/a.1/ >output &&
+	grep "^one/a.1" output
+
+'
+
 test_done
