{
#if 0
    fprintf(stderr, "DONE: %s, (%d+%d)\n",
	    r->url,
	    r->hdr_length,
	    r->content_length);
#endif
    if (r->content_length != r->bytes_read)
	fprintf(stderr, "ERROR! Short reply, expected %d bytes got %d\n",
	    r->content_length, r->bytes_read);
    else if (r->validsize >= 0) {
	if (r->validsize != r->bytes_read)
	    fprintf(stderr, "WARNING: %s Object size mismatch, expected %d got %d\n",
		    r->url, r->validsize, r->bytes_read);
	else if (opt_checksum && r->sum != r->validsum)
	    fprintf(stderr, "WARNING: %s Checksum error. Expected %d got %d\n",
		    r->url, r->validsum, r->sum);
    }
}
int
