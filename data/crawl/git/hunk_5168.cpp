 	git format-patch --ignore-if-in-upstream HEAD
 '
 
+test_expect_success 'format-patch --signature' '
+	git format-patch --stdout --signature="my sig" -1 >output &&
+	grep "my sig" output
+'
+
+test_expect_success 'format-patch with format.signature config' '
+	git config format.signature "config sig" &&
+	git format-patch --stdout -1 >output &&
+	grep "config sig" output
+'
+
+test_expect_success 'format-patch --signature overrides format.signature' '
+	git config format.signature "config sig" &&
+	git format-patch --stdout --signature="overrides" -1 >output &&
+	! grep "config sig" output &&
+	grep "overrides" output
+'
+
+test_expect_success 'format-patch --no-signature ignores format.signature' '
+	git config format.signature "config sig" &&
+	git format-patch --stdout --signature="my sig" --no-signature \
+		-1 >output &&
+	! grep "config sig" output &&
+	! grep "my sig" output &&
+	! grep "^-- \$" output
+'
+
+test_expect_success 'format-patch --signature --cover-letter' '
+	git config --unset-all format.signature &&
+	git format-patch --stdout --signature="my sig" --cover-letter \
+		-1 >output &&
+	grep "my sig" output &&
+	test 2 = $(grep "my sig" output | wc -l)
+'
+
+test_expect_success 'format.signature="" supresses signatures' '
+	git config format.signature "" &&
+	git format-patch --stdout -1 >output &&
+	! grep "^-- \$" output
+'
+
+test_expect_success 'format-patch --no-signature supresses signatures' '
+	git config --unset-all format.signature &&
+	git format-patch --stdout --no-signature -1 >output &&
+	! grep "^-- \$" output
+'
+
+test_expect_success 'format-patch --signature="" supresses signatures' '
+	git format-patch --signature="" -1 >output &&
+	! grep "^-- \$" output
+'
+
 test_done