			int flag = REF_ISPACKED;

			if (check_refname_format(refname, REFNAME_ALLOW_ONELEVEL)) {
				if (!refname_is_safe(refname))
					die("packed refname is dangerous: %s", refname);
				hashclr(sha1);
				flag |= REF_BAD_NAME | REF_ISBROKEN;
			}