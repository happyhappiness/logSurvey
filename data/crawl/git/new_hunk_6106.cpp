					mark = '*';
				else
					mark = '+';
				printf("%s%c%s",
				       get_color_code(i % COLUMN_COLORS_MAX),
				       mark, get_color_reset_code());
			}
			putchar(' ');
		}