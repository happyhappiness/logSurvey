    if (n < 0)
	return n;
    guess_size = n - (sizeof(pingerEchoData) - PINGER_PAYLOAD_SZ);
    if (guess_size != pecho.psize)
	fprintf(stderr, "size mismatch, guess=%d psize=%d\n",
	    guess_size, pecho.psize);
    pingerSendEcho(pecho.to,
	pecho.opcode,
	pecho.payload,
