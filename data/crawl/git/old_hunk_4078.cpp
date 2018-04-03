			sed -i "s/^line5/line5 p4 edit/" file_text &&
			p4 submit -d "file5 p4 edit"
		) &&
		! git p4 submit &&
		(
			# exepct something like:
			#    file_text - file(s) not opened on this client
			# but not copious diff output
			cd "$cli" &&
			p4 diff file_text >wc &&
			test_line_count = 1 wc
		)
	)
'
