int main(int argc, const char **argv)
{
	const char *usage =
		"Usage: git credential-osxkeychain <get|store|erase>";

	if (!argv[1])
		die(usage);
