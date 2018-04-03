	} while (++pos < active_nr);
	if (!found)
		die("git merge-index: %s not in the cache", path);
	run_program();
	return found;
}
