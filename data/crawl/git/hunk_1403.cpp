 			 */
 			if (!opt->shown_dashes &&
 			    (pch & opt->diffopt.output_format) == pch)
-				printf("---");
-			putchar('\n');
+				fprintf(opt->diffopt.file, "---");
+			putc('\n', opt->diffopt.file);
 		}
 	}
 	diff_flush(&opt->diffopt);
