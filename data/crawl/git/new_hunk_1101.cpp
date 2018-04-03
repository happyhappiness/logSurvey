	test -d .git/NOTES_MERGE_WORKTREE &&
	test_must_fail git notes merge z >output 2>&1 &&
	# Output should indicate what is wrong
	test_i18ngrep -q "\\.git/NOTES_MERGE_\\* exists" output
'

# Setup non-conflicting merge between x and new notes ref w