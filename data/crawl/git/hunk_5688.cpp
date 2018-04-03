 	if (line[0] == '+') {
 		unsigned bad;
 		data->lineno++;
-		if (!ws_blank_line(line + 1, len - 1, data->ws_rule))
-			data->trailing_blanks_start = 0;
-		else if (!data->trailing_blanks_start)
-			data->trailing_blanks_start = data->lineno;
 		if (is_conflict_marker(line + 1, len - 1)) {
 			data->status |= 1;
 			fprintf(data->o->file,
