      case RULES:       reason_str = "RULES";       break;
      case SPANNEDHOST: reason_str = "SPANNEDHOST"; break;
      case ROBOTS:      reason_str = "ROBOTS";      break;
    }

  fprintf (f, "%s\t", reason_str);
  write_reject_log_url (f, url);
  fprintf (f, "\t");
  write_reject_log_url (f, parent);
  fprintf (f, "\n");
}

/* vim:set sts=2 sw=2 cino+={s: */
