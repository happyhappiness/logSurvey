  type = NULL;
  type_instance = NULL;

  ret_putval->raw_identifier = identifier_copy;
  if (ret_putval->raw_identifier == NULL) {
    cmd_error(CMD_ERROR, err, "malloc failed.");
