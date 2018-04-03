	git add dir2/added
'

test_expect_success 'status (1)' '
	test_i18ngrep "use \"git rm --cached <file>\.\.\.\" to unstage" output
'

cat >expect <<\EOF
