			}
			if (check_refname_format(refname.buf,
						 REFNAME_ALLOW_ONELEVEL)) {
				hashclr(sha1);
				flag |= REF_BAD_NAME | REF_ISBROKEN;
			}