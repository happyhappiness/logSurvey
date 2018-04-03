
	git format-patch --cover-letter -2 &&
	sed -e "1,/A U Thor/d" -e "/^$/q" < 0000-cover-letter.patch > output &&
	test_cmp expect output

'

