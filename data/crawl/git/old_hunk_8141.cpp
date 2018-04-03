	FILE *rpt = fopen(loc, "w");
	struct branch *b;
	unsigned long lu;

	if (!rpt) {
		error("can't write crash report %s: %s", loc, strerror(errno));
