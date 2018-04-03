		     (stage == 2) ? "our" : "their");
}

/* NEEDSWORK: share with merge-recursive */
static void fill_mm(const unsigned char *sha1, mmfile_t *mm)
{
	unsigned long size;
	enum object_type type;

	if (!hashcmp(sha1, null_sha1)) {
		mm->ptr = xstrdup("");
		mm->size = 0;
		return;
	}

	mm->ptr = read_sha1_file(sha1, &type, &size);
	if (!mm->ptr || type != OBJ_BLOB)
		die("unable to read blob object %s", sha1_to_hex(sha1));
	mm->size = size;
}

static int checkout_merged(int pos, struct checkout *state)
{
	struct cache_entry *ce = active_cache[pos];
