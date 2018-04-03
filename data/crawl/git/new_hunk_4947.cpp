#!/bin/sh
#
# Copyright (c) 2010 Johan Herland
#

test_description='Test notes merging with manual conflict resolution'

. ./test-lib.sh

# Set up a notes merge scenario with different kinds of conflicts
test_expect_success 'setup commits' '
	test_commit 1st &&
	test_commit 2nd &&
	test_commit 3rd &&
	test_commit 4th &&
	test_commit 5th
'

commit_sha1=$(git rev-parse 1st^{commit})
commit_sha2=$(git rev-parse 2nd^{commit})
commit_sha3=$(git rev-parse 3rd^{commit})
commit_sha4=$(git rev-parse 4th^{commit})
commit_sha5=$(git rev-parse 5th^{commit})

verify_notes () {
	notes_ref="$1"
	git -c core.notesRef="refs/notes/$notes_ref" notes |
		sort >"output_notes_$notes_ref" &&
	test_cmp "expect_notes_$notes_ref" "output_notes_$notes_ref" &&
	git -c core.notesRef="refs/notes/$notes_ref" log --format="%H %s%n%N" \
		>"output_log_$notes_ref" &&
	test_cmp "expect_log_$notes_ref" "output_log_$notes_ref"
}

cat <<EOF | sort >expect_notes_x
6e8e3febca3c2bb896704335cc4d0c34cb2f8715 $commit_sha4
e5388c10860456ee60673025345fe2e153eb8cf8 $commit_sha3
ceefa674873670e7ecd131814d909723cce2b669 $commit_sha2
EOF

cat >expect_log_x <<EOF
$commit_sha5 5th

$commit_sha4 4th
x notes on 4th commit

$commit_sha3 3rd
x notes on 3rd commit

$commit_sha2 2nd
x notes on 2nd commit

$commit_sha1 1st

EOF

test_expect_success 'setup merge base (x)' '
	git config core.notesRef refs/notes/x &&
	git notes add -m "x notes on 2nd commit" 2nd &&
	git notes add -m "x notes on 3rd commit" 3rd &&
	git notes add -m "x notes on 4th commit" 4th &&
	verify_notes x
'

cat <<EOF | sort >expect_notes_y
e2bfd06a37dd2031684a59a6e2b033e212239c78 $commit_sha4
5772f42408c0dd6f097a7ca2d24de0e78d1c46b1 $commit_sha3
b0a6021ec006d07e80e9b20ec9b444cbd9d560d3 $commit_sha1
EOF

cat >expect_log_y <<EOF
$commit_sha5 5th

$commit_sha4 4th
y notes on 4th commit

$commit_sha3 3rd
y notes on 3rd commit

$commit_sha2 2nd

$commit_sha1 1st
y notes on 1st commit

EOF

test_expect_success 'setup local branch (y)' '
	git update-ref refs/notes/y refs/notes/x &&
	git config core.notesRef refs/notes/y &&
	git notes add -f -m "y notes on 1st commit" 1st &&
	git notes remove 2nd &&
	git notes add -f -m "y notes on 3rd commit" 3rd &&
	git notes add -f -m "y notes on 4th commit" 4th &&
	verify_notes y
'

cat <<EOF | sort >expect_notes_z
cff59c793c20bb49a4e01bc06fb06bad642e0d54 $commit_sha4
283b48219aee9a4105f6cab337e789065c82c2b9 $commit_sha2
0a81da8956346e19bcb27a906f04af327e03e31b $commit_sha1
EOF

cat >expect_log_z <<EOF
$commit_sha5 5th

$commit_sha4 4th
z notes on 4th commit

$commit_sha3 3rd

$commit_sha2 2nd
z notes on 2nd commit

$commit_sha1 1st
z notes on 1st commit

EOF

test_expect_success 'setup remote branch (z)' '
	git update-ref refs/notes/z refs/notes/x &&
	git config core.notesRef refs/notes/z &&
	git notes add -f -m "z notes on 1st commit" 1st &&
	git notes add -f -m "z notes on 2nd commit" 2nd &&
	git notes remove 3rd &&
	git notes add -f -m "z notes on 4th commit" 4th &&
	verify_notes z
'

# At this point, before merging z into y, we have the following status:
#
# commit | base/x  | local/y | remote/z | diff from x to y/z
# -------|---------|---------|----------|---------------------------
# 1st    | [none]  | b0a6021 | 0a81da8  | added     / added (diff)
# 2nd    | ceefa67 | [none]  | 283b482  | removed   / changed
# 3rd    | e5388c1 | 5772f42 | [none]   | changed   / removed
# 4th    | 6e8e3fe | e2bfd06 | cff59c7  | changed   / changed (diff)
# 5th    | [none]  | [none]  | [none]   | [none]

