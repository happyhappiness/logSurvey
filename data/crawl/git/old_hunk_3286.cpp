	commit->buffer = buffer;
}

void free_commit_buffer(struct commit *commit)
{
	free(commit->buffer);
