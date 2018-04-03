#include "utils_cmd_getval.h"

cmd_status_t cmd_parse_getval (size_t argc, char **argv,
    cmd_getval_t *ret_getval, cmd_error_handler_t *err)
{
  char *identifier_copy;
  int status;

  if (argc != 1)
  {
    if (argc == 0)
