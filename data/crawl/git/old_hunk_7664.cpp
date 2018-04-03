			white_space_at_end = 1;

		if (space_before_tab || white_space_at_end) {
			printf("%s:%d: %s", data->filename, data->lineno, ws);
			if (space_before_tab) {
				printf("space before tab");
