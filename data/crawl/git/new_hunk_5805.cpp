	git tag -a tag-obj_tag-obj -m "tagging a tag" tree_tag-obj
'

test_expect_success 'tree_tag'        '
	mkdir result &&
	(cd result && git init) &&
	git fast-export tree_tag > fe-stream &&
	(cd result && git fast-import < ../fe-stream)
'

# NEEDSWORK: not just check return status, but validate the output
test_expect_success 'tree_tag-obj'    'git fast-export tree_tag-obj'
test_expect_success 'tag-obj_tag'     'git fast-export tag-obj_tag'
test_expect_success 'tag-obj_tag-obj' 'git fast-export tag-obj_tag-obj'