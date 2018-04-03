			 void *buf, unsigned long size)
{
	if (!strict) {
		if (write_object_file(buf, size, typename(type),
				      &obj_list[nr].oid) < 0)
			die("failed to write object");
		added_object(nr, type, buf, size);
		free(buf);
		obj_list[nr].obj = NULL;
	} else if (type == OBJ_BLOB) {
		struct blob *blob;
		if (write_object_file(buf, size, typename(type),
				      &obj_list[nr].oid) < 0)
			die("failed to write object");
		added_object(nr, type, buf, size);
		free(buf);
