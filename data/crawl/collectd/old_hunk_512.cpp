
			if (strcmp ("LINEV", key) == 0)
				apcups_detail->linev = value;
			else if (strcmp ("BATTV", tokptr) == 0)
				apcups_detail->battv = value;
			else if (strcmp ("ITEMP", tokptr) == 0)
				apcups_detail->itemp = value;
			else if (strcmp ("LOADPCT", tokptr) == 0)
				apcups_detail->loadpct = value;
			else if (strcmp ("BCHARGE", tokptr) == 0)
				apcups_detail->bcharge = value;
			else if (strcmp ("OUTPUTV", tokptr) == 0)
				apcups_detail->outputv = value;
			else if (strcmp ("LINEFREQ", tokptr) == 0)
				apcups_detail->linefreq = value;
			else if (strcmp ("TIMELEFT", tokptr) == 0)
				apcups_detail->timeleft = value;
			else
			{
				syslog (LOG_WARNING, "apcups plugin: Received unknown property from apcupsd: `%s' = %f",
						key, value);
			}

			tokptr = strtok (NULL, ":");
		} /* while (tokptr != NULL) */
	}

	net_close (sockfd);

	if (n < 0)
	{
		syslog (LOG_WARNING, "apcups plugin: Error reading from socket");
		return (-1);
	}

	return (0);
}

#ifdef APCMAIN
int main(int argc, char **argv)
{
	/* we are not really going to use this */
	struct apc_detail_s apcups_detail;

	if (!*host || strcmp(host, "0.0.0.0") == 0)
		host = "localhost";

	do_pthreads_status(host, port, &apcups_detail);

	return 0;
}
#else
static void apcups_init (void)
{
	return;
}

static int apcups_config (char *key, char *value)
{
  static char lhost[126];
  
  if (strcasecmp (key, "host") == 0)
    {
      lhost[0] = '\0';
      strcpy(lhost,key);
      host = lhost;
    }
  else if (strcasecmp (key, "Port") == 0)
    {
      int port_tmp = atoi (value);
      if(port_tmp < 1 || port_tmp > 65535) {
	syslog (LOG_WARNING, "apcups: `port' failed: %s",
		value);
	return (1);
      } else {
	port = port_tmp;
      }
    }
  else
    {
      return (-1);
    }
  return(0);
}

#define BUFSIZE 256
static void apcups_submit (char *host,
			   struct apc_detail_s *apcups_detail)
{
	char buf[BUFSIZE];

	if (snprintf (buf, BUFSIZE, "%u:%f:%f",
		      (unsigned int) curtime,
		      apcups_detail->linev,
		      apcups_detail->outputv) >= BUFSIZE)
	  return;
	
	plugin_submit (MODULE_NAME, host, buf);
}

static void apc_bvolt_submit (char *host,
			   struct apc_detail_s *apcups_detail)
{
	char buf[BUFSIZE];

	if (snprintf (buf, BUFSIZE, "%u:%f",
		      (unsigned int) curtime,
		      apcups_detail->battv) >= BUFSIZE)
	  return;
	
	plugin_submit ("apcups_bvolt", host, buf);
}

static void apc_load_submit (char *host,
			   struct apc_detail_s *apcups_detail)
{
	char buf[BUFSIZE];

	if (snprintf (buf, BUFSIZE, "%u:%f",
		      (unsigned int) curtime,
		      apcups_detail->loadpct) >= BUFSIZE)
	  return;
	
	plugin_submit ("apcups_load", host, buf);
}

static void apc_charge_submit (char *host,
			   struct apc_detail_s *apcups_detail)
{
	char buf[BUFSIZE];

	if (snprintf (buf, BUFSIZE, "%u:%f",
		      (unsigned int) curtime,
		      apcups_detail->bcharge) >= BUFSIZE)
	  return;
	
	plugin_submit ("apcups_charge", host, buf);
}

static void apc_temp_submit (char *host,
			   struct apc_detail_s *apcups_detail)
{
	char buf[BUFSIZE];

	if (snprintf (buf, BUFSIZE, "%u:%f",
		      (unsigned int) curtime,
		      apcups_detail->itemp) >= BUFSIZE)
	  return;
	
	plugin_submit ("apcups_temp", host, buf);
}

static void apc_time_submit (char *host,
			   struct apc_detail_s *apcups_detail)
{
	char buf[BUFSIZE];

	if (snprintf (buf, BUFSIZE, "%u:%f",
		      (unsigned int) curtime,
		      apcups_detail->timeleft) >= BUFSIZE)
	  return;
	
