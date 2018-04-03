      *
      * \note arguments may be evaluated more than once, be careful
      *       of side-effects
+     *
+     * XXX: This method either should not exist or should not be virtual.
+     * Kids should not be forced to re-implement vappendf() logic.
+     * That logic should be implemented once, using other [Packable] APIs.
+     * Packable is not about providing a printf(3) service. Packable
+     * is about writing opaque data to various custom destinations.
      */
     virtual void vappendf(const char *fmt, va_list ap) = 0;
 