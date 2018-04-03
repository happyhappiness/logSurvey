
int main(int argc, char **argv)
{
	if (argc == 2 && !strcmp(argv[1], "--bug"))
		return test_regex_bug();
	else
		usage("test-regex --bug");
}