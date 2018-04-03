    n = recv(0, (char *) &pecho, sizeof(pecho), 0);
    if (n < 0)
	return n;
    if (0 == n) {
	/* EOF indicator */
	fprintf(stderr, "EOF encountered\n");
	errno = 0;
	return -1;
    }
    guess_size = n - (sizeof(pingerEchoData) - PINGER_PAYLOAD_SZ);
    if (guess_size != pecho.psize) {
	fprintf(stderr, "size mismatch, guess=%d psize=%d\n",
	    guess_size, pecho.psize);
	/* don't process this message, but keep running */
	return 0;
    }
    pingerSendEcho(pecho.to,
	pecho.opcode,
