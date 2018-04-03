 	/*
 	 * And then the pretty-printed message itself
 	 */
-	len = pretty_print_commit(opt->commit_format, commit, ~0u, this_header,
-				  sizeof(this_header), abbrev, subject,
+	len = pretty_print_commit(opt->commit_format, commit, ~0u,
+				  &msgbuf, &msgbuf_len, abbrev, subject,
 				  extra_headers, opt->date_mode);
 
 	if (opt->add_signoff)
-		len = append_signoff(this_header, sizeof(this_header), len,
+		len = append_signoff(&msgbuf, &msgbuf_len, len,
 				     opt->add_signoff);
-	printf("%s%s%s", this_header, extra, sep);
+	printf("%s%s%s", msgbuf, extra, sep);
+	free(msgbuf);
 }
 
 int log_tree_diff_flush(struct rev_info *opt)