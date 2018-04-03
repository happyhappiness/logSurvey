	if test $UNAME_RELEASE = "V4.0"; then
		UNAME_RELEASE=`/usr/sbin/sizer -v | awk '{print $3}'`
	fi
	# A Vn.n version is a released version.
	# A Tn.n version is a released field test version.
	# A Xn.n version is an unreleased experimental baselevel.
	# 1.2 uses "1.2" for uname -r.
	eval $set_cc_for_build
	cat <<EOF >$dummy.s
	.data
\$Lformat:
	.byte 37,100,45,37,120,10,0	# "%d-%x\n"

	.text
	.globl main
	.align 4
	.ent main
main:
	.frame \$30,16,\$26,0
	ldgp \$29,0(\$27)
	.prologue 1
	.long 0x47e03d80 # implver \$0
	lda \$2,-1
	.long 0x47e20c21 # amask \$2,\$1
	lda \$16,\$Lformat
	mov \$0,\$17
	not \$1,\$18
	jsr \$26,printf
	ldgp \$29,0(\$26)
	mov 0,\$16
	jsr \$26,exit
	.end main
EOF
	$CC_FOR_BUILD -o $dummy $dummy.s 2>/dev/null
	if test "$?" = 0 ; then
		case `$dummy` in
			0-0)
				UNAME_MACHINE="alpha"
				;;
			1-0)
				UNAME_MACHINE="alphaev5"
				;;
			1-1)
				UNAME_MACHINE="alphaev56"
				;;
			1-101)
				UNAME_MACHINE="alphapca56"
				;;
			2-303)
				UNAME_MACHINE="alphaev6"
				;;
			2-307)
				UNAME_MACHINE="alphaev67"
				;;
			2-1307)
				UNAME_MACHINE="alphaev68"
				;;
			3-1307)
				UNAME_MACHINE="alphaev7"
				;;
		esac
	fi
	rm -f $dummy.s $dummy && rmdir $tmpdir
	echo ${UNAME_MACHINE}-dec-osf`echo ${UNAME_RELEASE} | sed -e 's/^[VTX]//' | tr 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' 'abcdefghijklmnopqrstuvwxyz'`
	exit 0 ;;
    Alpha\ *:Windows_NT*:*)
