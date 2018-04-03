 dlopen_self_static=$enable_dlopen_self_static
 
 # Compiler flag to prevent dynamic linking.
-link_static_flag=$lt_link_static_flag
+link_static_flag=$lt_[]_LT_AC_TAGVAR(lt_prog_compiler_static, $1)
 
 # Compiler flag to turn off builtin functions.
-no_builtin_flag=$lt_no_builtin_flag
+no_builtin_flag=$lt_[]_LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)
 
 # Compiler flag to allow reflexive dlopens.
-export_dynamic_flag_spec=$lt_export_dynamic_flag_spec
+export_dynamic_flag_spec=$lt_[]_LT_AC_TAGVAR(export_dynamic_flag_spec, $1)
 
 # Compiler flag to generate shared objects directly from archives.
-whole_archive_flag_spec=$lt_whole_archive_flag_spec
+whole_archive_flag_spec=$lt_[]_LT_AC_TAGVAR(whole_archive_flag_spec, $1)
 
 # Compiler flag to generate thread-safe objects.
-thread_safe_flag_spec=$lt_thread_safe_flag_spec
+thread_safe_flag_spec=$lt_[]_LT_AC_TAGVAR(thread_safe_flag_spec, $1)
 
 # Library versioning type.
 version_type=$version_type
 
-# Format of library name prefix.
-libname_spec=$lt_libname_spec
+# Format of library name prefix.
+libname_spec=$lt_libname_spec
+
+# List of archive names.  First name is the real one, the rest are links.
+# The last name is the one that the linker finds with -lNAME.
+library_names_spec=$lt_library_names_spec
+
+# The coded name of the library, if different from the real name.
+soname_spec=$lt_soname_spec
+
+# Commands used to build and install an old-style archive.
+RANLIB=$lt_RANLIB
+old_archive_cmds=$lt_[]_LT_AC_TAGVAR(old_archive_cmds, $1)
+old_postinstall_cmds=$lt_old_postinstall_cmds
+old_postuninstall_cmds=$lt_old_postuninstall_cmds
+
+# Create an old-style archive from a shared archive.
+old_archive_from_new_cmds=$lt_[]_LT_AC_TAGVAR(old_archive_from_new_cmds, $1)
+
+# Create a temporary old-style archive to link instead of a shared archive.
+old_archive_from_expsyms_cmds=$lt_[]_LT_AC_TAGVAR(old_archive_from_expsyms_cmds, $1)
+
+# Commands used to build and install a shared archive.
+archive_cmds=$lt_[]_LT_AC_TAGVAR(archive_cmds, $1)
+archive_expsym_cmds=$lt_[]_LT_AC_TAGVAR(archive_expsym_cmds, $1)
+postinstall_cmds=$lt_postinstall_cmds
+postuninstall_cmds=$lt_postuninstall_cmds
+
+# Commands used to build a loadable module (assumed same as above if empty)
+module_cmds=$lt_[]_LT_AC_TAGVAR(module_cmds, $1)
+module_expsym_cmds=$lt_[]_LT_AC_TAGVAR(module_expsym_cmds, $1)
+
+# Commands to strip libraries.
+old_striplib=$lt_old_striplib
+striplib=$lt_striplib
+
+# Dependencies to place before the objects being linked to create a
+# shared library.
+predep_objects=$lt_[]_LT_AC_TAGVAR(predep_objects, $1)
+
+# Dependencies to place after the objects being linked to create a
+# shared library.
+postdep_objects=$lt_[]_LT_AC_TAGVAR(postdep_objects, $1)
+
+# Dependencies to place before the objects being linked to create a
+# shared library.
+predeps=$lt_[]_LT_AC_TAGVAR(predeps, $1)
+
+# Dependencies to place after the objects being linked to create a
+# shared library.
+postdeps=$lt_[]_LT_AC_TAGVAR(postdeps, $1)
+
+# The library search path used internally by the compiler when linking
+# a shared library.
+compiler_lib_search_path=$lt_[]_LT_AC_TAGVAR(compiler_lib_search_path, $1)
+
+# Method to check whether dependent libraries are shared objects.
+deplibs_check_method=$lt_deplibs_check_method
+
+# Command to use when deplibs_check_method == file_magic.
+file_magic_cmd=$lt_file_magic_cmd
+
+# Flag that allows shared libraries with undefined symbols to be built.
+allow_undefined_flag=$lt_[]_LT_AC_TAGVAR(allow_undefined_flag, $1)
+
+# Flag that forces no undefined symbols.
+no_undefined_flag=$lt_[]_LT_AC_TAGVAR(no_undefined_flag, $1)
+
+# Commands used to finish a libtool library installation in a directory.
+finish_cmds=$lt_finish_cmds
+
+# Same as above, but a single script fragment to be evaled but not shown.
+finish_eval=$lt_finish_eval
+
+# Take the output of nm and produce a listing of raw symbols and C names.
+global_symbol_pipe=$lt_lt_cv_sys_global_symbol_pipe
+
+# Transform the output of nm in a proper C declaration
+global_symbol_to_cdecl=$lt_lt_cv_sys_global_symbol_to_cdecl
+
+# Transform the output of nm in a C name address pair
+global_symbol_to_c_name_address=$lt_lt_cv_sys_global_symbol_to_c_name_address
+
+# This is the shared library runtime path variable.
+runpath_var=$runpath_var
+
+# This is the shared library path variable.
+shlibpath_var=$shlibpath_var
+
+# Is shlibpath searched before the hard-coded library search path?
+shlibpath_overrides_runpath=$shlibpath_overrides_runpath
+
+# How to hardcode a shared library path into an executable.
+hardcode_action=$_LT_AC_TAGVAR(hardcode_action, $1)
+
+# Whether we should hardcode library paths into libraries.
+hardcode_into_libs=$hardcode_into_libs
+
+# Flag to hardcode \$libdir into a binary during linking.
+# This must work even if \$libdir does not exist.
+hardcode_libdir_flag_spec=$lt_[]_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)
+
+# If ld is used when linking, flag to hardcode \$libdir into
+# a binary during linking. This must work even if \$libdir does
+# not exist.
+hardcode_libdir_flag_spec_ld=$lt_[]_LT_AC_TAGVAR(hardcode_libdir_flag_spec_ld, $1)
+
+# Whether we need a single -rpath flag with a separated argument.
+hardcode_libdir_separator=$lt_[]_LT_AC_TAGVAR(hardcode_libdir_separator, $1)
+
+# Set to yes if using DIR/libNAME${shared_ext} during linking hardcodes DIR into the
+# resulting binary.
+hardcode_direct=$_LT_AC_TAGVAR(hardcode_direct, $1)
+
+# Set to yes if using the -LDIR flag during linking hardcodes DIR into the
+# resulting binary.
+hardcode_minus_L=$_LT_AC_TAGVAR(hardcode_minus_L, $1)
+
+# Set to yes if using SHLIBPATH_VAR=DIR during linking hardcodes DIR into
+# the resulting binary.
+hardcode_shlibpath_var=$_LT_AC_TAGVAR(hardcode_shlibpath_var, $1)
+
+# Set to yes if building a shared library automatically hardcodes DIR into the library
+# and all subsequent libraries and executables linked against it.
+hardcode_automatic=$_LT_AC_TAGVAR(hardcode_automatic, $1)
+
+# Variables whose values should be saved in libtool wrapper scripts and
+# restored at relink time.
+variables_saved_for_relink="$variables_saved_for_relink"
+
+# Whether libtool must link a program against all its dependency libraries.
+link_all_deplibs=$_LT_AC_TAGVAR(link_all_deplibs, $1)
+
+# Compile-time system search path for libraries
+sys_lib_search_path_spec=$lt_sys_lib_search_path_spec
+
+# Run-time system search path for libraries
+sys_lib_dlsearch_path_spec=$lt_sys_lib_dlsearch_path_spec
+
+# Fix the shell variable \$srcfile for the compiler.
+fix_srcfile_path="$_LT_AC_TAGVAR(fix_srcfile_path, $1)"
+
+# Set to yes if exported symbols are required.
+always_export_symbols=$_LT_AC_TAGVAR(always_export_symbols, $1)
+
+# The commands to list exported symbols.
+export_symbols_cmds=$lt_[]_LT_AC_TAGVAR(export_symbols_cmds, $1)
+
+# The commands to extract the exported symbol list from a shared archive.
+extract_expsyms_cmds=$lt_extract_expsyms_cmds
+
+# Symbols that should not be listed in the preloaded symbols.
+exclude_expsyms=$lt_[]_LT_AC_TAGVAR(exclude_expsyms, $1)
+
+# Symbols that must always be exported.
+include_expsyms=$lt_[]_LT_AC_TAGVAR(include_expsyms, $1)
+
+ifelse([$1],[],
+[# ### END LIBTOOL CONFIG],
+[# ### END LIBTOOL TAG CONFIG: $tagname])
+
+__EOF__
+
+ifelse([$1],[], [
+  case $host_os in
+  aix3*)
+    cat <<\EOF >> "$cfgfile"
+
+# AIX sometimes has problems with the GCC collect2 program.  For some
+# reason, if we set the COLLECT_NAMES environment variable, the problems
+# vanish in a puff of smoke.
+if test "X${COLLECT_NAMES+set}" != Xset; then
+  COLLECT_NAMES=
+  export COLLECT_NAMES
+fi
+EOF
+    ;;
+  esac
+
+  # We use sed instead of cat because bash on DJGPP gets confused if
+  # if finds mixed CR/LF and LF-only lines.  Since sed operates in
+  # text mode, it properly converts lines to CR/LF.  This bash problem
+  # is reportedly fixed, but why not run on old versions too?
+  sed '$q' "$ltmain" >> "$cfgfile" || (rm -f "$cfgfile"; exit 1)
+
+  mv -f "$cfgfile" "$ofile" || \
+    (rm -f "$ofile" && cp "$cfgfile" "$ofile" && rm -f "$cfgfile")
+  chmod +x "$ofile"
+])
+else
+  # If there is no Makefile yet, we rely on a make rule to execute
+  # `config.status --recheck' to rerun these tests and create the
+  # libtool script then.
+  test -f Makefile && make "$ltmain"
+fi
+])# AC_LIBTOOL_CONFIG
+
+
+# AC_LIBTOOL_PROG_COMPILER_NO_RTTI([TAGNAME])
+# -------------------------------------------
+AC_DEFUN([AC_LIBTOOL_PROG_COMPILER_NO_RTTI],
+[AC_REQUIRE([_LT_AC_SYS_COMPILER])dnl
+
+_LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=
+
+if test "$GCC" = yes; then
+  _LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)=' -fno-builtin'
+
+  AC_LIBTOOL_COMPILER_OPTION([if $compiler supports -fno-rtti -fno-exceptions],
+    lt_cv_prog_compiler_rtti_exceptions,
+    [-fno-rtti -fno-exceptions], [],
+    [_LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)="$_LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1) -fno-rtti -fno-exceptions"])
+fi
+])# AC_LIBTOOL_PROG_COMPILER_NO_RTTI
+
+
+# AC_LIBTOOL_SYS_GLOBAL_SYMBOL_PIPE
+# ---------------------------------
+AC_DEFUN([AC_LIBTOOL_SYS_GLOBAL_SYMBOL_PIPE],
+[AC_REQUIRE([AC_CANONICAL_HOST])
+AC_REQUIRE([AC_PROG_NM])
+AC_REQUIRE([AC_OBJEXT])
+# Check for command to grab the raw symbol name followed by C symbol from nm.
+AC_MSG_CHECKING([command to parse $NM output from $compiler object])
+AC_CACHE_VAL([lt_cv_sys_global_symbol_pipe],
+[
+# These are sane defaults that work on at least a few old systems.
+# [They come from Ultrix.  What could be older than Ultrix?!! ;)]
+
+# Character class describing NM global symbol codes.
+symcode='[[BCDEGRST]]'
+
+# Regexp to match symbols that can be accessed directly from C.
+sympat='\([[_A-Za-z]][[_A-Za-z0-9]]*\)'
+
+# Transform the above into a raw symbol and a C symbol.
+symxfrm='\1 \2\3 \3'
+
+# Transform an extracted symbol line into a proper C declaration
+lt_cv_sys_global_symbol_to_cdecl="sed -n -e 's/^. .* \(.*\)$/extern int \1;/p'"
+
+# Transform an extracted symbol line into symbol name and symbol address
+lt_cv_sys_global_symbol_to_c_name_address="sed -n -e 's/^: \([[^ ]]*\) $/  {\\\"\1\\\", (lt_ptr) 0},/p' -e 's/^$symcode \([[^ ]]*\) \([[^ ]]*\)$/  {\"\2\", (lt_ptr) \&\2},/p'"
+
+# Define system-specific variables.
+case $host_os in
+aix*)
+  symcode='[[BCDT]]'
+  ;;
+cygwin* | mingw* | pw32*)
+  symcode='[[ABCDGISTW]]'
+  ;;
+hpux*) # Its linker distinguishes data from code symbols
+  if test "$host_cpu" = ia64; then
+    symcode='[[ABCDEGRST]]'
+  fi
+  lt_cv_sys_global_symbol_to_cdecl="sed -n -e 's/^T .* \(.*\)$/extern int \1();/p' -e 's/^$symcode* .* \(.*\)$/extern char \1;/p'"
+  lt_cv_sys_global_symbol_to_c_name_address="sed -n -e 's/^: \([[^ ]]*\) $/  {\\\"\1\\\", (lt_ptr) 0},/p' -e 's/^$symcode* \([[^ ]]*\) \([[^ ]]*\)$/  {\"\2\", (lt_ptr) \&\2},/p'"
+  ;;
+irix* | nonstopux*)
+  symcode='[[BCDEGRST]]'
+  ;;
+osf*)
+  symcode='[[BCDEGQRST]]'
+  ;;
+solaris* | sysv5*)
+  symcode='[[BDT]]'
+  ;;
+sysv4)
+  symcode='[[DFNSTU]]'
+  ;;
+esac
+
+# Handle CRLF in mingw tool chain
+opt_cr=
+case $build_os in
+mingw*)
+  opt_cr=`echo 'x\{0,1\}' | tr x '\015'` # option cr in regexp
+  ;;
+esac
+
+# If we're using GNU nm, then use its standard symbol codes.
+case `$NM -V 2>&1` in
+*GNU* | *'with BFD'*)
+  symcode='[[ABCDGISTW]]' ;;
+esac
+
+# Try without a prefix undercore, then with it.
+for ac_symprfx in "" "_"; do
 
