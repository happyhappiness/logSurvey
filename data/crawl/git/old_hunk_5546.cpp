	ACK_ready
};

static enum ack_type get_ack(int fd, unsigned char *result_sha1)
{
	static char line[1000];
