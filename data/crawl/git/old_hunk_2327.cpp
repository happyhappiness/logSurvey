	/* Print the lines after the trailers as is */
	print_lines(outfile, lines, trailer_end, INT_MAX);

	strbuf_list_free(lines);
}
