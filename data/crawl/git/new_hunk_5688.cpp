	if (line[0] == '+') {
		unsigned bad;
		data->lineno++;
		if (is_conflict_marker(line + 1, len - 1)) {
			data->status |= 1;
			fprintf(data->o->file,
