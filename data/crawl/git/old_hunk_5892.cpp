		if (flags & CSUM_FSYNC)
			fsync_or_die(f->fd, f->name);
		if (close(f->fd))
			die("%s: sha1 file error on close (%s)",
			    f->name, strerror(errno));
		fd = 0;
	} else
		fd = f->fd;
