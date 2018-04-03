
'

test_expect_success 'set-up a few more tags for tag export tests' '
	git checkout -f master &&
	HEAD_TREE=`git show -s --pretty=raw HEAD | grep tree | sed "s/tree //"` &&
	git tag    tree_tag        -m "tagging a tree" $HEAD_TREE &&
	git tag -a tree_tag-obj    -m "tagging a tree" $HEAD_TREE &&
	git tag    tag-obj_tag     -m "tagging a tag" tree_tag-obj &&
	git tag -a tag-obj_tag-obj -m "tagging a tag" tree_tag-obj
'

# NEEDSWORK: not just check return status, but validate the output
# two tests commented out due to crash and thus unreliable return code
test_expect_failure 'tree_tag'        'git fast-export tree_tag'
test_expect_failure 'tree_tag-obj'    'git fast-export tree_tag-obj'
test_expect_failure 'tag-obj_tag'     'git fast-export tag-obj_tag'
test_expect_failure 'tag-obj_tag-obj' 'git fast-export tag-obj_tag-obj'

test_done