	    fprintf(stderr, "WARNING: %s invalid checksum wanted 0x%lx got 0x%lx\n",
		r->url, r->validsum, r->sum);
    }
    if (trace_file) {
	if (opt_checksum)
	    fprintf(trace_file, "%s %s %d %s %d 0x%lx\n",
		r->method, r->url, r->status, r->requestbodyfile, r->bodysize, r->sum);
	else
	    fprintf(trace_file, "%s %s %d %s %d\n",
		r->method, r->url, r->status, r->requestbodyfile, r->bodysize);
    }
    free_request(r);
}
