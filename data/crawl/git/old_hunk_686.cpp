--------

-----------------------------------------
int print_callback(const unsigned char sha1[20],
		    void *data)
{
	printf("%s\n", sha1_to_hex(sha1));
	return 0; /* always continue */
}

void some_func(void)
{
	struct sha1_array hashes = SHA1_ARRAY_INIT;
	unsigned char sha1[20];

	/* Read objects into our set */
	while (read_object_from_stdin(sha1))
		sha1_array_append(&hashes, sha1);

	/* Check if some objects are in our set */
	while (read_object_from_stdin(sha1)) {
		if (sha1_array_lookup(&hashes, sha1) >= 0)
			printf("it's in there!\n");

	/*
