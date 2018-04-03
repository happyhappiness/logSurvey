
void set_object_name_for_intent_to_add_entry(struct cache_entry *ce)
{
	struct object_id oid;
	if (write_object_file("", 0, blob_type, &oid))
		die("cannot create an empty blob in the object database");
	oidcpy(&ce->oid, &oid);
}

int add_to_index(struct index_state *istate, const char *path, struct stat *st, int flags)
