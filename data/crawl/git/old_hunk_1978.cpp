	strbuf_release(&hi->tcp_port);
}

static int execute(void)
{
	char *line = packet_buffer;
