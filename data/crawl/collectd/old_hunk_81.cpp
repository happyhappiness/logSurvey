		}
	}

	PRINT_TO_SOCK (fh, "0 Done: %i successful, %i errors\n",
			success, error);

	strarray_free (plugins, plugins_num);
	strarray_free (identifiers, identifiers_num);
	return (0);
#undef PRINT_TO_SOCK
} /* int handle_flush */

/* vim: set sw=4 ts=4 tw=78 noexpandtab : */

