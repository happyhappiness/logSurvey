		if (item->kind == REF_LOCAL_BRANCH)
			fill_tracking_info(&stat, item->name);

		strbuf_addf(&out, " %s %s%s",
			find_unique_abbrev(item->commit->object.sha1, abbrev),
			stat.buf, sub);
		strbuf_release(&stat);
		strbuf_release(&subject);
	}
	printf("%s\n", out.buf);
	strbuf_release(&name);
	strbuf_release(&out);
}

static int calc_maxwidth(struct ref_list *refs)
{
	int i, w = 0;
	for (i = 0; i < refs->index; i++) {
		if (!matches_merge_filter(refs->list[i].commit))
			continue;
		if (refs->list[i].len > w)
			w = refs->list[i].len;
	}
	return w;
}
