#!/bin/sh

test_description='add -i basic tests'
. ./test-lib.sh

test_expect_success 'setup (initial)' '
	echo content >file &&
	git add file &&
	echo more >>file &&
	echo lines >>file
'
test_expect_success 'status works (initial)' '
	git add -i </dev/null >output &&
	grep "+1/-0 *+2/-0 file" output
'
cat >expected <<EOF
new file mode 100644
index 0000000..d95f3ad
--- /dev/null
@@ -0,0 +1 @@
EOF
test_expect_success 'diff works (initial)' '
	(echo d; echo 1) | git add -i >output &&
	sed -ne "/new file/,/content/p" <output >diff &&
	diff -u expected diff
'
test_expect_success 'revert works (initial)' '
	git add file &&
	(echo r; echo 1) | git add -i &&
	git ls-files >output &&
	! grep . output
'

test_expect_success 'setup (commit)' '
	echo baseline >file &&
	git add file &&
	git commit -m commit &&
	echo content >>file &&
	git add file &&
	echo more >>file &&
	echo lines >>file
'
test_expect_success 'status works (commit)' '
	git add -i </dev/null >output &&
	grep "+1/-0 *+2/-0 file" output
'
cat >expected <<EOF
index 180b47c..b6f2c08 100644
--- a/file
@@ -1 +1,2 @@
 baseline
EOF
test_expect_success 'diff works (commit)' '
	(echo d; echo 1) | git add -i >output &&
	sed -ne "/^index/,/content/p" <output >diff &&
	diff -u expected diff
'
test_expect_success 'revert works (commit)' '
	git add file &&
	(echo r; echo 1) | git add -i &&
	git add -i </dev/null >output &&
	grep "unchanged *+3/-0 file" output
'

test_done