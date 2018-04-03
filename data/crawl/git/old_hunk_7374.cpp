struct obj_info {
	off_t offset;
	unsigned char sha1[20];
};

static struct obj_info *obj_list;

static void added_object(unsigned nr, enum object_type type,
			 void *data, unsigned long size);

static void write_object(unsigned nr, enum object_type type,
			 void *buf, unsigned long size)
{
	if (write_sha1_file(buf, size, typename(type), obj_list[nr].sha1) < 0)
		die("failed to write object");
	added_object(nr, type, buf, size);
}

static void resolve_delta(unsigned nr, enum object_type type,
