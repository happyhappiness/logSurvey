
	git config --unset core.whitespace
	echo "F whitespace=trailing,cr-at-eol" >.gitattributes
	git diff --color >output
	grep "$blue_grep" output >error
	grep -v "$blue_grep" output >normal

	grep Eight normal >/dev/null &&
	grep HT error >/dev/null &&
