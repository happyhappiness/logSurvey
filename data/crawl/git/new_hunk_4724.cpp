					/* strip trailing slash */
					pathspec[j] = xstrndup(ce->name, len);
				else
					die (_("Path '%s' is in submodule '%.*s'"),
						pathspec[j], len, ce->name);
			}
		}
