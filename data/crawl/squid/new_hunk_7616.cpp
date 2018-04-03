	     * for first try it's a dirty hack, by hacking getanswer
	     * to place th e ttl in a global variable */
	    if (_dns_ttl_ > -1)
		printf("$ttl %d\n", _dns_ttl_);
#endif

	    printf("$end\n");
