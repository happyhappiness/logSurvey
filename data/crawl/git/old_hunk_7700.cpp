
'

test_expect_success 'with indent-non-tab only' '

	git config core.whitespace indent,-trailing,-space
	git diff --color >output
	grep "$blue_grep" output >error
