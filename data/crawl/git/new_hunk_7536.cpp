		match_end = !trailing;
	}

	pos = frag->newpos ? (frag->newpos - 1) : 0;
	prepare_image(&preimage, oldlines, oldsize, 1);
	prepare_image(&postimage, newlines, newsize, 1);
	for (;;) {

		applied_pos = find_pos(img, &preimage, &postimage,
				       pos, match_beginning, match_end);

		if (applied_pos >= 0)
			break;

		/* Am I at my context limits? */
		if ((leading <= p_context) && (trailing <= p_context))
