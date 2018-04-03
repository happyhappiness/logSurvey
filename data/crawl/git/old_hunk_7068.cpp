#include "parse-options.h"

static int boolean = 0;
static int integer = 0;
static char *string = NULL;

int main(int argc, const char **argv)
{
	const char *usage[] = {
