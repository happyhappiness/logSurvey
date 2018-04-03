	}
}

static void wt_shortstatus_other(int null_termination, struct string_list_item *it,
				 struct wt_status *s, const char *sign)
{
	if (null_termination) {
		fprintf(stdout, "%s %s%c", sign, it->string, 0);
	} else {
		struct strbuf onebuf = STRBUF_INIT;
		const char *one;
		one = quote_path(it->string, -1, &onebuf, s->prefix);
		color_fprintf(s->fp, color(WT_STATUS_UNTRACKED, s), sign);
		printf(" %s\n", one);
		strbuf_release(&onebuf);
	}
