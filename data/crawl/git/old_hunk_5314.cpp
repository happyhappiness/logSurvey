	return strbuf_detach(&helpbuf, NULL);
}

static struct tree *empty_tree(void)
{
	struct tree *tree = xcalloc(1, sizeof(struct tree));
