
$answer = "$delete_command $example\n";
&run_make_with_options($makefile,"clean",&get_logfile,0);

&compare_output($answer,&get_logfile(1)) || &error ("abort");
if (-f $example) {
   $test_passed = 0;
}

1;