-# List of archive names.  First name is the real one, the rest are links.
-# The last name is the one that the linker finds with -lNAME.
-library_names_spec=$lt_library_names_spec
+  # Write the raw and C identifiers.
+  lt_cv_sys_global_symbol_pipe="sed -n -e 's/^.*[[ 	]]\($symcode$symcode*\)[[ 	]][[ 	]]*\($ac_symprfx\)$sympat$opt_cr$/$symxfrm/p'"
 
-# The coded name of the library, if different from the real name.
-soname_spec=$lt_soname_spec
+  # Check to see that the pipe works correctly.
+  pipe_works=no
 
-# Commands used to build and install an old-style archive.
-RANLIB=$lt_RANLIB
-old_archive_cmds=$lt_old_archive_cmds
-old_postinstall_cmds=$lt_old_postinstall_cmds
-old_postuninstall_cmds=$lt_old_postuninstall_cmds
+  rm -f conftest*
+  cat > conftest.$ac_ext <<EOF
+#ifdef __cplusplus
+extern "C" {
+#endif
+char nm_test_var;
+void nm_test_func(){}
+#ifdef __cplusplus
+}
+#endif
+int main(){nm_test_var='a';nm_test_func();return(0);}
+EOF
 
-# Create an old-style archive from a shared archive.
-old_archive_from_new_cmds=$lt_old_archive_from_new_cmds
+  if AC_TRY_EVAL(ac_compile); then
+    # Now try to grab the symbols.
+    nlist=conftest.nm
+    if AC_TRY_EVAL(NM conftest.$ac_objext \| $lt_cv_sys_global_symbol_pipe \> $nlist) && test -s "$nlist"; then
+      # Try sorting and uniquifying the output.
+      if sort "$nlist" | uniq > "$nlist"T; then
+	mv -f "$nlist"T "$nlist"
+      else
+	rm -f "$nlist"T
+      fi
 
-# Create a temporary old-style archive to link instead of a shared archive.
-old_archive_from_expsyms_cmds=$lt_old_archive_from_expsyms_cmds
+      # Make sure that we snagged all the symbols we need.
+      if grep ' nm_test_var$' "$nlist" >/dev/null; then
+	if grep ' nm_test_func$' "$nlist" >/dev/null; then
+	  cat <<EOF > conftest.$ac_ext
+#ifdef __cplusplus
+extern "C" {
+#endif
 
-# Commands used to build and install a shared archive.
-archive_cmds=$lt_archive_cmds
-archive_expsym_cmds=$lt_archive_expsym_cmds
-postinstall_cmds=$lt_postinstall_cmds
-postuninstall_cmds=$lt_postuninstall_cmds
+EOF
+	  # Now generate the symbol file.
+	  eval "$lt_cv_sys_global_symbol_to_cdecl"' < "$nlist" | grep -v main >> conftest.$ac_ext'
 
-# Commands to strip libraries.
-old_striplib=$lt_old_striplib
-striplib=$lt_striplib
+	  cat <<EOF >> conftest.$ac_ext
+#if defined (__STDC__) && __STDC__
+# define lt_ptr_t void *
+#else
+# define lt_ptr_t char *
+# define const
+#endif
 
-# Method to check whether dependent libraries are shared objects.
-deplibs_check_method=$lt_deplibs_check_method
+/* The mapping between symbol names and symbols. */
+const struct {
+  const char *name;
+  lt_ptr_t address;
+}
+lt_preloaded_symbols[[]] =
+{
+EOF
+	  $SED "s/^$symcode$symcode* \(.*\) \(.*\)$/  {\"\2\", (lt_ptr_t) \&\2},/" < "$nlist" | grep -v main >> conftest.$ac_ext
+	  cat <<\EOF >> conftest.$ac_ext
+  {0, (lt_ptr_t) 0}
+};
 
-# Command to use when deplibs_check_method == file_magic.
-file_magic_cmd=$lt_file_magic_cmd
+#ifdef __cplusplus
+}
+#endif
+EOF
+	  # Now try linking the two files.
+	  mv conftest.$ac_objext conftstm.$ac_objext
+	  lt_save_LIBS="$LIBS"
+	  lt_save_CFLAGS="$CFLAGS"
+	  LIBS="conftstm.$ac_objext"
+	  CFLAGS="$CFLAGS$_LT_AC_TAGVAR(lt_prog_compiler_no_builtin_flag, $1)"
+	  if AC_TRY_EVAL(ac_link) && test -s conftest${ac_exeext}; then
+	    pipe_works=yes
+	  fi
+	  LIBS="$lt_save_LIBS"
+	  CFLAGS="$lt_save_CFLAGS"
+	else
+	  echo "cannot find nm_test_func in $nlist" >&AS_MESSAGE_LOG_FD
+	fi
+      else
+	echo "cannot find nm_test_var in $nlist" >&AS_MESSAGE_LOG_FD
+      fi
+    else
+      echo "cannot run $lt_cv_sys_global_symbol_pipe" >&AS_MESSAGE_LOG_FD
+    fi
+  else
+    echo "$progname: failed program was:" >&AS_MESSAGE_LOG_FD
+    cat conftest.$ac_ext >&5
+  fi
+  rm -f conftest* conftst*
 
-# Flag that allows shared libraries with undefined symbols to be built.
-allow_undefined_flag=$lt_allow_undefined_flag
+  # Do not use the global_symbol_pipe unless it works.
+  if test "$pipe_works" = yes; then
+    break
+  else
+    lt_cv_sys_global_symbol_pipe=
+  fi
+done
+])
+if test -z "$lt_cv_sys_global_symbol_pipe"; then
+  lt_cv_sys_global_symbol_to_cdecl=
+fi
+if test -z "$lt_cv_sys_global_symbol_pipe$lt_cv_sys_global_symbol_to_cdecl"; then
+  AC_MSG_RESULT(failed)
+else
+  AC_MSG_RESULT(ok)
+fi
+]) # AC_LIBTOOL_SYS_GLOBAL_SYMBOL_PIPE
 
-# Flag that forces no undefined symbols.
-no_undefined_flag=$lt_no_undefined_flag
 
-# Commands used to finish a libtool library installation in a directory.
-finish_cmds=$lt_finish_cmds
+# AC_LIBTOOL_PROG_COMPILER_PIC([TAGNAME])
+# ---------------------------------------
+AC_DEFUN([AC_LIBTOOL_PROG_COMPILER_PIC],
+[_LT_AC_TAGVAR(lt_prog_compiler_wl, $1)=
+_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
+_LT_AC_TAGVAR(lt_prog_compiler_static, $1)=
 
-# Same as above, but a single script fragment to be evaled but not shown.
-finish_eval=$lt_finish_eval
+AC_MSG_CHECKING([for $compiler option to produce PIC])
+ ifelse([$1],[CXX],[
+  # C++ specific cases for pic, static, wl, etc.
+  if test "$GXX" = yes; then
+    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-static'
 
-# Take the output of nm and produce a listing of raw symbols and C names.
-global_symbol_pipe=$lt_global_symbol_pipe
+    case $host_os in
+    aix*)
+      # All AIX code is PIC.
+      if test "$host_cpu" = ia64; then
+	# AIX 5 now supports IA64 processor
+	_LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      fi
+      ;;
+    amigaos*)
+      # FIXME: we need at least 68020 code to build shared libraries, but
+      # adding the `-m68020' flag to GCC prevents building anything better,
+      # like `-m68040'.
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-m68020 -resident32 -malways-restore-a4'
+      ;;
+    beos* | cygwin* | irix5* | irix6* | nonstopux* | osf3* | osf4* | osf5*)
+      # PIC is the default for these OSes.
+      ;;
+    mingw* | os2* | pw32*)
+      # This hack is so that the source file can tell whether it is being
+      # built for inclusion in a dll (and should export symbols for example).
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'
+      ;;
+    darwin* | rhapsody*)
+      # PIC is the default on this platform
+      # Common symbols not allowed in MH_DYLIB files
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      ;;
+    *djgpp*)
+      # DJGPP does not support shared libraries at all
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
+      ;;
+    sysv4*MP*)
+      if test -d /usr/nec; then
+	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=-Kconform_pic
+      fi
+      ;;
+    hpux*)
+      # PIC is the default for IA64 HP-UX and 64-bit HP-UX, but
+      # not for PA HP-UX.
+      case "$host_cpu" in
+      hppa*64*|ia64*)
+	;;
+      *)
+	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+	;;
+      esac
+      ;;
+    *)
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+      ;;
+    esac
+  else
+    case $host_os in
+      aix4* | aix5*)
+	# All AIX code is PIC.
+	if test "$host_cpu" = ia64; then
+	  # AIX 5 now supports IA64 processor
+	  _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+	else
+	  _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-bnso -bI:/lib/syscalls.exp'
+	fi
+	;;
+      chorus*)
+	case $cc_basename in
+	cxch68)
+	  # Green Hills C++ Compiler
+	  # _LT_AC_TAGVAR(lt_prog_compiler_static, $1)="--no_auto_instantiation -u __main -u __premain -u _abort -r $COOL_DIR/lib/libOrb.a $MVME_DIR/lib/CC/libC.a $MVME_DIR/lib/classix/libcx.s.a"
+	  ;;
+	esac
+	;;
+      dgux*)
+	case $cc_basename in
+	  ec++)
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	    ;;
+	  ghcx)
+	    # Green Hills C++ Compiler
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
+	    ;;
+	  *)
+	    ;;
+	esac
+	;;
+      freebsd*)
+	# FreeBSD uses GNU C++
+	;;
+      hpux9* | hpux10* | hpux11*)
+	case $cc_basename in
+	  CC)
+	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)="${ac_cv_prog_cc_wl}-a ${ac_cv_prog_cc_wl}archive"
+	    if test "$host_cpu" != ia64; then
+	      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
+	    fi
+	    ;;
+	  aCC)
+	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)="${ac_cv_prog_cc_wl}-a ${ac_cv_prog_cc_wl}archive"
+	    case "$host_cpu" in
+	    hppa*64*|ia64*)
+	      # +Z the default
+	      ;;
+	    *)
+	      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
+	      ;;
+	    esac
+	    ;;
+	  *)
+	    ;;
+	esac
+	;;
+      irix5* | irix6* | nonstopux*)
+	case $cc_basename in
+	  CC)
+	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
+	    # CC pic flag -KPIC is the default.
+	    ;;
+	  *)
+	    ;;
+	esac
+	;;
+      linux*)
+	case $cc_basename in
+	  KCC)
+	    # KAI C++ Compiler
+	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='--backend -Wl,'
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+	    ;;
+	  icpc)
+	    # Intel C++
+	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-static'
+	    ;; 
+	  cxx)
+	    # Compaq C++
+	    # Make sure the PIC flag is empty.  It appears that all Alpha
+	    # Linux and Compaq Tru64 Unix objects are PIC.
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
+	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
+	    ;;
+	  *)
+	    ;;
+	esac
+	;;
+      lynxos*)
+	;;
+      m88k*)
+	;;
+      mvs*)
+	case $cc_basename in
+	  cxx)
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-W c,exportall'
+	    ;;
+	  *)
+	    ;;
+	esac
+	;;
+      netbsd*)
+	;;
+      osf3* | osf4* | osf5*)
+	case $cc_basename in
+	  KCC)
+	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='--backend -Wl,'
+	    ;;
+	  RCC)
+	    # Rational C++ 2.4.1
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
+	    ;;
+	  cxx)
+	    # Digital/Compaq C++
+	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	    # Make sure the PIC flag is empty.  It appears that all Alpha
+	    # Linux and Compaq Tru64 Unix objects are PIC.
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
+	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
+	    ;;
+	  *)
+	    ;;
+	esac
+	;;
+      psos*)
+	;;
+      sco*)
+	case $cc_basename in
+	  CC)
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+	    ;;
+	  *)
+	    ;;
+	esac
+	;;
+      solaris*)
+	case $cc_basename in
+	  CC)
+	    # Sun C++ 4.2, 5.x and Centerline C++
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+	    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
+	    ;;
+	  gcx)
+	    # Green Hills C++ Compiler
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-PIC'
+	    ;;
+	  *)
+	    ;;
+	esac
+	;;
+      sunos4*)
+	case $cc_basename in
+	  CC)
+	    # Sun C++ 4.x
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
+	    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+	    ;;
+	  lcc)
+	    # Lucid
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
+	    ;;
+	  *)
+	    ;;
+	esac
+	;;
+      tandem*)
+	case $cc_basename in
+	  NCC)
+	    # NonStop-UX NCC 3.20
+	    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	    ;;
+	  *)
+	    ;;
+	esac
+	;;
+      unixware*)
+	;;
+      vxworks*)
+	;;
+      *)
+	_LT_AC_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
+	;;
+    esac
+  fi
+],
+[
+  if test "$GCC" = yes; then
+    _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+    _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-static'
 
-# Transform the output of nm in a proper C declaration
-global_symbol_to_cdecl=$lt_global_symbol_to_cdecl
+    case $host_os in
+      aix*)
+      # All AIX code is PIC.
+      if test "$host_cpu" = ia64; then
+	# AIX 5 now supports IA64 processor
+	_LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      fi
+      ;;
 
