		goto cleanup_return;
	}

	printf("%s\n", oid_to_hex(&bases->item->object.oid));

cleanup_return:
	free_commit_list(bases);
