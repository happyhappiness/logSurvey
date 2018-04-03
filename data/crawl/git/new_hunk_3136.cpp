		return fsck_tag((struct tag *) obj, (const char *) data,
			size, options);

	return report(options, obj, FSCK_MSG_UNKNOWN_TYPE, "unknown type '%d' (internal fsck error)",
			  obj->type);
}

int fsck_error_function(struct object *obj, int msg_type, const char *message)
{
	error("object %s: %s", sha1_to_hex(obj->sha1), message);
	return 1;
}
