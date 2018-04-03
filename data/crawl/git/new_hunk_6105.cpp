			else {
				for (j = 0; j < i; j++)
					putchar(' ');
				printf("%s%c%s [%s] ",
				       get_color_code(i % COLUMN_COLORS_MAX),
				       is_head ? '*' : '!',
				       get_color_reset_code(), ref_name[i]);
			}

			if (!reflog) {
