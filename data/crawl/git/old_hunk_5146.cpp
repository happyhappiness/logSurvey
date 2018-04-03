	return (is_null_sha1(sha) || mode == 0) ? NULL: (unsigned char *)sha;
}

/* Per entry merge function */
static int process_entry(struct merge_options *o,
			 const char *path, struct stage_data *entry)
