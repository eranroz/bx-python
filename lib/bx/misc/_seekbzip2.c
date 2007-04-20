/* Generated by Pyrex 0.9.5.1a on Sun Apr  1 23:02:20 2007 */

#include "Python.h"
#include "structmember.h"
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif
__PYX_EXTERN_C double pow(double, double);
#include "micro-bunzip.h"
#include "unistd.h"
#include "stdlib.h"


typedef struct {PyObject **p; char *s;} __Pyx_InternTabEntry; /*proto*/
typedef struct {PyObject **p; char *s; long n;} __Pyx_StringTabEntry; /*proto*/

static PyObject *__pyx_m;
static PyObject *__pyx_b;
static int __pyx_lineno;
static char *__pyx_filename;
static char **__pyx_f;

static char __pyx_mdoc[] = "\nPyrex/C extension supporting `bx.misc.seekbzip2` (wrapping the low level\nfunctions in `micro-bunzip.c`).\n";

static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list); /*proto*/

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name); /*proto*/

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb); /*proto*/

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t); /*proto*/

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t); /*proto*/

static void __Pyx_AddTraceback(char *funcname); /*proto*/

/* Declarations from _seekbzip2 */


struct __pyx_obj_10_seekbzip2_SeekBzip2 {
  PyObject_HEAD
  bunzip_data (*bd);
  int file_fd;
  int at_eof;
};

static PyTypeObject *__pyx_ptype_10_seekbzip2_SeekBzip2 = 0;


/* Implementation of _seekbzip2 */


static PyObject *__pyx_n_sys;
static PyObject *__pyx_n_os;

static PyObject *__pyx_n_open;
static PyObject *__pyx_n_O_RDONLY;

