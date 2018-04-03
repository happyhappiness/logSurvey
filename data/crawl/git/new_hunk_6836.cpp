					else
						putchar(' ');
				}
				show_line_to_eol(ll->line, -1, c_reset);
				ll = ll->next;
			}
			if (cnt < lno)
