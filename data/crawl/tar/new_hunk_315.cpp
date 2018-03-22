	int e = errno;
	ERROR ((0, e, _("%s: Was unable to backup this file"),
		quotearg_colon (CURRENT_FILE_NAME)));
	skip_member ();
	return;
      }

