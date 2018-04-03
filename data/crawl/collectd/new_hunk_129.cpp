#include "utils_cmd_getval.h"

cmd_status_t cmd_parse_getval (size_t argc, char **argv,
    cmd_getval_t *ret_getval, const cmd_options_t *opts,
    cmd_error_handler_t *err)
{
  char *identifier_copy;
  int status;

  if ((ret_getval == NULL) || (opts == NULL))
  {
    errno = EINVAL;
    cmd_error (CMD_ERROR, err, "Invalid arguments to cmd_parse_getval.");
    return (CMD_ERROR);
  }

  if (argc != 1)
  {
    if (argc == 0)
