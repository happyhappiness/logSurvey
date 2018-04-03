     mvmeppc:OpenBSD:*:*)
 	echo powerpc-unknown-openbsd${UNAME_RELEASE}
 	exit 0 ;;
-    pmax:OpenBSD:*:*)
-	echo mipsel-unknown-openbsd${UNAME_RELEASE}
-	exit 0 ;;
     sgi:OpenBSD:*:*)
-	echo mipseb-unknown-openbsd${UNAME_RELEASE}
+	echo mips64-unknown-openbsd${UNAME_RELEASE}
 	exit 0 ;;
     sun3:OpenBSD:*:*)
 	echo m68k-unknown-openbsd${UNAME_RELEASE}
 	exit 0 ;;
-    wgrisc:OpenBSD:*:*)
-	echo mipsel-unknown-openbsd${UNAME_RELEASE}
-	exit 0 ;;
     *:OpenBSD:*:*)
 	echo ${UNAME_MACHINE}-unknown-openbsd${UNAME_RELEASE}
 	exit 0 ;;
+    *:ekkoBSD:*:*)
+	echo ${UNAME_MACHINE}-unknown-ekkobsd${UNAME_RELEASE}
+	exit 0 ;;
+    macppc:MirBSD:*:*)
+	echo powerppc-unknown-mirbsd${UNAME_RELEASE}
+	exit 0 ;;
+    *:MirBSD:*:*)
+	echo ${UNAME_MACHINE}-unknown-mirbsd${UNAME_RELEASE}
+	exit 0 ;;
     alpha:OSF1:*:*)
-	if test $UNAME_RELEASE = "V4.0"; then
+	case $UNAME_RELEASE in
+	*4.0)
 		UNAME_RELEASE=`/usr/sbin/sizer -v | awk '{print $3}'`
-	fi
+		;;
+	*5.*)
+	        UNAME_RELEASE=`/usr/sbin/sizer -v | awk '{print $4}'`
+		;;
+	esac
+	# According to Compaq, /usr/sbin/psrinfo has been available on
+	# OSF/1 and Tru64 systems produced since 1995.  I hope that
+	# covers most systems running today.  This code pipes the CPU
+	# types through head -n 1, so we only detect the type of CPU 0.
+	ALPHA_CPU_TYPE=`/usr/sbin/psrinfo -v | sed -n -e 's/^  The alpha \(.*\) processor.*$/\1/p' | head -n 1`
+	case "$ALPHA_CPU_TYPE" in
+	    "EV4 (21064)")
+		UNAME_MACHINE="alpha" ;;
+	    "EV4.5 (21064)")
+		UNAME_MACHINE="alpha" ;;
+	    "LCA4 (21066/21068)")
+		UNAME_MACHINE="alpha" ;;
+	    "EV5 (21164)")
+		UNAME_MACHINE="alphaev5" ;;
+	    "EV5.6 (21164A)")
+		UNAME_MACHINE="alphaev56" ;;
+	    "EV5.6 (21164PC)")
+		UNAME_MACHINE="alphapca56" ;;
+	    "EV5.7 (21164PC)")
+		UNAME_MACHINE="alphapca57" ;;
+	    "EV6 (21264)")
+		UNAME_MACHINE="alphaev6" ;;
+	    "EV6.7 (21264A)")
+		UNAME_MACHINE="alphaev67" ;;
+	    "EV6.8CB (21264C)")
+		UNAME_MACHINE="alphaev68" ;;
+	    "EV6.8AL (21264B)")
+		UNAME_MACHINE="alphaev68" ;;
+	    "EV6.8CX (21264D)")
+		UNAME_MACHINE="alphaev68" ;;
+	    "EV6.9A (21264/EV69A)")
+		UNAME_MACHINE="alphaev69" ;;
+	    "EV7 (21364)")
+		UNAME_MACHINE="alphaev7" ;;
+	    "EV7.9 (21364A)")
+		UNAME_MACHINE="alphaev79" ;;
+	esac
+	# A Pn.n version is a patched version.
 	# A Vn.n version is a released version.
 	# A Tn.n version is a released field test version.
 	# A Xn.n version is an unreleased experimental baselevel.
 	# 1.2 uses "1.2" for uname -r.
-	cat <<EOF >$dummy.s
-	.data
-\$Lformat:
-	.byte 37,100,45,37,120,10,0	# "%d-%x\n"
-
-	.text
-	.globl main
-	.align 4
-	.ent main
-main:
-	.frame \$30,16,\$26,0
-	ldgp \$29,0(\$27)
-	.prologue 1
-	.long 0x47e03d80 # implver \$0
-	lda \$2,-1
-	.long 0x47e20c21 # amask \$2,\$1
-	lda \$16,\$Lformat
-	mov \$0,\$17
-	not \$1,\$18
-	jsr \$26,printf
-	ldgp \$29,0(\$26)
-	mov 0,\$16
-	jsr \$26,exit
-	.end main
-EOF
-	eval $set_cc_for_build
-	$CC_FOR_BUILD $dummy.s -o $dummy 2>/dev/null
-	if test "$?" = 0 ; then
-		case `./$dummy` in
-			0-0)
-				UNAME_MACHINE="alpha"
-				;;
-			1-0)
-				UNAME_MACHINE="alphaev5"
-				;;
-			1-1)
-				UNAME_MACHINE="alphaev56"
-				;;
-			1-101)
-				UNAME_MACHINE="alphapca56"
-				;;
-			2-303)
-				UNAME_MACHINE="alphaev6"
-				;;
-			2-307)
-				UNAME_MACHINE="alphaev67"
-				;;
-			2-1307)
-				UNAME_MACHINE="alphaev68"
-				;;
-		esac
-	fi
-	rm -f $dummy.s $dummy
-	echo ${UNAME_MACHINE}-dec-osf`echo ${UNAME_RELEASE} | sed -e 's/^[VTX]//' | tr 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' 'abcdefghijklmnopqrstuvwxyz'`
+	echo ${UNAME_MACHINE}-dec-osf`echo ${UNAME_RELEASE} | sed -e 's/^[PVTX]//' | tr 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' 'abcdefghijklmnopqrstuvwxyz'`
 	exit 0 ;;
     Alpha\ *:Windows_NT*:*)
 	# How do we know it's Interix rather than the generic POSIX subsystem?
