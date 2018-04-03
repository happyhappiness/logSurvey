	return merge_status;
}

static struct merge_file_info merge_file_1(struct merge_options *o,
					   const struct diff_filespec *one,
					   const struct diff_filespec *a,
					   const struct diff_filespec *b,
					   const char *branch1,
					   const char *branch2)
{
	struct merge_file_info result;
	result.merge = 0;
	result.clean = 1;

	if ((S_IFMT & a->mode) != (S_IFMT & b->mode)) {
		result.clean = 0;
		if (S_ISREG(a->mode)) {
			result.mode = a->mode;
			hashcpy(result.sha, a->sha1);
		} else {
			result.mode = b->mode;
			hashcpy(result.sha, b->sha1);
		}
	} else {
		if (!sha_eq(a->sha1, one->sha1) && !sha_eq(b->sha1, one->sha1))
			result.merge = 1;

		/*
		 * Merge modes
		 */
		if (a->mode == b->mode || a->mode == one->mode)
			result.mode = b->mode;
		else {
			result.mode = a->mode;
			if (b->mode != one->mode) {
				result.clean = 0;
				result.merge = 1;
			}
		}

		if (sha_eq(a->sha1, b->sha1) || sha_eq(a->sha1, one->sha1))
			hashcpy(result.sha, b->sha1);
		else if (sha_eq(b->sha1, one->sha1))
			hashcpy(result.sha, a->sha1);
		else if (S_ISREG(a->mode)) {
			mmbuffer_t result_buf;
			int merge_status;

			merge_status = merge_3way(o, &result_buf, one, a, b,
						  branch1, branch2);

			if ((merge_status < 0) || !result_buf.ptr)
				die(_("Failed to execute internal merge"));

			if (write_sha1_file(result_buf.ptr, result_buf.size,
					    blob_type, result.sha))
				die(_("Unable to add %s to database"),
				    a->path);

			free(result_buf.ptr);
			result.clean = (merge_status == 0);
		} else if (S_ISGITLINK(a->mode)) {
			result.clean = merge_submodule(result.sha,
						       one->path, one->sha1,
						       a->sha1, b->sha1,
						       !o->call_depth);
		} else if (S_ISLNK(a->mode)) {
			hashcpy(result.sha, a->sha1);

			if (!sha_eq(a->sha1, b->sha1))
				result.clean = 0;
		} else {
			die(_("unsupported object type in the tree"));
		}
	}

	return result;
}

static struct merge_file_info
merge_file_special_markers(struct merge_options *o,
			   const struct diff_filespec *one,
			   const struct diff_filespec *a,
			   const struct diff_filespec *b,
			   const char *branch1,
			   const char *filename1,
			   const char *branch2,
			   const char *filename2)
{
	char *side1 = NULL;
	char *side2 = NULL;
	struct merge_file_info mfi;

	if (filename1)
		side1 = xstrfmt("%s:%s", branch1, filename1);
	if (filename2)
		side2 = xstrfmt("%s:%s", branch2, filename2);

	mfi = merge_file_1(o, one, a, b,
			   side1 ? side1 : branch1, side2 ? side2 : branch2);
	free(side1);
	free(side2);
	return mfi;
}

static struct merge_file_info merge_file_one(struct merge_options *o,
					 const char *path,
					 const unsigned char *o_sha, int o_mode,
					 const unsigned char *a_sha, int a_mode,
					 const unsigned char *b_sha, int b_mode,
					 const char *branch1,
					 const char *branch2)
{
	struct diff_filespec one, a, b;

	one.path = a.path = b.path = (char *)path;
	hashcpy(one.sha1, o_sha);
	one.mode = o_mode;
	hashcpy(a.sha1, a_sha);
	a.mode = a_mode;
	hashcpy(b.sha1, b_sha);
	b.mode = b_mode;
	return merge_file_1(o, &one, &a, &b, branch1, branch2);
}

static void handle_change_delete(struct merge_options *o,
				 const char *path,
				 const unsigned char *o_sha, int o_mode,
				 const unsigned char *a_sha, int a_mode,
				 const unsigned char *b_sha, int b_mode,
				 const char *change, const char *change_past)
{
	char *renamed = NULL;
	if (dir_in_way(path, !o->call_depth)) {
		renamed = unique_path(o, path, a_sha ? o->branch1 : o->branch2);
	}

	if (o->call_depth) {