-# Transform the output of nm in a C name address pair
-global_symbol_to_c_name_address=$lt_global_symbol_to_c_name_address
+    amigaos*)
+      # FIXME: we need at least 68020 code to build shared libraries, but
+      # adding the `-m68020' flag to GCC prevents building anything better,
+      # like `-m68040'.
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-m68020 -resident32 -malways-restore-a4'
+      ;;
 
-# This is the shared library runtime path variable.
-runpath_var=$runpath_var
+    beos* | cygwin* | irix5* | irix6* | nonstopux* | osf3* | osf4* | osf5*)
+      # PIC is the default for these OSes.
+      ;;
 
-# This is the shared library path variable.
-shlibpath_var=$shlibpath_var
+    mingw* | pw32* | os2*)
+      # This hack is so that the source file can tell whether it is being
+      # built for inclusion in a dll (and should export symbols for example).
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'
+      ;;
 
-# Is shlibpath searched before the hard-coded library search path?
-shlibpath_overrides_runpath=$shlibpath_overrides_runpath
+    darwin* | rhapsody*)
+      # PIC is the default on this platform
+      # Common symbols not allowed in MH_DYLIB files
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      ;;
 
-# How to hardcode a shared library path into an executable.
-hardcode_action=$hardcode_action
+    msdosdjgpp*)
+      # Just because we use GCC doesn't mean we suddenly get shared libraries
+      # on systems that don't support them.
+      _LT_AC_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
+      enable_shared=no
+      ;;
 
-# Whether we should hardcode library paths into libraries.
-hardcode_into_libs=$hardcode_into_libs
+    sysv4*MP*)
+      if test -d /usr/nec; then
+	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=-Kconform_pic
+      fi
+      ;;
 
-# Flag to hardcode \$libdir into a binary during linking.
-# This must work even if \$libdir does not exist.
-hardcode_libdir_flag_spec=$lt_hardcode_libdir_flag_spec
+    hpux*)
+      # PIC is the default for IA64 HP-UX and 64-bit HP-UX, but
+      # not for PA HP-UX.
+      case "$host_cpu" in
+      hppa*64*|ia64*)
+	# +Z the default
+	;;
+      *)
+	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+	;;
+      esac
+      ;;
 
-# Whether we need a single -rpath flag with a separated argument.
-hardcode_libdir_separator=$lt_hardcode_libdir_separator
+    *)
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+      ;;
+    esac
+  else
+    # PORTME Check for flag to pass linker flags through the system compiler.
+    case $host_os in
+    aix*)
+      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+      if test "$host_cpu" = ia64; then
+	# AIX 5 now supports IA64 processor
+	_LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      else
+	_LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-bnso -bI:/lib/syscalls.exp'
+      fi
+      ;;
 
-# Set to yes if using DIR/libNAME.so during linking hardcodes DIR into the
-# resulting binary.
-hardcode_direct=$hardcode_direct
+    mingw* | pw32* | os2*)
+      # This hack is so that the source file can tell whether it is being
+      # built for inclusion in a dll (and should export symbols for example).
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'
+      ;;
 
-# Set to yes if using the -LDIR flag during linking hardcodes DIR into the
-# resulting binary.
-hardcode_minus_L=$hardcode_minus_L
+    hpux9* | hpux10* | hpux11*)
+      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+      # PIC is the default for IA64 HP-UX and 64-bit HP-UX, but
+      # not for PA HP-UX.
+      case "$host_cpu" in
+      hppa*64*|ia64*)
+	# +Z the default
+	;;
+      *)
+	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='+Z'
+	;;
+      esac
+      # Is there a better lt_prog_compiler_static that works with the bundled CC?
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='${wl}-a ${wl}archive'
+      ;;
 
-# Set to yes if using SHLIBPATH_VAR=DIR during linking hardcodes DIR into
-# the resulting binary.
-hardcode_shlibpath_var=$hardcode_shlibpath_var
+    irix5* | irix6* | nonstopux*)
+      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+      # PIC (with -KPIC) is the default.
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
+      ;;
 
-# Variables whose values should be saved in libtool wrapper scripts and
-# restored at relink time.
-variables_saved_for_relink="$variables_saved_for_relink"
+    newsos6)
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      ;;
 
-# Whether libtool must link a program against all its dependency libraries.
-link_all_deplibs=$link_all_deplibs
+    linux*)
+      case $CC in
+      icc|ecc)
+	_LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+	_LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-static'
+        ;;
+      ccc)
+        _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+        # All Alpha code is PIC.
+        _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
+        ;;
+      esac
+      ;;
 
-# Compile-time system search path for libraries
-sys_lib_search_path_spec=$lt_sys_lib_search_path_spec
+    osf3* | osf4* | osf5*)
+      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+      # All OSF/1 code is PIC.
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-non_shared'
+      ;;
 
-# Run-time system search path for libraries
-sys_lib_dlsearch_path_spec=$lt_sys_lib_dlsearch_path_spec
+    sco3.2v5*)
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-Kpic'
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-dn'
+      ;;
 
-# Fix the shell variable \$srcfile for the compiler.
-fix_srcfile_path="$fix_srcfile_path"
+    solaris*)
+      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      ;;
 
-# Set to yes if exported symbols are required.
-always_export_symbols=$always_export_symbols
+    sunos4*)
+      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Qoption ld '
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-PIC'
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      ;;
 
-# The commands to list exported symbols.
-export_symbols_cmds=$lt_export_symbols_cmds
+    sysv4 | sysv4.2uw2* | sysv4.3* | sysv5*)
+      _LT_AC_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      ;;
 
-# The commands to extract the exported symbol list from a shared archive.
-extract_expsyms_cmds=$lt_extract_expsyms_cmds
+    sysv4*MP*)
+      if test -d /usr/nec ;then
+	_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-Kconform_pic'
+	_LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      fi
+      ;;
 
-# Symbols that should not be listed in the preloaded symbols.
-exclude_expsyms=$lt_exclude_expsyms
+    uts4*)
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-pic'
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
+      ;;
 
-# Symbols that must always be exported.
-include_expsyms=$lt_include_expsyms
+    *)
+      _LT_AC_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
+      ;;
+    esac
+  fi
+])
+AC_MSG_RESULT([$_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)])
 
-# ### END LIBTOOL CONFIG
+#
+# Check to make sure the PIC flag actually works.
+#
+if test -n "$_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)"; then
+  AC_LIBTOOL_COMPILER_OPTION([if $compiler PIC flag $_LT_AC_TAGVAR(lt_prog_compiler_pic, $1) works],
+    _LT_AC_TAGVAR(lt_prog_compiler_pic_works, $1),
+    [$_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)ifelse([$1],[],[ -DPIC],[ifelse([$1],[CXX],[ -DPIC],[])])], [],
+    [case $_LT_AC_TAGVAR(lt_prog_compiler_pic, $1) in
+     "" | " "*) ;;
+     *) _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=" $_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)" ;;
+     esac],
+    [_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
+     _LT_AC_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no])
+fi
+case "$host_os" in
+  # For platforms which do not support PIC, -DPIC is meaningless:
+  *djgpp*)
+    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
+    ;;
+  *)
+    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)="$_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)ifelse([$1],[],[ -DPIC],[ifelse([$1],[CXX],[ -DPIC],[])])"
+    ;;
+esac
+])
 
-__EOF__
 
+# AC_LIBTOOL_PROG_LD_SHLIBS([TAGNAME])
+# ------------------------------------
+# See if the linker supports building shared libraries.
+AC_DEFUN([AC_LIBTOOL_PROG_LD_SHLIBS],
+[AC_MSG_CHECKING([whether the $compiler linker ($LD) supports shared libraries])
+ifelse([$1],[CXX],[
+  _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
   case $host_os in
-  aix3*)
-    cat <<\EOF >> "${ofile}T"
-
-# AIX sometimes has problems with the GCC collect2 program.  For some
-# reason, if we set the COLLECT_NAMES environment variable, the problems
-# vanish in a puff of smoke.
-if test "X${COLLECT_NAMES+set}" != Xset; then
-  COLLECT_NAMES=
-  export COLLECT_NAMES
-fi
-EOF
+  aix4* | aix5*)
+    # If we're using GNU nm, then we don't want the "-C" option.
+    # -C means demangle to AIX nm, but means don't demangle with GNU nm
+    if $NM -V 2>&1 | grep 'GNU' > /dev/null; then
+      _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM -Bpg $libobjs $convenience | awk '\''{ if (((\[$]2 == "T") || (\[$]2 == "D") || (\[$]2 == "B")) && ([substr](\[$]3,1,1) != ".")) { print \[$]3 } }'\'' | sort -u > $export_symbols'
+    else
+      _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM -BCpg $libobjs $convenience | awk '\''{ if (((\[$]2 == "T") || (\[$]2 == "D") || (\[$]2 == "B")) && ([substr](\[$]3,1,1) != ".")) { print \[$]3 } }'\'' | sort -u > $export_symbols'
+    fi
     ;;
+  pw32*)
+    _LT_AC_TAGVAR(export_symbols_cmds, $1)="$ltdll_cmds"
+  ;;
+  cygwin* | mingw*)
+    _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED -e '\''/^[[BCDGS]] /s/.* \([[^ ]]*\)/\1 DATA/'\'' | $SED -e '\''/^[[AITW]] /s/.* //'\'' | sort | uniq > $export_symbols'
+  ;;
+  *)
+    _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
+  ;;
   esac
+],[
+  runpath_var=
+  _LT_AC_TAGVAR(allow_undefined_flag, $1)=
+  _LT_AC_TAGVAR(enable_shared_with_static_runtimes, $1)=no
+  _LT_AC_TAGVAR(archive_cmds, $1)=
+  _LT_AC_TAGVAR(archive_expsym_cmds, $1)=
+  _LT_AC_TAGVAR(old_archive_From_new_cmds, $1)=
+  _LT_AC_TAGVAR(old_archive_from_expsyms_cmds, $1)=
+  _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)=
+  _LT_AC_TAGVAR(whole_archive_flag_spec, $1)=
+  _LT_AC_TAGVAR(thread_safe_flag_spec, $1)=
+  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)=
+  _LT_AC_TAGVAR(hardcode_libdir_flag_spec_ld, $1)=
+  _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=
+  _LT_AC_TAGVAR(hardcode_direct, $1)=no
+  _LT_AC_TAGVAR(hardcode_minus_L, $1)=no
+  _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
+  _LT_AC_TAGVAR(link_all_deplibs, $1)=unknown
+  _LT_AC_TAGVAR(hardcode_automatic, $1)=no
+  _LT_AC_TAGVAR(module_cmds, $1)=
+  _LT_AC_TAGVAR(module_expsym_cmds, $1)=  
+  _LT_AC_TAGVAR(always_export_symbols, $1)=no
+  _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED '\''s/.* //'\'' | sort | uniq > $export_symbols'
+  # include_expsyms should be a list of space-separated symbols to be *always*
+  # included in the symbol list
+  _LT_AC_TAGVAR(include_expsyms, $1)=
+  # exclude_expsyms can be an extended regexp of symbols to exclude
+  # it will be wrapped by ` (' and `)$', so one must not match beginning or
+  # end of line.  Example: `a|bc|.*d.*' will exclude the symbols `a' and `bc',
+  # as well as any symbol that contains `d'.
+  _LT_AC_TAGVAR(exclude_expsyms, $1)="_GLOBAL_OFFSET_TABLE_"
+  # Although _GLOBAL_OFFSET_TABLE_ is a valid symbol C name, most a.out
+  # platforms (ab)use it in PIC code, but their linkers get confused if
+  # the symbol is explicitly referenced.  Since portable code cannot
+  # rely on this symbol name, it's probably fine to never include it in
+  # preloaded symbol tables.
+  extract_expsyms_cmds=
 
   case $host_os in
