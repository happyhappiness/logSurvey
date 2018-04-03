	convert_attrs(&ca, path);

	assert(ca.drv);
	assert(ca.drv->clean);

	if (!apply_filter(path, NULL, 0, fd, dst, ca.drv, CAP_CLEAN))
		die("%s: clean filter '%s' failed", path, ca.drv->name);
