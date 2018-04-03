			/* abbreviated? */
			if (!strncmp(options->long_name, arg, arg_end - arg)) {
is_abbreviated:
				if (abbrev_option)
					return error("Ambiguous option: %s "
						"(could be --%s%s or --%s%s)",
						arg,
						(flags & OPT_UNSET) ?
							"no-" : "",
						options->long_name,
						(abbrev_flags & OPT_UNSET) ?
							"no-" : "",
						abbrev_option->long_name);
				if (!(flags & OPT_UNSET) && *arg_end)
					p->opt = arg_end + 1;
				abbrev_option = options;
