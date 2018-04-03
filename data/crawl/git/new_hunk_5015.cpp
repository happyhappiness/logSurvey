	repo_diff(revision - 1, revision);
	fputc('\n', stdout);

	printf("progress Imported commit %"PRIu32".\n\n", revision);
}

void fast_export_blob(uint32_t mode, uint32_t mark, uint32_t len)
