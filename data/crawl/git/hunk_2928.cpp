 	test_cmp expect output
 '
 
+cat > expect << EOF
+beta.noindent
+nextsection.nonewline
+123456.a123
+version.1.2.3eX.alpha
+EOF
+
+test_expect_success '--name-only --list' '
+	git config --name-only --list >output &&
+	test_cmp expect output
+'
+
 cat > expect << EOF
 beta.noindent sillyValue
 nextsection.nonewline wow2 for me
