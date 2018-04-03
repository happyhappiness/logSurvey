	if (!oidcmp(&remote->object.oid, base_oid)) {
		/* Already merged; result == local commit */
		if (o->verbosity >= 2)
			printf("Already up to date!\n");
		oidcpy(result_oid, &local->object.oid);
		goto found_result;
	}
