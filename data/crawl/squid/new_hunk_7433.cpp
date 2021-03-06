
/*
 * $Id: useragent.cc,v 1.1 1996/11/08 00:02:25 wessels Exp $
 *
 * DEBUG: section 40    User-Agent logging
 * AUTHOR: Joe Ramey <ramey@csc.ti.com>
 *
 * SQUID Internet Object Cache  http://squid.nlanr.net/Squid/
 * --------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from the
 *  Internet community.  Development is led by Duane Wessels of the
 *  National Laboratory for Applied Network Research and funded by
 *  the National Science Foundation.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *  
 */

#include "squid.h"

FILE *cache_useragent_log = NULL;

void
useragentOpenLog(void)
{
#if USE_USERAGENT_LOG
    char *fname = NULL;
    int log_fd = -1;
    fname = Config.Log.useragent;
    /* Close and reopen the log.  It may have been renamed "manually"
     * before HUP'ing us. */
    if (cache_useragent_log) {
	file_close(fileno(cache_useragent_log));
	fclose(cache_useragent_log);
	cache_useragent_log = NULL;
    }
    if (fname && strcmp(fname, "none") != 0) {
	log_fd = file_open(fname, NULL, O_WRONLY | O_CREAT | O_APPEND);
	if (log_fd < 0) {
	    debug(40, 0, "useragentOpenLog: %s: %s\n", fname, xstrerror());
	} else if ((cache_useragent_log = fdopen(log_fd, "a")) == NULL) {
	    file_close(log_fd);
	    debug(40, 0, "useragentOpenLog: %s: %s\n", fname, xstrerror());
	}
    }
    if (log_fd < 0 || cache_useragent_log == NULL)
	debug(40, 1, "User-Agent logging is disabled.\n");
#endif
}

void
useragentRotateLog(void)
{
#if USE_USERAGENT_LOG
    char *fname = NULL;
    int i;
    LOCAL_ARRAY(char, from, MAXPATHLEN);
    LOCAL_ARRAY(char, to, MAXPATHLEN);
    if ((fname = Config.Log.useragent) == NULL)
	return;
    if (strcmp(fname, "none") == 0)
	return;
    debug(40, 1, "useragentRotateLog: Rotating.\n");
    /* Rotate numbers 0 through N up one */
    for (i = Config.Log.rotateNumber; i > 1;) {
	i--;
	sprintf(from, "%s.%d", fname, i - 1);
	sprintf(to, "%s.%d", fname, i);
	rename(from, to);
    }
    /* Rotate the current log to .0 */
    if (Config.Log.rotateNumber > 0) {
	sprintf(to, "%s.%d", fname, 0);
	rename(fname, to);
    }
    useragentOpenLog();
#endif
}

void
logUserAgent(const char *client, const char *agent)
{
#if USE_USERAGENT_LOG
    static time_t last_time = 0;
    static char time_str[128];
    const char *s;
    if (!cache_useragent_log)
	return;
    if (squid_curtime != last_time) {
	s = mkhttpdlogtime(&squid_curtime);
	strcpy(time_str, s);
	last_time = squid_curtime;
    }
    fprintf(cache_useragent_log, "%s [%s] \"%s\"\n",
	client,
	time_str,
	agent);
    if (unbuffered_logs)
	fflush(cache_useragent_log);
#endif
}