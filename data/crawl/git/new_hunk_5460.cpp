
	git config --unset core.whitespace
	echo "F whitespace=indent,-trailing,-space" >.gitattributes
	prepare_output

	grep Eight error >/dev/null &&
	grep HT normal >/dev/null &&
