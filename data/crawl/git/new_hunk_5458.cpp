
	git config --unset core.whitespace
	echo "F whitespace=-space" >.gitattributes
	prepare_output

	grep Eight normal >/dev/null &&
	grep HT normal >/dev/null &&
