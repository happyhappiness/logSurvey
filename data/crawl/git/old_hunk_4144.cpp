cat >expect80 <<'EOF'
 abcd | 1000 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
EOF

cat >expect200 <<'EOF'
 abcd | 1000 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
EOF

while read verb expect cmd args
do
	test_expect_success "$cmd $verb COLUMNS (big change)" '
		COLUMNS=200 git $cmd $args >output
		grep " | " output >actual &&
		test_cmp "$expect" actual
	'
done <<\EOF
ignores expect80 format-patch -1 --stdout
respects expect200 diff HEAD^ HEAD --stat
