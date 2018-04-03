#if COLLECT_DEBUG
  case IPMI_LOG_DEBUG_START:
  case IPMI_LOG_DEBUG:
    fprintf(stderr, "ipmi plugin: %s\n", msg);
    break;
  case IPMI_LOG_DEBUG_CONT:
  case IPMI_LOG_DEBUG_END:
    fprintf(stderr, "%s\n", msg);
    break;
#else
  case IPMI_LOG_DEBUG_START:
