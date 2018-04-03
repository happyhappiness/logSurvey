  return 0;
}

static void exit_usage (const char *name, int status) {
  fprintf ((status == 0) ? stdout : stderr, "Usage: %s [options]\n"
      "\n"
      "Valid options are:\n"
      "  -h, --help               Display this help message.\n"
