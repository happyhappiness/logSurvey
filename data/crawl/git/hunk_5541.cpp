  Hello World
 +It's a new day for git
 EOF
-git diff-files -p > diff.output
-test_expect_success 'git diff-files -p' 'cmp diff.expect diff.output'
-git diff > diff.output
-test_expect_success 'git diff' 'cmp diff.expect diff.output'
-
-tree=$(git write-tree 2>/dev/null)
 
-test_expect_success 'tree' "test 8988da15d077d4829fc51d8544c097def6644dbb = $tree"
+test_expect_success 'git diff-files -p' '
+	git diff-files -p > diff.output &&
+	cmp diff.expect diff.output
+'
 
-output="$(echo "Initial commit" | git commit-tree $(git write-tree) 2>&1 > .git/refs/heads/master)"
+test_expect_success 'git diff' '
+	git diff > diff.output &&
+	cmp diff.expect diff.output
+'
 
-git diff-index -p HEAD > diff.output
-test_expect_success 'git diff-index -p HEAD' 'cmp diff.expect diff.output'
+test_expect_success 'tree' '
+	tree=$(git write-tree 2>/dev/null)
+	test 8988da15d077d4829fc51d8544c097def6644dbb = $tree
+'
 
-git diff HEAD > diff.output
-test_expect_success 'git diff HEAD' 'cmp diff.expect diff.output'
+test_expect_success 'git diff-index -p HEAD' '
+	echo "Initial commit" | \
+	git commit-tree $(git write-tree) 2>&1 > .git/refs/heads/master &&
+	git diff-index -p HEAD > diff.output &&
+	cmp diff.expect diff.output
+'
 
-#rm hello
-#test_expect_success 'git read-tree --reset HEAD' "git read-tree --reset HEAD ; test \"hello: needs update\" = \"$(git update-index --refresh)\""
+test_expect_success 'git diff HEAD' '
+	git diff HEAD > diff.output &&
+	cmp diff.expect diff.output
+'
 
 cat > whatchanged.expect << EOF
 commit VARIABLE
