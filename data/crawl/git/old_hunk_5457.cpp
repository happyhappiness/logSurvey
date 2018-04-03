
	rm -f .gitattributes
	git config core.whitespace -space
	git diff --color >output
	grep "$blue_grep" output >error
	grep -v "$blue_grep" output >normal

	grep Eight normal >/dev/null &&
	grep HT normal >/dev/null &&
