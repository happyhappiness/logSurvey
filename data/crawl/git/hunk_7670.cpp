 				dels += deleted;
 			}
 		}
-		free(data->files[i]->name);
-		free(data->files[i]);
 	}
-	free(data->files);
-
 	printf(" %d files changed, %d insertions(+), %d deletions(-)\n",
 	       total_files, adds, dels);
 }
