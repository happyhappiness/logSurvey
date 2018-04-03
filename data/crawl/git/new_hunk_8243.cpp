+Hello World
EOF

git whatchanged -p --root | \
	sed -e "1s/^\(.\{7\}\).\{40\}/\1VARIABLE/" \
		-e "2,3s/^\(.\{8\}\).*$/\1VARIABLE/" \
> whatchanged.output
test_expect_success 'git whatchanged -p --root' 'cmp whatchanged.expect whatchanged.output'

git tag my-first-tag
test_expect_success 'git tag my-first-tag' 'cmp .git/refs/heads/master .git/refs/tags/my-first-tag'
