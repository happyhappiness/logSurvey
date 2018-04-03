				    comment_end = i;
			}
			if (comment_end)
				putchar(' ');
			for (i = 0; i < comment_end; i++)
				putchar(hunk_comment[i]);
		}
