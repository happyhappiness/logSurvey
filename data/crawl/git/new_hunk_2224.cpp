			else if (skip_prefix(formatp, "strip=", &arg))
				refname = strip_ref_components(refname, arg);
			else
				die(_("unknown %.*s format %s"),
				    (int)(formatp - name), name, formatp);
		}

