	else if (opt_checksum && r->validsum != r->sum)
	    fprintf(stderr,"WARNING: %s invalid checksum wanted %d got %d\n",
		    r->url, r->validsum, r->sum);
    }
    if (trace_file) {
	fprintf(trace_file,"%s %s %s %d %d\n",
		r->method, r->url, r->requestbodyfile, r->bodysize, r->sum);
    }
    free(r);
}
