#!/bin/sh

test_description='Test diff-highlight'

CURR_DIR=$(pwd)
TEST_OUTPUT_DIRECTORY=$(pwd)
TEST_DIRECTORY="$CURR_DIR"/../../../t
DIFF_HIGHLIGHT="$CURR_DIR"/../diff-highlight

CW="$(printf "\033[7m")"	# white
CR="$(printf "\033[27m")"	# reset

. "$TEST_DIRECTORY"/test-lib.sh

if ! test_have_prereq PERL
then
	skip_all='skipping diff-highlight tests; perl not available'
	test_done
fi

# dh_test is a test helper function which takes 3 file names as parameters. The
# first 2 files are used to generate diff and commit output, which is then
# piped through diff-highlight. The 3rd file should contain the expected output
# of diff-highlight (minus the diff/commit header, ie. everything after and
# including the first @@ line).
dh_test () {
	a="$1" b="$2" &&

	cat >patch.exp &&

	{
		cat "$a" >file &&
		git add file &&
		git commit -m "Add a file" &&

		cat "$b" >file &&
		git diff file >diff.raw &&
		git commit -a -m "Update a file" &&
		git show >commit.raw
	} >/dev/null &&

	"$DIFF_HIGHLIGHT" <diff.raw | test_strip_patch_header >diff.act &&
	"$DIFF_HIGHLIGHT" <commit.raw | test_strip_patch_header >commit.act &&
	test_cmp patch.exp diff.act &&
	test_cmp patch.exp commit.act
}

test_strip_patch_header () {
	sed -n '/^@@/,$p' $*
}

test_expect_success 'diff-highlight highlights the beginning of a line' '
	cat >a <<-\EOF &&
		aaa
		bbb
		ccc
	EOF

	cat >b <<-\EOF &&
		aaa
		0bb
		ccc
	EOF

	dh_test a b <<-EOF
		@@ -1,3 +1,3 @@
		 aaa
		-${CW}b${CR}bb
		+${CW}0${CR}bb
		 ccc
	EOF
'

test_expect_success 'diff-highlight highlights the end of a line' '
	cat >a <<-\EOF &&
		aaa
		bbb
		ccc
	EOF

	cat >b <<-\EOF &&
		aaa
		bb0
		ccc
	EOF

	dh_test a b <<-EOF
		@@ -1,3 +1,3 @@
		 aaa
		-bb${CW}b${CR}
		+bb${CW}0${CR}
		 ccc
	EOF
'

test_expect_success 'diff-highlight highlights the middle of a line' '
	cat >a <<-\EOF &&
		aaa
		bbb
		ccc
	EOF

	cat >b <<-\EOF &&
		aaa
		b0b
		ccc
	EOF

	dh_test a b <<-EOF
		@@ -1,3 +1,3 @@
		 aaa
		-b${CW}b${CR}b
		+b${CW}0${CR}b
		 ccc
	EOF
'

test_expect_success 'diff-highlight does not highlight whole line' '
	cat >a <<-\EOF &&
		aaa
		bbb
		ccc
	EOF

	cat >b <<-\EOF &&
		aaa
		000
		ccc
	EOF

	dh_test a b <<-EOF
		@@ -1,3 +1,3 @@
		 aaa
		-bbb
		+000
		 ccc
	EOF
'

test_expect_failure 'diff-highlight highlights mismatched hunk size' '
	cat >a <<-\EOF &&
		aaa
		bbb
	EOF

	cat >b <<-\EOF &&
		aaa
		b0b
		ccc
	EOF

	dh_test a b <<-EOF
		@@ -1,3 +1,3 @@
		 aaa
		-b${CW}b${CR}b
		+b${CW}0${CR}b
		+ccc
	EOF
'

# TODO add multi-byte test

test_done