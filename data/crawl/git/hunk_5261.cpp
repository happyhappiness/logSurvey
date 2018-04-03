 	 git rev-parse --verify refs/remotes/origin/side2)
 '
 
+cat >test/expect <<\EOF
+some-tag
+EOF
+
+test_expect_success 'add with reachable tags (default)' '
+	(cd one &&
+	 >foobar &&
+	 git add foobar &&
+	 git commit -m "Foobar" &&
+	 git tag -a -m "Foobar tag" foobar-tag &&
+	 git reset --hard HEAD~1 &&
+	 git tag -a -m "Some tag" some-tag) &&
+	(mkdir add-tags &&
+	 cd add-tags &&
+	 git init &&
+	 git remote add -f origin ../one &&
+	 git tag -l some-tag >../test/output &&
+	 git tag -l foobar-tag >>../test/output &&
+	 test_must_fail git config remote.origin.tagopt) &&
+	test_cmp test/expect test/output
+'
+
+cat >test/expect <<\EOF
+some-tag
+foobar-tag
+--tags
+EOF
+
+test_expect_success 'add --tags' '
+	(rm -rf add-tags &&
+	 mkdir add-tags &&
+	 cd add-tags &&
+	 git init &&
+	 git remote add -f --tags origin ../one &&
+	 git tag -l some-tag >../test/output &&
+	 git tag -l foobar-tag >>../test/output &&
+	 git config remote.origin.tagopt >>../test/output) &&
+	test_cmp test/expect test/output
+'
+
+cat >test/expect <<\EOF
+--no-tags
+EOF
+
+test_expect_success 'add --no-tags' '
+	(rm -rf add-tags &&
+	 mkdir add-no-tags &&
+	 cd add-no-tags &&
+	 git init &&
+	 git remote add -f --no-tags origin ../one &&
+	 git tag -l some-tag >../test/output &&
+	 git tag -l foobar-tag >../test/output &&
+	 git config remote.origin.tagopt >>../test/output) &&
+	(cd one &&
+	 git tag -d some-tag foobar-tag) &&
+	test_cmp test/expect test/output
+'
+
+test_expect_success 'reject --no-no-tags' '
+	(cd add-no-tags &&
+	 test_must_fail git remote add -f --no-no-tags neworigin ../one)
+'
+
 cat > one/expect << EOF
   apis/master
   apis/side