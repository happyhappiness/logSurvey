    StringCounter *sc;
    StringAddrCounter *ssc;

    fprintf (stderr, "handle_dns (buf = %p, len = %i)\n",
		    (void *) buf, len);

    if (len < sizeof(qh))
	return 0;

