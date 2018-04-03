	}

	if (state->update_index) {
		if (write_locked_index(&the_index, state->lock_file, COMMIT_LOCK))
			die(_("Unable to write new index file"));
		state->newfd = -1;
	}

	return !!errs;

end:
	exit(res == -1 ? 1 : 128);
}

int cmd_apply(int argc, const char **argv, const char *prefix)