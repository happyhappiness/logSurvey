	}
	fclose(config_file);
 unlock_and_out:
	if (close(out_fd) || commit_lock_file(lock) < 0)
			ret = error("Cannot commit config file!");
 out:
	free(config_filename);
