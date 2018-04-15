
static void cpu_init (void)
{
#ifdef PROCESSOR_CPU_LOAD_INFO
	port_host = mach_host_self ();

	if ((status = host_processors (port_host, &cpu_list, &cpu_list_len)) != KERN_SUCCESS)
	{
		fprintf (stderr, "host_processors returned %i\n", (int) status);
		cpu_list_len = 0;
		return (-1);
	}

	DBG ("host_processors returned %i %s", (int) list_len, list_len == 1 ? "processor" : "processors");
	syslog (LOG_INFO, "Plugin `cpu' found %i processor%s.", (int) cpu_list_len, cpu_list_len == 1 ? "" : "s");
/* #endif PROCESSOR_CPU_LOAD_INFO */

#elif defined(HAVE_LIBKSTAT)
	kstat_t *ksp_chain;

	numcpu = 0;
