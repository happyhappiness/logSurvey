	int agent_len;

	sort_ref_list(&ref, ref_compare_name);
	qsort(sought, nr_sought, sizeof(*sought), cmp_ref_by_name);

	if (is_repository_shallow() && !server_supports("shallow"))
		die("Server does not support shallow clients");
