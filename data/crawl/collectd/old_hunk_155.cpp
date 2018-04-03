  int ret = rte_eal_init(g_configuration->eal_argc, argp);
  if (ret < 0) {
    g_configuration->eal_initialized = 0;
    printf("dpdkstat: ERROR initializing EAL ret = %d\n", ret);
    printf("dpdkstat: EAL arguments: ");
    for (i = 0; i < g_configuration->eal_argc; i++) {
      printf("%s ", argp[i]);
    }
    printf("\n");
    return ret;
  }
  return 0;
}

static int dpdk_helper_run (void)
{
  pid_t ppid = getppid();
  g_configuration->helper_status = DPDK_HELPER_WAITING_ON_PRIMARY;

