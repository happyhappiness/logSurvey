	return -1;
}

int strbuf_getwholeline(struct strbuf *sb, FILE *fp, int term)
{
	int ch;
