        $dir = $1;
        push (@rmdirs, $dir);
        -d "$workpath/$dir"
	   || mkdir ("$workpath/$dir", 0777)
           || &error ("Couldn't mkdir $workpath/$dir: $!\n");
      }
    }
