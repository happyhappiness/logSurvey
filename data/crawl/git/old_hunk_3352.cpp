		}
	}

	if (shallow_update) {
		if (!checked_connectivity)
			error("BUG: run 'git fsck' for safety.\n"
			      "If there are errors, try to remove "
			      "the reported refs above");
		if (alt_shallow_file && *alt_shallow_file)
			unlink(alt_shallow_file);
	}
}

static struct command *read_head_info(struct sha1_array *shallow)