cat <<EOF | sort >expect_conflicts
$commit_sha1
$commit_sha2
$commit_sha3
$commit_sha4
EOF

cat >expect_conflict_$commit_sha1 <<EOF
<<<<<<< refs/notes/m
y notes on 1st commit
=======
z notes on 1st commit
>>>>>>> refs/notes/z
EOF

cat >expect_conflict_$commit_sha2 <<EOF
z notes on 2nd commit
EOF

cat >expect_conflict_$commit_sha3 <<EOF
y notes on 3rd commit
EOF

cat >expect_conflict_$commit_sha4 <<EOF
<<<<<<< refs/notes/m
y notes on 4th commit
=======
z notes on 4th commit
>>>>>>> refs/notes/z
EOF

cp expect_notes_y expect_notes_m
cp expect_log_y expect_log_m

git rev-parse refs/notes/y > pre_merge_y

test_expect_success 'merge z into m (== y) with default ("manual") resolver => Conflicting 3-way merge' '
	git update-ref refs/notes/m refs/notes/y &&
	git config core.notesRef refs/notes/m &&
	test_must_fail git notes merge z >output &&
	# Output should point to where to resolve conflicts
	grep -q "\\.git/NOTES_MERGE_WORKTREE" output &&
	# Inspect merge conflicts
	ls .git/NOTES_MERGE_WORKTREE >output_conflicts &&
	test_cmp expect_conflicts output_conflicts &&
	( for f in $(cat expect_conflicts); do
		test_cmp "expect_conflict_$f" ".git/NOTES_MERGE_WORKTREE/$f" ||
		exit 1
	done ) &&
	# Verify that current notes tree (pre-merge) has not changed (m == y)
	verify_notes y &&
	verify_notes m &&
	test "$(git rev-parse refs/notes/m)" = "$(cat pre_merge_y)"
'

cat <<EOF | sort >expect_notes_z
00494adecf2d9635a02fa431308d67993f853968 $commit_sha4
283b48219aee9a4105f6cab337e789065c82c2b9 $commit_sha2
0a81da8956346e19bcb27a906f04af327e03e31b $commit_sha1
EOF

cat >expect_log_z <<EOF
$commit_sha5 5th

$commit_sha4 4th
z notes on 4th commit

More z notes on 4th commit

$commit_sha3 3rd

$commit_sha2 2nd
z notes on 2nd commit

$commit_sha1 1st
z notes on 1st commit

EOF

test_expect_success 'change notes in z' '
	git notes --ref z append -m "More z notes on 4th commit" 4th &&
	verify_notes z
'

test_expect_success 'cannot do merge w/conflicts when previous merge is unfinished' '
	test -d .git/NOTES_MERGE_WORKTREE &&
	test_must_fail git notes merge z >output 2>&1 &&
	# Output should indicate what is wrong
	grep -q "\\.git/NOTES_MERGE_\\* exists" output
'

# Setup non-conflicting merge between x and new notes ref w

cat <<EOF | sort >expect_notes_w
ceefa674873670e7ecd131814d909723cce2b669 $commit_sha2
f75d1df88cbfe4258d49852f26cfc83f2ad4494b $commit_sha1
EOF

cat >expect_log_w <<EOF
$commit_sha5 5th

$commit_sha4 4th

$commit_sha3 3rd

$commit_sha2 2nd
x notes on 2nd commit

$commit_sha1 1st
w notes on 1st commit

EOF

test_expect_success 'setup unrelated notes ref (w)' '
	git config core.notesRef refs/notes/w &&
	git notes add -m "w notes on 1st commit" 1st &&
	git notes add -m "x notes on 2nd commit" 2nd &&
	verify_notes w
'

cat <<EOF | sort >expect_notes_w
6e8e3febca3c2bb896704335cc4d0c34cb2f8715 $commit_sha4
e5388c10860456ee60673025345fe2e153eb8cf8 $commit_sha3
ceefa674873670e7ecd131814d909723cce2b669 $commit_sha2
f75d1df88cbfe4258d49852f26cfc83f2ad4494b $commit_sha1
EOF

cat >expect_log_w <<EOF
$commit_sha5 5th

$commit_sha4 4th
x notes on 4th commit

$commit_sha3 3rd
x notes on 3rd commit

$commit_sha2 2nd
x notes on 2nd commit

$commit_sha1 1st
w notes on 1st commit

EOF

test_expect_success 'can do merge without conflicts even if previous merge is unfinished (x => w)' '
	test -d .git/NOTES_MERGE_WORKTREE &&
	git notes merge x &&
	verify_notes w &&
	# Verify that other notes refs has not changed (x and y)
	verify_notes x &&
	verify_notes y
'

test_done