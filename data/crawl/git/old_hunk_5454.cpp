
blue_grep='7;34m' ;# ESC [ 7 ; 3 4 m

test_expect_success default '

	git diff --color >output
	grep "$blue_grep" output >error
	grep -v "$blue_grep" output >normal

	grep Eight normal >/dev/null &&
	grep HT error >/dev/null &&
