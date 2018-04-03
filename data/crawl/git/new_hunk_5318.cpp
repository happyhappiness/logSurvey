	struct child_process *helper;
	struct ref *ref;

	helper = get_helper(transport);
	if (!data->push)
		return 1;