-  cygwin* | mingw* | pw32* | os2*)
-    cat <<'EOF' >> "${ofile}T"
-      # This is a source program that is used to create dlls on Windows
-      # Don't remove nor modify the starting and closing comments
-# /* ltdll.c starts here */
-# #define WIN32_LEAN_AND_MEAN
-# #include <windows.h>
-# #undef WIN32_LEAN_AND_MEAN
-# #include <stdio.h>
-#
-# #ifndef __CYGWIN__
-# #  ifdef __CYGWIN32__
-# #    define __CYGWIN__ __CYGWIN32__
-# #  endif
-# #endif
-#
-# #ifdef __cplusplus
-# extern "C" {
-# #endif
-# BOOL APIENTRY DllMain (HINSTANCE hInst, DWORD reason, LPVOID reserved);
-# #ifdef __cplusplus
-# }
-# #endif
-#
-# #ifdef __CYGWIN__
-# #include <cygwin/cygwin_dll.h>
-# DECLARE_CYGWIN_DLL( DllMain );
-# #endif
-# HINSTANCE __hDllInstance_base;
-#
-# BOOL APIENTRY
-# DllMain (HINSTANCE hInst, DWORD reason, LPVOID reserved)
-# {
-#   __hDllInstance_base = hInst;
-#   return TRUE;
-# }
-# /* ltdll.c ends here */
-	# This is a source program that is used to create import libraries
-	# on Windows for dlls which lack them. Don't remove nor modify the
-	# starting and closing comments
-# /* impgen.c starts here */
-# /*   Copyright (C) 1999-2000 Free Software Foundation, Inc.
-#
-#  This file is part of GNU libtool.
-#
-#  This program is free software; you can redistribute it and/or modify
-#  it under the terms of the GNU General Public License as published by
-#  the Free Software Foundation; either version 2 of the License, or
-#  (at your option) any later version.
-#
-#  This program is distributed in the hope that it will be useful,
-#  but WITHOUT ANY WARRANTY; without even the implied warranty of
-#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-#  GNU General Public License for more details.
-#
-#  You should have received a copy of the GNU General Public License
-#  along with this program; if not, write to the Free Software
-#  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
-#  */
-#
-# #include <stdio.h>		/* for printf() */
-# #include <unistd.h>		/* for open(), lseek(), read() */
-# #include <fcntl.h>		/* for O_RDONLY, O_BINARY */
-# #include <string.h>		/* for strdup() */
-#
-# /* O_BINARY isn't required (or even defined sometimes) under Unix */
-# #ifndef O_BINARY
-# #define O_BINARY 0
-# #endif
-#
-# static unsigned int
-# pe_get16 (fd, offset)
-#      int fd;
-#      int offset;
-# {
-#   unsigned char b[2];
-#   lseek (fd, offset, SEEK_SET);
-#   read (fd, b, 2);
-#   return b[0] + (b[1]<<8);
-# }
-#
-# static unsigned int
-# pe_get32 (fd, offset)
-#     int fd;
-#     int offset;
-# {
-#   unsigned char b[4];
-#   lseek (fd, offset, SEEK_SET);
-#   read (fd, b, 4);
-#   return b[0] + (b[1]<<8) + (b[2]<<16) + (b[3]<<24);
-# }
-#
-# static unsigned int
-# pe_as32 (ptr)
-#      void *ptr;
-# {
-#   unsigned char *b = ptr;
-#   return b[0] + (b[1]<<8) + (b[2]<<16) + (b[3]<<24);
-# }
-#
-# int
-# main (argc, argv)
-#     int argc;
-#     char *argv[];
-# {
-#     int dll;
-#     unsigned long pe_header_offset, opthdr_ofs, num_entries, i;
-#     unsigned long export_rva, export_size, nsections, secptr, expptr;
-#     unsigned long name_rvas, nexp;
-#     unsigned char *expdata, *erva;
-#     char *filename, *dll_name;
-#
-#     filename = argv[1];
-#
-#     dll = open(filename, O_RDONLY|O_BINARY);
-#     if (dll < 1)
-# 	return 1;
-#
-#     dll_name = filename;
-#
-#     for (i=0; filename[i]; i++)
-# 	if (filename[i] == '/' || filename[i] == '\\'  || filename[i] == ':')
-# 	    dll_name = filename + i +1;
-#
-#     pe_header_offset = pe_get32 (dll, 0x3c);
-#     opthdr_ofs = pe_header_offset + 4 + 20;
-#     num_entries = pe_get32 (dll, opthdr_ofs + 92);
-#
-#     if (num_entries < 1) /* no exports */
-# 	return 1;
-#
-#     export_rva = pe_get32 (dll, opthdr_ofs + 96);
-#     export_size = pe_get32 (dll, opthdr_ofs + 100);
-#     nsections = pe_get16 (dll, pe_header_offset + 4 +2);
-#     secptr = (pe_header_offset + 4 + 20 +
-# 	      pe_get16 (dll, pe_header_offset + 4 + 16));
-#
-#     expptr = 0;
-#     for (i = 0; i < nsections; i++)
-#     {
-# 	char sname[8];
-# 	unsigned long secptr1 = secptr + 40 * i;
-# 	unsigned long vaddr = pe_get32 (dll, secptr1 + 12);
-# 	unsigned long vsize = pe_get32 (dll, secptr1 + 16);
-# 	unsigned long fptr = pe_get32 (dll, secptr1 + 20);
-# 	lseek(dll, secptr1, SEEK_SET);
-# 	read(dll, sname, 8);
-# 	if (vaddr <= export_rva && vaddr+vsize > export_rva)
-# 	{
-# 	    expptr = fptr + (export_rva - vaddr);
-# 	    if (export_rva + export_size > vaddr + vsize)
-# 		export_size = vsize - (export_rva - vaddr);
-# 	    break;
-# 	}
-#     }
-#
-#     expdata = (unsigned char*)malloc(export_size);
-#     lseek (dll, expptr, SEEK_SET);
-#     read (dll, expdata, export_size);
-#     erva = expdata - export_rva;
-#
-#     nexp = pe_as32 (expdata+24);
-#     name_rvas = pe_as32 (expdata+32);
-#
-#     printf ("EXPORTS\n");
-#     for (i = 0; i<nexp; i++)
-#     {
-# 	unsigned long name_rva = pe_as32 (erva+name_rvas+i*4);
-# 	printf ("\t%s @ %ld ;\n", erva+name_rva, 1+ i);
-#     }
-#
-#     return 0;
-# }
-# /* impgen.c ends here */
-
-EOF
+  cygwin* | mingw* | pw32*)
+    # FIXME: the MSVC++ port hasn't been tested in a loooong time
+    # When not using gcc, we currently assume that we are using
+    # Microsoft Visual C++.
+    if test "$GCC" != yes; then
+      with_gnu_ld=no
+    fi
+    ;;
+  openbsd*)
+    with_gnu_ld=no
     ;;
   esac
 
-  # We use sed instead of cat because bash on DJGPP gets confused if
-  # if finds mixed CR/LF and LF-only lines.  Since sed operates in
-  # text mode, it properly converts lines to CR/LF.  This bash problem
-  # is reportedly fixed, but why not run on old versions too?
-  sed '$q' "$ltmain" >> "${ofile}T" || (rm -f "${ofile}T"; exit 1)
-
-  mv -f "${ofile}T" "$ofile" || \
-    (rm -f "$ofile" && cp "${ofile}T" "$ofile" && rm -f "${ofile}T")
-  chmod +x "$ofile"
-fi
-##
-## END FIXME
-
-])# _LT_AC_LTCONFIG_HACK
+  _LT_AC_TAGVAR(ld_shlibs, $1)=yes
+  if test "$with_gnu_ld" = yes; then
+    # If archive_cmds runs LD, not CC, wlarc should be empty
+    wlarc='${wl}'
 
-# AC_LIBTOOL_DLOPEN - enable checks for dlopen support
-AC_DEFUN([AC_LIBTOOL_DLOPEN], [AC_BEFORE([$0],[AC_LIBTOOL_SETUP])])
+    # See if GNU ld supports shared libraries.
+    case $host_os in
+    aix3* | aix4* | aix5*)
+      # On AIX/PPC, the GNU linker is very broken
+      if test "$host_cpu" != ia64; then
+	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+	cat <<EOF 1>&2
 
-# AC_LIBTOOL_WIN32_DLL - declare package support for building win32 dll's
-AC_DEFUN([AC_LIBTOOL_WIN32_DLL], [AC_BEFORE([$0], [AC_LIBTOOL_SETUP])])
+*** Warning: the GNU linker, at least up to release 2.9.1, is reported
+*** to be unable to reliably create shared libraries on AIX.
+*** Therefore, libtool is disabling shared libraries support.  If you
+*** really care for shared libraries, you may want to modify your PATH
+*** so that a non-GNU linker is found, and then restart.
 
-# AC_ENABLE_SHARED - implement the --enable-shared flag
-# Usage: AC_ENABLE_SHARED[(DEFAULT)]
-#   Where DEFAULT is either `yes' or `no'.  If omitted, it defaults to
-#   `yes'.
-AC_DEFUN([AC_ENABLE_SHARED],
-[define([AC_ENABLE_SHARED_DEFAULT], ifelse($1, no, no, yes))dnl
-AC_ARG_ENABLE(shared,
-changequote(<<, >>)dnl
-<<  --enable-shared[=PKGS]  build shared libraries [default=>>AC_ENABLE_SHARED_DEFAULT],
-changequote([, ])dnl
-[p=${PACKAGE-default}
-case $enableval in
-yes) enable_shared=yes ;;
-no) enable_shared=no ;;
-*)
-  enable_shared=no
-  # Look at the argument we got.  We use all the common list separators.
-  IFS="${IFS= 	}"; ac_save_ifs="$IFS"; IFS="${IFS}:,"
-  for pkg in $enableval; do
-    if test "X$pkg" = "X$p"; then
-      enable_shared=yes
-    fi
-  done
-  IFS="$ac_save_ifs"
-  ;;
-esac],
-enable_shared=AC_ENABLE_SHARED_DEFAULT)dnl
-])
+EOF
+      fi
+      ;;
 
-# AC_DISABLE_SHARED - set the default shared flag to --disable-shared
-AC_DEFUN([AC_DISABLE_SHARED],
-[AC_BEFORE([$0],[AC_LIBTOOL_SETUP])dnl
-AC_ENABLE_SHARED(no)])
+    amigaos*)
+      _LT_AC_TAGVAR(archive_cmds, $1)='$rm $output_objdir/a2ixlibrary.data~$echo "#define NAME $libname" > $output_objdir/a2ixlibrary.data~$echo "#define LIBRARY_ID 1" >> $output_objdir/a2ixlibrary.data~$echo "#define VERSION $major" >> $output_objdir/a2ixlibrary.data~$echo "#define REVISION $revision" >> $output_objdir/a2ixlibrary.data~$AR $AR_FLAGS $lib $libobjs~$RANLIB $lib~(cd $output_objdir && a2ixlibrary -32)'
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
+
+      # Samuel A. Falvo II <kc5tja@dolphin.openprojects.net> reports
+      # that the semantics of dynamic libraries on AmigaOS, at least up
+      # to version 4, is to share data among multiple programs linked
+      # with the same dynamic library.  Since this doesn't match the
+      # behavior of shared libraries on other platforms, we can't use
+      # them.
+      _LT_AC_TAGVAR(ld_shlibs, $1)=no
+      ;;
 
-# AC_ENABLE_STATIC - implement the --enable-static flag
-# Usage: AC_ENABLE_STATIC[(DEFAULT)]
-#   Where DEFAULT is either `yes' or `no'.  If omitted, it defaults to
-#   `yes'.
-AC_DEFUN([AC_ENABLE_STATIC],
-[define([AC_ENABLE_STATIC_DEFAULT], ifelse($1, no, no, yes))dnl
-AC_ARG_ENABLE(static,
-changequote(<<, >>)dnl
-<<  --enable-static[=PKGS]  build static libraries [default=>>AC_ENABLE_STATIC_DEFAULT],
-changequote([, ])dnl
-[p=${PACKAGE-default}
-case $enableval in
-yes) enable_static=yes ;;
-no) enable_static=no ;;
-*)
-  enable_static=no
-  # Look at the argument we got.  We use all the common list separators.
-  IFS="${IFS= 	}"; ac_save_ifs="$IFS"; IFS="${IFS}:,"
-  for pkg in $enableval; do
-    if test "X$pkg" = "X$p"; then
-      enable_static=yes
-    fi
-  done
-  IFS="$ac_save_ifs"
-  ;;
-esac],
-enable_static=AC_ENABLE_STATIC_DEFAULT)dnl
-])
+    beos*)
+      if $LD --help 2>&1 | grep ': supported targets:.* elf' > /dev/null; then
+	_LT_AC_TAGVAR(allow_undefined_flag, $1)=unsupported
+	# Joseph Beckenbach <jrb3@best.com> says some releases of gcc
+	# support --undefined.  This deserves some investigation.  FIXME
+	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -nostart $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+      else
+	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+      fi
+      ;;
 
-# AC_DISABLE_STATIC - set the default static flag to --disable-static
-AC_DEFUN([AC_DISABLE_STATIC],
-[AC_BEFORE([$0],[AC_LIBTOOL_SETUP])dnl
-AC_ENABLE_STATIC(no)])
+    cygwin* | mingw* | pw32*)
+      # _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1) is actually meaningless,
+      # as there is no search path for DLLs.
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+      _LT_AC_TAGVAR(allow_undefined_flag, $1)=unsupported
+      _LT_AC_TAGVAR(always_export_symbols, $1)=no
+      _LT_AC_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
+      _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM $libobjs $convenience | $global_symbol_pipe | $SED -e '\''/^[[BCDGS]] /s/.* \([[^ ]]*\)/\1 DATA/'\'' | $SED -e '\''/^[[AITW]] /s/.* //'\'' | sort | uniq > $export_symbols'
+
+      if $LD --help 2>&1 | grep 'auto-import' > /dev/null; then
+        _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags -o $output_objdir/$soname ${wl}--image-base=0x10000000 ${wl}--out-implib,$lib'
+	# If the export-symbols file already is a .def file (1st line
+	# is EXPORTS), use it as is; otherwise, prepend...
+	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='if test "x`$SED 1q $export_symbols`" = xEXPORTS; then
+	  cp $export_symbols $output_objdir/$soname.def;
+	else
+	  echo EXPORTS > $output_objdir/$soname.def;
+	  cat $export_symbols >> $output_objdir/$soname.def;
+	fi~
+	$CC -shared $output_objdir/$soname.def $libobjs $deplibs $compiler_flags -o $output_objdir/$soname ${wl}--image-base=0x10000000  ${wl}--out-implib,$lib'
+      else
+	ld_shlibs=no
+      fi
+      ;;
 
