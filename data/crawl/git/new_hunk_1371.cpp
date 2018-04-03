
	va_start(ap, fmt);
	strbuf_vaddf(&sb, fmt, ap);
	result = options->error_func(options, object, msg_type, sb.buf);
	strbuf_release(&sb);
	va_end(ap);

	return result;
}

static char *get_object_name(struct fsck_options *options, struct object *obj)
{
	if (!options->object_names)
		return NULL;
	return lookup_decoration(options->object_names, obj);
}

static void put_object_name(struct fsck_options *options, struct object *obj,
	const char *fmt, ...)
{
	va_list ap;
	struct strbuf buf = STRBUF_INIT;
	char *existing;

	if (!options->object_names)
		return;
	existing = lookup_decoration(options->object_names, obj);
	if (existing)
		return;
	va_start(ap, fmt);
	strbuf_vaddf(&buf, fmt, ap);
	add_decoration(options->object_names, obj, strbuf_detach(&buf, NULL));
	va_end(ap);
}

static const char *describe_object(struct fsck_options *o, struct object *obj)
{
	static struct strbuf buf = STRBUF_INIT;
	char *name;

	strbuf_reset(&buf);
	strbuf_addstr(&buf, oid_to_hex(&obj->oid));
	if (o->object_names && (name = lookup_decoration(o->object_names, obj)))
		strbuf_addf(&buf, " (%s)", name);

	return buf.buf;
}

static int fsck_walk_tree(struct tree *tree, void *data, struct fsck_options *options)
{
	struct tree_desc desc;
	struct name_entry entry;
	int res = 0;
	const char *name;

	if (parse_tree(tree))
		return -1;

	name = get_object_name(options, &tree->object);
	init_tree_desc(&desc, tree->buffer, tree->size);
	while (tree_entry(&desc, &entry)) {
		struct object *obj;
		int result;

		if (S_ISGITLINK(entry.mode))
			continue;

		if (S_ISDIR(entry.mode)) {
			obj = &lookup_tree(entry.oid->hash)->object;
			if (name)
				put_object_name(options, obj, "%s%s/", name,
					entry.path);
			result = options->walk(obj, OBJ_TREE, data, options);
		}
		else if (S_ISREG(entry.mode) || S_ISLNK(entry.mode)) {
			obj = &lookup_blob(entry.oid->hash)->object;
			if (name)
				put_object_name(options, obj, "%s%s", name,
					entry.path);
			result = options->walk(obj, OBJ_BLOB, data, options);
		}
		else {
			result = error("in tree %s: entry %s has bad mode %.6o",
					describe_object(options, &tree->object), entry.path, entry.mode);
		}
		if (result < 0)
			return result;
