{
	unsigned char sha1[20];
	enum object_type type;
	void *buf;
	unsigned long size;

	if (get_sha1(obj_name, sha1))
		die("Not a valid object name %s", obj_name);

	buf = NULL;
