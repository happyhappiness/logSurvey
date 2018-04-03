
int main(int argc, char **argv)
{
	if (!strcmp(argv[1], "wildmatch"))
		return !!wildmatch(argv[3], argv[2], 0);
	else if (!strcmp(argv[1], "iwildmatch"))