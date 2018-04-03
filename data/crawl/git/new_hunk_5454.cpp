
blue_grep='7;34m' ;# ESC [ 7 ; 3 4 m

printf "\033[%s" "$blue_grep" >check-grep
if (grep "$blue_grep" <check-grep | grep "$blue_grep") >/dev/null 2>&1
then
	grep_a=grep
elif (grep -a "$blue_grep" <check-grep | grep -a "$blue_grep") >/dev/null 2>&1
then
	grep_a='grep -a'
else
	grep_a=grep ;# expected to fail...
fi
rm -f check-grep

prepare_output () {
	git diff --color >output
	$grep_a "$blue_grep" output >error
	$grep_a -v "$blue_grep" output >normal
}

test_expect_success default '

	prepare_output

	grep Eight normal >/dev/null &&
	grep HT error >/dev/null &&
