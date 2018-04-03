	method += 2;
	method_id = cacheIndexParseMethod(method);
	if (method_id == METHOD_NONE) {
	    fprintf(stderr, "%s:%d: invalid method %s in '%s'\n", 
		fname, scanned_count, method, buf);
	    continue;
	}
	while (*url) url--;