					putchar(' ');
				p_mask <<= 1;
			}
			printf("%.*s%s\n", sl->len, sl->bol, c_reset);
		}
	}
}
