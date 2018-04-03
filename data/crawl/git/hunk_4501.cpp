 
 	# push master too; this ensures there is at least one '"'push'"' command to
 	# the remote helper and triggers interaction with the helper.
-	test_must_fail git push -v origin +master master:retsam >output 2>&1 &&
+	test_must_fail git push -v origin +master master:retsam >output 2>&1'
 
+test_expect_success 'push fails for non-fast-forward refs unmatched by remote helper: remote output' '
 	grep "^ + [a-f0-9]*\.\.\.[a-f0-9]* *master -> master (forced update)$" output &&
-	grep "^ ! \[rejected\] *master -> retsam (non-fast-forward)$" output &&
+	grep "^ ! \[rejected\] *master -> retsam (non-fast-forward)$" output
+'
 
+test_expect_success C_LOCALE_OUTPUT 'push fails for non-fast-forward refs unmatched by remote helper: our output' '
 	grep "To prevent you from losing history, non-fast-forward updates were rejected" \
 		output
 '