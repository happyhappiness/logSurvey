	git config aninvalid.unit >actual &&
	test_cmp expect actual &&
	cat >expect <<-\EOF &&
	fatal: bad numeric config value '\''1auto'\'' for '\''aninvalid.unit'\'' in .git/config: invalid unit
	EOF
	test_must_fail git config --int --get aninvalid.unit 2>actual &&
	test_i18ncmp expect actual
'

cat > expect << EOF
true
false
