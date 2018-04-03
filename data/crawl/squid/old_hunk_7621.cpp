	    /* DNS TTL handling - bne@CareNet.hu
	     * for first try it's a dirty hack, by hacking getanswer
	     * to place th e ttl in a global variable */
	    printf("$ttl %d\n", _dns_ttl_);
#endif

	    printf("$end\n");