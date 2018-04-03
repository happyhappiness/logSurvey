		if (color_parse("reset", color) < 0)
			die("BUG: couldn't parse 'reset' as a color");
		resetv.s = color;
		append_atom(&resetv, &state);
	}
	final_buf = &state.stack->output;
	fwrite(final_buf->buf, 1, final_buf->len, stdout);
	pop_stack_element(&state.stack);
	putchar('\n');
}
