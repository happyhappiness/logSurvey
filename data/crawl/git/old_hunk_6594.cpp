
	strbuf_insert(buf, 0, header_buf, header_len);

	if (sign && do_sign(buf) < 0)
		die("unable to sign the tag");
	if (write_sha1_file(buf->buf, buf->len, tag_type, result) < 0)
		die("unable to write tag file");
}

struct msg_arg {