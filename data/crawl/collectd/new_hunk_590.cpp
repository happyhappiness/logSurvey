static void cpu_init (void)
{
#ifdef PROCESSOR_CPU_LOAD_INFO
	kern_return_t status;

	port_host = mach_host_self ();

	if ((status = host_processors (port_host, &cpu_list, &cpu_list_len)) != KERN_SUCCESS)
	{
		syslog (LOG_ERR, "cpu-plugin: host_processors returned %i\n", (int) status);
		cpu_list_len = 0;
		return;
	}

	DBG ("host_processors returned %i %s", (int) cpu_list_len, cpu_list_len == 1 ? "processor" : "processors");
	syslog (LOG_INFO, "cpu-plugin: Found %i processor%s.", (int) cpu_list_len, cpu_list_len == 1 ? "" : "s");
/* #endif PROCESSOR_CPU_LOAD_INFO */

#elif defined(HAVE_LIBKSTAT)
