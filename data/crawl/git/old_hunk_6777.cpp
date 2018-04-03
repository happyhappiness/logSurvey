				continue;
			}
			if (!removed)
				die("git-rm: %s: %s", path, strerror(errno));
		}
	}

