	    debug(50, 0) ("chdir: %s: %s\n", Config.coredump_dir, xstrerror());
	}
    }
    debug(0, 1) ("Current Directory is %s\n", p);
    xfree(p);
    return;
}

static void