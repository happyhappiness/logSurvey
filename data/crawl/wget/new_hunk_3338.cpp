	if ( line != buf )
	  fputs(buf, out);
	free(buf);
	if ( output_name ) {
	  output_error = ferror(out);
	  output_error |= fclose(out);
	} else {		/* out == stdout */
	  fflush(out);
	  output_error = ferror(out);
	}
	if ( output_error ) {
	  fprintf(stderr, "%s: error writing to %s\n", program_name,
		  (output_name ? output_name : "stdout"));
	  exit(1);
	}
	if ( in != stdin )
	  fclose(in);
	return 0;
}

/* Skip over whitespace and comments, in either direction. */
char *
skipspace(p, dir)
    register char *p;
