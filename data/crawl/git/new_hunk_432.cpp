		*file = o->file;
}

static void drop_origin_blob(struct blame_origin *o)
{
	if (o->file.ptr) {
