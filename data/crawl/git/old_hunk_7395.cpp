	return -1;
}

/*
 * Check a single reachable object
 */
static void check_reachable_object(struct object *obj)
{
	const struct object_refs *refs;

	/*
	 * We obviously want the object to be parsed,
	 * except if it was in a pack-file and we didn't
