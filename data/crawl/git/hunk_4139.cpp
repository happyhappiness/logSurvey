 respects expect200 log -1 --stat
 EOF
 
+cat >expect1 <<'EOF'
+ ...aaaaaaa | 1000 ++++++
+EOF
+cat >expect1-graph <<'EOF'
+|  ...aaaaaaa | 1000 ++++++
+EOF
+while read teststate verb expect cmd args
+do
+	test_expect_$teststate "$cmd $verb prefix greater than COLUMNS (big change)" '
+		COLUMNS=1 git $cmd $args >output
+		grep " | " output >actual &&
+		test_cmp "$expect" actual
+	'
+
+	test "$cmd" != diff || continue
+
+	test_expect_$teststate "$cmd --graph $verb prefix greater than COLUMNS (big change)" '
+		COLUMNS=1 git $cmd $args --graph >output
+		grep " | " output >actual &&
+		test_cmp "$expect-graph" actual
+	'
+done <<\EOF
+success ignores expect80 format-patch -1 --stdout
+failure respects expect1 diff HEAD^ HEAD --stat
+failure respects expect1 show --stat
+failure respects expect1 log -1 --stat
+EOF
+
 cat >expect <<'EOF'
  abcd | 1000 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 EOF