	unsigned char expn[4096];
	size_t size = eltsize * nmemb;
	int posn = 0;
	struct http_object_request *freq =
		(struct http_object_request *)data;
	do {
		ssize_t retval = xwrite(freq->localfile,
					(char *) ptr + posn, size - posn);
