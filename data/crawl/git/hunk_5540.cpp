 '
 
 cat > show-branch2.expect << EOF
-! [master] Merged "mybranch" changes.
- * [mybranch] Merged "mybranch" changes.
+! [master] Merge work in mybranch
+ * [mybranch] Merge work in mybranch
 --
+-- [master] Merge work in mybranch
 EOF
 
 test_expect_success 'git show-branch (part 2)' '
 	git show-branch --topo-order master mybranch > show-branch2.output &&
 	cmp show-branch2.expect show-branch2.output
 '
 
+cat > show-branch3.expect << EOF
+! [master] Merge work in mybranch
+ * [mybranch] Merge work in mybranch
+--
+-- [master] Merge work in mybranch
+EOF
+
+test_expect_success 'git show-branch (part 3)' '
+	git show-branch --topo-order --more=2 master mybranch \
+		> show-branch3.output &&
+	cmp show-branch3.expect show-branch3.output
+'
+
+test_expect_success 'rewind to "Some fun." and "Some work."' '
+	git checkout mybranch &&
+	git reset --hard master^2 &&
+	git checkout master &&
+	git reset --hard master^
+'
+
+cat > show-branch4.expect << EOF
+* [master] Some fun.
+ ! [mybranch] Some work.
+--
+ + [mybranch] Some work.
+*  [master] Some fun.
+*+ [mybranch^] Initial commit
+EOF
+
+test_expect_success 'git show-branch (part 4)' '
+	git show-branch --topo-order > show-branch4.output &&
+	cmp show-branch4.expect show-branch4.output
+'
+
+test_expect_success 'manual merge' '
+	mb=$(git merge-base HEAD mybranch) &&
+	git name-rev --name-only --tags $mb > name-rev.output &&
+	test "my-first-tag" = $(cat name-rev.output) &&
+
+	git read-tree -m -u $mb HEAD mybranch
+'
+
+cat > ls-files.expect << EOF
+100644 7f8b141b65fdcee47321e399a2598a235a032422 0	example
+100644 557db03de997c86a4a028e1ebd3a1ceb225be238 1	hello
+100644 ba42a2a96e3027f3333e13ede4ccf4498c3ae942 2	hello
+100644 cc44c73eb783565da5831b4d820c962954019b69 3	hello
+EOF
+
+test_expect_success 'git ls-files --stage' '
+	git ls-files --stage > ls-files.output &&
+	cmp ls-files.expect ls-files.output
+'
+
+cat > ls-files-unmerged.expect << EOF
+100644 557db03de997c86a4a028e1ebd3a1ceb225be238 1	hello
+100644 ba42a2a96e3027f3333e13ede4ccf4498c3ae942 2	hello
+100644 cc44c73eb783565da5831b4d820c962954019b69 3	hello
+EOF
+
+test_expect_success 'git ls-files --unmerged' '
+	git ls-files --unmerged > ls-files-unmerged.output &&
+	cmp ls-files-unmerged.expect ls-files-unmerged.output
+'
+
+test_expect_success 'git-merge-index' '
+	test_must_fail git merge-index git-merge-one-file hello
+'
+
+test_expect_success 'git ls-files --stage (part 2)' '
+	git ls-files --stage > ls-files.output2 &&
+	cmp ls-files.expect ls-files.output2
+'
+
 test_expect_success 'git repack' 'git repack'
 test_expect_success 'git prune-packed' 'git prune-packed'
 test_expect_success '-> only packed objects' '