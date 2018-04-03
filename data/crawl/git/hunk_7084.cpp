+diff --git a/main.c b/main.c
+--- a/main.c
+@@ -1,7 +1,9 @@
+ #include <stdio.h>
+ 
+ int func(int num);
+ void print_int(int num);
+ 
+ int main() {
+ 	int i;
+@@ -10,6 +12,8 @@
+ 		print_int(func(i));
+ 	}
+ 
+ 	return 0;
+ }
+ 
+@@ -21,3 +25,7 @@
+ 	printf("%d", num);
+ }
+ 
