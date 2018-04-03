		resetv.s = color;
		append_atom(&resetv, &state);
	}
	final_buf = &state.stack->output;
	fwrite(final_buf->buf, 1, final_buf->len, stdout);
	pop_stack_element(&state.stack);
