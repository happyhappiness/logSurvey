+#!/bin/sh
+
+test_description='diff whitespace error detection'
+
+. ./test-lib.sh
+
+test_expect_success setup '
+
+	git config diff.color.whitespace "blue reverse" &&
+	>F &&
+	git add F &&
+	echo "         Eight SP indent" >>F &&
+	echo " 	HT and SP indent" >>F &&
+	echo "With trailing SP " >>F &&
+	echo "No problem" >>F
+
+'
+
+blue_grep='7;34m' ;# ESC [ 7 ; 3 4 m
+
+test_expect_success default '
+
+	git diff --color >output
+	grep "$blue_grep" output >error
+	grep -v "$blue_grep" output >normal
+
+	grep Eight normal >/dev/null &&
+	grep HT error >/dev/null &&
+	grep With error >/dev/null &&
+	grep No normal >/dev/null
+
+'
+
+test_expect_success 'without -trail' '
+
+	git config core.whitespace -trail
+	git diff --color >output
+	grep "$blue_grep" output >error
+	grep -v "$blue_grep" output >normal
+
+	grep Eight normal >/dev/null &&
+	grep HT error >/dev/null &&
+	grep With normal >/dev/null &&
+	grep No normal >/dev/null
+
+'
+
+test_expect_success 'without -space' '
+
+	git config core.whitespace -space
+	git diff --color >output
+	grep "$blue_grep" output >error
+	grep -v "$blue_grep" output >normal
+
+	grep Eight normal >/dev/null &&
+	grep HT normal >/dev/null &&
+	grep With error >/dev/null &&
+	grep No normal >/dev/null
+
+'
+
+test_expect_success 'with indent-non-tab only' '
+
+	git config core.whitespace indent,-trailing,-space
+	git diff --color >output
+	grep "$blue_grep" output >error
+	grep -v "$blue_grep" output >normal
+
+	grep Eight error >/dev/null &&
+	grep HT normal >/dev/null &&
+	grep With normal >/dev/null &&
+	grep No normal >/dev/null
+
+'
+
+test_done