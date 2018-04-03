
	rm -f .gitattributes
	git config core.whitespace cr-at-eol
	prepare_output

	grep Eight normal >/dev/null &&
	grep HT error >/dev/null &&
