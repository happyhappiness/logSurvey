#
# Do some checking before 'git push'.

CORES=`grep -c ^processor /proc/cpuinfo 2>/dev/null || echo 0`
if [ $CORES -lt 1 ]; then CORES=1; fi

make -f Makefile distclean 2>/dev/null

# automatically exit on error
set -e

CFLAGS="-std=c89 -pedantic -O2 -g -Wall -Wextra -Wstrict-prototypes -Wold-style-definition -Wwrite-strings -Wshadow -Wformat -Wformat-security -Wunreachable-code -Wstrict-prototypes -Wmissing-prototypes -Wold-style-definition"

