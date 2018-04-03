			sed -i "s/^line5/line5 p4 edit/" file_text &&
			p4 submit -d "file5 p4 edit"
		) &&
		echo s | test_expect_code 1 git p4 submit &&
		(
			# make sure the file is not left open
			cd "$cli" &&
			! p4 fstat -T action file_text
		)
	)
'
