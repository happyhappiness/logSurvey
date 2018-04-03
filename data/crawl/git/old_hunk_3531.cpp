	return 0;
}

static int batch_one_object(const char *obj_name, int print_contents)
{
	unsigned char sha1[20];
	enum object_type type = 0;
	unsigned long size;
	void *contents = NULL;

	if (!obj_name)
	   return 1;
