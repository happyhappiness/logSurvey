    n = recv(0, (char *) &pecho, sizeof(pecho), 0);
    if (n < 0)
	return n;
    guess_size = n - (sizeof(pingerEchoData) - PINGER_PAYLOAD_SZ);
    if (guess_size != pecho.psize)
	fprintf(stderr, "size mismatch, guess=%d psize=%d\n",
	    guess_size, pecho.psize);
