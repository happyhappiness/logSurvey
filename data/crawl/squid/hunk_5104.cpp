         # Use sysv4.2uw... so that sysv4* matches it.
 	echo ${UNAME_MACHINE}-pc-sysv4.2uw${UNAME_VERSION}
 	exit 0 ;;
+    i*86:OS/2:*:*)
+	# If we were able to find `uname', then EMX Unix compatibility
+	# is probably installed.
+	echo ${UNAME_MACHINE}-pc-os2-emx
+	exit 0 ;;
+    i*86:XTS-300:*:STOP)
+	echo ${UNAME_MACHINE}-unknown-stop
+	exit 0 ;;
+    i*86:atheos:*:*)
+	echo ${UNAME_MACHINE}-unknown-atheos
+	exit 0 ;;
+	i*86:syllable:*:*)
+	echo ${UNAME_MACHINE}-pc-syllable
+	exit 0 ;;
+    i*86:LynxOS:2.*:* | i*86:LynxOS:3.[01]*:* | i*86:LynxOS:4.0*:*)
+	echo i386-unknown-lynxos${UNAME_RELEASE}
+	exit 0 ;;
+    i*86:*DOS:*:*)
+	echo ${UNAME_MACHINE}-pc-msdosdjgpp
+	exit 0 ;;
     i*86:*:4.*:* | i*86:SYSTEM_V:4.*:*)
 	UNAME_REL=`echo ${UNAME_RELEASE} | sed 's/\/MP$//'`
 	if grep Novell /usr/include/link.h >/dev/null 2>/dev/null; then
