		printf("%c %s%-*s%s %s %s%s\n", c, branch_get_color(color),
		       maxwidth, item->name,
		       branch_get_color(COLOR_BRANCH_RESET),
		       find_unique_abbrev(item->commit->object.sha1, abbrev),
		       stat, sub);
		strbuf_release(&subject);
	} else {
