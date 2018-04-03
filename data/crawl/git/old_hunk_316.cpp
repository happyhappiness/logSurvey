			if (allow)
				warning(msg, ce->name);
			else
				return error(msg, ce->name);

			drop_cache_tree = 1;
		}
		if (ce_write_entry(&c, newfd, ce, previous_name) < 0)
			return -1;
	}
	strbuf_release(&previous_name_buf);

	/* Write extension data here */
	if (!strip_extensions && istate->split_index) {
		struct strbuf sb = STRBUF_INIT;