       implicit |= implicit_percent != 0;
 
       if (implicit && pattern != 0)
-	makefile_fatal (filename, lineno,
-			"mixed implicit and static pattern rules");
+	fatal (flocp, "mixed implicit and static pattern rules");
 
       if (implicit && implicit_percent == 0)
-	makefile_fatal (filename, lineno, "mixed implicit and normal rules");
+	fatal (flocp, "mixed implicit and normal rules");
 
       if (implicit)
 	{
