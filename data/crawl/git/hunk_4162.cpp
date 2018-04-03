 	'n=$(grep $a verify | wc -l) &&
 	 test 1 = $n'
 
+###
+### series S
+###
+#
+# Make sure missing spaces and EOLs after mark references
+# cause errors.
+#
+# Setup:
+#
+#   1--2--4
+#    \   /
+#     -3-
+#
+#   commit marks:  301, 302, 303, 304
+#   blob marks:              403, 404, resp.
+#   note mark:          202
+#
+# The error message when a space is missing not at the
+# end of the line is:
+#
+#   Missing space after ..
+#
+# or when extra characters come after the mark at the end
+# of the line:
+#
+#   Garbage after ..
+#
+# or when the dataref is neither "inline " or a known SHA1,
+#
+#   Invalid dataref ..
+#
+test_tick
+
+cat >input <<INPUT_END
+commit refs/heads/S
+mark :301
+committer $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL> $GIT_COMMITTER_DATE
+data <<COMMIT
+commit 1
+COMMIT
+M 100644 inline hello.c
+data <<BLOB
+blob 1
+BLOB
+
+commit refs/heads/S
+mark :302
+committer $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL> $GIT_COMMITTER_DATE
+data <<COMMIT
+commit 2
+COMMIT
+from :301
+M 100644 inline hello.c
+data <<BLOB
+blob 2
+BLOB
+
+blob
+mark :403
+data <<BLOB
+blob 3
+BLOB
+
+blob
+mark :202
+data <<BLOB
+note 2
+BLOB
+INPUT_END
+
+test_expect_success 'S: initialize for S tests' '
+	git fast-import --export-marks=marks <input
+'
+
+#
+# filemodify, three datarefs
+#
+test_expect_success 'S: filemodify with garbage after mark must fail' '
+	test_must_fail git fast-import --import-marks=marks <<-EOF 2>err &&
+	commit refs/heads/S
+	committer $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL> $GIT_COMMITTER_DATE
+	data <<COMMIT
+	commit N
+	COMMIT
+	M 100644 :403x hello.c
+	EOF
+	cat err &&
+	test_i18ngrep "space after mark" err
+'
+
+# inline is misspelled; fast-import thinks it is some unknown dataref
+test_expect_success 'S: filemodify with garbage after inline must fail' '
+	test_must_fail git fast-import --import-marks=marks <<-EOF 2>err &&
+	commit refs/heads/S
+	committer $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL> $GIT_COMMITTER_DATE
+	data <<COMMIT
+	commit N
+	COMMIT
+	M 100644 inlineX hello.c
+	data <<BLOB
+	inline
+	BLOB
+	EOF
+	cat err &&
+	test_i18ngrep "nvalid dataref" err
+'
+
+test_expect_success 'S: filemodify with garbage after sha1 must fail' '
+	sha1=$(grep :403 marks | cut -d\  -f2) &&
+	test_must_fail git fast-import --import-marks=marks <<-EOF 2>err &&
+	commit refs/heads/S
+	committer $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL> $GIT_COMMITTER_DATE
+	data <<COMMIT
+	commit N
+	COMMIT
+	M 100644 ${sha1}x hello.c
+	EOF
+	cat err &&
+	test_i18ngrep "space after SHA1" err
+'
+
+#
+# notemodify, three ways to say dataref
+#
+test_expect_success 'S: notemodify with garabge after mark dataref must fail' '
+	test_must_fail git fast-import --import-marks=marks <<-EOF 2>err &&
+	commit refs/heads/S
+	committer $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL> $GIT_COMMITTER_DATE
+	data <<COMMIT
+	commit S note dataref markref
+	COMMIT
+	N :202x :302
+	EOF
+	cat err &&
+	test_i18ngrep "space after mark" err
+'
+
+test_expect_success 'S: notemodify with garbage after inline dataref must fail' '
+	test_must_fail git fast-import --import-marks=marks <<-EOF 2>err &&
+	commit refs/heads/S
+	committer $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL> $GIT_COMMITTER_DATE
+	data <<COMMIT
+	commit S note dataref inline
+	COMMIT
+	N inlineX :302
+	data <<BLOB
+	note blob
+	BLOB
+	EOF
+	cat err &&
+	test_i18ngrep "nvalid dataref" err
+'
+
+test_expect_success 'S: notemodify with garbage after sha1 dataref must fail' '
+	sha1=$(grep :202 marks | cut -d\  -f2) &&
+	test_must_fail git fast-import --import-marks=marks <<-EOF 2>err &&
+	commit refs/heads/S
+	committer $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL> $GIT_COMMITTER_DATE
+	data <<COMMIT
+	commit S note dataref sha1
+	COMMIT
+	N ${sha1}x :302
+	EOF
+	cat err &&
+	test_i18ngrep "space after SHA1" err
+'
+
+#
+# notemodify, mark in committish
+#
+test_expect_success 'S: notemodify with garbarge after mark committish must fail' '
+	test_must_fail git fast-import --import-marks=marks <<-EOF 2>err &&
+	commit refs/heads/Snotes
+	committer $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL> $GIT_COMMITTER_DATE
+	data <<COMMIT
+	commit S note committish
+	COMMIT
+	N :202 :302x
+	EOF
+	cat err &&
+	test_i18ngrep "after mark" err
+'
+
+#
+# from
+#
+test_expect_success 'S: from with garbage after mark must fail' '
+	# no &&
+	git fast-import --import-marks=marks --export-marks=marks <<-EOF 2>err
+	commit refs/heads/S2
+	mark :303
+	committer $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL> $GIT_COMMITTER_DATE
+	data <<COMMIT
+	commit 3
+	COMMIT
+	from :301x
+	M 100644 :403 hello.c
+	EOF
+
+	ret=$? &&
+	echo returned $ret &&
+	test $ret -ne 0 && # failed, but it created the commit
+
+	# go create the commit, need it for merge test
+	git fast-import --import-marks=marks --export-marks=marks <<-EOF &&
+	commit refs/heads/S2
+	mark :303
+	committer $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL> $GIT_COMMITTER_DATE
+	data <<COMMIT
+	commit 3
+	COMMIT
+	from :301
+	M 100644 :403 hello.c
+	EOF
+
+	# now evaluate the error
+	cat err &&
+	test_i18ngrep "after mark" err
+'
+
+
+#
+# merge
+#
+test_expect_success 'S: merge with garbage after mark must fail' '
+	test_must_fail git fast-import --import-marks=marks <<-EOF 2>err &&
+	commit refs/heads/S
+	mark :304
+	committer $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL> $GIT_COMMITTER_DATE
+	data <<COMMIT
+	merge 4
+	COMMIT
+	from :302
+	merge :303x
+	M 100644 :403 hello.c
+	EOF
+	cat err &&
+	test_i18ngrep "after mark" err
+'
+
+#
+# tag, from markref
+#
+test_expect_success 'S: tag with garbage after mark must fail' '
+	test_must_fail git fast-import --import-marks=marks <<-EOF 2>err &&
+	tag refs/tags/Stag
+	from :302x
+	tagger $GIT_COMMITTER_NAME <$GIT_COMMITTER_EMAIL> $GIT_COMMITTER_DATE
+	data <<TAG
+	tag S
+	TAG
+	EOF
+	cat err &&
+	test_i18ngrep "after mark" err
+'
+
+#
+# cat-blob markref
+#
+test_expect_success 'S: cat-blob with garbage after mark must fail' '
+	test_must_fail git fast-import --import-marks=marks <<-EOF 2>err &&
+	cat-blob :403x
+	EOF
+	cat err &&
+	test_i18ngrep "after mark" err
+'
+
+#
+# ls markref
+#
+test_expect_success 'S: ls with garbage after mark must fail' '
+	test_must_fail git fast-import --import-marks=marks <<-EOF 2>err &&
+	ls :302x hello.c
+	EOF
+	cat err &&
+	test_i18ngrep "space after mark" err
+'
+
+test_expect_success 'S: ls with garbage after sha1 must fail' '
+	sha1=$(grep :302 marks | cut -d\  -f2) &&
+	test_must_fail git fast-import --import-marks=marks <<-EOF 2>err &&
+	ls ${sha1}x hello.c
+	EOF
+	cat err &&
+	test_i18ngrep "space after tree-ish" err
+'
+
 test_done