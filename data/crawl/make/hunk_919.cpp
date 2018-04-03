 	# A Xn.n version is an unreleased experimental baselevel.
 	# 1.2 uses "1.2" for uname -r.
 	cat <<EOF >$dummy.s
+	.data
+\$Lformat:
+	.byte 37,100,45,37,120,10,0	# "%d-%x\n"
+
+	.text
 	.globl main
+	.align 4
 	.ent main
 main:
-	.frame \$30,0,\$26,0
-	.prologue 0
-	.long 0x47e03d80 # implver $0
-	lda \$2,259
-	.long 0x47e20c21 # amask $2,$1
-	srl \$1,8,\$2
-	sll \$2,2,\$2
-	sll \$0,3,\$0
-	addl \$1,\$0,\$0
-	addl \$2,\$0,\$0
-	ret \$31,(\$26),1
+	.frame \$30,16,\$26,0
+	ldgp \$29,0(\$27)
+	.prologue 1
+	.long 0x47e03d80 # implver \$0
+	lda \$2,-1
+	.long 0x47e20c21 # amask \$2,\$1
+	lda \$16,\$Lformat
+	mov \$0,\$17
+	not \$1,\$18
+	jsr \$26,printf
+	ldgp \$29,0(\$26)
+	mov 0,\$16
+	jsr \$26,exit
 	.end main
 EOF
 	$CC_FOR_BUILD $dummy.s -o $dummy 2>/dev/null
 	if test "$?" = 0 ; then
-		./$dummy
-		case "$?" in
-			7)
+		case `./$dummy` in
+			0-0)
 				UNAME_MACHINE="alpha"
 				;;
-			15)
+			1-0)
 				UNAME_MACHINE="alphaev5"
 				;;
-			14)
+			1-1)
 				UNAME_MACHINE="alphaev56"
 				;;
-			10)
+			1-101)
 				UNAME_MACHINE="alphapca56"
 				;;
-			16)
+			2-303)
 				UNAME_MACHINE="alphaev6"
 				;;
+			2-307)
+				UNAME_MACHINE="alphaev67"
+				;;
 		esac
 	fi
 	rm -f $dummy.s $dummy
