#if COLLECT_DEBUG
  case IPMI_LOG_DEBUG_START:
  case IPMI_LOG_DEBUG:
    DEBUG("ipmi plugin: %s", msg);
    break;
  case IPMI_LOG_DEBUG_CONT:
  case IPMI_LOG_DEBUG_END:
    DEBUG("%s", msg);
    break;
#else
  case IPMI_LOG_DEBUG_START:
