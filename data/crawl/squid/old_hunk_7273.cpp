	    debug(50, 1, "%s: %s\n", path, xstrerror());
	    fatal("storeDirOpenSwapLogs: Failed to open swap log.");
	}
	SD->swaplog_fd = fd;
    }
}
