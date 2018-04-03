		 * would trigger that.
		 */
		die_inside_submodule_path(item);
		die ("BUG: item->nowildcard_len > item->len || item->prefix > item->len)");
	}
}
