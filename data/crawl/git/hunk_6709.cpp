 			merge_msg.len)
 			die("Could not write to %s", git_path("MERGE_MSG"));
 		close(fd);
+		fd = open(git_path("MERGE_MODE"), O_WRONLY | O_CREAT | O_TRUNC, 0666);
+		if (fd < 0)
+			die("Could open %s for writing", git_path("MERGE_MODE"));
+		strbuf_reset(&buf);
+		if (!allow_fast_forward)
+			strbuf_addf(&buf, "no-ff");
+		if (write_in_full(fd, buf.buf, buf.len) != buf.len)
+			die("Could not write to %s", git_path("MERGE_MODE"));
+		close(fd);
 	}
 
 	if (merge_was_ok) {