static int __pyx_f_10_seekbzip2_9SeekBzip2___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_10_seekbzip2_9SeekBzip2___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_filename = 0;
  int __pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  int __pyx_4;
  static char *__pyx_argnames[] = {"filename",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_filename)) return -1;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_filename);

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":45 */
  ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->at_eof = 0;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":46 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_os); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 46; goto __pyx_L1;}
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_open); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 46; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_os); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 46; goto __pyx_L1;}
  __pyx_3 = PyObject_GetAttr(__pyx_1, __pyx_n_O_RDONLY); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 46; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 46; goto __pyx_L1;}
  Py_INCREF(__pyx_v_filename);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_filename);
  PyTuple_SET_ITEM(__pyx_1, 1, __pyx_3);
  __pyx_3 = 0;
  __pyx_3 = PyObject_CallObject(__pyx_2, __pyx_1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 46; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_4 = PyInt_AsLong(__pyx_3); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 46; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->file_fd = __pyx_4;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":48 */
  start_bunzip((&((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd),((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->file_fd,NULL,0);

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("_seekbzip2.SeekBzip2.__init__");
  __pyx_r = -1;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_filename);
  return __pyx_r;
}

static PyObject *__pyx_n_close;

static PyObject *__pyx_f_10_seekbzip2_9SeekBzip2_close(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_10_seekbzip2_9SeekBzip2_close(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":51 */
  free(((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd->dbuf);

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":52 */
  free(((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd);

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":53 */
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_os); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 53; goto __pyx_L1;}
  __pyx_2 = PyObject_GetAttr(__pyx_1, __pyx_n_close); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 53; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyInt_FromLong(((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->file_fd); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 53; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 53; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
  __pyx_1 = 0;
  __pyx_1 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 53; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("_seekbzip2.SeekBzip2.close");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_n_Exception;

static PyObject *__pyx_k3p;

static char (__pyx_k3[]) = "lseek of underlying file failed";

static PyObject *__pyx_f_10_seekbzip2_9SeekBzip2_seek(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_10_seekbzip2_9SeekBzip2_seek[] = "\n        Seek the bunzip_data to a specific chunk (position must correspond to\n        that start of a compressed data block).\n        ";
static PyObject *__pyx_f_10_seekbzip2_9SeekBzip2_seek(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  unsigned PY_LONG_LONG __pyx_v_position;
  off_t __pyx_v_n_byte;
  int __pyx_v_n_bit;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  static char *__pyx_argnames[] = {"position",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "K", __pyx_argnames, &__pyx_v_position)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":64 */
  __pyx_v_n_byte = (__pyx_v_position / 8);

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":65 */
  __pyx_v_n_bit = (__pyx_v_position % 8);

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":70 */
  __pyx_1 = (lseek(((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->file_fd,__pyx_v_n_byte,0) != __pyx_v_n_byte);
  if (__pyx_1) {

    /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":71 */
    __pyx_2 = __Pyx_GetName(__pyx_b, __pyx_n_Exception); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
    __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
    Py_INCREF(__pyx_k3p);
    PyTuple_SET_ITEM(__pyx_3, 0, __pyx_k3p);
    __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    __Pyx_Raise(__pyx_4, 0, 0);
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":73 */
  ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd->inbufBitCount = 0;
  ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd->inbufPos = 0;
  ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd->inbufCount = 0;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":74 */
  get_bits(((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd,__pyx_v_n_bit);

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":77 */
  ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd->writeCount = (-1);

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":79 */
  ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->at_eof = 0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("_seekbzip2.SeekBzip2.seek");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_n_append;
static PyObject *__pyx_n_join;

static PyObject *__pyx_k4p;
static PyObject *__pyx_k5p;

static char (__pyx_k4[]) = "read_bunzip error %d";
static char (__pyx_k5[]) = "";

static PyObject *__pyx_f_10_seekbzip2_9SeekBzip2_readline(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_10_seekbzip2_9SeekBzip2_readline(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_amount;
  PyObject *__pyx_v_rval;
  char (*__pyx_v_p_rval);
  int __pyx_v_gotcount;
  int __pyx_v_totalcount;
  int __pyx_v_status;
  int __pyx_v_spaceleft;
  int __pyx_v_desired;
  PyObject *__pyx_v_chunks;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  static char *__pyx_argnames[] = {"amount",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "i", __pyx_argnames, &__pyx_v_amount)) return 0;
  Py_INCREF(__pyx_v_self);
  __pyx_v_rval = Py_None; Py_INCREF(Py_None);
  __pyx_v_chunks = Py_None; Py_INCREF(Py_None);

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":89 */
  __pyx_v_gotcount = 0;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":90 */
  __pyx_v_totalcount = 0;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":92 */
  __pyx_1 = ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->at_eof;
  if (__pyx_1) {

    /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":93 */
    Py_INCREF(Py_None);
    __pyx_r = Py_None;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":94 */
  __pyx_2 = PyList_New(0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 94; goto __pyx_L1;}
  Py_DECREF(__pyx_v_chunks);
  __pyx_v_chunks = __pyx_2;
  __pyx_2 = 0;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":97 */
  __pyx_2 = PyString_FromStringAndSize(NULL,8192); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 97; goto __pyx_L1;}
  Py_DECREF(__pyx_v_rval);
  __pyx_v_rval = __pyx_2;
  __pyx_2 = 0;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":98 */
  __pyx_v_p_rval = PyString_AsString(__pyx_v_rval);

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":99 */
  __pyx_v_spaceleft = 8192;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":100 */
  while (1) {
    __pyx_1 = (__pyx_v_amount != 0);
    if (!__pyx_1) break;

    /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":101 */
    __pyx_1 = (__pyx_v_amount > 0);
    if (__pyx_1) {
      __pyx_1 = (__pyx_v_amount < __pyx_v_spaceleft);
    }
    if (__pyx_1) {

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":102 */
      __pyx_v_desired = __pyx_v_amount;
      goto __pyx_L5;
    }
    /*else*/ {

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":104 */
      __pyx_v_desired = __pyx_v_spaceleft;
    }
    __pyx_L5:;

    /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":110 */
    __pyx_v_status = read_bunzip_to_char(((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd,__pyx_v_p_rval,__pyx_v_desired,(&__pyx_v_gotcount),10);

    /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":115 */
    __pyx_1 = (__pyx_v_status == (-9));
    if (__pyx_1) {

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":119 */
      __pyx_2 = PyObject_GetAttr(__pyx_v_chunks, __pyx_n_append); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 119; goto __pyx_L1;}
      __pyx_3 = PySequence_GetSlice(__pyx_v_rval, 0, ((8192 - __pyx_v_spaceleft) + __pyx_v_gotcount)); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 119; goto __pyx_L1;}
      __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 119; goto __pyx_L1;}
      PyTuple_SET_ITEM(__pyx_4, 0, __pyx_3);
      __pyx_3 = 0;
      __pyx_3 = PyObject_CallObject(__pyx_2, __pyx_4); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 119; goto __pyx_L1;}
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      Py_DECREF(__pyx_4); __pyx_4 = 0;
      Py_DECREF(__pyx_3); __pyx_3 = 0;

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":120 */
      goto __pyx_L4;
      goto __pyx_L6;
    }
    __pyx_1 = (__pyx_v_status == (-10));
    if (__pyx_1) {

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":125 */
      __pyx_2 = PyObject_GetAttr(__pyx_v_chunks, __pyx_n_append); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 125; goto __pyx_L1;}
      __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 125; goto __pyx_L1;}
      Py_INCREF(__pyx_v_rval);
      PyTuple_SET_ITEM(__pyx_4, 0, __pyx_v_rval);
      __pyx_3 = PyObject_CallObject(__pyx_2, __pyx_4); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 125; goto __pyx_L1;}
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      Py_DECREF(__pyx_4); __pyx_4 = 0;
      Py_DECREF(__pyx_3); __pyx_3 = 0;

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":126 */
      __pyx_v_amount = (__pyx_v_amount - __pyx_v_gotcount);

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":127 */
      __pyx_1 = (__pyx_v_amount == 0);
      if (__pyx_1) {

        /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":129 */
        goto __pyx_L4;
        goto __pyx_L7;
      }
      __pyx_L7:;

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":130 */
      __pyx_2 = PyString_FromStringAndSize(NULL,8192); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 130; goto __pyx_L1;}
      Py_DECREF(__pyx_v_rval);
      __pyx_v_rval = __pyx_2;
      __pyx_2 = 0;

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":131 */
      __pyx_v_p_rval = PyString_AsString(__pyx_v_rval);

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":132 */
      __pyx_v_spaceleft = 8192;
      goto __pyx_L6;
    }
    __pyx_1 = (__pyx_v_status == (-8));
    if (__pyx_1) {

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":136 */
      __pyx_1 = __pyx_v_gotcount;
      if (__pyx_1) {
        __pyx_1 = ((__pyx_v_p_rval[(__pyx_v_gotcount - 1)]) == 10);
      }
      if (__pyx_1) {

        /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":137 */
        __pyx_4 = PyObject_GetAttr(__pyx_v_chunks, __pyx_n_append); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 137; goto __pyx_L1;}
        __pyx_3 = PySequence_GetSlice(__pyx_v_rval, 0, ((8192 - __pyx_v_spaceleft) + __pyx_v_gotcount)); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 137; goto __pyx_L1;}
        __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 137; goto __pyx_L1;}
        PyTuple_SET_ITEM(__pyx_2, 0, __pyx_3);
        __pyx_3 = 0;
        __pyx_3 = PyObject_CallObject(__pyx_4, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 137; goto __pyx_L1;}
        Py_DECREF(__pyx_4); __pyx_4 = 0;
        Py_DECREF(__pyx_2); __pyx_2 = 0;
        Py_DECREF(__pyx_3); __pyx_3 = 0;

        /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":138 */
        goto __pyx_L4;
        goto __pyx_L8;
      }
      __pyx_L8:;

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":140 */
      __pyx_v_p_rval = (__pyx_v_p_rval + __pyx_v_gotcount);

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":141 */
      __pyx_v_spaceleft = (__pyx_v_spaceleft - __pyx_v_gotcount);

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":142 */
      __pyx_v_amount = (__pyx_v_amount - __pyx_v_gotcount);

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":144 */
      __pyx_v_status = get_next_block(((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd);

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":145 */
      __pyx_1 = (__pyx_v_status == (-1));
      if (__pyx_1) {

        /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":147 */
        ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->at_eof = 1;

        /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":148 */
        __pyx_4 = PyObject_GetAttr(__pyx_v_chunks, __pyx_n_append); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; goto __pyx_L1;}
        __pyx_2 = PySequence_GetSlice(__pyx_v_rval, 0, __pyx_v_gotcount); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; goto __pyx_L1;}
        __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; goto __pyx_L1;}
        PyTuple_SET_ITEM(__pyx_3, 0, __pyx_2);
        __pyx_2 = 0;
        __pyx_2 = PyObject_CallObject(__pyx_4, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; goto __pyx_L1;}
        Py_DECREF(__pyx_4); __pyx_4 = 0;
        Py_DECREF(__pyx_3); __pyx_3 = 0;
        Py_DECREF(__pyx_2); __pyx_2 = 0;

        /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":149 */
        goto __pyx_L4;
        goto __pyx_L9;
      }
      __pyx_L9:;

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":150 */
      ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd->writeCRC = 0xffffffff;

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":151 */
      ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd->writeCopies = 0;
      goto __pyx_L6;
    }
    /*else*/ {

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":154 */
      __pyx_4 = __Pyx_GetName(__pyx_b, __pyx_n_Exception); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 154; goto __pyx_L1;}
      __pyx_3 = PyInt_FromLong(__pyx_v_status); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 154; goto __pyx_L1;}
      __pyx_2 = PyNumber_Remainder(__pyx_k4p, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 154; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 154; goto __pyx_L1;}
      PyTuple_SET_ITEM(__pyx_3, 0, __pyx_2);
      __pyx_2 = 0;
      __pyx_2 = PyObject_CallObject(__pyx_4, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 154; goto __pyx_L1;}
      Py_DECREF(__pyx_4); __pyx_4 = 0;
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __Pyx_Raise(__pyx_2, 0, 0);
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 154; goto __pyx_L1;}
    }
    __pyx_L6:;
  }
  __pyx_L4:;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":156 */
  __pyx_4 = PyObject_GetAttr(__pyx_k5p, __pyx_n_join); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 156; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 156; goto __pyx_L1;}
  Py_INCREF(__pyx_v_chunks);
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_v_chunks);
  __pyx_2 = PyObject_CallObject(__pyx_4, __pyx_3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 156; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_r = __pyx_2;
  __pyx_2 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("_seekbzip2.SeekBzip2.readline");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_rval);
  Py_DECREF(__pyx_v_chunks);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_k6p;

static char (__pyx_k6[]) = "read_bunzip error %d";

static PyObject *__pyx_f_10_seekbzip2_9SeekBzip2_read(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_10_seekbzip2_9SeekBzip2_read(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_amount;
  PyObject *__pyx_v_rval;
  char (*__pyx_v_p_rval);
  int __pyx_v_gotcount;
  int __pyx_v_totalcount;
  int __pyx_v_status;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  static char *__pyx_argnames[] = {"amount",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "i", __pyx_argnames, &__pyx_v_amount)) return 0;
  Py_INCREF(__pyx_v_self);
  __pyx_v_rval = Py_None; Py_INCREF(Py_None);

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":164 */
  __pyx_v_totalcount = 0;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":166 */
  __pyx_1 = ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->at_eof;
  if (__pyx_1) {

    /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":167 */
    Py_INCREF(Py_None);
    __pyx_r = Py_None;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":169 */
  __pyx_2 = PyString_FromStringAndSize(NULL,__pyx_v_amount); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 169; goto __pyx_L1;}
  Py_DECREF(__pyx_v_rval);
  __pyx_v_rval = __pyx_2;
  __pyx_2 = 0;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":170 */
  __pyx_v_p_rval = PyString_AsString(__pyx_v_rval);

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":173 */
  while (1) {
    __pyx_1 = (__pyx_v_amount > 0);
    if (!__pyx_1) break;

    /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":174 */
    __pyx_v_gotcount = read_bunzip(((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd,__pyx_v_p_rval,__pyx_v_amount);

    /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":175 */
    __pyx_1 = (__pyx_v_gotcount < 0);
    if (__pyx_1) {

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":176 */
      __pyx_2 = __Pyx_GetName(__pyx_b, __pyx_n_Exception); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 176; goto __pyx_L1;}
      __pyx_3 = PyInt_FromLong(__pyx_v_gotcount); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 176; goto __pyx_L1;}
      __pyx_4 = PyNumber_Remainder(__pyx_k6p, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 176; goto __pyx_L1;}
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 176; goto __pyx_L1;}
      PyTuple_SET_ITEM(__pyx_3, 0, __pyx_4);
      __pyx_4 = 0;
      __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 176; goto __pyx_L1;}
      Py_DECREF(__pyx_2); __pyx_2 = 0;
      Py_DECREF(__pyx_3); __pyx_3 = 0;
      __Pyx_Raise(__pyx_4, 0, 0);
      Py_DECREF(__pyx_4); __pyx_4 = 0;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 176; goto __pyx_L1;}
      goto __pyx_L5;
    }
    __pyx_1 = (__pyx_v_gotcount == 0);
    if (__pyx_1) {

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":178 */
      __pyx_v_status = get_next_block(((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd);

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":179 */
      __pyx_1 = (__pyx_v_status == (-1));
      if (__pyx_1) {

        /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":180 */
        ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->at_eof = 1;

        /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":181 */
        goto __pyx_L4;
        goto __pyx_L6;
      }
      __pyx_L6:;

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":182 */
      ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd->writeCRC = 0xffffffff;

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":183 */
      ((struct __pyx_obj_10_seekbzip2_SeekBzip2 *)__pyx_v_self)->bd->writeCopies = 0;
      goto __pyx_L5;
    }
    /*else*/ {

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":185 */
      __pyx_v_totalcount = (__pyx_v_totalcount + __pyx_v_gotcount);

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":186 */
      __pyx_v_amount = (__pyx_v_amount - __pyx_v_gotcount);

      /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":187 */
      __pyx_v_p_rval = (__pyx_v_p_rval + __pyx_v_gotcount);
    }
    __pyx_L5:;
  }
  __pyx_L4:;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":189 */
  __pyx_2 = PySequence_GetSlice(__pyx_v_rval, 0, __pyx_v_totalcount); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 189; goto __pyx_L1;}
  __pyx_r = __pyx_2;
  __pyx_2 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("_seekbzip2.SeekBzip2.read");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_rval);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static __Pyx_InternTabEntry __pyx_intern_tab[] = {
  {&__pyx_n_Exception, "Exception"},
  {&__pyx_n_O_RDONLY, "O_RDONLY"},
  {&__pyx_n_append, "append"},
  {&__pyx_n_close, "close"},
  {&__pyx_n_join, "join"},
  {&__pyx_n_open, "open"},
  {&__pyx_n_os, "os"},
  {&__pyx_n_sys, "sys"},
  {0, 0}
};

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_k3p, __pyx_k3, sizeof(__pyx_k3)},
  {&__pyx_k4p, __pyx_k4, sizeof(__pyx_k4)},
  {&__pyx_k5p, __pyx_k5, sizeof(__pyx_k5)},
  {&__pyx_k6p, __pyx_k6, sizeof(__pyx_k6)},
  {0, 0, 0}
};

