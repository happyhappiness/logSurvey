				char *buf = read_sha1_file(obj->sha1,
						&type, &size);
				if (buf) {
					fwrite(buf, size, 1, f);
					free(buf);
				}
			} else
				fprintf(f, "%s\n", sha1_to_hex(obj->sha1));
			fclose(f);
		}
		return;
	}
