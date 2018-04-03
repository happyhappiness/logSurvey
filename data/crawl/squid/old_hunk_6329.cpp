    struct _request *r = data;
    if (opt_range)
	; /* skip size checks for now */
    else
    if (r->bodysize != r->content_length && r->content_length > 0)
	fprintf(stderr,"ERROR: %s expected %d bytes got %d\n",
		r->url, r->content_length, r->bodysize);
    else if (r->validsize >= 0) {
	if (r->validsize != r->bodysize)
	    fprintf(stderr,"WARNING: %s size mismatch wanted %d bytes got %d\n",
		    r->url, r->validsize, r->bodysize);
	else if (opt_checksum && r->validsum != r->sum)
	    fprintf(stderr,"WARNING: %s invalid checksum wanted %d got %d\n",
		    r->url, r->validsum, r->sum);
    }
    if (trace_file) {
	fprintf(trace_file,"%s %s %s %d %d\n",
		r->method, r->url, r->requestbodyfile, r->bodysize, r->sum);
    }
    free(r);
