{
    struct _request *r = data;
    if (opt_range);		/* skip size checks for now */
    else if (r->bodysize != r->content_length && r->content_length >= 0)
	fprintf(stderr, "ERROR: %s got %d of %d bytes\n",
	    r->url, r->bodysize, r->content_length);
