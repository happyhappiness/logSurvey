 int main(int argc, char *argv[])
 {
 	const char *usage =
-	    "Usage: git credential-wincred <get|store|erase>\n";
+	    "usage: git credential-wincred <get|store|erase>\n";
 
 	if (!argv[1])
 		die(usage);