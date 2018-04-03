	qsort(array->items, array->nr, sizeof(struct ref_array_item *), compare_refs);
}

static void append_atom(struct atom_value *v, struct ref_formatting_state *state)
{
	struct strbuf *s = &state->stack->output;

	switch (state->quote_style) {
	case QUOTE_NONE:
		strbuf_addstr(s, v->s);
		break;
	case QUOTE_SHELL:
		sq_quote_buf(s, v->s);
		break;
	case QUOTE_PERL:
		perl_quote_buf(s, v->s);
		break;
	case QUOTE_PYTHON:
		python_quote_buf(s, v->s);
		break;
	case QUOTE_TCL:
		tcl_quote_buf(s, v->s);
		break;
	}
}

static int hex1(char ch)
