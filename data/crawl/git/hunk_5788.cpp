 
 . ./test-lib.sh
 
+cat >hello.c <<EOF
+#include <stdio.h>
+int main(int argc, const char **argv)
+{
+	printf("Hello world.\n");
+	return 0;
+}
+EOF
+
 test_expect_success setup '
 	{
 		echo foo mmap bar
