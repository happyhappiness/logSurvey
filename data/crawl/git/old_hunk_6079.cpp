	}
	printf("Removing stale temporary file %s\n", fullpath);
	if (!show_only)
		unlink(fullpath);
	return 0;
}

