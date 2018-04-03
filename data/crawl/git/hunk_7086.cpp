+diff --git a/main.c b/main.c
+--- a/main.c
+@@ -1,13 +1,14 @@
+ #include <stdio.h>
+ 
+ int func(int num);
+-void print_int(int num);
+ 
+ int main() {
+ 	int i;
+ 
+ 	for (i = 0; i < 10; i++) {
+-		print_int(func(i));
+ 	}
+ 
+ 	return 0;
+@@ -17,7 +18,7 @@
+ 	return num * num;
+ }
+ 
+-void print_int(int num) {
+-	printf("%d", num);
+ }
+ 