	plugin_submit ("apcups_time", host, buf);
}

static void apc_freq_submit (char *host,
			   struct apc_detail_s *apcups_detail)
{
	char buf[BUFSIZE];

	if (snprintf (buf, BUFSIZE, "%u:%f",
		      (unsigned int) curtime,
		      apcups_detail->linefreq) >= BUFSIZE)
	  return;
	
	plugin_submit ("apcups_freq", host, buf);
}
#undef BUFSIZE

static void apcups_read (void)
{
  struct apc_detail_s apcups_detail;
	
  apcups_detail.linev = 0.0;
  apcups_detail.loadpct = 0.0;
  apcups_detail.bcharge = 0.0;
  apcups_detail.timeleft = 0.0;
  apcups_detail.outputv = 0.0;
  apcups_detail.itemp = 0.0;
  apcups_detail.battv = 0.0;
  apcups_detail.linefreq = 0.0;

  
  if (!*host || strcmp(host, "0.0.0.0") == 0)
    host = "localhost";
  
  do_pthreads_status(host, port, &apcups_detail);
 
  apcups_submit (host, &apcups_detail);
  apc_bvolt_submit (host, &apcups_detail);
  apc_load_submit (host, &apcups_detail);
  apc_charge_submit (host, &apcups_detail);
  apc_temp_submit (host, &apcups_detail);
  apc_time_submit (host, &apcups_detail);
  apc_freq_submit (host, &apcups_detail);
}


static void apcups_write (char *host, char *inst, char *val)
{
  char file[512];
  int status;
  
  status = snprintf (file, 512, volt_file_template, inst);
  if (status < 1)
    return;
  else if (status >= 512)
    return;
  
  rrd_update_file (host, file, val, volt_ds_def, volt_ds_num);
}

static void apc_bvolt_write (char *host, char *inst, char *val)
{
  char file[512];
  int status;
  
  status = snprintf (file, 512, bvolt_file_template, inst);
  if (status < 1)
    return;
  else if (status >= 512)
    return;
  
  rrd_update_file (host, file, val, bvolt_ds_def, bvolt_ds_num);
}

static void apc_load_write (char *host, char *inst, char *val)
{
  char file[512];
  int status;
  
  status = snprintf (file, 512, load_file_template, inst);
  if (status < 1)
    return;
  else if (status >= 512)
    return;
  
  rrd_update_file (host, file, val, load_ds_def, load_ds_num);
}

static void apc_charge_write (char *host, char *inst, char *val)
{
  char file[512];
  int status;
  
  status = snprintf (file, 512, charge_file_template, inst);
  if (status < 1)
    return;
  else if (status >= 512)
    return;
  
  rrd_update_file (host, file, val, charge_ds_def, charge_ds_num);
}

static void apc_temp_write (char *host, char *inst, char *val)
{
  char file[512];
  int status;
  
  status = snprintf (file, 512, temp_file_template, inst);
  if (status < 1)
    return;
  else if (status >= 512)
    return;
  
  rrd_update_file (host, file, val, temp_ds_def, temp_ds_num);
}

static void apc_time_write (char *host, char *inst, char *val)
{
  char file[512];
  int status;
  
  status = snprintf (file, 512, time_file_template, inst);
  if (status < 1)
    return;
  else if (status >= 512)
    return;
  
  rrd_update_file (host, file, val, time_ds_def, time_ds_num);
}

static void apc_freq_write (char *host, char *inst, char *val)
{
  char file[512];
  int status;
  
  status = snprintf (file, 512, freq_file_template, inst);
  if (status < 1)
    return;
  else if (status >= 512)
    return;
  
  rrd_update_file (host, file, val, freq_ds_def, freq_ds_num);
}

void module_register (void)
{
	plugin_register (MODULE_NAME, apcups_init, apcups_read, apcups_write);
	plugin_register ("apcups_bvolt", NULL, NULL, apc_bvolt_write);
	plugin_register ("apcups_load", NULL, NULL, apc_load_write);
	plugin_register ("apcups_charge", NULL, NULL, apc_charge_write);
	plugin_register ("apcups_temp", NULL, NULL, apc_temp_write);
	plugin_register ("apcups_time", NULL, NULL, apc_time_write);
	plugin_register ("apcups_freq", NULL, NULL, apc_freq_write);
	cf_register (MODULE_NAME, apcups_config, config_keys, config_keys_num);
}

#endif /* ifdef APCMAIN */
#undef MODULE_NAME