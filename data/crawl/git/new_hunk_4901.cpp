	return ret;
}

static char *resolve_relative_path(const char *rel)
{
	if (prefixcmp(rel, "./") && prefixcmp(rel, "../"))
		return NULL;

	if (!startup_info)
		die("BUG: startup_info struct is not initialized.");

	if (!is_inside_work_tree())
		die("relative path syntax can't be used outside working tree.");

	/* die() inside prefix_path() if resolved path is outside worktree */
	return prefix_path(startup_info->prefix,
			   startup_info->prefix ? strlen(startup_info->prefix) : 0,
			   rel);
}

int get_sha1_with_context_1(const char *name, unsigned char *sha1,
			    struct object_context *oc,
			    int gently, const char *prefix)