static PyObject *__pyx_tp_new_10_seekbzip2_SeekBzip2(PyTypeObject *t, PyObject *a, PyObject *k) {
  PyObject *o = (*t->tp_alloc)(t, 0);
  return o;
}

static void __pyx_tp_dealloc_10_seekbzip2_SeekBzip2(PyObject *o) {
  (*o->ob_type->tp_free)(o);
}

static int __pyx_tp_traverse_10_seekbzip2_SeekBzip2(PyObject *o, visitproc v, void *a) {
  return 0;
}

static int __pyx_tp_clear_10_seekbzip2_SeekBzip2(PyObject *o) {
  return 0;
}

static struct PyMethodDef __pyx_methods_10_seekbzip2_SeekBzip2[] = {
  {"close", (PyCFunction)__pyx_f_10_seekbzip2_9SeekBzip2_close, METH_VARARGS|METH_KEYWORDS, 0},
  {"seek", (PyCFunction)__pyx_f_10_seekbzip2_9SeekBzip2_seek, METH_VARARGS|METH_KEYWORDS, __pyx_doc_10_seekbzip2_9SeekBzip2_seek},
  {"readline", (PyCFunction)__pyx_f_10_seekbzip2_9SeekBzip2_readline, METH_VARARGS|METH_KEYWORDS, 0},
  {"read", (PyCFunction)__pyx_f_10_seekbzip2_9SeekBzip2_read, METH_VARARGS|METH_KEYWORDS, 0},
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_SeekBzip2 = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
};

