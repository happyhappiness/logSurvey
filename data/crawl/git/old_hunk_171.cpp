		int zret = Z_OK;
		readlen = read_istream(st, ibuf, sizeof(ibuf));
		if (readlen == -1)
			die(_("unable to read %s"), sha1_to_hex(sha1));

		stream.next_in = ibuf;
		stream.avail_in = readlen;
