 	test_cmp exp act
 '
 
-test_expect_success 'non-fast-forward push fails' '
-	cd "$HTTPD_DOCUMENT_ROOT_PATH"/test_repo.git &&
-	HEAD=$(git rev-parse --verify HEAD) &&
-
-	cd "$ROOT_PATH"/test_repo_clone &&
-	git checkout master &&
-	echo "changed" > path2 &&
-	git commit -a -m path2 --amend &&
-
-	!(git push -v origin >output 2>&1) &&
-	(cd "$HTTPD_DOCUMENT_ROOT_PATH"/test_repo.git &&
-	 test $HEAD = $(git rev-parse --verify HEAD))
-'
-
-test_expect_success 'non-fast-forward push show ref status' '
-	grep "^ ! \[rejected\][ ]*master -> master (non-fast-forward)$" output
-'
-
-test_expect_success 'non-fast-forward push shows help message' '
-	grep "To prevent you from losing history, non-fast-forward updates were rejected" \
-		output
-'
+test_http_push_nonff "$HTTPD_DOCUMENT_ROOT_PATH"/test_repo.git \
+	"$ROOT_PATH"/test_repo_clone master
 
 test_expect_success 'push fails for non-fast-forward refs unmatched by remote helper' '
 	# create a dissimilarly-named remote ref so that git is unable to match the