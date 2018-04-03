 		die("Cover letter needs email format");
 
 	if (!use_stdout && reopen_stdout(numbered_files ?
-				NULL : "cover-letter", 0, rev->total))
+				NULL : "cover-letter", 0, rev))
 		return;
 
 	head_sha1 = sha1_to_hex(head->object.sha1);
