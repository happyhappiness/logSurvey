	}
}

static void update_remote_refs(const struct ref *refs,
			       const struct ref *mapped_refs,
			       const struct ref *remote_head_points_at,
			       const char *branch_top,
			       const char *msg)
{
	if (refs) {
		write_remote_refs(mapped_refs);
		if (option_single_branch)
