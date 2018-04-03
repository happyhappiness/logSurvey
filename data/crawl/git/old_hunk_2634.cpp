		   will fail first.  But just in case..
		 */
		if (--mi->content_top < mi->content) {
			fprintf(stderr, "Detected mismatched boundaries, "
					"can't recover\n");
			exit(1);
		}
		handle_filter(mi, &newline);
		strbuf_release(&newline);

		/* skip to the next boundary */
		if (!find_boundary(mi, line))
