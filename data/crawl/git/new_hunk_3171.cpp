			}
			if (comment_end)
				printf("%s%s %s%s", c_reset,
						    c_context, c_reset,
						    c_func);
			for (i = 0; i < comment_end; i++)
				putchar(hunk_comment[i]);
