		}
	}

	if (shallow_update && !checked_connectivity)
		error("BUG: run 'git fsck' for safety.\n"
		      "If there are errors, try to remove "
		      "the reported refs above");
}

static struct command *read_head_info(struct sha1_array *shallow)
