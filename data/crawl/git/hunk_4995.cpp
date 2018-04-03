 	struct strbuf out = STRBUF_INIT;
 
 	pp_user_info("Tagger", rev->commit_format, &out, buf, rev->date_mode,
-		git_log_output_encoding ?
-		git_log_output_encoding: git_commit_encoding);
+		get_log_output_encoding());
 	printf("%s", out.buf);
 	strbuf_release(&out);
 }
