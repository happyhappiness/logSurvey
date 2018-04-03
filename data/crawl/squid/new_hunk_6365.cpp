reply_done(int fd, void *data)
{
    struct _request *r = data;
    if (opt_range)
	; /* skip size checks for now */
    if (r->bodysize != r->content_length)
	fprintf(stderr,"ERROR: %s expected %d bytes got %d\n",
		r->url, r->content_length, r->bodysize);
