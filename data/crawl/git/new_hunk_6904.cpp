			if (!name)
				continue;

			if (data->name_only) {
				fwrite(p_start, p - p_start + 1 - 40, 1, stdout);
				printf(name);
			} else {
				fwrite(p_start, p - p_start + 1, 1, stdout);
				printf(" (%s)", name);
			}
			p_start = p + 1;
		}
	}