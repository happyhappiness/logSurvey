	 * since this is something that is prunable.
	 */
	if (show_unreachable) {
		printf("unreachable %s %s\n", typename(obj->type), sha1_to_hex(obj->sha1));
		return;
	}