+    netbsd*)
+      if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
+	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable $libobjs $deplibs $linker_flags -o $lib'
+	wlarc=
+      else
+	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      fi
+      ;;
 
-# AC_ENABLE_FAST_INSTALL - implement the --enable-fast-install flag
-# Usage: AC_ENABLE_FAST_INSTALL[(DEFAULT)]
-#   Where DEFAULT is either `yes' or `no'.  If omitted, it defaults to
-#   `yes'.
-AC_DEFUN([AC_ENABLE_FAST_INSTALL],
-[define([AC_ENABLE_FAST_INSTALL_DEFAULT], ifelse($1, no, no, yes))dnl
-AC_ARG_ENABLE(fast-install,
-changequote(<<, >>)dnl
-<<  --enable-fast-install[=PKGS]  optimize for fast installation [default=>>AC_ENABLE_FAST_INSTALL_DEFAULT],
-changequote([, ])dnl
-[p=${PACKAGE-default}
-case $enableval in
-yes) enable_fast_install=yes ;;
-no) enable_fast_install=no ;;
-*)
-  enable_fast_install=no
-  # Look at the argument we got.  We use all the common list separators.
-  IFS="${IFS= 	}"; ac_save_ifs="$IFS"; IFS="${IFS}:,"
-  for pkg in $enableval; do
-    if test "X$pkg" = "X$p"; then
-      enable_fast_install=yes
-    fi
-  done
-  IFS="$ac_save_ifs"
-  ;;
-esac],
-enable_fast_install=AC_ENABLE_FAST_INSTALL_DEFAULT)dnl
-])
+    solaris* | sysv5*)
+      if $LD -v 2>&1 | grep 'BFD 2\.8' > /dev/null; then
+	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+	cat <<EOF 1>&2
 
-# AC_DISABLE_FAST_INSTALL - set the default to --disable-fast-install
-AC_DEFUN([AC_DISABLE_FAST_INSTALL],
-[AC_BEFORE([$0],[AC_LIBTOOL_SETUP])dnl
-AC_ENABLE_FAST_INSTALL(no)])
+*** Warning: The releases 2.8.* of the GNU linker cannot reliably
+*** create shared libraries on Solaris systems.  Therefore, libtool
+*** is disabling shared libraries support.  We urge you to upgrade GNU
+*** binutils to release 2.9.1 or newer.  Another option is to modify
+*** your PATH or compiler configuration so that the native linker is
+*** used, and then restart.
 
-# AC_LIBTOOL_PICMODE - implement the --with-pic flag
-# Usage: AC_LIBTOOL_PICMODE[(MODE)]
-#   Where MODE is either `yes' or `no'.  If omitted, it defaults to
-#   `both'.
-AC_DEFUN([AC_LIBTOOL_PICMODE],
-[AC_BEFORE([$0],[AC_LIBTOOL_SETUP])dnl
-pic_mode=ifelse($#,1,$1,default)])
+EOF
+      elif $LD --help 2>&1 | grep ': supported targets:.* elf' > /dev/null; then
+	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      else
+	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+      fi
+      ;;
 
+    sunos4*)
+      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -assert pure-text -Bshareable -o $lib $libobjs $deplibs $linker_flags'
+      wlarc=
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-# AC_PATH_TOOL_PREFIX - find a file program which can recognise shared library
-AC_DEFUN([AC_PATH_TOOL_PREFIX],
-[AC_MSG_CHECKING([for $1])
-AC_CACHE_VAL(lt_cv_path_MAGIC_CMD,
-[case $MAGIC_CMD in
-  /*)
-  lt_cv_path_MAGIC_CMD="$MAGIC_CMD" # Let the user override the test with a path.
-  ;;
-  ?:/*)
-  lt_cv_path_MAGIC_CMD="$MAGIC_CMD" # Let the user override the test with a dos path.
-  ;;
-  *)
-  ac_save_MAGIC_CMD="$MAGIC_CMD"
-  IFS="${IFS=   }"; ac_save_ifs="$IFS"; IFS=":"
-dnl $ac_dummy forces splitting on constant user-supplied paths.
-dnl POSIX.2 word splitting is done only on the output of word expansions,
-dnl not every word.  This closes a longstanding sh security hole.
-  ac_dummy="ifelse([$2], , $PATH, [$2])"
-  for ac_dir in $ac_dummy; do
-    test -z "$ac_dir" && ac_dir=.
-    if test -f $ac_dir/$1; then
-      lt_cv_path_MAGIC_CMD="$ac_dir/$1"
-      if test -n "$file_magic_test_file"; then
-	case $deplibs_check_method in
-	"file_magic "*)
-	  file_magic_regex="`expr \"$deplibs_check_method\" : \"file_magic \(.*\)\"`"
-	  MAGIC_CMD="$lt_cv_path_MAGIC_CMD"
-	  if eval $file_magic_cmd \$file_magic_test_file 2> /dev/null |
-	    egrep "$file_magic_regex" > /dev/null; then
-	    :
-	  else
-	    cat <<EOF 1>&2
+    *)
+      if $LD --help 2>&1 | grep ': supported targets:.* elf' > /dev/null; then
+	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      else
+	_LT_AC_TAGVAR(ld_shlibs, $1)=no
+      fi
+      ;;
+    esac
 
-*** Warning: the command libtool uses to detect shared libraries,
-*** $file_magic_cmd, produces output that libtool cannot recognize.
-*** The result is that libtool may fail to recognize shared libraries
-*** as such.  This will affect the creation of libtool libraries that
-*** depend on shared libraries, but programs linked with such libtool
-*** libraries will work regardless of this problem.  Nevertheless, you
-*** may want to report the problem to your system manager and/or to
-*** bug-libtool@gnu.org
+    if test "$_LT_AC_TAGVAR(ld_shlibs, $1)" = yes; then
+      runpath_var=LD_RUN_PATH
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}--rpath ${wl}$libdir'
+      _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}--export-dynamic'
+      # ancient GNU ld didn't support --whole-archive et. al.
+      if $LD --help 2>&1 | grep 'no-whole-archive' > /dev/null; then
+ 	_LT_AC_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
+      else
+  	_LT_AC_TAGVAR(whole_archive_flag_spec, $1)=
+      fi
+    fi
+  else
+    # PORTME fill in a description of your system's linker (not GNU ld)
+    case $host_os in
+    aix3*)
+      _LT_AC_TAGVAR(allow_undefined_flag, $1)=unsupported
+      _LT_AC_TAGVAR(always_export_symbols, $1)=yes
+      _LT_AC_TAGVAR(archive_expsym_cmds, $1)='$LD -o $output_objdir/$soname $libobjs $deplibs $linker_flags -bE:$export_symbols -T512 -H512 -bM:SRE~$AR $AR_FLAGS $lib $output_objdir/$soname'
+      # Note: this linker hardcodes the directories in LIBPATH if there
+      # are no directories specified by -L.
+      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
+      if test "$GCC" = yes && test -z "$link_static_flag"; then
+	# Neither direct hardcoding nor static linking is supported with a
+	# broken collect2.
+	_LT_AC_TAGVAR(hardcode_direct, $1)=unsupported
+      fi
+      ;;
 
-EOF
-	  fi ;;
+    aix4* | aix5*)
+      if test "$host_cpu" = ia64; then
+	# On IA64, the linker does run time linking by default, so we don't
+	# have to do anything special.
+	aix_use_runtimelinking=no
+	exp_sym_flag='-Bexport'
+	no_entry_flag=""
+      else
+	# If we're using GNU nm, then we don't want the "-C" option.
+	# -C means demangle to AIX nm, but means don't demangle with GNU nm
+	if $NM -V 2>&1 | grep 'GNU' > /dev/null; then
+	  _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM -Bpg $libobjs $convenience | awk '\''{ if (((\[$]2 == "T") || (\[$]2 == "D") || (\[$]2 == "B")) && ([substr](\[$]3,1,1) != ".")) { print \[$]3 } }'\'' | sort -u > $export_symbols'
+	else
+	  _LT_AC_TAGVAR(export_symbols_cmds, $1)='$NM -BCpg $libobjs $convenience | awk '\''{ if (((\[$]2 == "T") || (\[$]2 == "D") || (\[$]2 == "B")) && ([substr](\[$]3,1,1) != ".")) { print \[$]3 } }'\'' | sort -u > $export_symbols'
+	fi
+	aix_use_runtimelinking=no
+
+	# Test if we are trying to use run time linking or normal
+	# AIX style linking. If -brtl is somewhere in LDFLAGS, we
+	# need to do runtime linking.
+	case $host_os in aix4.[[23]]|aix4.[[23]].*|aix5*)
+	  for ld_flag in $LDFLAGS; do
+  	  if (test $ld_flag = "-brtl" || test $ld_flag = "-Wl,-brtl"); then
+  	    aix_use_runtimelinking=yes
+  	    break
+  	  fi
+	  done
 	esac
+
+	exp_sym_flag='-bexport'
+	no_entry_flag='-bnoentry'
       fi
-      break
-    fi
-  done
-  IFS="$ac_save_ifs"
-  MAGIC_CMD="$ac_save_MAGIC_CMD"
-  ;;
-esac])
-MAGIC_CMD="$lt_cv_path_MAGIC_CMD"
-if test -n "$MAGIC_CMD"; then
-  AC_MSG_RESULT($MAGIC_CMD)
-else
-  AC_MSG_RESULT(no)
-fi
-])
 
+      # When large executables or shared objects are built, AIX ld can
+      # have problems creating the table of contents.  If linking a library
+      # or program results in "error TOC overflow" add -mminimal-toc to
+      # CXXFLAGS/CFLAGS for g++/gcc.  In the cases where that is not
+      # enough to fix the problem, add -Wl,-bbigtoc to LDFLAGS.
+
+      _LT_AC_TAGVAR(archive_cmds, $1)=''
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=':'
+      _LT_AC_TAGVAR(link_all_deplibs, $1)=yes
+
+      if test "$GCC" = yes; then
+	case $host_os in aix4.[012]|aix4.[012].*)
+	# We only want to do this on AIX 4.2 and lower, the check
+	# below for broken collect2 doesn't work under 4.3+
+	  collect2name=`${CC} -print-prog-name=collect2`
+	  if test -f "$collect2name" && \
+  	   strings "$collect2name" | grep resolve_lib_name >/dev/null
+	  then
+  	  # We have reworked collect2
+  	  _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+	  else
+  	  # We have old collect2
+  	  _LT_AC_TAGVAR(hardcode_direct, $1)=unsupported
+  	  # It fails to find uninstalled libraries when the uninstalled
+  	  # path is not listed in the libpath.  Setting hardcode_minus_L
+  	  # to unsupported forces relinking
+  	  _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
+  	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+  	  _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=
+	  fi
+	esac
+	shared_flag='-shared'
+      else
+	# not using gcc
+	if test "$host_cpu" = ia64; then
+  	# VisualAge C++, Version 5.5 for AIX 5L for IA-64, Beta 3 Release
+  	# chokes on -Wl,-G. The following line is correct:
+	  shared_flag='-G'
+	else
+  	if test "$aix_use_runtimelinking" = yes; then
+	    shared_flag='${wl}-G'
+	  else
+	    shared_flag='${wl}-bM:SRE'
+  	fi
+	fi
+      fi
 
-# AC_PATH_MAGIC - find a file program which can recognise a shared library
-AC_DEFUN([AC_PATH_MAGIC],
-[AC_REQUIRE([AC_CHECK_TOOL_PREFIX])dnl
-AC_PATH_TOOL_PREFIX(${ac_tool_prefix}file, /usr/bin:$PATH)
-if test -z "$lt_cv_path_MAGIC_CMD"; then
-  if test -n "$ac_tool_prefix"; then
-    AC_PATH_TOOL_PREFIX(file, /usr/bin:$PATH)
-  else
-    MAGIC_CMD=:
-  fi
-fi
-])
+      # It seems that -bexpall does not export symbols beginning with
+      # underscore (_), so it is better to generate a list of symbols to export.
+      _LT_AC_TAGVAR(always_export_symbols, $1)=yes
+      if test "$aix_use_runtimelinking" = yes; then
+	# Warning - without using the other runtime loading flags (-brtl),
+	# -berok will link without error, but may produce a broken library.
+	_LT_AC_TAGVAR(allow_undefined_flag, $1)='-berok'
+       # Determine the default libpath from the value encoded in an empty executable.
+       _LT_AC_SYS_LIBPATH_AIX
+       _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
+	_LT_AC_TAGVAR(archive_expsym_cmds, $1)="\$CC"' -o $output_objdir/$soname $libobjs $deplibs $compiler_flags `if test "x${allow_undefined_flag}" != "x"; then echo "${wl}${allow_undefined_flag}"; else :; fi` '"\${wl}$no_entry_flag \${wl}$exp_sym_flag:\$export_symbols $shared_flag"
+       else
+	if test "$host_cpu" = ia64; then
+	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $libdir:/usr/lib:/lib'
+	  _LT_AC_TAGVAR(allow_undefined_flag, $1)="-z nodefs"
+	  _LT_AC_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs $compiler_flags ${wl}${allow_undefined_flag} '"\${wl}$no_entry_flag \${wl}$exp_sym_flag:\$export_symbols"
+	else
+	 # Determine the default libpath from the value encoded in an empty executable.
+	 _LT_AC_SYS_LIBPATH_AIX
+	 _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-blibpath:$libdir:'"$aix_libpath"
+	  # Warning - without using the other run time loading flags,
+	  # -berok will link without error, but may produce a broken library.
+	  _LT_AC_TAGVAR(no_undefined_flag, $1)=' ${wl}-bernotok'
+	  _LT_AC_TAGVAR(allow_undefined_flag, $1)=' ${wl}-berok'
+	  # -bexpall does not export symbols beginning with underscore (_)
+	  _LT_AC_TAGVAR(always_export_symbols, $1)=yes
+	  # Exported symbols can be pulled into shared objects from archives
+	  _LT_AC_TAGVAR(whole_archive_flag_spec, $1)=' '
+	  _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=yes
+	  # This is similar to how AIX traditionally builds it's shared libraries.
+	  _LT_AC_TAGVAR(archive_expsym_cmds, $1)="\$CC $shared_flag"' -o $output_objdir/$soname $libobjs $deplibs $compiler_flags ${wl}-bE:$export_symbols ${wl}-bnoentry${allow_undefined_flag}~$AR $AR_FLAGS $output_objdir/$libname$release.a $output_objdir/$soname'
+	fi
+      fi
+      ;;
 
+    amigaos*)
+      _LT_AC_TAGVAR(archive_cmds, $1)='$rm $output_objdir/a2ixlibrary.data~$echo "#define NAME $libname" > $output_objdir/a2ixlibrary.data~$echo "#define LIBRARY_ID 1" >> $output_objdir/a2ixlibrary.data~$echo "#define VERSION $major" >> $output_objdir/a2ixlibrary.data~$echo "#define REVISION $revision" >> $output_objdir/a2ixlibrary.data~$AR $AR_FLAGS $lib $libobjs~$RANLIB $lib~(cd $output_objdir && a2ixlibrary -32)'
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
+      # see comment about different semantics on the GNU ld section
+      _LT_AC_TAGVAR(ld_shlibs, $1)=no
+      ;;
 
-# AC_PROG_LD - find the path to the GNU or non-GNU linker
-AC_DEFUN([AC_PROG_LD],
-[AC_ARG_WITH(gnu-ld,
-[  --with-gnu-ld           assume the C compiler uses GNU ld [default=no]],
-test "$withval" = no || with_gnu_ld=yes, with_gnu_ld=no)
-AC_REQUIRE([AC_PROG_CC])dnl
-AC_REQUIRE([AC_CANONICAL_HOST])dnl
-AC_REQUIRE([AC_CANONICAL_BUILD])dnl
-AC_REQUIRE([_LT_AC_LIBTOOL_SYS_PATH_SEPARATOR])dnl
-ac_prog=ld
-if test "$GCC" = yes; then
-  # Check if gcc -print-prog-name=ld gives a path.
-  AC_MSG_CHECKING([for ld used by GCC])
-  case $host in
-  *-*-mingw*)
-    # gcc leaves a trailing carriage return which upsets mingw
-    ac_prog=`($CC -print-prog-name=ld) 2>&5 | tr -d '\015'` ;;
-  *)
-    ac_prog=`($CC -print-prog-name=ld) 2>&5` ;;
-  esac
-  case $ac_prog in
-    # Accept absolute paths.
-    [[\\/]]* | [[A-Za-z]]:[[\\/]]*)
-      re_direlt='/[[^/]][[^/]]*/\.\./'
-      # Canonicalize the path of ld
-      ac_prog=`echo $ac_prog| sed 's%\\\\%/%g'`
-      while echo $ac_prog | grep "$re_direlt" > /dev/null 2>&1; do
-	ac_prog=`echo $ac_prog| sed "s%$re_direlt%/%"`
-      done
-      test -z "$LD" && LD="$ac_prog"
+    bsdi4*)
+      _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)=-rdynamic
       ;;
-  "")
-    # If it fails, then pretend we aren't using GCC.
-    ac_prog=ld
-    ;;
-  *)
-    # If it is relative, then search for the first ld in PATH.
-    with_gnu_ld=unknown
-    ;;
-  esac
-elif test "$with_gnu_ld" = yes; then
-  AC_MSG_CHECKING([for GNU ld])
-else
-  AC_MSG_CHECKING([for non-GNU ld])
-fi
-AC_CACHE_VAL(lt_cv_path_LD,
-[if test -z "$LD"; then
-  IFS="${IFS= 	}"; ac_save_ifs="$IFS"; IFS=$PATH_SEPARATOR
-  for ac_dir in $PATH; do
-    test -z "$ac_dir" && ac_dir=.
-    if test -f "$ac_dir/$ac_prog" || test -f "$ac_dir/$ac_prog$ac_exeext"; then
-      lt_cv_path_LD="$ac_dir/$ac_prog"
-      # Check to see if the program is GNU ld.  I'd rather use --version,
-      # but apparently some GNU ld's only accept -v.
-      # Break only if it was the GNU/non-GNU ld that we prefer.
-      if "$lt_cv_path_LD" -v 2>&1 < /dev/null | egrep '(GNU|with BFD)' > /dev/null; then
-	test "$with_gnu_ld" != no && break
-      else
-	test "$with_gnu_ld" != yes && break
-      fi
-    fi
-  done
-  IFS="$ac_save_ifs"
-else
-  lt_cv_path_LD="$LD" # Let the user override the test with a path.
-fi])
-LD="$lt_cv_path_LD"
-if test -n "$LD"; then
-  AC_MSG_RESULT($LD)
-else
-  AC_MSG_RESULT(no)
-fi
-test -z "$LD" && AC_MSG_ERROR([no acceptable ld found in \$PATH])
-AC_PROG_LD_GNU
-])
 
