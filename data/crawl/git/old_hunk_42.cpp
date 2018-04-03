			 void *buf, unsigned long size)
{
	if (!strict) {
		if (write_sha1_file(buf, size, typename(type), obj_list[nr].oid.hash) < 0)
			die("failed to write object");
		added_object(nr, type, buf, size);
		free(buf);
		obj_list[nr].obj = NULL;
	} else if (type == OBJ_BLOB) {
		struct blob *blob;
		if (write_sha1_file(buf, size, typename(type), obj_list[nr].oid.hash) < 0)
			die("failed to write object");
		added_object(nr, type, buf, size);
		free(buf);
