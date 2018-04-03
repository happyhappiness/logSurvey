 }
 
 test_expect_success 'basic usage requires no repo' '
-	lines=$(git difftool -h | grep ^usage: | wc -l) &&
-	test "$lines" -eq 1 &&
+	test_expect_code 129 git difftool -h >output &&
+	grep ^usage: output &&
 	# create a ceiling directory to prevent Git from finding a repo
 	mkdir -p not/repo &&
-	ceiling="$PWD/not" &&
-	lines=$(cd not/repo &&
-		GIT_CEILING_DIRECTORIES="$ceiling" git difftool -h |
-		grep ^usage: | wc -l) &&
-	test "$lines" -eq 1 &&
-	rmdir -p not/repo
+	test_when_finished rm -r not &&
+	test_expect_code 129 \
+	env GIT_CEILING_DIRECTORIES="$(pwd)/not" \
+	git -C not/repo difftool -h >output &&
+	grep ^usage: output
 '
 
 # Create a file on master and change it on branch