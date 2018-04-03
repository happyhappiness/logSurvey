			     const char *c_meta, const char *c_reset)
{
	printf("%s%s", c_meta, prefix);
	quote_c_style(path, NULL, stdout, 0);
	printf("%s\n", c_reset);
}

