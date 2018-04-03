 	pp.fmt = rev->commit_format;
 	pp.date_mode = rev->date_mode;
 	pp_user_info(&pp, "Tagger", &out, buf, get_log_output_encoding());
-	printf("%s", out.buf);
+	fprintf(rev->diffopt.file, "%s", out.buf);
 	strbuf_release(&out);
 }
 
