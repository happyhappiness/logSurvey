	return git_default_config(var, value, cb);
}

int write_tar_archive(struct archiver_args *args)
{
	int err = 0;

	git_config(git_tar_config, NULL);

	if (args->commit_sha1)
		err = write_global_extended_header(args);
	if (!err)
		err = write_archive_entries(args, write_tar_entry);
	if (!err)
		write_trailer();
	return err;
}
