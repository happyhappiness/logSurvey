	    fatal("Failed to open error text file");
	}
	if (fstat(fd, &sb) < 0)
	    fatal_dump("stat() failed on error text file");
	safe_free(error_text[i]);
	error_text[i] = xcalloc(sb.st_size + 1, 1);
	if (read(fd, error_text[i], sb.st_size) != sb.st_size)
	    fatal_dump("failed to fully read error text file");
	file_close(fd);
    }
}

static void
errorStateFree(ErrorState * err)
{
