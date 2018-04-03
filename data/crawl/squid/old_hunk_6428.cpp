	    return atoi(t);
	}
    }
    return 0;
}

int
handle_read(char *buf, int len)
{
    struct _r *r = Requests;
    const char *end;
    int hlen;
    if (len < 0) {
	perror("read");
	Requests = r->next;
	free(r);
	noutstanding--;
	return -1;
    }
    if (len == 0) {
	fprintf(stderr, "DONE: %s, server closed socket, read %d bytes\n", r->url, r->bytes_read);
	Requests = r->next;
	free(r);
	noutstanding--;
	return -1;
    }
    if (r->hdr_length == 0) {
	hlen = min(len, REPLY_HDR_SZ - r->hdr_length);
	strncpy(r->reply_hdrs + r->hdr_length, buf, hlen);
	r->hdr_offset += hlen;
	*(r->reply_hdrs + REPLY_HDR_SZ - 1) = '\0';
    }
    if (r->hdr_length == 0 && (end = mime_headers_end(r->reply_hdrs)) != NULL) {
	fprintf(stderr, "FOUND EOH FOR %s\n", r->url);
	r->hdr_length = end - r->reply_hdrs;
	fprintf(stderr, "HDR_LENGTH = %d\n", r->hdr_length);
	r->content_length = get_header_int_value("content-length:", r->reply_hdrs, end);
	fprintf(stderr, "CONTENT_LENGTH = %d\n", r->content_length);
    }
    if (r->content_length && r->hdr_length) {
	int bytes_left = r->content_length + r->hdr_length - r->bytes_read;
	int bytes_used = len > bytes_left ? bytes_left : len;
	r->bytes_read += bytes_used;
	len -= bytes_used;
	if (r->bytes_read == r->content_length + r->hdr_length) {
	    fprintf(stderr, "DONE: %s, (%d == %d+%d)\n",
		r->url,
		r->bytes_read,
		r->hdr_length,
		r->content_length);
	    Requests = r->next;
	    free(r);
	    noutstanding--;
	} else {
	    assert(r->bytes_read < r->content_length + r->hdr_length);
	}
	if (len) {
	    assert(bytes_used > 0);
	    xmemmove(buf, buf + bytes_used, len);
	    return handle_read(buf, len);
	}
    }
    return 0;
