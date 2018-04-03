     ptimer_destroy -- destroy the timer.
     ptimer_granularity -- returns the approximate granularity of the timers.

   Timers measure time in milliseconds, but the timings they return
   are floating point numbers, so they can carry as much precision as
   the underlying system timer supports.  For example, to measure the
   time it takes to run a loop, you can use something like:

     ptimer *tmr = ptimer_new ();
     while (...)
       ... loop ...
     double msecs = ptimer_measure ();
     printf ("The loop took %.2f ms\n", msecs);  */

#include <config.h>

