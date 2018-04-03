    /* else: cmd_parse_option did not find an option; treat this as a
     * value list. */

    status = parse_values(argv[i], &vl, ds);
    if (status != 0) {
      cmd_error(CMD_PARSE_ERROR, err, "Parsing the values string failed.");
      result = CMD_PARSE_ERROR;
      break;
    }

    tmp = (value_list_t *)realloc(ret_putval->vl, (ret_putval->vl_num + 1) *
                                                      sizeof(*ret_putval->vl));
    if (tmp == NULL) {
      cmd_error(CMD_ERROR, err, "realloc failed.");
      cmd_destroy_putval(ret_putval);
      result = CMD_ERROR;
      break;
    }

    ret_putval->vl = tmp;
    ret_putval->vl_num++;
    memcpy(&ret_putval->vl[ret_putval->vl_num - 1], &vl, sizeof(vl));
  } /* while (*buffer != 0) */
  /* Done parsing the options. */

  if (result != CMD_OK) {
    if (ret_putval->vl_num == 0)
      sfree(vl.values);
    cmd_destroy_putval(ret_putval);
  }

  return (result);
} /* cmd_status_t cmd_parse_putval */
