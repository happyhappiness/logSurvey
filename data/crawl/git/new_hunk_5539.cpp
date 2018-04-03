EOF

cat > show-branch.expect << EOF
* [master] Merge work in mybranch
 ! [mybranch] Some work.
--
-  [master] Merge work in mybranch
*+ [mybranch] Some work.
*  [master^] Some fun.
EOF

test_expect_success 'git show-branch' '
	git commit -m "Merge work in mybranch" -i hello &&
	git show-branch --topo-order --more=1 master mybranch \
		> show-branch.output &&
	cmp show-branch.expect show-branch.output
'

