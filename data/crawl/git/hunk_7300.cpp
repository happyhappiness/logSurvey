 			}
 		}
 	}
-	printf(" %d files changed, %d insertions(+), %d deletions(-)\n",
+	fprintf(options->file, " %d files changed, %d insertions(+), %d deletions(-)\n",
 	       total_files, adds, dels);
 }
 
