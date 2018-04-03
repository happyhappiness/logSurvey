#include "parse-options.h"
#include "dir.h"
#include "run-command.h"

/**
 * Like strbuf_getline(), but treats both '\n' and "\r\n" as line terminators.
