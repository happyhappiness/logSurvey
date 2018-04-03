
static void mark_object_for_connectivity(const unsigned char *sha1)
{
	struct object *obj = lookup_object(sha1);

	/*
	 * Setting the object type here isn't strictly necessary for a
	 * connectivity check. In most cases, our walk will expect a certain
	 * type (e.g., a tree referencing a blob) and will use lookup_blob() to
	 * assign the type. But doing it here has two advantages:
	 *
	 *   1. When the fsck_walk code looks at objects that _don't_ come from
	 *      links (e.g., the tip of a ref), it may complain about the
	 *      "unknown object type".
	 *
	 *   2. This serves as a nice cross-check that the graph links are
	 *      sane. So --connectivity-only does not check that the bits of
	 *      blobs are not corrupted, but it _does_ check that 100644 tree
	 *      entries point to blobs, and so forth.
	 *
	 * Unfortunately we can't just use parse_object() here, because the
	 * whole point of --connectivity-only is to avoid reading the object
	 * data more than necessary.
	 */
	if (!obj || obj->type == OBJ_NONE) {
		enum object_type type = sha1_object_info(sha1, NULL);
		switch (type) {
		case OBJ_BAD:
			error("%s: unable to read object type",
			      sha1_to_hex(sha1));
			break;
		case OBJ_COMMIT:
			obj = (struct object *)lookup_commit(sha1);
			break;
		case OBJ_TREE:
			obj = (struct object *)lookup_tree(sha1);
			break;
		case OBJ_BLOB:
			obj = (struct object *)lookup_blob(sha1);
			break;
		case OBJ_TAG:
			obj = (struct object *)lookup_tag(sha1);
			break;
		default:
			error("%s: unknown object type %d",
			      sha1_to_hex(sha1), type);
		}

		if (!obj || obj->type == OBJ_NONE) {
			errors_found |= ERROR_OBJECT;
			return;
		}
	}

	obj->flags |= HAS_OBJ;
}

