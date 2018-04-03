	git commit -m "Merge work in mybranch" -i hello &&
	git show-branch --topo-order --more=1 master mybranch \
		> show-branch.output &&
	test_cmp show-branch.expect show-branch.output
'

cat > resolve.expect << EOF
