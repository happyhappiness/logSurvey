			match_beginning = match_end = 0;
			continue;
		}

		/*
		 * Reduce the number of context lines; reduce both
		 * leading and trailing if they are equal otherwise
		 * just reduce the larger context.
		 */
		if (leading >= trailing) {
			remove_first_line(&preimage);
			remove_first_line(&postimage);
			pos--;
			leading--;
		}
		if (trailing > leading) {
			remove_last_line(&preimage);
			remove_last_line(&postimage);
			trailing--;
		}
	}

	if (applied_pos >= 0) {
		if (ws_error_action == correct_ws_error &&
		    new_blank_lines_at_end &&
		    postimage.nr + applied_pos == img->nr) {
			/*
			 * If the patch application adds blank lines
			 * at the end, and if the patch applies at the
			 * end of the image, remove those added blank
			 * lines.
			 */
			while (new_blank_lines_at_end--)
				remove_last_line(&postimage);
		}

		/*
		 * Warn if it was necessary to reduce the number
		 * of context lines.
		 */
		if ((leading != frag->leading) ||
		    (trailing != frag->trailing))
			fprintf(stderr, "Context reduced to (%ld/%ld)"
				" to apply fragment at %d\n",
				leading, trailing, applied_pos+1);
		update_image(img, applied_pos, &preimage, &postimage);
	} else {
		if (apply_verbosely)
			error("while searching for:\n%.*s", oldsize, oldlines);
	}

	free(old);
	free(new);
	free(preimage.line_allocated);
	free(postimage.line_allocated);

	return (applied_pos < 0);
}

static int apply_binary_fragment(struct image *img, struct patch *patch)
{
	struct fragment *fragment = patch->fragments;
	unsigned long len;
