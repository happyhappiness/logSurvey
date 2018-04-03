				       output_directory));
}

int cmd_format_patch(int argc, const char **argv, const char *prefix)
{
	struct commit *commit;
	struct commit **list = NULL;
	struct rev_info rev;
	int nr = 0, total, i, j;
	int use_stdout = 0;
	int start_number = -1;
	int keep_subject = 0;
	int numbered_files = 0;		/* _just_ numbers */
	int subject_prefix = 0;
	int ignore_if_in_upstream = 0;
	int cover_letter = 0;
	int boundary_count = 0;
