	 * diff before committing.
	 */
	if (s->fp != stdout) {
		const char *explanation = _("Do not touch the line above.\nEverything below will be removed.");
		struct strbuf buf = STRBUF_INIT;

		rev.diffopt.use_color = 0;
		fprintf(s->fp, "%c %s", comment_line_char, cut_line);
		strbuf_add_commented_lines(&buf, explanation, strlen(explanation));
		fputs(buf.buf, s->fp);
		strbuf_release(&buf);
	}
	run_diff_index(&rev, 1);
}
