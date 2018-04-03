	}

	if (info->show_timestamp)
		printf("%lu ", commit->date);
	if (info->header_prefix)
		fputs(info->header_prefix, stdout);

