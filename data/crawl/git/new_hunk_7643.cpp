{
	unsigned char sha1[20];
	char *url;
	struct strbuf buffer = STRBUF_INIT;
	char *data;
	int i = 0;

	struct active_request_slot *slot;
	struct slot_results results;

	if (push_verbosely)
		fprintf(stderr, "Getting pack list\n");

