	return ecbdata.hit;
}

static unsigned int contains(mmfile_t *mf, regex_t *regexp, kwset_t kws)
{
	unsigned int cnt;
