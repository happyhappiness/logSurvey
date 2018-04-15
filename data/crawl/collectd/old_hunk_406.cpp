		XSRETURN_EMPTY;
	}

	log_debug ("Collectd::plugin_log: level = %i, message = \"%s\"",
			SvIV (ST (0)), SvPV_nolen (ST (1)));
	plugin_log (SvIV (ST (0)), SvPV_nolen (ST (1)));
	XSRETURN_YES;
} /* static XS (Collectd_plugin_log) */
