 	"$LIB_HTTPD_PATH" -d "$HTTPD_ROOT_PATH" \
 		-f "$TEST_PATH/apache.conf" $HTTPD_PARA -k stop
 }
+
+test_http_push_nonff() {
+	REMOTE_REPO=$1
+	LOCAL_REPO=$2
+	BRANCH=$3
+
+	test_expect_success 'non-fast-forward push fails' '
+		cd "$REMOTE_REPO" &&
+		HEAD=$(git rev-parse --verify HEAD) &&
+
+		cd "$LOCAL_REPO" &&
+		git checkout $BRANCH &&
+		echo "changed" > path2 &&
+		git commit -a -m path2 --amend &&
+
+		!(git push -v origin >output 2>&1) &&
+		(cd "$REMOTE_REPO" &&
+		 test $HEAD = $(git rev-parse --verify HEAD))
+	'
+
+	test_expect_success 'non-fast-forward push show ref status' '
+		grep "^ ! \[rejected\][ ]*$BRANCH -> $BRANCH (non-fast-forward)$" output
+	'
+
+	test_expect_success 'non-fast-forward push shows help message' '
+		grep "To prevent you from losing history, non-fast-forward updates were rejected" \
+			output
+	'
+}
