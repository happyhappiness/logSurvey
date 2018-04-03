
		name_part = skip_range_arg(item->string);
		if (!name_part || *name_part != ':' || !name_part[1])
			die("-L argument not 'start,end:file' or ':funcname:file': %s",
			    item->string);
		range_part = xstrndup(item->string, name_part - item->string);
		name_part++;
