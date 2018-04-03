    return copy_sz;
}

Specifier *
htcpBuildSpecifier(char *buf, size_t buflen, HtcpStuff *stuff)
{
	off_t off = 0;
	...
}

size_t
htcpBuildTstOpData(char *buf, size_t buflen, HtcpStuff *stuff)
{
	return htcpBuildSpecifier(buf, buflen, stuff);
}

size_t
htcpBuildOpData(char *buf, size_t buflen, HtcpStuff *stuff)
{
	off_t off = 0;
	switch(stuff->op) {
	case HTCP_TST:
		off = htcpBuildTstOpData(buf + off, buflen, stuff);
		break:
	default:
		assert(0);
		break;
	}
	return off;
}

size_t
htcpBuildData(char *buf, size_t buflen, HtcpStuff *stuff)
{
	off_t off = 0;
	off += sizeof(htcpDataHeader);	/* skip! */
	htcpBuildOpData(buf + off, buflen - off, stuff);
	...
}

htcpBuildPacket(HtcpStuff *stuff)
{
	size_t buflen = 8192;
	off_t off = 0;
	char *buf = xcalloc(buflen, 1);
	/* skip the header -- we don't know the overall length */
	off += sizeof(htcpHeader);
	off += htcpBuildData(buf + off, buflen-off, stuff);
	...
}