		unsigned long max_age = approxidate(args->deepen_since);
		packet_buf_write(&req_buf, "deepen-since %lu", max_age);
	}
	packet_buf_flush(&req_buf);
	state_len = req_buf.len;

