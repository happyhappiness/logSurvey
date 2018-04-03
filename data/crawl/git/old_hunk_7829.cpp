	}
}

static void log_show_early(struct rev_info *revs, struct commit_list *list)
{
	int i = revs->early_output;

	sort_in_topological_order(&list, revs->lifo);
	while (list && i) {
		struct commit *commit = list->item;
		log_tree_commit(revs, commit);
		list = list->next;
		i--;
	}
}

static void early_output(int signal)
