	return lk->fp;
}

char *get_locked_file_path(struct lock_file *lk)
{
	if (!lk->active)
