		}

		if (item->kind == REF_LOCAL_BRANCH)
			fill_tracking_info(&stat, item->name);

		printf("%c %s%-*s%s %s %s%s\n", c, branch_get_color(color),
		       maxwidth, item->name,
		       branch_get_color(COLOR_BRANCH_RESET),
		       find_unique_abbrev(item->commit->object.sha1, abbrev),
		       stat.buf, sub);
		strbuf_release(&stat);
		strbuf_release(&subject);
	} else {
		printf("%c %s%s%s\n", c, branch_get_color(color), item->name,
		       branch_get_color(COLOR_BRANCH_RESET));
	}
}

static int calc_maxwidth(struct ref_list *refs)
{
	int i, l, w = 0;
	for (i = 0; i < refs->index; i++) {
		if (!matches_merge_filter(refs->list[i].commit))
			continue;
		l = strlen(refs->list[i].name);
		if (l > w)
			w = l;
	}
	return w;
}
