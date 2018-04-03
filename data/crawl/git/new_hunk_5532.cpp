
test_expect_success 'git resolve' '
	git checkout mybranch &&
	git merge -m "Merge upstream changes." master |
		sed -e "1s/[0-9a-f]\{7\}/VARIABLE/g" >resolve.output &&
	test_cmp resolve.expect resolve.output
'

cat > show-branch2.expect << EOF
