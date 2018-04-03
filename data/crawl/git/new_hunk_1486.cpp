	unsigned char sha1[20];
	if (write_sha1_file("", 0, blob_type, sha1))
		die("cannot create an empty blob in the object database");
	hashcpy(ce->oid.hash, sha1);
}

int add_to_index(struct index_state *istate, const char *path, struct stat *st, int flags, int force_mode)
