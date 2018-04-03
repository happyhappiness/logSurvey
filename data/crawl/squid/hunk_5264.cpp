 
 /*
- * $Id: win32.cc,v 1.7 2003/02/21 22:50:13 robertc Exp $
+ * $Id: win32.cc,v 1.8 2003/04/21 12:54:10 hno Exp $
  *
  * * * * * * * * Legal stuff * * * * * * *
  *
  * (C) 2001 Guido Serassio <serassio@libero.it>,
  *   inspired by previous work by Romeo Anghelache & Eric Stern.
- * This program is free software; you can redistribute it and/or modify
- * it under the terms of the GNU General Public License as published by
- * the Free Software Foundation; either version 2 of the License, or
- * (at your option) any later version.
+ *
+ * SQUID Web Proxy Cache          http://www.squid-cache.org/
+ * ----------------------------------------------------------
+ *
+ *  Squid is the result of efforts by numerous individuals from
+ *  the Internet community; see the CONTRIBUTORS file for full
+ *  details.   Many organizations have provided support for Squid's
+ *  development; see the SPONSORS file for full details.  Squid is
+ *  Copyrighted (C) 2001 by the Regents of the University of
+ *  California; see the COPYRIGHT file for full details.  Squid
+ *  incorporates software developed and/or copyrighted by other
+ *  sources; see the CREDITS file for full details.
+ *
+ *  This program is free software; you can redistribute it and/or modify
+ *  it under the terms of the GNU General Public License as published by
+ *  the Free Software Foundation; either version 2 of the License, or
+ *  (at your option) any later version.
  *  
- * This program is distributed in the hope that it will be useful,
- * but WITHOUT ANY WARRANTY; without even the implied warranty of
- * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
- * GNU General Public License for more details.
- * 
- * You should have received a copy of the GNU General Public License
- * along with this program; if not, write to the Free Software
- * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
+ *  This program is distributed in the hope that it will be useful,
+ *  but WITHOUT ANY WARRANTY; without even the implied warranty of
+ *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ *  GNU General Public License for more details.
+ *
+ *  You should have received a copy of the GNU General Public License
+ *  along with this program; if not, write to the Free Software
+ *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
  *
  */
 
+#ifndef WIN32_C
+#define WIN32_C
+
 #include "squid.h"
 
-/* This code compiles only CygWin & Windows NT Port */
+/* This code compiles only on Cygwin & Windows NT Port */
 #if defined(_SQUID_MSWIN_) || defined(_SQUID_CYGWIN_)
-#include <windows.h>
+#include "squid_windows.h"
 
 static unsigned int GetOSVersion();
+void WIN32_svcstatusupdate(DWORD, DWORD);
+void WINAPI WIN32_svcHandler(DWORD);
+#ifdef USE_WIN32_SERVICE
+static int WIN32_StoreKey(const char *, DWORD, unsigned char *, int);
+static int WIN32_create_key(void);
+static void WIN32_build_argv (char *);
+#endif
+extern "C" void WINAPI SquidMain(DWORD, char **);
+
+#ifdef USE_WIN32_SERVICE
+static SERVICE_STATUS svcStatus;
+static SERVICE_STATUS_HANDLE svcHandle;
+static int WIN32_argc;
+static char ** WIN32_argv;
+static char * WIN32_module_name;
+#endif
+static int Squid_Aborting = 0;
+
+#define VENDOR "GNU"
+static char VENDORString[] = VENDOR;
+#define SOFTWARENAME "Squid"
+static char SOFTWARENAMEString[] = SOFTWARENAME;
+#define WIN32_VERSION "3.0"
+static char WIN32_VERSIONString[] = WIN32_VERSION;
+#define SOFTWARE "SOFTWARE"
+static char SOFTWAREString[] = SOFTWARE;
+#define COMMANDLINE "CommandLine"
+#define CONFIGFILE  "ConfigFile"
+#undef ChangeServiceConfig2
+typedef BOOL (WINAPI * PFChangeServiceConfig2) (SC_HANDLE, DWORD, LPVOID);
+#ifdef UNICODE
+#define CHANGESERVICECONFIG2 "ChangeServiceConfig2W"
+#else
+#define CHANGESERVICECONFIG2 "ChangeServiceConfig2A"
+#endif
+#ifdef USE_WIN32_SERVICE
+static SC_ACTION Squid_SCAction[] = { { SC_ACTION_RESTART, 60000 } };
+static char Squid_ServiceDescriptionString[] = SOFTWARENAME " " VERSION " WWW Proxy Server";
+static SERVICE_DESCRIPTION Squid_ServiceDescription = { Squid_ServiceDescriptionString };
+static SERVICE_FAILURE_ACTIONS Squid_ServiceFailureActions = { INFINITE, NULL, NULL, 1, Squid_SCAction };
+static char REGKEY[256]=SOFTWARE"\\"VENDOR"\\"SOFTWARENAME"\\"WIN32_VERSION"\\";
+static char *keys[] = {
+                          SOFTWAREString,	    /* key[0] */
+                          VENDORString,	    /* key[1] */
+                          SOFTWARENAMEString,   /* key[2] */
+                          WIN32_VERSIONString,  /* key[3] */
+                          NULL,	    /* key[4] */
+                          NULL	    /* key[5] */
+                      };
+#endif
 
 /* ====================================================================== */
 /* LOCAL FUNCTIONS */
 /* ====================================================================== */
 
