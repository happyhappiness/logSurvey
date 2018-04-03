 	git push --mirror "$HTTPD_URL"/smart/alternates-mirror.git
 '
 
-test_expect_success TTY 'quiet push' '
+test_expect_success TTY 'push shows progress when stderr is a tty' '
+	cd "$ROOT_PATH"/test_repo_clone &&
+	test_commit noisy &&
+	test_terminal git push >output 2>&1 &&
+	grep "^Writing objects" output
+'
+
+test_expect_success TTY 'push --quiet silences status and progress' '
 	cd "$ROOT_PATH"/test_repo_clone &&
 	test_commit quiet &&
-	test_terminal git push --quiet --no-progress 2>&1 | tee output &&
+	test_terminal git push --quiet >output 2>&1 &&
 	test_cmp /dev/null output
 '
 
+test_expect_success TTY 'push --no-progress silences progress but not status' '
+	cd "$ROOT_PATH"/test_repo_clone &&
+	test_commit no-progress &&
+	test_terminal git push --no-progress >output 2>&1 &&
+	grep "^To http" output &&
+	! grep "^Writing objects"
+'
+
+test_expect_success 'push --progress shows progress to non-tty' '
+	cd "$ROOT_PATH"/test_repo_clone &&
+	test_commit progress &&
+	git push --progress >output 2>&1 &&
+	grep "^To http" output &&
+	grep "^Writing objects" output
+'
+
 stop_httpd
 test_done