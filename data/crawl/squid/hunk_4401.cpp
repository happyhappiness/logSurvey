 	LIBC=gnulibc1
 	# endif
 	#else
-	#if defined(__INTEL_COMPILER) || defined(__PGI) || defined(__SUNPRO_C) || defined(__SUNPRO_CC)
+	#ifdef __INTEL_COMPILER
 	LIBC=gnu
 	#else
 	LIBC=gnuaout
 	#endif
 	#endif
-	#ifdef __dietlibc__
-	LIBC=dietlibc
-	#endif
 EOF
-	eval "`$CC_FOR_BUILD -E $dummy.c 2>/dev/null | sed -n '
-	    /^LIBC/{
-		s: ::g
-		p
-	    }'`"
-	test x"${LIBC}" != x && {
-		echo "${UNAME_MACHINE}-pc-linux-${LIBC}"
-		exit
-	}
-	test x"${TENTATIVE}" != x && { echo "${TENTATIVE}"; exit; }
+	eval `$CC_FOR_BUILD -E $dummy.c 2>/dev/null | grep ^LIBC=`
+	test x"${LIBC}" != x && echo "${UNAME_MACHINE}-pc-linux-${LIBC}" && exit 0
+	test x"${TENTATIVE}" != x && echo "${TENTATIVE}" && exit 0
 	;;
     i*86:DYNIX/ptx:4*:*)
 	# ptx 4.0 does uname -s correctly, with DYNIX/ptx in there.
 	# earlier versions are messed up and put the nodename in both
 	# sysname and nodename.
 	echo i386-sequent-sysv4
-	exit ;;
+	exit 0 ;;
     i*86:UNIX_SV:4.2MP:2.*)
         # Unixware is an offshoot of SVR4, but it has its own version
         # number series starting with 2...
         # I am not positive that other SVR4 systems won't match this,
 	# I just have to hope.  -- rms.
         # Use sysv4.2uw... so that sysv4* matches it.
 	echo ${UNAME_MACHINE}-pc-sysv4.2uw${UNAME_VERSION}
-	exit ;;
+	exit 0 ;;
     i*86:OS/2:*:*)
 	# If we were able to find `uname', then EMX Unix compatibility
 	# is probably installed.
 	echo ${UNAME_MACHINE}-pc-os2-emx
-	exit ;;
+	exit 0 ;;
     i*86:XTS-300:*:STOP)
 	echo ${UNAME_MACHINE}-unknown-stop
-	exit ;;
+	exit 0 ;;
     i*86:atheos:*:*)
 	echo ${UNAME_MACHINE}-unknown-atheos
-	exit ;;
-    i*86:syllable:*:*)
-	echo ${UNAME_MACHINE}-pc-syllable
-	exit ;;
+	exit 0 ;;
     i*86:LynxOS:2.*:* | i*86:LynxOS:3.[01]*:* | i*86:LynxOS:4.0*:*)
 	echo i386-unknown-lynxos${UNAME_RELEASE}
-	exit ;;
+	exit 0 ;;
     i*86:*DOS:*:*)
 	echo ${UNAME_MACHINE}-pc-msdosdjgpp
-	exit ;;
+	exit 0 ;;
     i*86:*:4.*:* | i*86:SYSTEM_V:4.*:*)
 	UNAME_REL=`echo ${UNAME_RELEASE} | sed 's/\/MP$//'`
 	if grep Novell /usr/include/link.h >/dev/null 2>/dev/null; then
 		echo ${UNAME_MACHINE}-univel-sysv${UNAME_REL}
 	else
 		echo ${UNAME_MACHINE}-pc-sysv${UNAME_REL}
 	fi
-	exit ;;
-    i*86:*:5:[678]*)
-    	# UnixWare 7.x, OpenUNIX and OpenServer 6.
+	exit 0 ;;
+    i*86:*:5:[78]*)
 	case `/bin/uname -X | grep "^Machine"` in
 	    *486*)	     UNAME_MACHINE=i486 ;;
 	    *Pentium)	     UNAME_MACHINE=i586 ;;
 	    *Pent*|*Celeron) UNAME_MACHINE=i686 ;;
 	esac
 	echo ${UNAME_MACHINE}-unknown-sysv${UNAME_RELEASE}${UNAME_SYSTEM}${UNAME_VERSION}
-	exit ;;
+	exit 0 ;;
     i*86:*:3.2:*)
 	if test -f /usr/options/cb.name; then
 		UNAME_REL=`sed -n 's/.*Version //p' </usr/options/cb.name`
