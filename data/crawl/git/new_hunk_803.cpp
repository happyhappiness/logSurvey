			something_displayed = 1;
			for (i = 0; i < rejects->nr; i++)
				strbuf_addf(&path, "\t%s\n", rejects->items[i].string);
			error(ERRORMSG(o, e), super_prefixed(path.buf));
			strbuf_release(&path);
		}
		string_list_clear(rejects, 0);
