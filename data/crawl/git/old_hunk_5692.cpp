
	rm -f .gitattributes &&
	test_must_fail git diff --check >output &&
	grep "ends with blank lines." output &&
	grep "trailing whitespace" output

'