	}
}

static void show_commit(struct commit *commit)
{
	add_object_entry(commit->object.sha1, OBJ_COMMIT, NULL, 0);
}

static void show_object(struct object_array_entry *p)
{
	add_preferred_base_object(p->name);
	add_object_entry(p->item->sha1, p->item->type, p->name, 0);
}

static void show_edge(struct commit *commit)
{
	add_preferred_base(commit->object.sha1);
}

static void get_object_list(int ac, const char **av)
{
	struct rev_info revs;
