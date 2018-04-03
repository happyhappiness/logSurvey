}

/* Get and print status from apcupsd NIS server */
static int apc_query_server (char *host, int port,
		struct apc_detail_s *apcups_detail)
{
	int     n;
	char    recvline[1024];
	char   *tokptr;
	char   *key;
	double  value;

	static int sockfd   = -1;
	static unsigned int complain = 0;

#if APCMAIN
# define PRINT_VALUE(name, val) printf("  Found property: name = %s; value = %f;\n", name, val)
#else
# define PRINT_VALUE(name, val) /**/
#endif

	if (sockfd < 0)
	{
		if ((sockfd = net_open (host, NULL, port)) < 0)
		{
			/* Complain once every six hours. */
			int complain_step = 21600 / atoi (COLLECTD_STEP);

			if ((complain % complain_step) == 0)
				syslog (LOG_ERR, "apcups plugin: Connecting to the apcupsd failed.");
			complain++;

			return (-1);
		}
		else if (complain > 1)
		{
			syslog (LOG_NOTICE, "apcups plugin: Connection re-established to the apcupsd.");
			complain = 0;
		}
	}

	if (net_send (&sockfd, "status", 6) < 0)
	{
		syslog (LOG_ERR, "apcups plugin: Writing to the socket failed.");
		return (-1);
	}

	while ((n = net_recv (&sockfd, recvline, sizeof (recvline) - 1)) > 0)
	{
		assert (n < sizeof (recvline));
		recvline[n] = '\0';
#if APCMAIN
		printf ("net_recv = `%s';\n", recvline);
#endif /* if APCMAIN */

		tokptr = strtok (recvline, " :\t");
		while (tokptr != NULL)
		{
			key = tokptr;
			if ((tokptr = strtok (NULL, " :\t")) == NULL)
				continue;
			value = atof (tokptr);

			PRINT_VALUE (key, value);

			if (strcmp ("LINEV", key) == 0)
				apcups_detail->linev = value;
			else if (strcmp ("BATTV", key) == 0) 
				apcups_detail->battv = value;
			else if (strcmp ("ITEMP", key) == 0)
				apcups_detail->itemp = value;
			else if (strcmp ("LOADPCT", key) == 0)
				apcups_detail->loadpct = value;
			else if (strcmp ("BCHARGE", key) == 0)
				apcups_detail->bcharge = value;
			else if (strcmp ("OUTPUTV", key) == 0)
				apcups_detail->outputv = value;
			else if (strcmp ("LINEFREQ", key) == 0)
				apcups_detail->linefreq = value;
			else if (strcmp ("TIMELEFT", key) == 0)
				apcups_detail->timeleft = value;

			tokptr = strtok (NULL, ":");
		} /* while (tokptr != NULL) */
	}
	
	if (n < 0)
	{
		syslog (LOG_WARNING, "apcups plugin: Error reading from socket");
		return (-1);
	}
#if APCMAIN
	else
	{
		/* close the opened socket */
		net_close (&sockfd);
	}
#endif /* APCMAIN */

	return (0);
}

#if APCMAIN
/*
 * This is used for testing apcups in a standalone mode.
 * Usefull for debugging.
 */
int main (int argc, char **argv)
{
	/* we are not really going to use this */
	struct apc_detail_s apcups_detail;

	openlog ("apcups", LOG_PID | LOG_NDELAY | LOG_LOCAL1, LOG_USER);

	if (global_host == NULL || strcmp (global_host, "0.0.0.0") == 0)
		global_host = "localhost";

	if(apc_query_server (global_host, global_port, &apcups_detail) < 0)
	{
		printf("apcups: Failed...\n");
		return(-1);
	}

	return 0;
}
#else
static int apcups_config (char *key, char *value)
{
	if (strcasecmp (key, "host") == 0)
	{
		if (global_host != NULL)
		{
			free (global_host);
			global_host = NULL;
		}
		if ((global_host = strdup (value)) == NULL)
			return (1);
	}
	else if (strcasecmp (key, "Port") == 0)
	{
		int port_tmp = atoi (value);
		if (port_tmp < 1 || port_tmp > 65535)
		{
			syslog (LOG_WARNING, "apcups plugin: Invalid port: %i", port_tmp);
			return (1);
		}
		global_port = port_tmp;
	}
	else
	{
		return (-1);
	}
	return (0);
}

