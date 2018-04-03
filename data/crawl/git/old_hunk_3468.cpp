	 */
	if (flags & PATHSPEC_PREFIX_ORIGIN) {
		struct strbuf sb = STRBUF_INIT;
		const char *start = elt;
		if (prefixlen && !literal_global) {
			/* Preserve the actual prefix length of each pattern */
			if (short_magic)
				die("BUG: prefixing on short magic is not supported");
			else if (long_magic_end) {
				strbuf_add(&sb, start, long_magic_end - start);
				strbuf_addf(&sb, ",prefix:%d", prefixlen);
				start = long_magic_end;
			} else {
				if (*start == ':')
					start++;
				strbuf_addf(&sb, ":(prefix:%d)", prefixlen);
			}
		}
		strbuf_add(&sb, start, copyfrom - start);
		strbuf_addstr(&sb, match);
		item->original = strbuf_detach(&sb, NULL);
	} else