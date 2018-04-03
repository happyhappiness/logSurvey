	struct strbuf out = STRBUF_INIT;

	pp_user_info("Tagger", rev->commit_format, &out, buf, rev->date_mode,
		get_log_output_encoding());
	printf("%s", out.buf);
	strbuf_release(&out);
}
