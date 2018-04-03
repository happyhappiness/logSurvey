		    int literally)
{
	struct stat st;
	struct object_id oid;

	if (fstat(fd, &st) < 0 ||
	    (literally
	     ? hash_literally(&oid, fd, type, flags)
	     : index_fd(oid.hash, fd, &st, type_from_string(type), path, flags)))
		die((flags & HASH_WRITE_OBJECT)
		    ? "Unable to add %s to database"
		    : "Unable to hash %s", path);
	printf("%s\n", oid_to_hex(&oid));
	maybe_flush_or_die(stdout, "hash to stdout");
}
