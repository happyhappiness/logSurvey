	# A Xn.n version is an unreleased experimental baselevel.
	# 1.2 uses "1.2" for uname -r.
	cat <<EOF >$dummy.s
	.globl main
	.ent main
main:
	.frame \$30,0,\$26,0
	.prologue 0
	.long 0x47e03d80 # implver $0
	lda \$2,259
	.long 0x47e20c21 # amask $2,$1
	srl \$1,8,\$2
	sll \$2,2,\$2
	sll \$0,3,\$0
	addl \$1,\$0,\$0
	addl \$2,\$0,\$0
	ret \$31,(\$26),1
	.end main
EOF
	$CC_FOR_BUILD $dummy.s -o $dummy 2>/dev/null
	if test "$?" = 0 ; then
		./$dummy
		case "$?" in
			7)
				UNAME_MACHINE="alpha"
				;;
			15)
				UNAME_MACHINE="alphaev5"
				;;
			14)
				UNAME_MACHINE="alphaev56"
				;;
			10)
				UNAME_MACHINE="alphapca56"
				;;
			16)
				UNAME_MACHINE="alphaev6"
				;;
		esac
	fi
	rm -f $dummy.s $dummy
