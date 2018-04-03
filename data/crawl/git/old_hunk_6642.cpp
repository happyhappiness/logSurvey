			sha1write(f, header, hdrlen);
			sha1write(f, dheader + pos, sizeof(dheader) - pos);
			hdrlen += sizeof(dheader) - pos;
		} else if (type == OBJ_REF_DELTA) {
			if (limit && hdrlen + 20 + datalen + 20 >= limit)
				return 0;
			sha1write(f, header, hdrlen);
			sha1write(f, entry->delta->idx.sha1, 20);
			hdrlen += 20;
		} else {
			if (limit && hdrlen + datalen + 20 >= limit)
				return 0;
			sha1write(f, header, hdrlen);
		}

		if (!pack_to_stdout && p->index_version == 1 &&
		    check_pack_inflate(p, &w_curs, offset, datalen, entry->size))
			die("corrupt packed object for %s", sha1_to_hex(entry->idx.sha1));
		copy_pack_data(f, p, &w_curs, offset, datalen);
		unuse_pack(&w_curs);
		reused++;
