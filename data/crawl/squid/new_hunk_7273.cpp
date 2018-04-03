	    debug(50, 1, "%s: %s\n", path, xstrerror());
	    fatal("storeDirOpenSwapLogs: Failed to open swap log.");
	}
	debug(20, 3, "Cache Dir #%d log opened on FD %d\n", i, fd);
	SD->swaplog_fd = fd;
    }
}
