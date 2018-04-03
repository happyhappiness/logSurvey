		struct ref_list *r;

		r = &header->references;
		printf_ln(Q_("The bundle contains %d ref",
			     "The bundle contains %d refs",
			     r->nr),
			  r->nr);
		list_refs(r, 0, NULL);
		r = &header->prerequisites;
		if (!r->nr) {
			printf_ln(_("The bundle records a complete history."));
		} else {
			printf_ln(Q_("The bundle requires this ref",
				     "The bundle requires these %d refs",
				     r->nr),
				  r->nr);
			list_refs(r, 0, NULL);