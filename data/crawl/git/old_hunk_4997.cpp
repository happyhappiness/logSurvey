	return read_packed_sha1(sha1, type, size);
}

void *read_sha1_file_repl(const unsigned char *sha1,
			  enum object_type *type,
			  unsigned long *size,
