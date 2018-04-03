	debug(50, 1, "%s: %s\n", swaplog_path, xstrerror());
	fatal("storeDirCloseTmpSwapLog: Failed to open swap log.");
    }
    SD->swaplog_fd = fd;
}

void