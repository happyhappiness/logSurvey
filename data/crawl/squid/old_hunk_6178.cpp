	    fprintf(stderr, "WARNING: %s invalid checksum wanted 0x%lx got 0x%lx\n",
		r->url, r->validsum, r->sum);
    }
    if (trace_file) {
	fprintf(trace_file, "%s %s %s %d 0x%lx\n",
	    r->method, r->url, r->requestbodyfile, r->bodysize, r->sum);
    }
    free_request(r);
}
