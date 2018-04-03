				char *buf = read_sha1_file(obj->sha1,
						&type, &size);
				if (buf) {
					if (fwrite(buf, size, 1, f) != 1)
						die("Could not write %s: %s",
						    filename, strerror(errno));
					free(buf);
				}
			} else
				fprintf(f, "%s\n", sha1_to_hex(obj->sha1));
			if (fclose(f))
				die("Could not finish %s: %s",
				    filename, strerror(errno));
		}
		return;
	}
