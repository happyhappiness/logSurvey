			sha1write(f, header, hdrlen);
			sha1write(f, dheader + pos, sizeof(dheader) - pos);
			hdrlen += sizeof(dheader) - pos;
			reused_delta++;
		} else if (type == OBJ_REF_DELTA) {
			if (limit && hdrlen + 20 + datalen + 20 >= limit)
				return 0;
			sha1write(f, header, hdrlen);
			sha1write(f, entry->delta->idx.sha1, 20);
			hdrlen += 20;
			reused_delta++;
		} else {
			if (limit && hdrlen + datalen + 20 >= limit)
				return 0;
			sha1write(f, header, hdrlen);
		}
		copy_pack_data(f, p, &w_curs, offset, datalen);
		unuse_pack(&w_curs);
		reused++;
