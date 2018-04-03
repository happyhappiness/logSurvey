	return lk->fp;
}

int get_lock_file_fd(struct lock_file *lk)
{
	if (!lk->active)
