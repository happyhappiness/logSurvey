'

cat > show-branch2.expect << EOF
! [master] Merged "mybranch" changes.
 * [mybranch] Merged "mybranch" changes.
--
EOF

test_expect_success 'git show-branch (part 2)' '
	git show-branch --topo-order master mybranch > show-branch2.output &&
	cmp show-branch2.expect show-branch2.output
'

test_expect_success 'git repack' 'git repack'
test_expect_success 'git prune-packed' 'git prune-packed'
test_expect_success '-> only packed objects' '