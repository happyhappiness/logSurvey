	printf("progress Imported commit %"PRIu32".\n\n", revision);
}

void fast_export_blob(uint32_t mode, uint32_t mark, uint32_t len, struct line_buffer *input)
{
	if (mode == REPO_MODE_LNK) {
		/* svn symlink blobs start with "link " */
		buffer_skip_bytes(input, 5);
		len -= 5;
	}
	printf("blob\nmark :%"PRIu32"\ndata %"PRIu32"\n", mark, len);
	buffer_copy_bytes(input, len);
	fputc('\n', stdout);
}
