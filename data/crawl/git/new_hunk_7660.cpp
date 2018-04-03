	const char *ws = diff_get_color(data->color_diff, DIFF_WHITESPACE);
	const char *reset = diff_get_color(data->color_diff, DIFF_RESET);
	const char *set = diff_get_color(data->color_diff, DIFF_FILE_NEW);
	char *err;

	if (line[0] == '+') {
		data->status = check_and_emit_line(line + 1, len - 1,
		    data->ws_rule, NULL, NULL, NULL, NULL);
		if (!data->status)
			return;
		err = whitespace_error_string(data->status);
		printf("%s:%d: %s%s:%s ", data->filename, data->lineno,
		    ws, err, reset);
		free(err);
		emit_line(set, reset, line, 1);
		(void)check_and_emit_line(line + 1, len - 1, data->ws_rule,
		    stdout, set, reset, ws);
		data->lineno++;
	} else if (line[0] == ' ')
		data->lineno++;
