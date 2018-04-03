	return p->score * 100 / MAX_SCORE;
}

static void fill_metainfo(struct strbuf *msg,
			  const char *name,
			  const char *other,
