		}
		if (close(msg_fd) || commit_lock_file(&msg_file) < 0)
			die ("Error wrapping up %s", defmsg);
		fprintf(stderr, "Automatic %s failed.%s\n",
			me, help_msg(commit->object.sha1));
		exit(1);
	}
	if (close(msg_fd) || commit_lock_file(&msg_file) < 0)