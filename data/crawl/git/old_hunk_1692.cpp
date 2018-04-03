	 * since this is something that is prunable.
	 */
	if (show_unreachable) {
		printf("unreachable %s %s\n", typename(obj->type), oid_to_hex(&obj->oid));
		return;
	}