+#ifdef USE_WIN32_SERVICE
+static int
+WIN32_create_key(void)
+{
+    int index;
+    HKEY hKey;
+    HKEY hKeyNext;
+    int retval;
+    LONG rv;
+
+    hKey = HKEY_LOCAL_MACHINE;
+    index = 0;
+    retval = 0;
+
+    /* Walk the tree, creating at each stage if necessary */
+
+    while (keys[index]) {
+        unsigned long result;
+        rv = RegCreateKeyEx(hKey, keys[index],	/* subkey */
+                            0,			/* reserved */
+                            NULL,		/* class */
+                            REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKeyNext, &result);
+
+        if (rv != ERROR_SUCCESS) {
+            fprintf(stderr, "RegCreateKeyEx(%s),%d\n", keys[index], (int) rv);
+            retval = -4;
+        }
+
+        /* Close the old key */
+        rv = RegCloseKey(hKey);
+
+        if (rv != ERROR_SUCCESS) {
+            fprintf(stderr, "RegCloseKey %d\n", (int) rv);
+
+            if (retval == 0) {
+                /* Keep error status from RegCreateKeyEx, if any */
+                retval = -4;
+            }
+        }
+
+        if (retval) {
+            break;
+        }
+
+        hKey = hKeyNext;
+        index++;
+    }
+
+    if (keys[index] == NULL) {
+        /* Close the final key we opened, if we walked the entire
+         * tree
+         */
+        rv = RegCloseKey(hKey);
+
+        if (rv != ERROR_SUCCESS) {
+            fprintf(stderr, "RegCloseKey %d\n", (int) rv);
+
+            if (retval == 0) {
+                /* Keep error status from RegCreateKeyEx, if any */
+                retval = -4;
+            }
+        }
+    }
+
+    return retval;
+}
+
+static int
+WIN32_StoreKey(const char *key, DWORD type, unsigned char *value,
+               int value_size)
+{
+    LONG rv;
+    HKEY hKey;
+    int retval;
+
+    rv = RegOpenKeyEx(HKEY_LOCAL_MACHINE, REGKEY, 0, KEY_WRITE, &hKey);
+
+    if (rv == ERROR_FILE_NOT_FOUND) {
+        /* Key could not be opened -- try to create it
+         */
+
+        if (WIN32_create_key() < 0) {
+            /* Creation failed (error already reported) */
+            return -4;
+        }
+
+        /* Now it has been created we should be able to open it
+         */
+        rv = RegOpenKeyEx(HKEY_LOCAL_MACHINE, REGKEY, 0, KEY_WRITE, &hKey);
+
+        if (rv == ERROR_FILE_NOT_FOUND) {
+            fprintf(stderr, "Registry does not contain key %s after creation\n",
+                    REGKEY);
+            return -1;
+        }
+    }
+
+    if (rv != ERROR_SUCCESS) {
+        fprintf(stderr, "RegOpenKeyEx HKLM\\%s, %d\n", REGKEY, (int) rv);
+        return -4;
+    }
+
+    /* Now set the value and data */
+    rv = RegSetValueEx(hKey, key,	/* value key name */
+                       0,			/* reserved */
+                       type,			/* type */
+                       value,			/* value data */
+                       (DWORD) value_size);	/* for size of "value" */
+
+    retval = 0;			/* Return value */
+
+    if (rv != ERROR_SUCCESS) {
+        fprintf(stderr, "RegQueryValueEx(key %s),%d\n", key, (int) rv);
+        retval = -4;
+    } else {
+        fprintf(stderr, "Registry stored HKLM\\%s\\%s value %s\n",
+                REGKEY,
+                key,
+                type == REG_SZ ? value : (unsigned char *) "(not displayable)");
+    }
+
+    /* Make sure we close the key even if there was an error storing
+     * the data
+     */
+    rv = RegCloseKey(hKey);
+
+    if (rv != ERROR_SUCCESS) {
+        fprintf(stderr, "RegCloseKey HKLM\\%s, %d\n", REGKEY, (int) rv);
+
+        if (retval == 0) {
+            /* Keep error status from RegQueryValueEx, if any */
+            retval = -4;
+        }
+    }
+
+    return retval;
+}
+
+#endif
+
 static unsigned int
 GetOSVersion()
 {
