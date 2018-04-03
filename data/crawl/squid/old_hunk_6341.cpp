	else if (opt_checksum && r->validsum != r->sum)
	    fprintf(stderr,"WARNING: %s invalid checksum wanted %d got %d\n",
		    r->url, r->validsum, r->sum);
    } else if (opt_checksum) {
	fprintf(stderr,"DONE: %s checksum %d size %d\n",
		r->url, r->sum, r->bodysize);
    }
    free(r);
}
