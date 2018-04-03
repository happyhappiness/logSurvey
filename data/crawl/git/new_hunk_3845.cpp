	return last;
}

static struct ref *get_refs(int for_push)
{
	struct discovery *heads;