
	git config --unset core.whitespace
	echo "F whitespace=-trail" >.gitattributes
	prepare_output

	grep Eight normal >/dev/null &&
	grep HT error >/dev/null &&
