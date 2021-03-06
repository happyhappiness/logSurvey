
	if ((ctx.fmt != CMIT_FMT_USERFORMAT) &&
	    ctx.notes_message && *ctx.notes_message) {
		if (cmit_fmt_is_mail(ctx.fmt)) {
			strbuf_addstr(&msgbuf, "---\n");
			opt->shown_dashes = 1;
		}
		strbuf_addstr(&msgbuf, ctx.notes_message);
	}

	if (opt->show_log_size) {
		fprintf(opt->diffopt.file, "log size %i\n", (int)msgbuf.len);
		graph_show_oneline(opt->graph);
	}

