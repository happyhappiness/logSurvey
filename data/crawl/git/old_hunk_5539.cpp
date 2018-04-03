EOF

cat > show-branch.expect << EOF
* [master] Merged "mybranch" changes.
 ! [mybranch] Some work.
--
*+ [mybranch] Some work.
EOF

test_expect_success 'git show-branch' '
	git commit -m "Merged \"mybranch\" changes." -i hello &&
	git show-branch --topo-order master mybranch > show-branch.output &&
	cmp show-branch.expect show-branch.output
'

