 	write_error (name);
       else if (count != written)
 	{
-	  char buf1[UINTMAX_STRSIZE_BOUND];
-	  char buf2[UINTMAX_STRSIZE_BOUND];
-	  ERROR ((0, 0, _("%s: Could only write %s of %s bytes"),
-		  quotearg_colon (name),
-		  STRINGIFY_BIGINT (totalsize - *sizeleft, buf1),
-		  STRINGIFY_BIGINT (totalsize, buf2)));
+	  write_error_details (name, count, written);
 	  skip_file (*sizeleft);
 	}
 
