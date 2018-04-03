		quote_c_style(value, &buf, NULL, 0);
	strbuf_addch(&buf, '\n');

	ret = strbuf_set_helper_option(data, &buf);
	strbuf_release(&buf);
	return ret;
}