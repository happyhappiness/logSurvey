
		if (!pack_to_stdout && p->index_version == 1 &&
		    check_pack_inflate(p, &w_curs, offset, datalen, entry->size))
			die("corrupt packed object for %s", sha1_to_hex(entry->idx.sha1));
		copy_pack_data(f, p, &w_curs, offset, datalen);
		unuse_pack(&w_curs);
		reused++;
