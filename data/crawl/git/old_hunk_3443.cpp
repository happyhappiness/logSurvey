		struct ref *ref = to_fetch[i];
		if (!ref->name || !*ref->name)
			die("cannot fetch by sha1 over smart http");
		packet_buf_write(&preamble, "%s\n", ref->name);
	}
	packet_buf_flush(&preamble);
