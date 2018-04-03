
	rm -f .gitattributes
	git config core.whitespace -space
	prepare_output

	grep Eight normal >/dev/null &&
	grep HT normal >/dev/null &&
