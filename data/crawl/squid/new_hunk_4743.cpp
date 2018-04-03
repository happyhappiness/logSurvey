	    fprintf(stderr, "WARNING: %s invalid checksum wanted 0x%lx got 0x%lx\n",
		r->url, r->validsum, r->sum);
    }
    if (r->validstatus && r->status != r->validstatus) {
	    fprintf(stderr, "WARNING: %s status mismatch wanted %d got %d\n",
		r->url, r->validstatus, r->status);
    }
    if (trace_file) {
	if (opt_checksum)
	    fprintf(trace_file, "%s %s %d %s %d 0x%lx\n",
