	git checkout mybranch &&
	git merge -m "Merge upstream changes." master |
		sed -e "1s/[0-9a-f]\{7\}/VARIABLE/g" \
		-e "s/^Fast[- ]forward /FASTFORWARD /" >resolve.output
'

test_expect_success C_LOCALE_OUTPUT 'git resolve output' '
	test_cmp resolve.expect resolve.output
'
