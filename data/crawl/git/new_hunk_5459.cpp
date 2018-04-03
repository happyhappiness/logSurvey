
	rm -f .gitattributes
	git config core.whitespace indent,-trailing,-space
	prepare_output

	grep Eight error >/dev/null &&
	grep HT normal >/dev/null &&
