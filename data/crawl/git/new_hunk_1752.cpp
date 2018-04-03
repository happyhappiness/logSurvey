		if (!one->data && !two->data &&
		    S_ISREG(one->mode) && S_ISREG(two->mode) &&
		    !DIFF_OPT_TST(o, BINARY)) {
			if (!oidcmp(&one->oid, &two->oid)) {
				if (must_show_header)
					fprintf(o->file, "%s", header.buf);
				goto free_ab_and_return;
