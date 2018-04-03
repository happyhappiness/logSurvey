		strstr(server_capabilities, feature) != NULL;
}

int path_match(const char *path, int nr, char **match)
{
	int i;