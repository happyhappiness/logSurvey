	}

	if (state->update_index) {
		res = write_locked_index(&the_index, state->lock_file, COMMIT_LOCK);
		if (res) {
			error(_("Unable to write new index file"));
			res = -128;
			goto end;
		}
		state->newfd = -1;
	}

	return !!errs;

end:
	if (state->newfd >= 0) {
		rollback_lock_file(state->lock_file);
		state->newfd = -1;
	}

	return (res == -1 ? 1 : 128);
}

int cmd_apply(int argc, const char **argv, const char *prefix)