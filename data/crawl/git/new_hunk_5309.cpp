		rollback_lock_file(lock);
		return clean ? 0 : 1;
	} else {
		return try_merge_command(strategy, common, head_arg, remoteheads);
	}
}
