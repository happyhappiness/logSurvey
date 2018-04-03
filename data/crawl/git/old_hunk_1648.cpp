		return error("reference '%s' does not point to a blob", name);
	}

	ret = git_config_from_mem(fn, "blob", name, buf, size, data);
	free(buf);

	return ret;
