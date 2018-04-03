		unsigned long max_age = approxidate(args->deepen_since);
		packet_buf_write(&req_buf, "deepen-since %lu", max_age);
	}
	if (args->deepen_not) {
		int i;
		for (i = 0; i < args->deepen_not->nr; i++) {
			struct string_list_item *s = args->deepen_not->items + i;
			packet_buf_write(&req_buf, "deepen-not %s", s->string);
		}
	}
	packet_buf_flush(&req_buf);
	state_len = req_buf.len;

