	 * since this is something that is prunable.
	 */
	if (show_unreachable) {
		printf("unreachable %s %s\n", printable_type(obj),
			describe_object(obj));
		return;
	}
