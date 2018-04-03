		}
		else {
			sha1 = ce->sha1;
			mode = ntohl(ce->ce_mode);
			entlen = pathlen - baselen;
		}
		if (mode != S_IFGITLINK && !missing_ok && !has_sha1_file(sha1))
			return error("invalid object %s", sha1_to_hex(sha1));

		if (!ce->ce_mode)
			continue; /* entry being removed */

		strbuf_grow(&buffer, entlen + 100);
