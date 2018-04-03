				close(ifd);
				return error("copy-fd: write returned 0");
			} else {
				close(ifd);
				return error("copy-fd: write returned %s",
					     strerror(errno));
			}
		}
	}