-# AC_PROG_LD_GNU -
-AC_DEFUN([AC_PROG_LD_GNU],
-[AC_CACHE_CHECK([if the linker ($LD) is GNU ld], lt_cv_prog_gnu_ld,
-[# I'd rather use --version here, but apparently some GNU ld's only accept -v.
-if $LD -v 2>&1 </dev/null | egrep '(GNU|with BFD)' 1>&5; then
-  lt_cv_prog_gnu_ld=yes
-else
-  lt_cv_prog_gnu_ld=no
-fi])
-with_gnu_ld=$lt_cv_prog_gnu_ld
-])
+    cygwin* | mingw* | pw32*)
+      # When not using gcc, we currently assume that we are using
+      # Microsoft Visual C++.
+      # hardcode_libdir_flag_spec is actually meaningless, as there is
+      # no search path for DLLs.
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)=' '
+      _LT_AC_TAGVAR(allow_undefined_flag, $1)=unsupported
+      # Tell ltmain to make .lib files, not .a files.
+      libext=lib
+      # Tell ltmain to make .dll files, not .so files.
+      shrext=".dll"
+      # FIXME: Setting linknames here is a bad hack.
+      _LT_AC_TAGVAR(archive_cmds, $1)='$CC -o $lib $libobjs $compiler_flags `echo "$deplibs" | $SED -e '\''s/ -lc$//'\''` -link -dll~linknames='
+      # The linker will automatically build a .lib file if we build a DLL.
+      _LT_AC_TAGVAR(old_archive_From_new_cmds, $1)='true'
+      # FIXME: Should let the user specify the lib program.
+      _LT_AC_TAGVAR(old_archive_cmds, $1)='lib /OUT:$oldlib$oldobjs$old_deplibs'
+      fix_srcfile_path='`cygpath -w "$srcfile"`'
+      _LT_AC_TAGVAR(enable_shared_with_static_runtimes, $1)=yes
+      ;;
 
-# AC_PROG_LD_RELOAD_FLAG - find reload flag for linker
-#   -- PORTME Some linkers may need a different reload flag.
-AC_DEFUN([AC_PROG_LD_RELOAD_FLAG],
-[AC_CACHE_CHECK([for $LD option to reload object files], lt_cv_ld_reload_flag,
-[lt_cv_ld_reload_flag='-r'])
-reload_flag=$lt_cv_ld_reload_flag
-test -n "$reload_flag" && reload_flag=" $reload_flag"
-])
+    darwin* | rhapsody*)
+    if $CC -v 2>&1 | grep 'Apple' >/dev/null ; then 
+      _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
+      case "$host_os" in
+      rhapsody* | darwin1.[[012]])
+	_LT_AC_TAGVAR(allow_undefined_flag, $1)='-undefined suppress'
+	;;
+      *) # Darwin 1.3 on
+	test -z ${LD_TWOLEVEL_NAMESPACE} && _LT_AC_TAGVAR(allow_undefined_flag, $1)='-flat_namespace -undefined suppress'
+	;;
+      esac
+      # FIXME: Relying on posixy $() will cause problems for
+      #        cross-compilation, but unfortunately the echo tests do not
+      #        yet detect zsh echo's removal of \ escapes.  Also zsh mangles
+      #	       `"' quotes if we put them in here... so don't!
+    	lt_int_apple_cc_single_mod=no
+    	output_verbose_link_cmd='echo'
+    	if $CC -dumpspecs 2>&1 | grep 'single_module' >/dev/null ; then
+    	  lt_int_apple_cc_single_mod=yes
+    	fi
+    	if test "X$lt_int_apple_cc_single_mod" = Xyes ; then
+    	  _LT_AC_TAGVAR(archive_cmds, $1)='$CC -dynamiclib -single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags -install_name $rpath/$soname $verstring'
+    	else
+        _LT_AC_TAGVAR(archive_cmds, $1)='$CC -r ${wl}-bind_at_load -keep_private_externs -nostdlib -o ${lib}-master.o $libobjs~$CC -dynamiclib $allow_undefined_flag -o $lib ${lib}-master.o $deplibs $compiler_flags -install_name $rpath/$soname $verstring'
+      fi
+      _LT_AC_TAGVAR(module_cmds, $1)='$CC -bundle ${wl}-bind_at_load $allow_undefined_flag -o $lib $libobjs $deplibs$compiler_flags'
+      # Don't fix this by using the ld -exported_symbols_list flag, it doesn't exist in older darwin ld's
+        if test "X$lt_int_apple_cc_single_mod" = Xyes ; then
+          _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -dynamiclib -single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags -install_name $rpath/$soname $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
+        else
+          _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -r ${wl}-bind_at_load -keep_private_externs -nostdlib -o ${lib}-master.o $libobjs~$CC -dynamiclib $allow_undefined_flag -o $lib ${lib}-master.o $deplibs $compiler_flags -install_name $rpath/$soname $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
+        fi
+          _LT_AC_TAGVAR(module_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -bundle $allow_undefined_flag  -o $lib $libobjs $deplibs$compiler_flags~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
+      _LT_AC_TAGVAR(hardcode_direct, $1)=no
+      _LT_AC_TAGVAR(hardcode_automatic, $1)=yes
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=unsupported
+      _LT_AC_TAGVAR(whole_archive_flag_spec, $1)='-all_load $convenience'
+      _LT_AC_TAGVAR(link_all_deplibs, $1)=yes
+    fi  
+      ;;
 
-# AC_DEPLIBS_CHECK_METHOD - how to check for library dependencies
-#  -- PORTME fill in with the dynamic library characteristics
-AC_DEFUN([AC_DEPLIBS_CHECK_METHOD],
-[AC_CACHE_CHECK([how to recognise dependent libraries],
-lt_cv_deplibs_check_method,
-[lt_cv_file_magic_cmd='$MAGIC_CMD'
-lt_cv_file_magic_test_file=
-lt_cv_deplibs_check_method='unknown'
-# Need to set the preceding variable on all platforms that support
-# interlibrary dependencies.
-# 'none' -- dependencies not supported.
-# `unknown' -- same as none, but documents that we really don't know.
-# 'pass_all' -- all dependencies passed with no checks.
-# 'test_compile' -- check by making test program.
-# 'file_magic [[regex]]' -- check by looking for files in library path
-# which responds to the $file_magic_cmd with a given egrep regex.
-# If you have `file' or equivalent on your system and you're not sure
-# whether `pass_all' will *always* work, you probably want this one.
+    dgux*)
+      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-case $host_os in
-aix4* | aix5*)
-  lt_cv_deplibs_check_method=pass_all
-  ;;
+    freebsd1*)
+      _LT_AC_TAGVAR(ld_shlibs, $1)=no
+      ;;
 
-beos*)
-  lt_cv_deplibs_check_method=pass_all
-  ;;
+    # FreeBSD 2.2.[012] allows us to include c++rt0.o to get C++ constructor
+    # support.  Future versions do this automatically, but an explicit c++rt0.o
+    # does not break anything, and helps significantly (at the cost of a little
+    # extra space).
+    freebsd2.2*)
+      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags /usr/lib/c++rt0.o'
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-bsdi4*)
-  lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[ML]]SB (shared object|dynamic lib)'
-  lt_cv_file_magic_cmd='/usr/bin/file -L'
-  lt_cv_file_magic_test_file=/shlib/libc.so
-  ;;
+    # Unfortunately, older versions of FreeBSD 2 do not have this feature.
+    freebsd2*)
+      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-cygwin* | mingw* | pw32*)
-  lt_cv_deplibs_check_method='file_magic file format pei*-i386(.*architecture: i386)?'
-  lt_cv_file_magic_cmd='$OBJDUMP -f'
-  ;;
+    # FreeBSD 3 and greater uses gcc -shared to do shared libraries.
+    freebsd*)
+      _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -o $lib $libobjs $deplibs $compiler_flags'
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-darwin* | rhapsody*)
-  lt_cv_deplibs_check_method='file_magic Mach-O dynamically linked shared library'
-  lt_cv_file_magic_cmd='/usr/bin/file -L'
-  case "$host_os" in
-  rhapsody* | darwin1.[[012]])
-    lt_cv_file_magic_test_file=`echo /System/Library/Frameworks/System.framework/Versions/*/System | head -1`
-    ;;
-  *) # Darwin 1.3 on
-    lt_cv_file_magic_test_file='/usr/lib/libSystem.dylib'
-    ;;
-  esac
-  ;;
+    hpux9*)
+      if test "$GCC" = yes; then
+	_LT_AC_TAGVAR(archive_cmds, $1)='$rm $output_objdir/$soname~$CC -shared -fPIC ${wl}+b ${wl}$install_libdir -o $output_objdir/$soname $libobjs $deplibs $compiler_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
+      else
+	_LT_AC_TAGVAR(archive_cmds, $1)='$rm $output_objdir/$soname~$LD -b +b $install_libdir -o $output_objdir/$soname $libobjs $deplibs $linker_flags~test $output_objdir/$soname = $lib || mv $output_objdir/$soname $lib'
+      fi
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
+      _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+
+      # hardcode_minus_L: Not really in the search PATH,
+      # but as the default location of the library.
+      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
+      _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+      ;;
 
