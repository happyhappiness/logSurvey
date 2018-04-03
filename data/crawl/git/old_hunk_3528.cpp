If <type> is specified, the raw (though uncompressed) contents of the <object>
will be returned.

If '--batch' is specified, output of the following form is printed for each
object specified on stdin:

------------
<sha1> SP <type> SP <size> LF
<contents> LF
------------

If '--batch-check' is specified, output of the following form is printed for
each object specified on stdin:

------------
<sha1> SP <type> SP <size> LF
------------

For both '--batch' and '--batch-check', output of the following form is printed
for each object specified on stdin that does not exist in the repository:

------------
<object> SP missing LF
