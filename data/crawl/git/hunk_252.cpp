 		while (strbuf_getline_lf(&oneline, stdin) != EOF &&
 		       !oneline.len)
 			; /* discard blanks */
-		insert_one_record(log, v, oneline.buf);
+
+		strbuf_reset(&mapped_author);
+		if (parse_stdin_author(log, &mapped_author, v) < 0)
+			continue;
+
+		insert_one_record(log, mapped_author.buf, oneline.buf);
 	}
 	strbuf_release(&author);
+	strbuf_release(&mapped_author);
 	strbuf_release(&oneline);
 }
 