-freebsd*)
-  if echo __ELF__ | $CC -E - | grep __ELF__ > /dev/null; then
-    case $host_cpu in
-    i*86 )
-      # Not sure whether the presence of OpenBSD here was a mistake.
-      # Let's accept both of them until this is cleared up.
-      lt_cv_deplibs_check_method='file_magic (FreeBSD|OpenBSD)/i[[3-9]]86 (compact )?demand paged shared library'
-      lt_cv_file_magic_cmd=/usr/bin/file
-      lt_cv_file_magic_test_file=`echo /usr/lib/libc.so.*`
+    hpux10* | hpux11*)
+      if test "$GCC" = yes -a "$with_gnu_ld" = no; then
+	case "$host_cpu" in
+	hppa*64*|ia64*)
+	  _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}+h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
+	  ;;
+	*)
+	  _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -fPIC ${wl}+h ${wl}$soname ${wl}+b ${wl}$install_libdir -o $lib $libobjs $deplibs $compiler_flags'
+	  ;;
+	esac
+      else
+	case "$host_cpu" in
+	hppa*64*|ia64*)
+	  _LT_AC_TAGVAR(archive_cmds, $1)='$LD -b +h $soname -o $lib $libobjs $deplibs $linker_flags'
+	  ;;
+	*)
+	  _LT_AC_TAGVAR(archive_cmds, $1)='$LD -b +h $soname +b $install_libdir -o $lib $libobjs $deplibs $linker_flags'
+	  ;;
+	esac
+      fi
+      if test "$with_gnu_ld" = no; then
+	case "$host_cpu" in
+	hppa*64*)
+	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
+	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec_ld, $1)='+b $libdir'
+	  _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
+	  _LT_AC_TAGVAR(hardcode_direct, $1)=no
+	  _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+	  ;;
+	ia64*)
+	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+	  _LT_AC_TAGVAR(hardcode_direct, $1)=no
+	  _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+
+	  # hardcode_minus_L: Not really in the search PATH,
+	  # but as the default location of the library.
+	  _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
+	  ;;
+	*)
+	  _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}+b ${wl}$libdir'
+	  _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
+	  _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+	  _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+
+	  # hardcode_minus_L: Not really in the search PATH,
+	  # but as the default location of the library.
+	  _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
+	  ;;
+	esac
+      fi
       ;;
-    esac
-  else
-    lt_cv_deplibs_check_method=pass_all
-  fi
-  ;;
 
-gnu*)
-  lt_cv_deplibs_check_method=pass_all
-  ;;
+    irix5* | irix6* | nonstopux*)
+      if test "$GCC" = yes; then
+	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
+      else
+	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -shared $libobjs $deplibs $linker_flags -soname $soname `test -n "$verstring" && echo -set_version $verstring` -update_registry ${output_objdir}/so_locations -o $lib'
+	_LT_AC_TAGVAR(hardcode_libdir_flag_spec_ld, $1)='-rpath $libdir'
+      fi
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+      _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
+      _LT_AC_TAGVAR(link_all_deplibs, $1)=yes
+      ;;
 
-hpux10.20*|hpux11*)
-  lt_cv_deplibs_check_method='file_magic (s[[0-9]][[0-9]][[0-9]]|PA-RISC[[0-9]].[[0-9]]) shared library'
-  lt_cv_file_magic_cmd=/usr/bin/file
-  lt_cv_file_magic_test_file=/usr/lib/libc.sl
-  ;;
+    netbsd*)
+      if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
+	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'  # a.out
+      else
+	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -shared -o $lib $libobjs $deplibs $linker_flags'      # ELF
+      fi
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-irix5* | irix6* | nonstopux*)
-  case $host_os in
-  irix5* | nonstopux*)
-    # this will be overridden with pass_all, but let us keep it just in case
-    lt_cv_deplibs_check_method="file_magic ELF 32-bit MSB dynamic lib MIPS - version 1"
-    ;;
-  *)
-    case $LD in
-    *-32|*"-32 ") libmagic=32-bit;;
-    *-n32|*"-n32 ") libmagic=N32;;
-    *-64|*"-64 ") libmagic=64-bit;;
-    *) libmagic=never-match;;
-    esac
-    # this will be overridden with pass_all, but let us keep it just in case
-    lt_cv_deplibs_check_method="file_magic ELF ${libmagic} MSB mips-[[1234]] dynamic lib MIPS - version 1"
-    ;;
-  esac
-  lt_cv_file_magic_test_file=`echo /lib${libsuff}/libc.so*`
-  lt_cv_deplibs_check_method=pass_all
-  ;;
+    newsos6)
+      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+      _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
+
+    openbsd*)
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      if test -z "`echo __ELF__ | $CC -E - | grep __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
+	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags'
+	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	_LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+      else
+       case $host_os in
+	 openbsd[[01]].* | openbsd2.[[0-7]] | openbsd2.[[0-7]].*)
+	   _LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'
+	   _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+	   ;;
+	 *)
+	   _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags'
+	   _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	   ;;
+       esac
+      fi
+      ;;
 
-# This must be Linux ELF.
-linux-gnu*)
-  case $host_cpu in
-  alpha* | hppa* | i*86 | mips | mipsel | powerpc* | sparc* | ia64* | s390* | x86_64*)
-    lt_cv_deplibs_check_method=pass_all ;;
-  *)
-    # glibc up to 2.1.1 does not perform some relocations on ARM
-    lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[LM]]SB (shared object|dynamic lib )' ;;
-  esac
-  lt_cv_file_magic_test_file=`echo /lib/libc.so* /lib/libc-*.so`
-  ;;
+    os2*)
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
+      _LT_AC_TAGVAR(allow_undefined_flag, $1)=unsupported
+      _LT_AC_TAGVAR(archive_cmds, $1)='$echo "LIBRARY $libname INITINSTANCE" > $output_objdir/$libname.def~$echo "DESCRIPTION \"$libname\"" >> $output_objdir/$libname.def~$echo DATA >> $output_objdir/$libname.def~$echo " SINGLE NONSHARED" >> $output_objdir/$libname.def~$echo EXPORTS >> $output_objdir/$libname.def~emxexp $libobjs >> $output_objdir/$libname.def~$CC -Zdll -Zcrtdll -o $lib $libobjs $deplibs $compiler_flags $output_objdir/$libname.def'
+      _LT_AC_TAGVAR(old_archive_From_new_cmds, $1)='emximp -o $output_objdir/$libname.a $output_objdir/$libname.def'
+      ;;
 
-netbsd*)
-  if echo __ELF__ | $CC -E - | grep __ELF__ > /dev/null; then
-    lt_cv_deplibs_check_method='match_pattern /lib[[^/\.]]+\.so\.[[0-9]]+\.[[0-9]]+$'
-  else
-    lt_cv_deplibs_check_method='match_pattern /lib[[^/\.]]+\.so$'
-  fi
-  ;;
+    osf3*)
+      if test "$GCC" = yes; then
+	_LT_AC_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
+	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
+      else
+	_LT_AC_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
+	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -shared${allow_undefined_flag} $libobjs $deplibs $linker_flags -soname $soname `test -n "$verstring" && echo -set_version $verstring` -update_registry ${output_objdir}/so_locations -o $lib'
+      fi
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+      _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
+      ;;
 
-newos6*)
-  lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[ML]]SB (executable|dynamic lib)'
-  lt_cv_file_magic_cmd=/usr/bin/file
-  lt_cv_file_magic_test_file=/usr/lib/libnls.so
-  ;;
+    osf4* | osf5*)	# as osf3* with the addition of -msym flag
+      if test "$GCC" = yes; then
+	_LT_AC_TAGVAR(allow_undefined_flag, $1)=' ${wl}-expect_unresolved ${wl}\*'
+	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared${allow_undefined_flag} $libobjs $deplibs $compiler_flags ${wl}-msym ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
+	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath ${wl}$libdir'
+      else
+	_LT_AC_TAGVAR(allow_undefined_flag, $1)=' -expect_unresolved \*'
+	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -shared${allow_undefined_flag} $libobjs $deplibs $linker_flags -msym -soname $soname `test -n "$verstring" && echo -set_version $verstring` -update_registry ${output_objdir}/so_locations -o $lib'
+	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='for i in `cat $export_symbols`; do printf "%s %s\\n" -exported_symbol "\$i" >> $lib.exp; done; echo "-hidden">> $lib.exp~
+	$LD -shared${allow_undefined_flag} -input $lib.exp $linker_flags $libobjs $deplibs -soname $soname `test -n "$verstring" && echo -set_version $verstring` -update_registry ${objdir}/so_locations -o $lib~$rm $lib.exp'
 
-openbsd*)
-  lt_cv_file_magic_cmd=/usr/bin/file
-  lt_cv_file_magic_test_file=`echo /usr/lib/libc.so.*`
-  if test -z "`echo __ELF__ | $CC -E - | grep __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
-    lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[LM]]SB shared object'
-  else
-    lt_cv_deplibs_check_method='file_magic OpenBSD.* shared library'
-  fi
-  ;;
+	# Both c and cxx compiler support -rpath directly
+	_LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-rpath $libdir'
+      fi
+      _LT_AC_TAGVAR(hardcode_libdir_separator, $1)=:
+      ;;
 
-osf3* | osf4* | osf5*)
-  # this will be overridden with pass_all, but let us keep it just in case
-  lt_cv_deplibs_check_method='file_magic COFF format alpha shared library'
-  lt_cv_file_magic_test_file=/shlib/libc.so
-  lt_cv_deplibs_check_method=pass_all
-  ;;
+    sco3.2v5*)
+      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-Bexport'
+      runpath_var=LD_RUN_PATH
+      hardcode_runpath_var=yes
+      ;;
 
-sco3.2v5*)
-  lt_cv_deplibs_check_method=pass_all
-  ;;
+    solaris*)
+      _LT_AC_TAGVAR(no_undefined_flag, $1)=' -z text'
+      if test "$GCC" = yes; then
+	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
+	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='$echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~$echo "local: *; };" >> $lib.exp~
+	  $CC -shared ${wl}-M ${wl}$lib.exp ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags~$rm $lib.exp'
+      else
+	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -G${allow_undefined_flag} -h $soname -o $lib $libobjs $deplibs $linker_flags'
+	_LT_AC_TAGVAR(archive_expsym_cmds, $1)='$echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~$echo "local: *; };" >> $lib.exp~
+  	$LD -G${allow_undefined_flag} -M $lib.exp -h $soname -o $lib $libobjs $deplibs $linker_flags~$rm $lib.exp'
+      fi
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      case $host_os in
+      solaris2.[[0-5]] | solaris2.[[0-5]].*) ;;
+      *) # Supported since Solaris 2.6 (maybe 2.5.1?)
+	_LT_AC_TAGVAR(whole_archive_flag_spec, $1)='-z allextract$convenience -z defaultextract' ;;
+      esac
+      _LT_AC_TAGVAR(link_all_deplibs, $1)=yes
+      ;;
 
-solaris*)
-  lt_cv_deplibs_check_method=pass_all
-  lt_cv_file_magic_test_file=/lib/libc.so
-  ;;
+    sunos4*)
+      if test "x$host_vendor" = xsequent; then
+	# Use $CC to link under sequent, because it throws in some extra .o
+	# files that make .init and .fini sections work.
+	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h $soname -o $lib $libobjs $deplibs $compiler_flags'
+      else
+	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -assert pure-text -Bstatic -o $lib $libobjs $deplibs $linker_flags'
+      fi
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-sysv5uw[[78]]* | sysv4*uw2*)
-  lt_cv_deplibs_check_method=pass_all
-  ;;
+    sysv4)
+      case $host_vendor in
+	sni)
+	  _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+	  _LT_AC_TAGVAR(hardcode_direct, $1)=yes # is this really true???
+	;;
+	siemens)
+	  ## LD is ld it makes a PLAMLIB
+	  ## CC just makes a GrossModule.
+	  _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -o $lib $libobjs $deplibs $linker_flags'
+	  _LT_AC_TAGVAR(reload_cmds, $1)='$CC -r -o $output$reload_objs'
+	  _LT_AC_TAGVAR(hardcode_direct, $1)=no
+        ;;
+	motorola)
+	  _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+	  _LT_AC_TAGVAR(hardcode_direct, $1)=no #Motorola manual says yes, but my tests say they lie
+	;;
+      esac
+      runpath_var='LD_RUN_PATH'
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
 
