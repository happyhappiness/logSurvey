		update_image(img, applied_pos, &preimage, &postimage);
	} else {
		if (apply_verbosely)
			error("while searching for:\n%.*s", oldsize, oldlines);
	}

	free(old);
	free(new);
	free(preimage.line_allocated);
	free(postimage.line_allocated);
