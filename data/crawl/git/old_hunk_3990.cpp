			     char **repo_abbrev)
{
	char buffer[1024];
	FILE *f = (filename == NULL ? NULL : fopen(filename, "r"));

	if (f == NULL)
		return 1;
	while (fgets(buffer, sizeof(buffer), f) != NULL)
		read_mailmap_line(map, buffer, repo_abbrev);
	fclose(f);
