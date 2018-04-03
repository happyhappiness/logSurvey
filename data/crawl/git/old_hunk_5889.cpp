					die("cannot read %s", msgfile);
			} else {
				if (strbuf_read_file(&buf, msgfile, 1024) < 0)
					die("could not open or read '%s': %s",
						msgfile, strerror(errno));
			}
		}
	}
