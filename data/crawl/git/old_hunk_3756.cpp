	}
}

static struct discovery* discover_refs(const char *service, int for_push)
{
	struct strbuf exp = STRBUF_INIT;
