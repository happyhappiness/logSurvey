		struct utimbuf utb;
		utb.actime = mtime;
		utb.modtime = mtime;
		if (utime(tmpfile, &utb) < 0)
			warning("failed utime() on %s: %s",
				tmpfile, strerror(errno));
	}

	return move_temp_to_file(tmpfile, filename);
}

int write_sha1_file(const void *buf, unsigned long len, const char *type, unsigned char *returnsha1)