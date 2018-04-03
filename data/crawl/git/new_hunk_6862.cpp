
'

cat > expect << EOF
---
 file |   16 ++++++++++++++++
 1 files changed, 16 insertions(+), 0 deletions(-)

diff --git a/file b/file
index 40f36c6..2dc5c23 100644
--- a/file
@@ -13,4 +13,20 @@ C
 10
 D
 E
 F
EOF

test_expect_success 'format-patch respects -U' '

	git format-patch -U4 -2 &&
	sed -e "1,/^$/d" -e "/^+5/q" < 0001-This-is-an-excessively-long-subject-line-for-a-messa.patch > output &&
	test_cmp expect output

'

test_done