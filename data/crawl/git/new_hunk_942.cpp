	free_all(&head);

	/* Print the lines after the trailers as is */
	fwrite(sb.buf + trailer_end, 1, sb.len - trailer_end, outfile);

	if (in_place)
		if (rename_tempfile(&trailers_tempfile, file))
			die_errno(_("could not rename temporary file to %s"), file);

	strbuf_release(&sb);
}