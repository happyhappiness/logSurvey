		test_cmp expect actual
	'

	test_expect_success "$cmd --stat-graph--width with big change" '
		git $cmd $args --stat-graph-width=26 >output
		grep " | " output >actual &&
		test_cmp expect actual
	'
done <<\EOF
format-patch -1 --stdout
diff HEAD^ HEAD --stat
