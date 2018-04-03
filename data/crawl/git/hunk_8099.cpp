 	/*
 	 * And then the pretty-printed message itself
 	 */
-	len = pretty_print_commit(opt->commit_format, commit, ~0u,
-				  &msgbuf, &msgbuf_len, abbrev, subject,
-				  extra_headers, opt->date_mode);
+	strbuf_init(&msgbuf, 0);
+	pretty_print_commit(opt->commit_format, commit, &msgbuf,
+				  abbrev, subject, extra_headers, opt->date_mode);
 
 	if (opt->add_signoff)
-		len = append_signoff(&msgbuf, &msgbuf_len, len,
-				     opt->add_signoff);
+		append_signoff(&msgbuf, opt->add_signoff);
 	if (opt->show_log_size)
-		printf("log size %i\n", len);
+		printf("log size %i\n", (int)msgbuf.len);
 
-	printf("%s%s%s", msgbuf, extra, sep);
-	free(msgbuf);
+	printf("%s%s%s", msgbuf.buf, extra, sep);
+	strbuf_release(&msgbuf);
 }
 
 int log_tree_diff_flush(struct rev_info *opt)