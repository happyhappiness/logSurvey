			fprintf(stderr, " %.*s", 8,
				sha1_to_hex(pp->item->object.sha1));

		sp = strstr(buf, "\n\n");
		if (sp) {
			sp += 2;
			for (ep = sp; *ep && *ep != '\n'; ep++)
				;
			fprintf(stderr, " %.*s", (int)(ep - sp), sp);
		}
		fprintf(stderr, "\n");
	}
}