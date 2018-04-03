 	ret = fmt_merge_msg(merge_summary, &input, &output);
 	if (ret)
 		return ret;
-	printf("%s", output.buf);
+	write_in_full(STDOUT_FILENO, output.buf, output.len);
 	return 0;
 }