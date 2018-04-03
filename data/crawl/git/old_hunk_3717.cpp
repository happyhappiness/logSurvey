overload methods.

If the text value ends with C<at file line 1> as $@ strings do, then
this infomation will be used to set the C<-file> and C<-line> arguments
of the error object.

This class is used internally if an eval'd block die's with an error
