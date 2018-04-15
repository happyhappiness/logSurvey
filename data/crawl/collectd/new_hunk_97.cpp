  int ret = rte_eal_init(g_configuration->eal_argc, argp);
  if (ret < 0) {
    g_configuration->eal_initialized = 0;
    return ret;
  }
  return 0;
}

static int dpdk_helper_run (void)
{
  char errbuf[ERR_BUF_SIZE];
  pid_t ppid = getppid();
  g_configuration->helper_status = DPDK_HELPER_WAITING_ON_PRIMARY;

