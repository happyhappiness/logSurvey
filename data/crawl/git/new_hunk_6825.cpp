		ca = reverse_commit_list(ca);
	}

	if (show(o, 5)) {
		output(o, 5, "found %u common ancestor(s):", commit_list_count(ca));
		for (iter = ca; iter; iter = iter->next)
			output_commit_title(iter->item);
	}
