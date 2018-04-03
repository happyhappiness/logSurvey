	git config -f .gitmodules  --remove-section submodule.subname
'

cat > expect << EOF
; On branch master
; Changes to be committed:
;   (use "git reset HEAD <file>..." to unstage)
;
;	modified:   sm
;
; Changes not staged for commit:
;   (use "git add <file>..." to update what will be committed)
;   (use "git checkout -- <file>..." to discard changes in working directory)
;
;	modified:   dir1/modified
;	modified:   sm (new commits)
;
; Submodule changes to be committed:
;
; * sm $head...$new_head (1):
;   > Add bar
;
; Submodules changed but not updated:
;
; * sm $new_head...$head2 (1):
;   > 2nd commit
;
; Untracked files:
;   (use "git add <file>..." to include in what will be committed)
;
;	.gitmodules
;	dir1/untracked
;	dir2/modified
;	dir2/untracked
;	expect
;	output
;	untracked
EOF

test_expect_success "status (core.commentchar with submodule summary)" '
	test_when_finished "git config --unset core.commentchar" &&
	git config core.commentchar ";" &&
	git status >output &&
	test_i18ncmp expect output
'

test_expect_success "status (core.commentchar with two chars with submodule summary)" '
	test_when_finished "git config --unset core.commentchar" &&
	git config core.commentchar ";;" &&
	git status >output &&
	test_i18ncmp expect output
'

cat > expect << EOF
# On branch master
# Changes not staged for commit:
