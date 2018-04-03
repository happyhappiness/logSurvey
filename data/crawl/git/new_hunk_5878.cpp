						&type, &size);
				if (buf) {
					if (fwrite(buf, size, 1, f) != 1)
						die_errno("Could not write '%s'",
							  filename);
					free(buf);
				}
			} else
				fprintf(f, "%s\n", sha1_to_hex(obj->sha1));
			if (fclose(f))
				die_errno("Could not finish '%s'",
					  filename);
		}
		return;
	}
