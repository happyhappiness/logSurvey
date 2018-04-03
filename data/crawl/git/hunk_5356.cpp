 	test_cmp expect-not-other output
 '
 
+cat > expect-both << EOF
+commit 387a89921c73d7ed72cd94d179c1c7048ca47756
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:18:13 2005 -0700
+
+    6th
+
+Notes:
+    order test
+
+Notes (other):
+    other note
+
+commit bd1753200303d0a0344be813e504253b3d98e74d
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:17:13 2005 -0700
+
+    5th
+
+Notes:
+    replacement for deleted note
+EOF
+
+test_expect_success 'Show all notes when notes.displayRef=refs/notes/*' '
+	GIT_NOTES_REF=refs/notes/commits git notes add \
+		-m"replacement for deleted note" HEAD^ &&
+	GIT_NOTES_REF=refs/notes/commits git notes add -m"order test" &&
+	git config --unset core.notesRef &&
+	git config notes.displayRef "refs/notes/*" &&
+	git log -2 > output &&
+	test_cmp expect-both output
+'
+
+test_expect_success 'core.notesRef is implicitly in notes.displayRef' '
+	git config core.notesRef refs/notes/commits &&
+	git config notes.displayRef refs/notes/other &&
+	git log -2 > output &&
+	test_cmp expect-both output
+'
+
+test_expect_success 'notes.displayRef can be given more than once' '
+	git config --unset core.notesRef &&
+	git config notes.displayRef refs/notes/commits &&
+	git config --add notes.displayRef refs/notes/other &&
+	git log -2 > output &&
+	test_cmp expect-both output
+'
+
+cat > expect-both-reversed << EOF
+commit 387a89921c73d7ed72cd94d179c1c7048ca47756
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:18:13 2005 -0700
+
+    6th
+
+Notes (other):
+    other note
+
+Notes:
+    order test
+EOF
+
+test_expect_success 'notes.displayRef respects order' '
+	git config core.notesRef refs/notes/other &&
+	git config --unset-all notes.displayRef &&
+	git config notes.displayRef refs/notes/commits &&
+	git log -1 > output &&
+	test_cmp expect-both-reversed output
+'
+
+test_expect_success 'GIT_NOTES_DISPLAY_REF works' '
+	git config --unset-all core.notesRef &&
+	git config --unset-all notes.displayRef &&
+	GIT_NOTES_DISPLAY_REF=refs/notes/commits:refs/notes/other \
+		git log -2 > output &&
+	test_cmp expect-both output
+'
+
+cat > expect-none << EOF
+commit 387a89921c73d7ed72cd94d179c1c7048ca47756
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:18:13 2005 -0700
+
+    6th
+
+commit bd1753200303d0a0344be813e504253b3d98e74d
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:17:13 2005 -0700
+
+    5th
+EOF
+
+test_expect_success 'GIT_NOTES_DISPLAY_REF overrides config' '
+	git config notes.displayRef "refs/notes/*" &&
+	GIT_NOTES_REF= GIT_NOTES_DISPLAY_REF= git log -2 > output &&
+	test_cmp expect-none output
+'
+
+test_expect_success '--show-notes=* adds to GIT_NOTES_DISPLAY_REF' '
+	GIT_NOTES_REF= GIT_NOTES_DISPLAY_REF= git log --show-notes=* -2 > output &&
+	test_cmp expect-both output
+'
+
+cat > expect-commits << EOF
+commit 387a89921c73d7ed72cd94d179c1c7048ca47756
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:18:13 2005 -0700
+
+    6th
+
+Notes:
+    order test
+EOF
+
+test_expect_success '--no-standard-notes' '
+	git log --no-standard-notes --show-notes=commits -1 > output &&
+	test_cmp expect-commits output
+'
+
+test_expect_success '--standard-notes' '
+	git log --no-standard-notes --show-notes=commits \
+		--standard-notes -2 > output &&
+	test_cmp expect-both output
+'
+
+test_expect_success '--show-notes=ref accumulates' '
+	git log --show-notes=other --show-notes=commits \
+		 --no-standard-notes -1 > output &&
+	test_cmp expect-both-reversed output
+'
+
 test_expect_success 'Allow notes on non-commits (trees, blobs, tags)' '
+	git config core.notesRef refs/notes/other &&
 	echo "Note on a tree" > expect
 	git notes add -m "Note on a tree" HEAD: &&
 	git notes show HEAD: > actual &&
