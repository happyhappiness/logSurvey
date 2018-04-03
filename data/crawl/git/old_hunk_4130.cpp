{
	int ret = 0;
	struct strbuf buf = STRBUF_INIT;

	/*
	 * Use an absolute path as-is, but interpret relative paths
