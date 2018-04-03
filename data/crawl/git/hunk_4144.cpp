 cat >expect80 <<'EOF'
  abcd | 1000 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 EOF
-
+cat >expect80-graph <<'EOF'
+|  abcd | 1000 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+EOF
 cat >expect200 <<'EOF'
  abcd | 1000 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 EOF
-
+cat >expect200-graph <<'EOF'
+|  abcd | 1000 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+EOF
 while read verb expect cmd args
 do
 	test_expect_success "$cmd $verb COLUMNS (big change)" '
 		COLUMNS=200 git $cmd $args >output
 		grep " | " output >actual &&
 		test_cmp "$expect" actual
 	'
+
+	test "$cmd" != diff || continue
+
+	test_expect_success "$cmd --graph $verb COLUMNS (big change)" '
+		COLUMNS=200 git $cmd $args --graph >output
+		grep " | " output >actual &&
+		test_cmp "$expect-graph" actual
+	'
 done <<\EOF
 ignores expect80 format-patch -1 --stdout
 respects expect200 diff HEAD^ HEAD --stat
