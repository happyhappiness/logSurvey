	return result;
}

static void free_remote_ref_states(struct ref_states *states)
{
	string_list_clear(&states->new, 0);
