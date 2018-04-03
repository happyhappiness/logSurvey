static void *read_object(const unsigned char *sha1, enum object_type *type,
			 unsigned long *size);

static void write_pack_access_log(struct packed_git *p, off_t obj_offset)
{
	static FILE *log_file;
