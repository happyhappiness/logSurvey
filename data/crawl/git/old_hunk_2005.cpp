	return 0;
}

int main(int argc, char **argv)
{
	const char *prefix = "prefix/";
	const char *usage[] = {
		"test-parse-options <options>",
		NULL
	};
	struct option options[] = {
		OPT_BOOL(0, "yes", &boolean, "get a boolean"),
		OPT_BOOL('D', "no-doubt", &boolean, "begins with 'no-'"),
