	}
}

void process_trailers(const char *file, int trim_empty, struct string_list *trailers)
{
	struct trailer_item *in_tok_first = NULL;
	struct trailer_item *in_tok_last = NULL;
