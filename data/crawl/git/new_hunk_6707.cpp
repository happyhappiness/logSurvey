		if (strncmp(sanitized, work_tree, len) ||
		    (sanitized[len] != '\0' && sanitized[len] != '/')) {
		error_out:
			die("'%s' is outside repository", orig);
		}
		if (sanitized[len] == '/')
			len++;
