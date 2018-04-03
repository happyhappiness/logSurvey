			free((void *) submodule->url);
			submodule->url = xstrdup(value);
		}
	}

	strbuf_release(&name);
