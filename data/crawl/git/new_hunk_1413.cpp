	return merge_status;
}

static int merge_file_1(struct merge_options *o,
					   const struct diff_filespec *one,
					   const struct diff_filespec *a,
					   const struct diff_filespec *b,
					   const char *branch1,
					   const char *branch2,
					   struct merge_file_info *result)
{
	result->merge = 0;
	result->clean = 1;

	if ((S_IFMT & a->mode) != (S_IFMT & b->mode)) {
		result->clean = 0;
		if (S_ISREG(a->mode)) {
			result->mode = a->mode;
			oidcpy(&result->oid, &a->oid);
		} else {
			result->mode = b->mode;
			oidcpy(&result->oid, &b->oid);
		}
	} else {
		if (!oid_eq(&a->oid, &one->oid) && !oid_eq(&b->oid, &one->oid))
			result->merge = 1;

		/*
		 * Merge modes
		 */
		if (a->mode == b->mode || a->mode == one->mode)
			result->mode = b->mode;
		else {
			result->mode = a->mode;
			if (b->mode != one->mode) {
				result->clean = 0;
				result->merge = 1;
			}
		}

		if (oid_eq(&a->oid, &b->oid) || oid_eq(&a->oid, &one->oid))
			oidcpy(&result->oid, &b->oid);
		else if (oid_eq(&b->oid, &one->oid))
			oidcpy(&result->oid, &a->oid);
		else if (S_ISREG(a->mode)) {
			mmbuffer_t result_buf;
			int ret = 0, merge_status;

			merge_status = merge_3way(o, &result_buf, one, a, b,
						  branch1, branch2);

			if ((merge_status < 0) || !result_buf.ptr)
				ret = err(o, _("Failed to execute internal merge"));

			if (!ret && write_sha1_file(result_buf.ptr, result_buf.size,
						    blob_type, result->oid.hash))
				ret = err(o, _("Unable to add %s to database"),
					  a->path);

			free(result_buf.ptr);
			if (ret)
				return ret;
			result->clean = (merge_status == 0);
		} else if (S_ISGITLINK(a->mode)) {
			result->clean = merge_submodule(result->oid.hash,
						       one->path,
						       one->oid.hash,
						       a->oid.hash,
						       b->oid.hash,
						       !o->call_depth);
		} else if (S_ISLNK(a->mode)) {
			oidcpy(&result->oid, &a->oid);

			if (!oid_eq(&a->oid, &b->oid))
				result->clean = 0;
		} else
			die("BUG: unsupported object type in the tree");
	}

	return 0;
}

static int merge_file_special_markers(struct merge_options *o,
			   const struct diff_filespec *one,
			   const struct diff_filespec *a,
			   const struct diff_filespec *b,
			   const char *branch1,
			   const char *filename1,
			   const char *branch2,
			   const char *filename2,
			   struct merge_file_info *mfi)
{
	char *side1 = NULL;
	char *side2 = NULL;
	int ret;

	if (filename1)
		side1 = xstrfmt("%s:%s", branch1, filename1);
	if (filename2)
		side2 = xstrfmt("%s:%s", branch2, filename2);

	ret = merge_file_1(o, one, a, b,
			   side1 ? side1 : branch1,
			   side2 ? side2 : branch2, mfi);
	free(side1);
	free(side2);
	return ret;
}

static int merge_file_one(struct merge_options *o,
					 const char *path,
					 const struct object_id *o_oid, int o_mode,
					 const struct object_id *a_oid, int a_mode,
					 const struct object_id *b_oid, int b_mode,
					 const char *branch1,
					 const char *branch2,
					 struct merge_file_info *mfi)
{
	struct diff_filespec one, a, b;

	one.path = a.path = b.path = (char *)path;
	oidcpy(&one.oid, o_oid);
	one.mode = o_mode;
	oidcpy(&a.oid, a_oid);
	a.mode = a_mode;
	oidcpy(&b.oid, b_oid);
	b.mode = b_mode;
	return merge_file_1(o, &one, &a, &b, branch1, branch2, mfi);
}

static int handle_change_delete(struct merge_options *o,
				 const char *path,
				 const struct object_id *o_oid, int o_mode,
				 const struct object_id *a_oid, int a_mode,
				 const struct object_id *b_oid, int b_mode,
				 const char *change, const char *change_past)
{
	char *renamed = NULL;
	int ret = 0;
	if (dir_in_way(path, !o->call_depth)) {
		renamed = unique_path(o, path, a_oid ? o->branch1 : o->branch2);
	}

	if (o->call_depth) {
