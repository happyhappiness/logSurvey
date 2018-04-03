
static int add_one_ref(const char *path, const unsigned char *sha1, int flag, void *cb_data)
{
	struct object *object = parse_object(sha1);
	struct rev_info *revs = (struct rev_info *)cb_data;

	if (!object)
		die("bad object ref: %s:%s", path, sha1_to_hex(sha1));
	add_pending_object(revs, object, "");

	return 0;