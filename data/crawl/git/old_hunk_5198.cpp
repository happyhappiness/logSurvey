			continue;

		error("pathspec '%s' did not match any file(s) known to git.",
		      pathspec[num] + prefix_offset);
		errors++;
	}
	return errors;
