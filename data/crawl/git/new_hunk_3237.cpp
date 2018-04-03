				 * "refs/foo"). So we can stop looking
				 * now and return true.
				 */
				ret = 1;
				goto cleanup;
			}
			error("'%s' exists; cannot create '%s'", dirname.buf, refname);
			goto cleanup;
		}


