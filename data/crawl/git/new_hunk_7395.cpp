	return -1;
}

static int mark_object(struct object *obj, int type, void *data)
{
	struct tree *tree = NULL;
	struct object *parent = data;
	int result;

	if (!obj) {
		printf("broken link from %7s %s\n",
			   typename(parent->type), sha1_to_hex(parent->sha1));
		printf("broken link from %7s %s\n",
			   (type == OBJ_ANY ? "unknown" : typename(type)), "unknown");
		errors_found |= ERROR_REACHABLE;
		return 1;
	}

	if (type != OBJ_ANY && obj->type != type)
		objerror(parent, "wrong object type in link");

	if (obj->flags & REACHABLE)
		return 0;
	obj->flags |= REACHABLE;
	if (!obj->parsed) {
		if (parent && !has_sha1_file(obj->sha1)) {
			printf("broken link from %7s %s\n",
				 typename(parent->type), sha1_to_hex(parent->sha1));
			printf("              to %7s %s\n",
				 typename(obj->type), sha1_to_hex(obj->sha1));
			errors_found |= ERROR_REACHABLE;
		}
		return 1;
	}

	if (obj->type == OBJ_TREE) {
		obj->parsed = 0;
		tree = (struct tree *)obj;
		if (parse_tree(tree) < 0)
			return 1; /* error already displayed */
	}
	result = fsck_walk(obj, mark_object, obj);
	if (tree) {
		free(tree->buffer);
		tree->buffer = NULL;
	}
	if (result < 0)
		result = 1;

	return result;
}

static void mark_object_reachable(struct object *obj)
{
	mark_object(obj, OBJ_ANY, 0);
}

static int mark_used(struct object *obj, int type, void *data)
{
	if (!obj)
		return 1;
	obj->used = 1;
	return 0;
}

/*
 * Check a single reachable object
 */
static void check_reachable_object(struct object *obj)
{
	/*
	 * We obviously want the object to be parsed,
	 * except if it was in a pack-file and we didn't
