
	if (sb->final_buf_size && cp[-1] != '\n')
		putchar('\n');
}

static void output(struct scoreboard *sb, int option)
