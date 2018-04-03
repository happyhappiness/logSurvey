+Hello World
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
  master
* mybranch
EOF

test_expect_success 'git branch' '
	git branch > branch.output &&
	cmp branch.expect branch.output
'

test_expect_success 'git resolve now fails' '
	git checkout mybranch &&
	echo "Work, work, work" >>hello &&
	git commit -m "Some work." -i hello &&

	git checkout master &&

	echo "Play, play, play" >>hello &&
	echo "Lots of fun" >>example &&
	git commit -m "Some fun." -i hello example &&

	test_must_fail git merge -m "Merge work in mybranch" mybranch
'

