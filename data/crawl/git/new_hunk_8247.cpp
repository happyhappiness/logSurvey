 4 files changed, 2 insertions(+), 2 deletions(-)
EOF
test_expect_success 'diff without --binary' \
	'git diff | git apply --stat --summary >current &&
	 cmp current expected'

test_expect_success 'diff with --binary' \
	'git diff --binary | git apply --stat --summary >current &&
	 cmp current expected'

# apply needs to be able to skip the binary material correctly
# in order to report the line number of a corrupt patch.
test_expect_success 'apply detecting corrupt patch correctly' \
	'git diff | sed -e 's/-CIT/xCIT/' >broken &&
	 if git apply --stat --summary broken 2>detected
	 then
		echo unhappy - should have detected an error
		(exit 1)
