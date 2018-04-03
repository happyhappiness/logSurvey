		if (annotated_cnt && !list) {
			if (debug)
				fprintf(stderr, _("finished search at %s\n"),
					oid_to_hex(&c->object.oid));
			break;
		}
		while (parents) {
