 	verify_notes z
 '
 
+cp expect_notes_y expect_notes_m
+cp expect_log_y expect_log_m
+
+test_expect_success 'redo merge of z into m (== y) with default ("manual") resolver => Conflicting 3-way merge' '
+	git update-ref refs/notes/m refs/notes/y &&
+	test_must_fail git notes merge z >output &&
+	# Output should point to where to resolve conflicts
+	grep -q "\\.git/NOTES_MERGE_WORKTREE" output &&
+	# Inspect merge conflicts
+	ls .git/NOTES_MERGE_WORKTREE >output_conflicts &&
+	test_cmp expect_conflicts output_conflicts &&
+	( for f in $(cat expect_conflicts); do
+		test_cmp "expect_conflict_$f" ".git/NOTES_MERGE_WORKTREE/$f" ||
+		exit 1
+	done ) &&
+	# Verify that current notes tree (pre-merge) has not changed (m == y)
+	verify_notes y &&
+	verify_notes m &&
+	test "$(git rev-parse refs/notes/m)" = "$(cat pre_merge_y)"
+'
+
+cp expect_notes_w expect_notes_m
+cp expect_log_w expect_log_m
+
+test_expect_success 'reset notes ref m to somewhere else (w)' '
+	git update-ref refs/notes/m refs/notes/w &&
+	verify_notes m &&
+	test "$(git rev-parse refs/notes/m)" = "$(git rev-parse refs/notes/w)"
+'
+
+test_expect_success 'fail to finalize conflicting merge if underlying ref has moved in the meantime (m != NOTES_MERGE_PARTIAL^1)' '
+	# Resolve conflicts
+	cat >.git/NOTES_MERGE_WORKTREE/$commit_sha1 <<EOF &&
+y and z notes on 1st commit
+EOF
+	cat >.git/NOTES_MERGE_WORKTREE/$commit_sha4 <<EOF &&
+y and z notes on 4th commit
+EOF
+	# Fail to finalize merge
+	test_must_fail git notes merge --commit >output 2>&1 &&
+	# .git/NOTES_MERGE_* must remain
+	test -f .git/NOTES_MERGE_PARTIAL &&
+	test -f .git/NOTES_MERGE_REF &&
+	test -f .git/NOTES_MERGE_WORKTREE/$commit_sha1 &&
+	test -f .git/NOTES_MERGE_WORKTREE/$commit_sha2 &&
+	test -f .git/NOTES_MERGE_WORKTREE/$commit_sha3 &&
+	test -f .git/NOTES_MERGE_WORKTREE/$commit_sha4 &&
+	# Refs are unchanged
+	test "$(git rev-parse refs/notes/m)" = "$(git rev-parse refs/notes/w)"
+	test "$(git rev-parse refs/notes/y)" = "$(git rev-parse NOTES_MERGE_PARTIAL^1)"
+	test "$(git rev-parse refs/notes/m)" != "$(git rev-parse NOTES_MERGE_PARTIAL^1)"
+	# Mention refs/notes/m, and its current and expected value in output
+	grep -q "refs/notes/m" output &&
+	grep -q "$(git rev-parse refs/notes/m)" output &&
+	grep -q "$(git rev-parse NOTES_MERGE_PARTIAL^1)" output &&
+	# Verify that other notes refs has not changed (w, x, y and z)
+	verify_notes w &&
+	verify_notes x &&
+	verify_notes y &&
+	verify_notes z
+'
+
+test_expect_success 'resolve situation by aborting the notes merge' '
+	git notes merge --abort &&
+	# No .git/NOTES_MERGE_* files left
+	test_must_fail ls .git/NOTES_MERGE_* >output 2>/dev/null &&
+	test_cmp /dev/null output &&
+	# m has not moved (still == w)
+	test "$(git rev-parse refs/notes/m)" = "$(git rev-parse refs/notes/w)"
+	# Verify that other notes refs has not changed (w, x, y and z)
+	verify_notes w &&
+	verify_notes x &&
+	verify_notes y &&
+	verify_notes z
+'
+
 test_done