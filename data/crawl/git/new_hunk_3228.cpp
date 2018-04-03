				break;

			if (!skip || !string_list_has_string(skip, extra_refname)) {
				strbuf_addf(err, "cannot process '%s' and '%s' at the same time",
					    refname, extra_refname);
				goto cleanup;
			}
		}
