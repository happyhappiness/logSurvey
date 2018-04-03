		if (!data->status)
			return;
		err = whitespace_error_string(data->status);
		printf("%s:%d: %s%s:%s ", data->filename, data->lineno,
		    ws, err, reset);
		free(err);
		emit_line(set, reset, line, 1);
		(void)check_and_emit_line(line + 1, len - 1, data->ws_rule,