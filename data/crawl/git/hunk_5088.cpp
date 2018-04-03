 	test_cmp expect output
 '
 
+test_expect_success '.git/config ignore=untracked suppresses submodules with untracked content' '
+	git config --add submodule.subname.ignore untracked &&
+	git config --add submodule.subname.path sm &&
+	git status > output &&
+	test_cmp expect output &&
+	git config --remove-section submodule.subname
+'
+
 test_expect_success '--ignore-submodules=dirty suppresses submodules with untracked content' '
 	git status --ignore-submodules=dirty > output &&
 	test_cmp expect output
 '
 
+test_expect_success '.git/config ignore=dirty suppresses submodules with untracked content' '
+	git config --add submodule.subname.ignore dirty &&
+	git config --add submodule.subname.path sm &&
+	git status > output &&
+	test_cmp expect output &&
+	git config --remove-section submodule.subname
+'
+
 test_expect_success '--ignore-submodules=dirty suppresses submodules with modified content' '
 	echo modified > sm/foo &&
 	git status --ignore-submodules=dirty > output &&
 	test_cmp expect output
 '
 
+test_expect_success '.git/config ignore=dirty suppresses submodules with modified content' '
+	git config --add submodule.subname.ignore dirty &&
+	git config --add submodule.subname.path sm &&
+	git status > output &&
+	test_cmp expect output &&
+	git config --remove-section submodule.subname
+'
+
 cat > expect << EOF
 # On branch master
+# Changes to be committed:
+#   (use "git reset HEAD <file>..." to unstage)
+#
+#	modified:   sm
+#
 # Changed but not updated:
 #   (use "git add <file>..." to update what will be committed)
 #   (use "git checkout -- <file>..." to discard changes in working directory)
