				die("line is badly quoted");
			strbuf_swap(&buf, &nbuf);
		}
		pathspec[0] = buf.buf;
		num_ignored += check_ignore(check, prefix, (const char **)pathspec);
		maybe_flush_or_die(stdout, "check-ignore to stdout");
	}
	strbuf_release(&buf);
	strbuf_release(&nbuf);
	return num_ignored;
