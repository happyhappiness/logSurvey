			mid = &data[i];
		if (data[i] == '\n') {
			if (mid - start != 40)
				die("%sinfo/refs not valid: is this a git repository?", url);
			data[i] = 0;
			ref_name = mid + 1;
			ref = xmalloc(sizeof(struct ref) +
