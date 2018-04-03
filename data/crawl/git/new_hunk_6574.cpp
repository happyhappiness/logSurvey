
'

cat > tag-content << EOF
object $(git rev-parse HEAD)
type commit
tag rosten
EOF

test_expect_success 'cope with tagger-less tags' '

	TAG=$(git hash-object -t tag -w tag-content) &&
	git update-ref refs/tags/sonnenschein $TAG &&
	git fast-export -C -C --signed-tags=strip --all > output &&
	test $(grep -c "^tag " output) = 4 &&
	! grep "Unspecified Tagger" output &&
	git fast-export -C -C --signed-tags=strip --all \
		--fake-missing-tagger > output &&
	test $(grep -c "^tag " output) = 4 &&
	grep "Unspecified Tagger" output

'

test_done