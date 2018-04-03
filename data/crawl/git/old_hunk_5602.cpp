
		strbuf_addf(&buf, "fetch %s %s\n",
			    sha1_to_hex(posn->old_sha1), posn->name);
		write_in_full(helper->in, buf.buf, buf.len);
		strbuf_reset(&buf);

		if (strbuf_getline(&buf, file, '\n') == EOF)
			exit(128); /* child died, message supplied already */
	}
	return 0;
}

