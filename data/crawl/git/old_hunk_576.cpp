
static void parse_from_commit(struct branch *b, char *buf, unsigned long size)
{
	if (!buf || size < 46)
		die("Not a valid commit: %s", oid_to_hex(&b->oid));
	if (memcmp("tree ", buf, 5)
		|| get_sha1_hex(buf + 5, b->branch_tree.versions[1].oid.hash))
		die("The commit %s is corrupt", oid_to_hex(&b->oid));
	oidcpy(&b->branch_tree.versions[0].oid,
	       &b->branch_tree.versions[1].oid);
