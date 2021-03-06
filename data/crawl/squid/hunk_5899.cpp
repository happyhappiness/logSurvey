+/*
+ * (C) 2000 Francesco Chemolli <kinkie@kame.usr.dsi.unimi.it>,
+ *        inspired by previous work by Andy Doran
+ *
+ * Distributed freely under the terms of the GNU General Public License,
+ * version 2. See the file COPYING for licensing details
+ *
+ * This program is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ 
+ * You should have received a copy of the GNU General Public License
+ * along with this program; if not, write to the Free Software
+ * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
+ */
+
+#ifndef _NTLM_H_
+#define _NTLM_H_
+
+#include "config.h"
+#include "ntlmauth.h"
+
+/* for time_t */
+#if HAVE_TIME_H
+#include <time.h>
+#endif
+#if HAVE_SYS_TIME_H
+#include <sys/time.h>
+#endif
+
+/************* CONFIGURATION ***************/
+/*
+ * define this if you want debugging
+ */
+#define DEBUG
+
+/*
+ * Number of authentication attempts to perform in case of certain errors
+ */
+#define BAD_DC_RETRIES_NUMBER 3
+
+/************* END CONFIGURATION ***************/
+
+#include <sys/types.h>
+
+
+/* Debugging stuff */
+
+#ifdef __GNUC__			/* this is really a gcc-ism */
+#ifdef DEBUG
+#include <stdio.h>
+#include <unistd.h>
+static char *__foo;
+#define debug(X...) fprintf(stderr,"ntlm-auth[%d](%s:%d): ", getpid(), \
+                    ((__foo=strrchr(__FILE__,'/'))==NULL?__FILE__:__foo+1),\
+                    __LINE__);\
+                    fprintf(stderr,X)
+#else /* DEBUG */
+#define debug(X...)		/* */
+#endif /* DEBUG */
+#else /* __GNUC__ */
+#define debug(char *format, ...) {}	/* Too lazy to write va_args stuff */
+#endif
+
+
+/* A couple of harmless helper macros */
+#define SEND(X) debug("sending '%s' to squid\n",X); printf(X); printf("\n");
+#define SEND2(X,Y...) debug("sending '" X "' to squid\n",Y); printf(X,Y);\
+         printf("\n");
+
+extern int ntlm_errno;
+#define NTLM_NO_ERROR 0
+#define NTLM_SERVER_ERROR 1
+#define NTLM_PROTOCOL_ERROR 2
+#define NTLM_LOGON_ERROR 3
+#define NTLM_BAD_PROTOCOL -1
+#define NTLM_NOT_CONNECTED 10
+
+
+const char *make_challenge(char *domain, char *controller);
+extern char *ntlm_check_auth(ntlm_authenticate * auth, int auth_length);
+void dc_disconnect(void);
+int connectedp(void);
+int is_dc_ok(char *domain, char *domain_controller);
+
+/* flags used for dc status */
+#define DC_OK 0x0
+#define DC_DEAD 0x1
+
+typedef struct _dc dc;
+struct _dc {
+    char *domain;
+    char *controller;
+    unsigned char status;
+    dc *next;
+};
+
+
+#endif /* _NTLM_H_ */
