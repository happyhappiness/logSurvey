	}
}

static void deepen(int depth, const struct object_array *shallows)
{
	struct commit_list *result = NULL, *backup = NULL;
