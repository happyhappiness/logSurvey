
'

cat > expect << EOF

diff --git a/file b/file
index 40f36c6..2dc5c23 100644
--- a/file
@@ -14,3 +14,19 @@ C
 D
 E
 F
EOF

test_expect_success 'format-patch -p suppresses stat' '

	git format-patch -p -2 &&
	sed -e "1,/^$/d" -e "/^+5/q" < 0001-This-is-an-excessively-long-subject-line-for-a-messa.patch > output &&
	test_cmp expect output

'

test_expect_success 'format-patch from a subdirectory (1)' '
	filename=$(
		rm -rf sub &&