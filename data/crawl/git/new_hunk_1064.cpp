struct alternate_object_database *alt_odb_list;
static struct alternate_object_database **alt_odb_tail;

/*
 * Return non-zero iff the path is usable as an alternate object database.
 */
static int alt_odb_usable(struct strbuf *path, const char *normalized_objdir)
{
	struct alternate_object_database *alt;

	/* Detect cases where alternate disappeared */
	if (!is_directory(path->buf)) {
		error("object directory %s does not exist; "
		      "check .git/objects/info/alternates.",
		      path->buf);
		return 0;
	}

	/*
	 * Prevent the common mistake of listing the same
	 * thing twice, or object directory itself.
	 */
	for (alt = alt_odb_list; alt; alt = alt->next) {
		if (path->len == alt->name - alt->base - 1 &&
		    !memcmp(path->buf, alt->base, path->len))
			return 0;
	}
	if (!fspathcmp(path->buf, normalized_objdir))
		return 0;

	return 1;
}

/*
 * Prepare alternate object database registry.
 *
