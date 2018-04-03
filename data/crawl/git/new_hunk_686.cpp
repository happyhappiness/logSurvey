--------

-----------------------------------------
int print_callback(const struct object_id *oid,
		    void *data)
{
	printf("%s\n", oid_to_hex(oid));
	return 0; /* always continue */
}

void some_func(void)
{
	struct sha1_array hashes = OID_ARRAY_INIT;
	struct object_id oid;

	/* Read objects into our set */
	while (read_object_from_stdin(oid.hash))
		oid_array_append(&hashes, &oid);

	/* Check if some objects are in our set */
	while (read_object_from_stdin(oid.hash)) {
		if (oid_array_lookup(&hashes, &oid) >= 0)
			printf("it's in there!\n");

	/*
