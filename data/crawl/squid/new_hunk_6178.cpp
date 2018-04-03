	    fprintf(stderr, "WARNING: %s invalid checksum wanted 0x%lx got 0x%lx\n",
		r->url, r->validsum, r->sum);
    }
    if (r->status != r->validstatus && r->validstatus)
	fprintf(stderr, "WARNING: %s status %d\n", r->url, r->status);
    if (trace_file) {
	fprintf(trace_file, "%s %s %s %d 0x%lx %d\n",
	    r->method, r->url, r->requestbodyfile, r->bodysize, r->sum, r->status);
    }
    free_request(r);
}
