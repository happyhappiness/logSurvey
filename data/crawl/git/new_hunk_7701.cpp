
'

test_expect_success 'with indent-non-tab only (attribute)' '

	git config --unset core.whitespace
	echo "F whitespace=indent,-trailing,-space" >.gitattributes
	git diff --color >output
	grep "$blue_grep" output >error
	grep -v "$blue_grep" output >normal

	grep Eight error >/dev/null &&
	grep HT normal >/dev/null &&
	grep With normal >/dev/null &&
	grep No normal >/dev/null

'

test_done
