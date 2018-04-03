	return strcmp(one->name, two->name);
}

static void sort_ref_array(struct ref_array *array)
{
	int i = 0, j = 1;

	/* Nothing to sort unless there are at least two entries */
	if (array->nr < 2)
