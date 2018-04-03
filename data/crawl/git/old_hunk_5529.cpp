EOF

test_expect_success 'git whatchanged -p --root' '
	git whatchanged -p --root | \
		sed -e "1s/^\(.\{7\}\).\{40\}/\1VARIABLE/" \
		-e "2,3s/^\(.\{8\}\).*$/\1VARIABLE/" \
	> whatchanged.output &&
	cmp whatchanged.expect whatchanged.output
'

test_expect_success 'git tag my-first-tag' '
	git tag my-first-tag &&
	cmp .git/refs/heads/master .git/refs/tags/my-first-tag
'

test_expect_success 'git checkout -b mybranch' '
	git checkout -b mybranch &&
	cmp .git/refs/heads/master .git/refs/heads/mybranch
'

cat > branch.expect <<EOF
