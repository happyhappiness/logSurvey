	for_each_ref(one_local_ref, NULL);
}

static int receive_status(int in)
{
	char line[1000];
	int ret = 0;
	int len = packet_read_line(in, line, sizeof(line));
	if (len < 10 || memcmp(line, "unpack ", 7)) {
		fprintf(stderr, "did not receive status back\n");
		return -1;
	}
	if (memcmp(line, "unpack ok\n", 10)) {
		fputs(line, stderr);
		ret = -1;
	}
	while (1) {
		len = packet_read_line(in, line, sizeof(line));
		if (!len)
