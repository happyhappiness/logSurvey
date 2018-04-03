			else {
				for (j = 0; j < i; j++)
					putchar(' ');
				printf("%c [%s] ",
				       is_head ? '*' : '!', ref_name[i]);
			}

			if (!reflog) {
