			const char *err)
{
	fprintf(stderr, "%s in %s %s: %s\n",
		msg_type, typename(obj->type), sha1_to_hex(obj->sha1), err);
}

static int objerror(struct object *obj, const char *err)
