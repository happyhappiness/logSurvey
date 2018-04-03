		if (write_cache(fd, active_cache, active_nr) ||
		    commit_locked_index(lock_file))
			die("unable to write new index file");
	}

	strbuf_release(&reflog_msg);
	strbuf_release(&branch_top);
	strbuf_release(&key);
	strbuf_release(&value);
	junk_pid = 0;
	return 0;
}
