*+ [mybranch] Some work.
EOF

test_expect_success 'git show-branch' '
	git commit -m "Merged \"mybranch\" changes." -i hello &&
	git show-branch --topo-order master mybranch > show-branch.output &&
	cmp show-branch.expect show-branch.output
'

cat > resolve.expect << EOF
Updating VARIABLE..VARIABLE
Fast forward (no commit created; -m option ignored)
 example |    1 +
 hello   |    1 +
 2 files changed, 2 insertions(+), 0 deletions(-)
EOF

test_expect_success 'git resolve' '
	git checkout mybranch &&
	git merge -m "Merge upstream changes." master | \
		sed -e "1s/[0-9a-f]\{7\}/VARIABLE/g" >resolve.output &&
	cmp resolve.expect resolve.output
'

cat > show-branch2.expect << EOF
! [master] Merged "mybranch" changes.
