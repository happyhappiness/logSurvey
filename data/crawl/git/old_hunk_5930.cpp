	if (fsync_object_files)
		fsync_or_die(fd, "sha1 file");
	if (close(fd) != 0)
		die("error when closing sha1 file (%s)", strerror(errno));
}

/* Size of directory component, including the ending '/' */
