{
	struct object *obj;

	if (!is_null_sha1(osha1)) {
		obj = lookup_object(osha1);
		if (obj) {
