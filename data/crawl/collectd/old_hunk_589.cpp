	return (0);
}

int rrd_create_file (char *filename, char **ds_def, int ds_num)
{
	char **argv;
	int argc;
	int i, j;
