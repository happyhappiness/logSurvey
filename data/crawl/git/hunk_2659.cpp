 	if (!dst.ptr)
 		size = 0;
 	dst.size = size;
-	xdi_diff(&src, &dst, &xpp, &xecfg, &ecb);
+	if (xdi_diff(&src, &dst, &xpp, &xecfg, &ecb))
+		die("unable to generate diff");
 	free(src.ptr);
 	free(dst.ptr);
 }
