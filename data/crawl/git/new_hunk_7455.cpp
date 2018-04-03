	mm->size = size;
}

static int merge_3way(mmbuffer_t *result_buf,
		      struct diff_filespec *o,
		      struct diff_filespec *a,
		      struct diff_filespec *b,
		      const char *branch1,
		      const char *branch2)
{
	mmfile_t orig, src1, src2;
	char *name1, *name2;
	int merge_status;

	name1 = xstrdup(mkpath("%s:%s", branch1, a->path));
	name2 = xstrdup(mkpath("%s:%s", branch2, b->path));