-sysv4 | sysv4.2uw2* | sysv4.3* | sysv5*)
-  case $host_vendor in
-  motorola)
-    lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[ML]]SB (shared object|dynamic lib) M[[0-9]][[0-9]]* Version [[0-9]]'
-    lt_cv_file_magic_test_file=`echo /usr/lib/libc.so*`
-    ;;
-  ncr)
-    lt_cv_deplibs_check_method=pass_all
-    ;;
-  sequent)
-    lt_cv_file_magic_cmd='/bin/file'
-    lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[LM]]SB (shared object|dynamic lib )'
-    ;;
-  sni)
-    lt_cv_file_magic_cmd='/bin/file'
-    lt_cv_deplibs_check_method="file_magic ELF [[0-9]][[0-9]]*-bit [[LM]]SB dynamic lib"
-    lt_cv_file_magic_test_file=/lib/libc.so
-    ;;
-  siemens)
-    lt_cv_deplibs_check_method=pass_all
-    ;;
-  esac
-  ;;
-esac
-])
-file_magic_cmd=$lt_cv_file_magic_cmd
-deplibs_check_method=$lt_cv_deplibs_check_method
-])
+    sysv4.3*)
+      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='-Bexport'
+      ;;
 
+    sysv4*MP*)
+      if test -d /usr/nec; then
+	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+	_LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+	runpath_var=LD_RUN_PATH
+	hardcode_runpath_var=yes
+	_LT_AC_TAGVAR(ld_shlibs, $1)=yes
+      fi
+      ;;
 
-# AC_PROG_NM - find the path to a BSD-compatible name lister
-AC_DEFUN([AC_PROG_NM],
-[AC_REQUIRE([_LT_AC_LIBTOOL_SYS_PATH_SEPARATOR])dnl
-AC_MSG_CHECKING([for BSD-compatible nm])
-AC_CACHE_VAL(lt_cv_path_NM,
-[if test -n "$NM"; then
-  # Let the user override the test.
-  lt_cv_path_NM="$NM"
-else
-  IFS="${IFS= 	}"; ac_save_ifs="$IFS"; IFS=$PATH_SEPARATOR
-  for ac_dir in $PATH /usr/ccs/bin /usr/ucb /bin; do
-    test -z "$ac_dir" && ac_dir=.
-    tmp_nm=$ac_dir/${ac_tool_prefix}nm
-    if test -f $tmp_nm || test -f $tmp_nm$ac_exeext ; then
-      # Check to see if the nm accepts a BSD-compat flag.
-      # Adding the `sed 1q' prevents false positives on HP-UX, which says:
-      #   nm: unknown option "B" ignored
-      # Tru64's nm complains that /dev/null is an invalid object file
-      if ($tmp_nm -B /dev/null 2>&1 | sed '1q'; exit 0) | egrep '(/dev/null|Invalid file or object type)' >/dev/null; then
-	lt_cv_path_NM="$tmp_nm -B"
-	break
-      elif ($tmp_nm -p /dev/null 2>&1 | sed '1q'; exit 0) | egrep /dev/null >/dev/null; then
-	lt_cv_path_NM="$tmp_nm -p"
-	break
+    sysv4.2uw2*)
+      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -o $lib $libobjs $deplibs $linker_flags'
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_minus_L, $1)=no
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      hardcode_runpath_var=yes
+      runpath_var=LD_RUN_PATH
+      ;;
+
+   sysv5OpenUNIX8* | sysv5UnixWare7* |  sysv5uw[[78]]* | unixware7*)
+      _LT_AC_TAGVAR(no_undefined_flag, $1)='${wl}-z ${wl}text'
+      if test "$GCC" = yes; then
+	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
       else
-	lt_cv_path_NM=${lt_cv_path_NM="$tmp_nm"} # keep the first match, but
-	continue # so that we can try to find one that supports BSD flags
+	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -G ${wl}-h ${wl}$soname -o $lib $libobjs $deplibs $compiler_flags'
       fi
-    fi
-  done
-  IFS="$ac_save_ifs"
-  test -z "$lt_cv_path_NM" && lt_cv_path_NM=nm
-fi])
-NM="$lt_cv_path_NM"
-AC_MSG_RESULT([$NM])
+      runpath_var='LD_RUN_PATH'
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
+
+    sysv5*)
+      _LT_AC_TAGVAR(no_undefined_flag, $1)=' -z text'
+      # $CC -shared without GNU ld will not create a library from C++
+      # object files and a static libstdc++, better avoid it by now
+      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G${allow_undefined_flag} -h $soname -o $lib $libobjs $deplibs $linker_flags'
+      _LT_AC_TAGVAR(archive_expsym_cmds, $1)='$echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~$echo "local: *; };" >> $lib.exp~
+  		$LD -G${allow_undefined_flag} -M $lib.exp -h $soname -o $lib $libobjs $deplibs $linker_flags~$rm $lib.exp'
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)=
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      runpath_var='LD_RUN_PATH'
+      ;;
+
+    uts4*)
+      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -G -h $soname -o $lib $libobjs $deplibs $linker_flags'
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-L$libdir'
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
+
+    *)
+      _LT_AC_TAGVAR(ld_shlibs, $1)=no
+      ;;
+    esac
+  fi
 ])
+AC_MSG_RESULT([$_LT_AC_TAGVAR(ld_shlibs, $1)])
+test "$_LT_AC_TAGVAR(ld_shlibs, $1)" = no && can_build_shared=no
 
-# AC_CHECK_LIBM - check for math library
-AC_DEFUN([AC_CHECK_LIBM],
-[AC_REQUIRE([AC_CANONICAL_HOST])dnl
-LIBM=
-case $host in
-*-*-beos* | *-*-cygwin* | *-*-pw32*)
-  # These system don't have libm
-  ;;
-*-ncr-sysv4.3*)
-  AC_CHECK_LIB(mw, _mwvalidcheckl, LIBM="-lmw")
-  AC_CHECK_LIB(m, main, LIBM="$LIBM -lm")
-  ;;
-*)
-  AC_CHECK_LIB(m, main, LIBM="-lm")
+variables_saved_for_relink="PATH $shlibpath_var $runpath_var"
+if test "$GCC" = yes; then
+  variables_saved_for_relink="$variables_saved_for_relink GCC_EXEC_PREFIX COMPILER_PATH LIBRARY_PATH"
+fi
+
+#
+# Do we need to explicitly link libc?
+#
+case "x$_LT_AC_TAGVAR(archive_cmds_need_lc, $1)" in
+x|xyes)
+  # Assume -lc should be added
+  _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=yes
+
+  if test "$enable_shared" = yes && test "$GCC" = yes; then
+    case $_LT_AC_TAGVAR(archive_cmds, $1) in
+    *'~'*)
+      # FIXME: we may have to deal with multi-command sequences.
+      ;;
+    '$CC '*)
+      # Test whether the compiler implicitly links with -lc since on some
+      # systems, -lgcc has to come before -lc. If gcc already passes -lc
+      # to ld, don't add -lc before -lgcc.
+      AC_MSG_CHECKING([whether -lc should be explicitly linked in])
+      $rm conftest*
+      printf "$lt_simple_compile_test_code" > conftest.$ac_ext
+  
+      if AC_TRY_EVAL(ac_compile) 2>conftest.err; then
+        soname=conftest
+        lib=conftest
+        libobjs=conftest.$ac_objext
+        deplibs=
+        wl=$_LT_AC_TAGVAR(lt_prog_compiler_wl, $1)
+        compiler_flags=-v
+        linker_flags=-v
+        verstring=
+        output_objdir=.
+        libname=conftest
+        lt_save_allow_undefined_flag=$_LT_AC_TAGVAR(allow_undefined_flag, $1)
+        _LT_AC_TAGVAR(allow_undefined_flag, $1)=
+        if AC_TRY_EVAL(_LT_AC_TAGVAR(archive_cmds, $1) 2\>\&1 \| grep \" -lc \" \>/dev/null 2\>\&1)
+        then
+	  _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
+        else
+	  _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=yes
+        fi
+        _LT_AC_TAGVAR(allow_undefined_flag, $1)=$lt_save_allow_undefined_flag
+      else
+        cat conftest.err 1>&5
+      fi
+      $rm conftest*
+      AC_MSG_RESULT([$_LT_AC_TAGVAR(archive_cmds_need_lc, $1)])
+      ;;
+    esac
+  fi
   ;;
 esac
-])
+])# AC_LIBTOOL_PROG_LD_SHLIBS
 
-# AC_LIBLTDL_CONVENIENCE[(dir)] - sets LIBLTDL to the link flags for
-# the libltdl convenience library and LTDLINCL to the include flags for
-# the libltdl header and adds --enable-ltdl-convenience to the
-# configure arguments.  Note that LIBLTDL and LTDLINCL are not
-# AC_SUBSTed, nor is AC_CONFIG_SUBDIRS called.  If DIR is not
-# provided, it is assumed to be `libltdl'.  LIBLTDL will be prefixed
-# with '${top_builddir}/' and LTDLINCL will be prefixed with
-# '${top_srcdir}/' (note the single quotes!).  If your package is not
-# flat and you're not using automake, define top_builddir and
-# top_srcdir appropriately in the Makefiles.
-AC_DEFUN([AC_LIBLTDL_CONVENIENCE],
-[AC_BEFORE([$0],[AC_LIBTOOL_SETUP])dnl
-  case $enable_ltdl_convenience in
-  no) AC_MSG_ERROR([this package needs a convenience libltdl]) ;;
-  "") enable_ltdl_convenience=yes
-      ac_configure_args="$ac_configure_args --enable-ltdl-convenience" ;;
-  esac
-  LIBLTDL='${top_builddir}/'ifelse($#,1,[$1],['libltdl'])/libltdlc.la
-  LTDLINCL='-I${top_srcdir}/'ifelse($#,1,[$1],['libltdl'])
-  # For backwards non-gettext consistent compatibility...
-  INCLTDL="$LTDLINCL"
-])
 
-# AC_LIBLTDL_INSTALLABLE[(dir)] - sets LIBLTDL to the link flags for
-# the libltdl installable library and LTDLINCL to the include flags for
-# the libltdl header and adds --enable-ltdl-install to the configure
-# arguments.  Note that LIBLTDL and LTDLINCL are not AC_SUBSTed, nor is
-# AC_CONFIG_SUBDIRS called.  If DIR is not provided and an installed
-# libltdl is not found, it is assumed to be `libltdl'.  LIBLTDL will
-# be prefixed with '${top_builddir}/' and LTDLINCL will be prefixed
-# with '${top_srcdir}/' (note the single quotes!).  If your package is
-# not flat and you're not using automake, define top_builddir and
-# top_srcdir appropriately in the Makefiles.
-# In the future, this macro may have to be called after AC_PROG_LIBTOOL.
-AC_DEFUN([AC_LIBLTDL_INSTALLABLE],
-[AC_BEFORE([$0],[AC_LIBTOOL_SETUP])dnl
-  AC_CHECK_LIB(ltdl, main,
-  [test x"$enable_ltdl_install" != xyes && enable_ltdl_install=no],
-  [if test x"$enable_ltdl_install" = xno; then
-     AC_MSG_WARN([libltdl not installed, but installation disabled])
-   else
-     enable_ltdl_install=yes
-   fi
-  ])
-  if test x"$enable_ltdl_install" = x"yes"; then
-    ac_configure_args="$ac_configure_args --enable-ltdl-install"
-    LIBLTDL='${top_builddir}/'ifelse($#,1,[$1],['libltdl'])/libltdl.la
-    LTDLINCL='-I${top_srcdir}/'ifelse($#,1,[$1],['libltdl'])
-  else
-    ac_configure_args="$ac_configure_args --enable-ltdl-install=no"
-    LIBLTDL="-lltdl"
-    LTDLINCL=
-  fi
-  # For backwards non-gettext consistent compatibility...
-  INCLTDL="$LTDLINCL"
-])
+# _LT_AC_FILE_LTDLL_C
+# -------------------
+# Be careful that the start marker always follows a newline.
+AC_DEFUN([_LT_AC_FILE_LTDLL_C], [
+# /* ltdll.c starts here */
+# #define WIN32_LEAN_AND_MEAN
+# #include <windows.h>
+# #undef WIN32_LEAN_AND_MEAN
+# #include <stdio.h>
+#
+# #ifndef __CYGWIN__
+# #  ifdef __CYGWIN32__
+# #    define __CYGWIN__ __CYGWIN32__
+# #  endif
+# #endif
+#
+# #ifdef __cplusplus
+# extern "C" {
+# #endif
+# BOOL APIENTRY DllMain (HINSTANCE hInst, DWORD reason, LPVOID reserved);
+# #ifdef __cplusplus
+# }
+# #endif
+#
+# #ifdef __CYGWIN__
+# #include <cygwin/cygwin_dll.h>
+# DECLARE_CYGWIN_DLL( DllMain );
+# #endif
+# HINSTANCE __hDllInstance_base;
+#
+# BOOL APIENTRY
+# DllMain (HINSTANCE hInst, DWORD reason, LPVOID reserved)
+# {
+#   __hDllInstance_base = hInst;
+#   return TRUE;
+# }
+# /* ltdll.c ends here */
+])# _LT_AC_FILE_LTDLL_C
+
+
+# _LT_AC_TAGVAR(VARNAME, [TAGNAME])
+# ---------------------------------
+AC_DEFUN([_LT_AC_TAGVAR], [ifelse([$2], [], [$1], [$1_$2])])
+
 
 # old names
 AC_DEFUN([AM_PROG_LIBTOOL],   [AC_PROG_LIBTOOL])
