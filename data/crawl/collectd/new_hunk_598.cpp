	return (NULL);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Functions for the actual parsing                                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * `cf_callback_mode'
 *   Chose the `operating_mode'
 *
 * Mode `value'
 */
int cf_callback_mode (const char *shortvar, const char *var,
		const char *arguments, const char *value, lc_flags_t flags,
