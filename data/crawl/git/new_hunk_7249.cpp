				close(ifd);
				return error("copy-fd: write returned 0");
			} else {
				int write_error = errno;
				close(ifd);
				return error("copy-fd: write returned %s",
					     strerror(write_error));
			}
		}
	}
