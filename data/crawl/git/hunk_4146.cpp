 		test_cmp expect actual
 	'
 
-	test_expect_success "$cmd --stat-graph--width with big change" '
+	test_expect_success "$cmd --stat-graph-width with big change" '
 		git $cmd $args --stat-graph-width=26 >output
 		grep " | " output >actual &&
 		test_cmp expect actual
 	'
+
+	test "$cmd" != diff || continue
+
+	test_expect_success "$cmd --stat-width=width --graph with big change" '
+		git $cmd $args --stat-width=40 --graph >output
+		grep " | " output >actual &&
+		test_cmp expect-graph actual
+	'
+
+	test_expect_success "$cmd --stat-graph-width --graph with big change" '
+		git $cmd $args --stat-graph-width=26 --graph >output
+		grep " | " output >actual &&
+		test_cmp expect-graph actual
+	'
 done <<\EOF
 format-patch -1 --stdout
 diff HEAD^ HEAD --stat
