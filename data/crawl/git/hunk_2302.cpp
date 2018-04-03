 
 setup_ssh_wrapper () {
 	test_expect_success 'setup ssh wrapper' '
-		write_script "$TRASH_DIRECTORY/ssh-wrapper" <<-\EOF &&
-		echo >>"$TRASH_DIRECTORY/ssh-output" "ssh: $*" &&
-		# throw away all but the last argument, which should be the
-		# command
-		while test $# -gt 1; do shift; done
-		eval "$1"
-		EOF
-		GIT_SSH="$TRASH_DIRECTORY/ssh-wrapper" &&
+		cp "$GIT_BUILD_DIR/test-fake-ssh$X" \
+			"$TRASH_DIRECTORY/ssh-wrapper$X" &&
+		GIT_SSH="$TRASH_DIRECTORY/ssh-wrapper$X" &&
 		export GIT_SSH &&
 		export TRASH_DIRECTORY &&
 		>"$TRASH_DIRECTORY"/ssh-output
 	'
 }
 
 copy_ssh_wrapper_as () {
-	cp "$TRASH_DIRECTORY/ssh-wrapper" "$1" &&
-	GIT_SSH="$1" &&
+	cp "$TRASH_DIRECTORY/ssh-wrapper$X" "${1%$X}$X" &&
+	GIT_SSH="${1%$X}$X" &&
 	export GIT_SSH
 }
 
