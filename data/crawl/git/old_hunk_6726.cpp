		}

		if (!no_query) {
			strbuf_init(&buf, 0);
			strbuf_addf(&buf, "  New remote branch%%s (next fetch "
				"will store in remotes/%s)", states.remote->name);
			show_list(buf.buf, &states.new);
			strbuf_release(&buf);
			show_list("  Stale tracking branch%s (use 'git remote "
				"prune')", &states.stale);
		}

		if (no_query)
			for_each_ref(append_ref_to_tracked_list, &states);
		show_list("  Tracked remote branch%s", &states.tracked);

		if (states.remote->push_refspec_nr) {
			printf("  Local branch%s pushed with 'git push'\n   ",