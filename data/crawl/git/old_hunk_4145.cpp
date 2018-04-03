		grep " | " output >actual &&
		test_cmp "$expect" actual
	'
done <<\EOF
ignores expect80 format-patch -1 --stdout
respects expect40 diff HEAD^ HEAD --stat
