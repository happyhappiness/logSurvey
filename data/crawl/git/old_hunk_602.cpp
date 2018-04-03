static void file_change_deleteall(struct branch *b)
{
	release_tree_content_recursive(b->branch_tree.tree);
	hashclr(b->branch_tree.versions[0].sha1);
	hashclr(b->branch_tree.versions[1].sha1);
	load_tree(&b->branch_tree);
	b->num_notes = 0;
}

static void parse_from_commit(struct branch *b, char *buf, unsigned long size)
{
	if (!buf || size < 46)
		die("Not a valid commit: %s", sha1_to_hex(b->sha1));
	if (memcmp("tree ", buf, 5)
		|| get_sha1_hex(buf + 5, b->branch_tree.versions[1].sha1))
		die("The commit %s is corrupt", sha1_to_hex(b->sha1));
	hashcpy(b->branch_tree.versions[0].sha1,
		b->branch_tree.versions[1].sha1);
}

static void parse_from_existing(struct branch *b)
{
	if (is_null_sha1(b->sha1)) {
		hashclr(b->branch_tree.versions[0].sha1);
		hashclr(b->branch_tree.versions[1].sha1);
	} else {
		unsigned long size;
		char *buf;

		buf = read_object_with_reference(b->sha1,
			commit_type, &size, b->sha1);
		parse_from_commit(b, buf, size);
		free(buf);
	}
