			if (allow)
				warning(msg, ce->name);
			else
				err = error(msg, ce->name);

			drop_cache_tree = 1;
		}
		if (ce_write_entry(&c, newfd, ce, previous_name) < 0)
			err = -1;

		if (err)
			break;
	}
	strbuf_release(&previous_name_buf);

	if (err)
		return err;

	/* Write extension data here */
	if (!strip_extensions && istate->split_index) {
		struct strbuf sb = STRBUF_INIT;