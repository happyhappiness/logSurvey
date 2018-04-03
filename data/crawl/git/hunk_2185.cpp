 	echo 1auto >expect &&
 	git config aninvalid.unit >actual &&
 	test_cmp expect actual &&
-	cat >expect <<-\EOF &&
-	fatal: bad numeric config value '\''1auto'\'' for '\''aninvalid.unit'\'' in file .git/config: invalid unit
-	EOF
 	test_must_fail git config --int --get aninvalid.unit 2>actual &&
-	test_i18ncmp expect actual
+	test_i18ngrep "bad numeric config value .1auto. for .aninvalid.unit. in file .git/config: invalid unit" actual
 '
 
 test_expect_success 'invalid stdin config' '
-	echo "fatal: bad config line 1 in standard input " >expect &&
 	echo "[broken" | test_must_fail git config --list --file - >output 2>&1 &&
-	test_cmp expect output
+	test_i18ngrep "bad config line 1 in standard input" output
 '
 
 cat > expect << EOF