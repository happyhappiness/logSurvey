	free(array);
}

static void prepare_pack(int window, int depth)
{
	struct object_entry **delta_list;
