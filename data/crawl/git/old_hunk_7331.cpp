	stop_progress(&progress);
}

int unpack_trees(unsigned len, struct tree_desc *t, struct unpack_trees_options *o)
{
	struct tree_entry_list **posns;
	int i;
	struct tree_entry_list df_conflict_list;
	static struct cache_entry *dfc;

	memset(&df_conflict_list, 0, sizeof(df_conflict_list));
	df_conflict_list.next = &df_conflict_list;
	memset(&state, 0, sizeof(state));
	state.base_dir = "";
	state.force = 1;