static PySequenceMethods __pyx_tp_as_sequence_SeekBzip2 = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_SeekBzip2 = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_SeekBzip2 = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_10_seekbzip2_SeekBzip2 = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "_seekbzip2.SeekBzip2", /*tp_name*/
  sizeof(struct __pyx_obj_10_seekbzip2_SeekBzip2), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_10_seekbzip2_SeekBzip2, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_SeekBzip2, /*tp_as_number*/
  &__pyx_tp_as_sequence_SeekBzip2, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_SeekBzip2, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_SeekBzip2, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_10_seekbzip2_SeekBzip2, /*tp_traverse*/
  __pyx_tp_clear_10_seekbzip2_SeekBzip2, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_10_seekbzip2_SeekBzip2, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_10_seekbzip2_9SeekBzip2___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_10_seekbzip2_SeekBzip2, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static struct PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); /*proto*/

PyMODINIT_FUNC init_seekbzip2(void); /*proto*/
PyMODINIT_FUNC init_seekbzip2(void) {
  PyObject *__pyx_1 = 0;
  __pyx_init_filenames();
  __pyx_m = Py_InitModule4("_seekbzip2", __pyx_methods, __pyx_mdoc, 0, PYTHON_API_VERSION);
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  __pyx_b = PyImport_AddModule("__builtin__");
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (__Pyx_InternStrings(__pyx_intern_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (PyType_Ready(&__pyx_type_10_seekbzip2_SeekBzip2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 38; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "SeekBzip2", (PyObject *)&__pyx_type_10_seekbzip2_SeekBzip2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 38; goto __pyx_L1;}
  __pyx_ptype_10_seekbzip2_SeekBzip2 = &__pyx_type_10_seekbzip2_SeekBzip2;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":35 */
  __pyx_1 = __Pyx_Import(__pyx_n_sys, 0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 35; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_sys, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 35; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":36 */
  __pyx_1 = __Pyx_Import(__pyx_n_os, 0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 36; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_os, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 36; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/Users/james/projects/bx-python-trunk/lib/bx/misc/_seekbzip2.pyx":158 */
  return;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("_seekbzip2");
}

static char *__pyx_filenames[] = {
  "_seekbzip2.pyx",
};

/* Runtime support code */

static void __pyx_init_filenames(void) {
  __pyx_f = __pyx_filenames;
}

static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list) {
    PyObject *__import__ = 0;
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    __import__ = PyObject_GetAttrString(__pyx_b, "__import__");
    if (!__import__)
        goto bad;
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    module = PyObject_CallFunction(__import__, "OOOO",
        name, global_dict, empty_dict, list);
bad:
    Py_XDECREF(empty_list);
    Py_XDECREF(__import__);
    Py_XDECREF(empty_dict);
    return module;
}

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name) {
    PyObject *result;
    result = PyObject_GetAttr(dict, name);
    if (!result)
        PyErr_SetObject(PyExc_NameError, name);
    return result;
}

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb) {
    Py_XINCREF(type);
    Py_XINCREF(value);
    Py_XINCREF(tb);
    /* First, check the traceback argument, replacing None with NULL. */
    if (tb == Py_None) {
        Py_DECREF(tb);
        tb = 0;
    }
    else if (tb != NULL && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto raise_error;
    }
    /* Next, replace a missing value with None */
    if (value == NULL) {
        value = Py_None;
        Py_INCREF(value);
    }
    /* Next, repeatedly, replace a tuple exception with its first item */
    while (PyTuple_Check(type) && PyTuple_Size(type) > 0) {
        PyObject *tmp = type;
        type = PyTuple_GET_ITEM(type, 0);
        Py_INCREF(type);
        Py_DECREF(tmp);
    }
    if (PyString_Check(type)) {
        if (PyErr_Warn(PyExc_DeprecationWarning,
                "raising a string exception is deprecated"))
            goto raise_error;
    }
    else if (PyType_Check(type) || PyClass_Check(type))
        ; /*PyErr_NormalizeException(&type, &value, &tb);*/
    else {
        /* Raising an instance.  The value should be a dummy. */
        if (value != Py_None) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto raise_error;
        }
        /* Normalize to raise <class>, <instance> */
        Py_DECREF(value);
        value = type;
        if (PyInstance_Check(type))
            type = (PyObject*) ((PyInstanceObject*)type)->in_class;
        else
            type = (PyObject*) type->ob_type;
        Py_INCREF(type);
    }
    PyErr_Restore(type, value, tb);
    return;
raise_error:
    Py_XDECREF(value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
    return;
}

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t) {
    while (t->p) {
        *t->p = PyString_InternFromString(t->s);
        if (!*t->p)
            return -1;
        ++t;
    }
    return 0;
}

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        if (!*t->p)
            return -1;
        ++t;
    }
    return 0;
}

