			const char *err)
{
	fprintf(stderr, "%s in %s %s: %s\n",
		msg_type, printable_type(obj), describe_object(obj), err);
}

static int objerror(struct object *obj, const char *err)
