
	git config --unset core.whitespace
	echo "F whitespace=trailing,cr-at-eol" >.gitattributes
	prepare_output

	grep Eight normal >/dev/null &&
	grep HT error >/dev/null &&
