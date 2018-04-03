	return 0;
}

struct object *peel_to_type(const char *name, int namelen,
			    struct object *o, enum object_type expected_type)
{
	if (name && !namelen)
		namelen = strlen(name);
	if (!o) {
		unsigned char sha1[20];
		if (get_sha1_1(name, namelen, sha1))
			return NULL;
		o = parse_object(sha1);
	}
	while (1) {
		if (!o || (!o->parsed && !parse_object(o->sha1)))
			return NULL;
		if (o->type == expected_type)
			return o;
		if (o->type == OBJ_TAG)
			o = ((struct tag*) o)->tagged;
		else if (o->type == OBJ_COMMIT)
			o = &(((struct commit *) o)->tree->object);
		else {
			if (name)
				error("%.*s: expected %s type, but the object "
				      "dereferences to %s type",
				      namelen, name, typename(expected_type),
				      typename(o->type));
			return NULL;
		}
	}
}

static int peel_onion(const char *name, int len, unsigned char *sha1)
{
	unsigned char outer[20];
