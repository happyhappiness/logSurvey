	git commit -s -m "Third on side" &&

	# Back to default
	git config i18n.commitencoding UTF-8
'

test_expect_success 'format-patch output (ISO-8859-1)' '
	git config i18n.logoutputencoding ISO-8859-1 &&

	git format-patch --stdout master..HEAD^ >out-l1 &&
	git format-patch --stdout HEAD^ >out-l2 &&
