		die("HTTP request failed");
	}

	data = buffer.buf;
	start = NULL;
	mid = data;
	while (i < buffer.len) {
		if (!start) {
			start = &data[i];
		}
