		strbuf_addstr(&pathbuf, filename);
	}

#ifndef NO_PTHREADS
	if (use_threads) {
		add_work(GREP_SOURCE_SHA1, pathbuf.buf, sha1);
		strbuf_release(&pathbuf);
		return 0;
	} else
#endif
	{
		struct grep_source gs;
		int hit;

		grep_source_init(&gs, GREP_SOURCE_SHA1, pathbuf.buf, sha1);
		strbuf_release(&pathbuf);
		hit = grep_source(opt, &gs);

		grep_source_clear(&gs);
		return hit;
	}
}

static int grep_file(struct grep_opt *opt, const char *filename)
{
	struct strbuf buf = STRBUF_INIT;

	if (opt->relative && opt->prefix_length)
		quote_path_relative(filename, -1, &buf, opt->prefix);
	else
		strbuf_addstr(&buf, filename);

#ifndef NO_PTHREADS
	if (use_threads) {
		add_work(GREP_SOURCE_FILE, buf.buf, filename);
		strbuf_release(&buf);
		return 0;
	} else
#endif
	{
		struct grep_source gs;
		int hit;

		grep_source_init(&gs, GREP_SOURCE_FILE, buf.buf, filename);
		strbuf_release(&buf);
		hit = grep_source(opt, &gs);

		grep_source_clear(&gs);
		return hit;
	}
}