#include "compile.h"
#include "frameobject.h"
#include "traceback.h"

static void __Pyx_AddTraceback(char *funcname) {
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    PyObject *py_globals = 0;
    PyObject *empty_tuple = 0;
    PyObject *empty_string = 0;
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    
    py_srcfile = PyString_FromString(__pyx_filename);
    if (!py_srcfile) goto bad;
    py_funcname = PyString_FromString(funcname);
    if (!py_funcname) goto bad;
    py_globals = PyModule_GetDict(__pyx_m);
    if (!py_globals) goto bad;
    empty_tuple = PyTuple_New(0);
    if (!empty_tuple) goto bad;
    empty_string = PyString_FromString("");
    if (!empty_string) goto bad;
    py_code = PyCode_New(
        0,            /*int argcount,*/
        0,            /*int nlocals,*/
        0,            /*int stacksize,*/
        0,            /*int flags,*/
        empty_string, /*PyObject *code,*/
        empty_tuple,  /*PyObject *consts,*/
        empty_tuple,  /*PyObject *names,*/
        empty_tuple,  /*PyObject *varnames,*/
        empty_tuple,  /*PyObject *freevars,*/
        empty_tuple,  /*PyObject *cellvars,*/
        py_srcfile,   /*PyObject *filename,*/
        py_funcname,  /*PyObject *name,*/
        __pyx_lineno,   /*int firstlineno,*/
        empty_string  /*PyObject *lnotab*/
    );
    if (!py_code) goto bad;
    py_frame = PyFrame_New(
        PyThreadState_Get(), /*PyThreadState *tstate,*/
        py_code,             /*PyCodeObject *code,*/
        py_globals,          /*PyObject *globals,*/
        0                    /*PyObject *locals*/
    );
    if (!py_frame) goto bad;
    py_frame->f_lineno = __pyx_lineno;
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    Py_XDECREF(empty_tuple);
    Py_XDECREF(empty_string);
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}
