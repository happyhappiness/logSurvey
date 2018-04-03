 
 	) &&
 	cmp .git/index saved-index >/dev/null
+'
 
+cat > expect << EOF
+zort
+Signed-off-by: C O Mitter <committer@example.com>
+EOF
+
+test_expect_success '--signoff' '
+	echo "yet another content *narf*" >> foo &&
+	echo "zort" |
+		GIT_EDITOR=../t7500/add-content git commit -s -F - foo &&
+	git cat-file commit HEAD | sed "1,/^$/d" > output &&
+	diff expect output
 '
 
 test_done