    int guess_size;
    memset(&pecho, '\0', sizeof(pecho));
    n = recv(0, (char *) &pecho, sizeof(pecho), 0);
    if (n < 0) {
	perror("recv");
	return n;
    }
    guess_size = n - (sizeof(pingerEchoData) - 8192);
    if (guess_size != pecho.psize)
	fprintf(stderr, "size mismatch, guess=%d psize=%d\n",
	    guess_size, pecho.psize);
