		die("malformed index info %s", buf.buf);
	}
	strbuf_release(&buf);
}

static const char update_index_usage[] =