static void apcups_init (void)
{
	return;
}

static void apc_write_voltage (char *host, char *inst, char *val)
{
	char file[512];
	int  status;

	status = snprintf (file, 512, bvolt_file_template, inst);
	if ((status < 1) || (status >= 512))
		return;

	rrd_update_file (host, file, val, bvolt_ds_def, bvolt_ds_num);
}

static void apc_write_charge (char *host, char *inst, char *val)
{
	rrd_update_file (host, charge_file_template, val, charge_ds_def, charge_ds_num);
}

static void apc_write_percent (char *host, char *inst, char *val)
{
	rrd_update_file (host, load_file_template, val, load_ds_def, load_ds_num);
}

static void apc_write_timeleft (char *host, char *inst, char *val)
{
	rrd_update_file (host, time_file_template, val, time_ds_def, time_ds_num);
}

static void apc_write_temperature (char *host, char *inst, char *val)
{
	rrd_update_file (host, temp_file_template, val, temp_ds_def, temp_ds_num);
}

static void apc_write_frequency (char *host, char *inst, char *val)
{
	char file[512];
	int  status;

	status = snprintf (file, 512, freq_file_template, inst);
	if ((status < 1) || (status >= 512))
		return;

	rrd_update_file (host, file, val, freq_ds_def, freq_ds_num);
}

static void apc_submit_generic (char *type, char *inst,
		double value)
{
	char buf[512];
	int  status;

	status = snprintf (buf, 512, "%u:%f",
			(unsigned int) curtime, value);
	if ((status < 1) || (status >= 512))
		return;

	DBG ("plugin_submit (%s, %s, %s);", type, inst, buf);
	plugin_submit (type, inst, buf);
}

static void apc_submit (struct apc_detail_s *apcups_detail)
{
	apc_submit_generic ("apcups_voltage",    "input",   apcups_detail->linev);
	apc_submit_generic ("apcups_voltage",    "output",  apcups_detail->outputv);
	apc_submit_generic ("apcups_voltage",    "battery", apcups_detail->battv);
	apc_submit_generic ("apcups_charge",     "-",       apcups_detail->bcharge);
	apc_submit_generic ("apcups_charge_pct", "-",       apcups_detail->loadpct);
	apc_submit_generic ("apcups_timeleft",   "-",       apcups_detail->timeleft);
	apc_submit_generic ("apcups_temp",       "-",       apcups_detail->itemp);
	apc_submit_generic ("apcups_frequency",  "input",   apcups_detail->linefreq);
}

static void apcups_read (void)
{
	struct apc_detail_s apcups_detail;
	int status;

	apcups_detail.linev    =   -1.0;
	apcups_detail.outputv  =   -1.0;
	apcups_detail.battv    =   -1.0;
	apcups_detail.loadpct  =   -1.0;
	apcups_detail.bcharge  =   -1.0;
	apcups_detail.timeleft =   -1.0;
	apcups_detail.itemp    = -300.0;
	apcups_detail.linefreq =   -1.0;
  
	status = apc_query_server (global_host == NULL
			? APCUPS_DEFAULT_HOST
			: global_host,
			global_port, &apcups_detail);
 
	/*
	 * if we did not connect then do not bother submitting
	 * zeros. We want rrd files to have NAN.
	 */
	if (status != 0)
	{
		DBG ("apc_query_server (%s, %i) = %i",
				global_host == NULL
				? APCUPS_DEFAULT_HOST
				: global_host,
				global_port, status);
		return;
	}

	apc_submit (&apcups_detail);
} /* apcups_read */

void module_register (void)
{
	plugin_register (MODULE_NAME, apcups_init, apcups_read, NULL);
	plugin_register ("apcups_voltage",    NULL, NULL, apc_write_voltage);
	plugin_register ("apcups_charge",     NULL, NULL, apc_write_charge);
	plugin_register ("apcups_charge_pct", NULL, NULL, apc_write_percent);
	plugin_register ("apcups_timeleft",   NULL, NULL, apc_write_timeleft);
	plugin_register ("apcups_temp",       NULL, NULL, apc_write_temperature);
	plugin_register ("apcups_frequency",  NULL, NULL, apc_write_frequency);
	cf_register (MODULE_NAME, apcups_config, config_keys, config_keys_num);
}

#endif /* if APCMAIN */
#undef MODULE_NAME
