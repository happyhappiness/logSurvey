{
	struct object_id oid;

	if (write_object_file(obj_buf->buffer, obj_buf->size,
			      typename(obj->type), &oid) < 0)
		die("failed to write object %s", oid_to_hex(&obj->oid));
	obj->flags |= FLAG_WRITTEN;
}
