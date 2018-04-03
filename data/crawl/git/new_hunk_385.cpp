		}
		write_eolinfo(istate, ce, ce->name);
		write_name(ce->name);
		print_debug(ce);
	}

	strbuf_release(&name);