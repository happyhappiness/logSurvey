        >output &&
      git diff expect output'
 
+cat > excludes-file << EOF
+*.[1-8]
+e*
+EOF
+
+git-config core.excludesFile excludes-file
+
+git-runstatus | grep "^#	" > output
+
+cat > expect << EOF
+#	.gitignore
+#	a.6
+#	one/
+#	output
+#	three/
+EOF
+
+test_expect_success 'git-status honours core.excludesfile' \
+	'diff -u expect output'
+
 test_done
