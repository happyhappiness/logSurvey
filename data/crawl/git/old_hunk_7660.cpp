	const char *ws = diff_get_color(data->color_diff, DIFF_WHITESPACE);
	const char *reset = diff_get_color(data->color_diff, DIFF_RESET);
	const char *set = diff_get_color(data->color_diff, DIFF_FILE_NEW);

	if (line[0] == '+') {
		int i, spaces = 0, space_before_tab = 0, white_space_at_end = 0;

		/* check space before tab */
		for (i = 1; i < len; i++) {
			if (line[i] == ' ')
				spaces++;
			else if (line[i] == '\t') {
				if (spaces) {
					space_before_tab = 1;
					break;
				}
			}
			else
				break;
		}

		/* check whitespace at line end */
		if (line[len - 1] == '\n')
			len--;
		if (isspace(line[len - 1]))
			white_space_at_end = 1;

		if (space_before_tab || white_space_at_end) {
			data->status = 1;
			printf("%s:%d: %s", data->filename, data->lineno, ws);
			if (space_before_tab) {
				printf("space before tab");
				if (white_space_at_end)
					putchar(',');
			}
			if (white_space_at_end)
				printf("whitespace at end");
			printf(":%s ", reset);
			emit_line_with_ws(1, set, reset, ws, line, len,
					  data->ws_rule);
		}

		data->lineno++;
	} else if (line[0] == ' ')
		data->lineno++;
