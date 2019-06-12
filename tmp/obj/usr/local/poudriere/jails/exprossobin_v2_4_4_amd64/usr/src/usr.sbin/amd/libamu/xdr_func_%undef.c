/*
 * Copyright (c) 1997-2014 Erez Zadok
 * Copyright (c) 1990 Jan-Simon Pendry
 * Copyright (c) 1990 Imperial College of Science, Technology & Medicine
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Jan-Simon Pendry at Imperial College, London.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *
 * File: am-utils/libamu/xdr_func.c
 *
 */

/*
 * Complete list of all possible xdr functions which may be needed.
 */
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif /* HAVE_CONFIG_H */
#include <am_defs.h>
#include <amu.h>

#ifdef __RPCSVC_MOUNT_H__
# error IRIX6 should not include rpcsvc/mount.h
#endif /* __RPCSVC_MOUNT_H__ */

/*
 * MACROS:
 */
#ifdef HAVE_FS_AUTOFS
# ifndef AUTOFS_MAXCOMPONENTLEN
#  define AUTOFS_MAXCOMPONENTLEN 255
# endif /* not AUTOFS_MAXCOMPONENTLEN */
# ifndef AUTOFS_MAXOPTSLEN
#  define AUTOFS_MAXOPTSLEN 255
# endif /* not AUTOFS_MAXOPTSLEN */
# ifndef AUTOFS_MAXPATHLEN
#  define AUTOFS_MAXPATHLEN 1024
# endif /* not AUTOFS_MAXPATHLEN */
#endif /* HAVE_FS_AUTOFS */

/* forward definitions, are they needed? */
extern bool_t xdr_exportnode(XDR *xdrs, exportnode *objp);
extern bool_t xdr_groupnode(XDR *xdrs, groupnode *objp);
extern bool_t xdr_name(XDR *xdrs, name *objp);


















































































/*
 * NFS V3 XDR FUNCTIONS:
 */
#ifdef HAVE_FS_NFS3
bool_t
xdr_am_fhandle3(XDR *xdrs, am_fhandle3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_fhandle3:");

  if (!xdr_bytes(xdrs,
		 (char **) &objp->fhandle3_val,
		 (u_int *) &objp->fhandle3_len,
		 AM_FHSIZE3))
    return (FALSE);
  return (TRUE);
}


bool_t
xdr_am_mountstat3(XDR *xdrs, am_mountstat3 *objp)
{
  enum_t local_obj = *objp;

  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_mountstat3:");

  if (!xdr_enum(xdrs, &local_obj))
    return (FALSE);
  return (TRUE);
}


bool_t
xdr_am_mountres3_ok(XDR *xdrs, am_mountres3_ok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_mountres3_ok:");

  if (!xdr_am_fhandle3(xdrs, &objp->fhandle))
    return (FALSE);
  if (!xdr_array(xdrs,
		 (char **) ((voidp) &objp->auth_flavors.auth_flavors_val),
		 (u_int *) &objp->auth_flavors.auth_flavors_len,
		 ~0,
		 sizeof(int),
		 (XDRPROC_T_TYPE) xdr_int))
    return (FALSE);
  return (TRUE);
}

bool_t
xdr_am_mountres3(XDR *xdrs, am_mountres3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_mountres3:");

  if (!xdr_am_mountstat3(xdrs, &objp->fhs_status))
    return (FALSE);

  if (objp->fhs_status == AM_MNT3_OK) {
    if (!xdr_am_mountres3_ok(xdrs, &objp->mountres3_u.mountinfo))
      return (FALSE);
  }
  return (TRUE);
}

bool_t
xdr_am_cookieverf3(XDR *xdrs, am_cookieverf3 objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_cookieverf3:");

  if (!xdr_opaque(xdrs, objp, AM_NFS3_COOKIEVERFSIZE))
    return FALSE;
  return TRUE;
}

#if 0
/* In FreeBSD xdr_uint64() is defined in ../../../include/rpcsvc/nfs_prot.x */
/*
 * Not ideal, xdr_u_int64_t() is not defined in Linux glibc RPC
 * but xdr_u_quad_t() is. But in libtirpc xdr_u_quad_t() is not
 * defined and xdr_u_int64_t() is. So xdr_u_int64_t() is probably
 * an expected standard xdr function so, if it isn't defined use
 * an internal xdr_u_int64_t() that uses xdr_u_quad_t().
 */

bool_t
xdr_uint64(XDR *xdrs, uint64 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_uint64:");

  if (!xdr_u_int64_t(xdrs, objp))
    return FALSE;
  return TRUE;
}
#endif

bool_t
xdr_am_cookie3(XDR *xdrs, am_cookie3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_cookie3:");

  if (!xdr_uint64(xdrs, objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_nfs_fh3(XDR *xdrs, am_nfs_fh3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_nfs_fh3:");

  if (!xdr_u_int(xdrs, &objp->am_fh3_length))
    return (FALSE);
  if (objp->am_fh3_length > AM_FHSIZE3)
    return (FALSE);
  if (!xdr_opaque(xdrs, objp->am_fh3_data, objp->am_fh3_length))
    return (FALSE);
  return (TRUE);
}

bool_t
xdr_am_nfsstat3(XDR *xdrs, am_nfsstat3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_nfsstat3:");

  if (!xdr_enum(xdrs, (enum_t *)objp))
    return (FALSE);
  return (TRUE);
}

bool_t
xdr_am_diropargs3(XDR *xdrs, am_diropargs3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_diropargs3:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->dir))
    return (FALSE);
  if (!xdr_am_filename3(xdrs, &objp->name))
    return (FALSE);
  return (TRUE);
}

bool_t
xdr_am_filename3(XDR *xdrs, am_filename3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_filename3:");

  if (!xdr_string(xdrs, objp, ~0))
    return (FALSE);
  return (TRUE);
}

bool_t
xdr_am_ftype3(XDR *xdrs, am_ftype3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_ftype3:");

  if (!xdr_enum(xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_mode3(XDR *xdrs, am_mode3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_mode3:");

  if (!xdr_u_int(xdrs, objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_uid3(XDR *xdrs, am_uid3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_uid3:");

  if (!xdr_u_int(xdrs, objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_gid3(XDR *xdrs, am_gid3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_gid3:");

  if (!xdr_u_int(xdrs, objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_size3(XDR *xdrs, am_size3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_size3:");

  if (!xdr_uint64(xdrs, objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_fileid3(XDR *xdrs, am_fileid3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_fileid3:");

  if (!xdr_uint64(xdrs, objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_specdata3(XDR *xdrs, am_specdata3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_specdata3:");

  if (!xdr_u_int(xdrs, &objp->specdata1))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->specdata2))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_nfstime3(XDR *xdrs, am_nfstime3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_nfstime3:");

  if (!xdr_u_int(xdrs, &objp->seconds))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->nseconds))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_fattr3(XDR *xdrs, am_fattr3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_fattr3:");

  if (!xdr_am_ftype3(xdrs, &objp->type))
    return FALSE;
  if (!xdr_am_mode3(xdrs, &objp->mode))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->nlink))
    return FALSE;
  if (!xdr_am_uid3(xdrs, &objp->uid))
    return FALSE;
  if (!xdr_am_gid3(xdrs, &objp->gid))
    return FALSE;
  if (!xdr_am_size3(xdrs, &objp->size))
    return FALSE;
  if (!xdr_am_size3(xdrs, &objp->used))
    return FALSE;
  if (!xdr_am_specdata3(xdrs, &objp->rdev))
    return FALSE;
  if (!xdr_uint64(xdrs, &objp->fsid))
    return FALSE;
  if (!xdr_am_fileid3(xdrs, &objp->fileid))
    return FALSE;
  if (!xdr_am_nfstime3(xdrs, &objp->atime))
    return FALSE;
  if (!xdr_am_nfstime3(xdrs, &objp->mtime))
    return FALSE;
  if (!xdr_am_nfstime3(xdrs, &objp->ctime))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_post_op_attr(XDR *xdrs, am_post_op_attr *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_post_op_attr:");

  if (!xdr_bool(xdrs, &objp->attributes_follow))
    return FALSE;
  switch (objp->attributes_follow) {
  case TRUE:
    if (!xdr_am_fattr3(xdrs, &objp->am_post_op_attr_u.attributes))
      return FALSE;
    break;
  case FALSE:
    break;
  default:
    return FALSE;
  }
  return TRUE;
}

bool_t
xdr_am_stable_how(XDR *xdrs, am_stable_how *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_stable_how:");

  if (!xdr_enum(xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_offset3(XDR *xdrs, am_offset3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_offset3:");

  if (!xdr_uint64(xdrs, objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_count3(XDR *xdrs, am_count3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_count3:");

  if (!xdr_u_int(xdrs, objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_wcc_attr(XDR *xdrs, am_wcc_attr *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_wcc_attr:");

  if (!xdr_am_size3(xdrs, &objp->size))
    return FALSE;
  if (!xdr_am_nfstime3(xdrs, &objp->mtime))
    return FALSE;
  if (!xdr_am_nfstime3(xdrs, &objp->ctime))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_pre_op_attr(XDR *xdrs, am_pre_op_attr *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, ":xdr_am_pre_op_attr");

  if (!xdr_bool(xdrs, &objp->attributes_follow))
    return FALSE;
  switch (objp->attributes_follow) {
  case TRUE:
    if (!xdr_am_wcc_attr(xdrs, &objp->am_pre_op_attr_u.attributes))
      return FALSE;
    break;
  case FALSE:
    break;
  default:
    return FALSE;
  }
  return TRUE;
}

bool_t
xdr_am_wcc_data(XDR *xdrs, am_wcc_data *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_wcc_data:");

  if (!xdr_am_pre_op_attr(xdrs, &objp->before))
    return FALSE;
  if (!xdr_am_post_op_attr(xdrs, &objp->after))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_WRITE3args(XDR *xdrs, am_WRITE3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_WRITE3args:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->file))
    return FALSE;
  if (!xdr_am_offset3(xdrs, &objp->offset))
    return FALSE;
  if (!xdr_am_count3(xdrs, &objp->count))
    return FALSE;
  if (!xdr_am_stable_how(xdrs, &objp->stable))
    return FALSE;
  if (!xdr_bytes(xdrs, (char **)&objp->data.data_val,
                (u_int *) &objp->data.data_len, ~0))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_writeverf3(XDR *xdrs, am_writeverf3 objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_writeverf3:");

  if (!xdr_opaque(xdrs, objp, AM_NFS3_WRITEVERFSIZE))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_WRITE3resok(XDR *xdrs, am_WRITE3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_WRITE3resok:");

  if (!xdr_am_wcc_data(xdrs, &objp->file_wcc))
    return FALSE;
  if (!xdr_am_count3(xdrs, &objp->count))
    return FALSE;
  if (!xdr_am_stable_how(xdrs, &objp->committed))
    return FALSE;
  if (!xdr_am_writeverf3(xdrs, objp->verf))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_WRITE3resfail(XDR *xdrs, am_WRITE3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_WRITE3resfail:");

  if (!xdr_am_wcc_data(xdrs, &objp->file_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_WRITE3res(XDR *xdrs, am_WRITE3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_WRITE3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_WRITE3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_WRITE3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_LOOKUP3args(XDR *xdrs, am_LOOKUP3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_LOOKUP3args:");

  if (!xdr_am_diropargs3(xdrs, &objp->what))
    return (FALSE);
  return (TRUE);
}

bool_t
xdr_am_LOOKUP3res(XDR *xdrs, am_LOOKUP3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_LOOKUP3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return (FALSE);
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_LOOKUP3resok(xdrs, &objp->res_u.ok))
      return (FALSE);
    break;
  default:
    if (!xdr_am_LOOKUP3resfail(xdrs, &objp->res_u.fail))
      return (FALSE);
    break;
  }
  return (TRUE);
}

bool_t
xdr_am_LOOKUP3resfail(XDR *xdrs, am_LOOKUP3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_LOOKUP3resfail:");

  if (!xdr_am_post_op_attr(xdrs, &objp->dir_attributes))
    return (FALSE);
  return (TRUE);
}

bool_t
xdr_am_LOOKUP3resok(XDR *xdrs, am_LOOKUP3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_LOOKUP3resok:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->object))
    return (FALSE);
  if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
    return (FALSE);
  if (!xdr_am_post_op_attr(xdrs, &objp->dir_attributes))
    return (FALSE);
  return (TRUE);
}

bool_t
xdr_am_COMMIT3args(XDR *xdrs, am_COMMIT3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_COMMIT3args:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->file))
    return FALSE;
  if (!xdr_am_offset3(xdrs, &objp->offset))
    return FALSE;
  if (!xdr_am_count3(xdrs, &objp->count))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_COMMIT3resok(XDR *xdrs, am_COMMIT3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_COMMIT3resok:");

  if (!xdr_am_wcc_data(xdrs, &objp->file_wcc))
    return FALSE;
  if (!xdr_am_writeverf3(xdrs, objp->verf))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_COMMIT3resfail(XDR *xdrs, am_COMMIT3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_COMMIT3resfail:");

  if (!xdr_am_wcc_data(xdrs, &objp->file_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_COMMIT3res(XDR *xdrs, am_COMMIT3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_COMMIT3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_COMMIT3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_COMMIT3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_ACCESS3args(XDR *xdrs, am_ACCESS3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_ACCESS3args:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->object))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->access))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_ACCESS3resok(XDR *xdrs, am_ACCESS3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_ACCESS3resok:");

  if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->access))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_ACCESS3resfail(XDR *xdrs, am_ACCESS3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_ACCESS3resfail:");

  if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_ACCESS3res(XDR *xdrs, am_ACCESS3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_ACCESS3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_ACCESS3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_ACCESS3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_GETATTR3args(XDR *xdrs, am_GETATTR3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_GETATTR3args:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->object))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_GETATTR3resok(XDR *xdrs, am_GETATTR3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_GETATTR3resok:");

  if (!xdr_am_fattr3(xdrs, &objp->obj_attributes))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_GETATTR3res(XDR *xdrs, am_GETATTR3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_GETATTR3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_GETATTR3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    break;
  }
  return TRUE;
}

bool_t
xdr_am_time_how(XDR *xdrs, am_time_how *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_time_how:");

  if (!xdr_enum(xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_set_mode3(XDR *xdrs, am_set_mode3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_set_mode3:");

  if (!xdr_bool(xdrs, &objp->set_it))
    return FALSE;
  switch (objp->set_it) {
  case TRUE:
    if (!xdr_am_mode3(xdrs, &objp->am_set_mode3_u.mode))
      return FALSE;
    break;
  default:
    break;
  }
  return TRUE;
}

bool_t
xdr_am_set_uid3(XDR *xdrs, am_set_uid3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_set_uid3:");

  if (!xdr_bool(xdrs, &objp->set_it))
    return FALSE;
  switch (objp->set_it) {
  case TRUE:
    if (!xdr_am_uid3(xdrs, &objp->am_set_uid3_u.uid))
      return FALSE;
    break;
  default:
    break;
  }
  return TRUE;
}

bool_t
xdr_am_set_gid3(XDR *xdrs, am_set_gid3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_set_gid3:");

  if (!xdr_bool(xdrs, &objp->set_it))
    return FALSE;
  switch (objp->set_it) {
  case TRUE:
    if (!xdr_am_gid3(xdrs, &objp->am_set_gid3_u.gid))
      return FALSE;
    break;
  default:
    break;
  }
  return TRUE;
}

bool_t
xdr_am_set_size3(XDR *xdrs, am_set_size3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_set_size3:");

  if (!xdr_bool(xdrs, &objp->set_it))
    return FALSE;
  switch (objp->set_it) {
  case TRUE:
    if (!xdr_am_size3(xdrs, &objp->am_set_size3_u.size))
      return FALSE;
    break;
  default:
    break;
  }
  return TRUE;
}

bool_t
xdr_am_set_atime(XDR *xdrs, am_set_atime *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_set_atime:");

  if (!xdr_am_time_how(xdrs, &objp->set_it))
    return FALSE;
  switch (objp->set_it) {
  case AM_SET_TO_CLIENT_TIME:
    if (!xdr_am_nfstime3(xdrs, &objp->am_set_atime_u.atime))
      return FALSE;
    break;
  default:
    break;
  }
  return TRUE;
}

bool_t
xdr_am_set_mtime(XDR *xdrs, am_set_mtime *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_set_mtime:");

  if (!xdr_am_time_how(xdrs, &objp->set_it))
    return FALSE;
  switch (objp->set_it) {
  case AM_SET_TO_CLIENT_TIME:
    if (!xdr_am_nfstime3(xdrs, &objp->am_set_mtime_u.mtime))
      return FALSE;
    break;
  default:
    break;
  }
  return TRUE;
}

bool_t
xdr_am_sattr3(XDR *xdrs, am_sattr3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_sattr3:");

  if (!xdr_am_set_mode3(xdrs, &objp->mode))
    return FALSE;
  if (!xdr_am_set_uid3(xdrs, &objp->uid))
    return FALSE;
  if (!xdr_am_set_gid3(xdrs, &objp->gid))
    return FALSE;
  if (!xdr_am_set_size3(xdrs, &objp->size))
     return FALSE;
  if (!xdr_am_set_atime(xdrs, &objp->atime))
    return FALSE;
  if (!xdr_am_set_mtime(xdrs, &objp->mtime))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_createmode3(XDR *xdrs, am_createmode3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_createmode3:");

  if (!xdr_enum(xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_createverf3(XDR *xdrs, am_createverf3 objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_createverf3:");

  if (!xdr_opaque(xdrs, objp, AM_NFS3_CREATEVERFSIZE))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_createhow3(XDR *xdrs, am_createhow3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_createhow3:");

   if (!xdr_am_createmode3(xdrs, &objp->mode))
     return FALSE;
  switch (objp->mode) {
  case AM_UNCHECKED:
    if (!xdr_am_sattr3(xdrs, &objp->am_createhow3_u.obj_attributes))
      return FALSE;
    break;
  case AM_GUARDED:
    if (!xdr_am_sattr3(xdrs, &objp->am_createhow3_u.g_obj_attributes))
      return FALSE;
    break;
  case AM_EXCLUSIVE:
    if (!xdr_am_createverf3(xdrs, objp->am_createhow3_u.verf))
      return FALSE;
    break;
  default:
    return FALSE;
  }
  return TRUE;
}

bool_t
xdr_am_CREATE3args(XDR *xdrs, am_CREATE3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_CREATE3args:");

  if (!xdr_am_diropargs3(xdrs, &objp->where))
    return FALSE;
  if (!xdr_am_createhow3(xdrs, &objp->how))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_post_op_fh3(XDR *xdrs, am_post_op_fh3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_post_op_fh3:");

  if (!xdr_bool(xdrs, &objp->handle_follows))
    return FALSE;
  switch (objp->handle_follows) {
  case TRUE:
    if (!xdr_am_nfs_fh3(xdrs, &objp->am_post_op_fh3_u.handle))
      return FALSE;
    break;
  case FALSE:
    break;
  default:
    return FALSE;
  }
  return TRUE;
}

bool_t
xdr_am_CREATE3resok(XDR *xdrs, am_CREATE3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_CREATE3resok:");

  if (!xdr_am_post_op_fh3(xdrs, &objp->obj))
    return FALSE;
  if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
    return FALSE;
  if (!xdr_am_wcc_data(xdrs, &objp->dir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_CREATE3resfail(XDR *xdrs, am_CREATE3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_CREATE3resfail:");

  if (!xdr_am_wcc_data(xdrs, &objp->dir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_CREATE3res(XDR *xdrs, am_CREATE3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_CREATE3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_CREATE3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_CREATE3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_REMOVE3args(XDR *xdrs, am_REMOVE3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_REMOVE3args:");

  if (!xdr_am_diropargs3(xdrs, &objp->object))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_REMOVE3resok(XDR *xdrs, am_REMOVE3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_REMOVE3resok:");

  if (!xdr_am_wcc_data(xdrs, &objp->dir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_REMOVE3resfail(XDR *xdrs, am_REMOVE3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_REMOVE3resfail:");

  if (!xdr_am_wcc_data(xdrs, &objp->dir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_REMOVE3res(XDR *xdrs, am_REMOVE3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_REMOVE3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_REMOVE3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_REMOVE3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_READ3args(XDR *xdrs, am_READ3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READ3args:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->file))
    return FALSE;
  if (!xdr_am_offset3(xdrs, &objp->offset))
    return FALSE;
  if (!xdr_am_count3(xdrs, &objp->count))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_READ3resok(XDR *xdrs, am_READ3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READ3resok:");

  if (!xdr_am_post_op_attr(xdrs, &objp->file_attributes))
    return FALSE;
  if (!xdr_am_count3(xdrs, &objp->count))
    return FALSE;
  if (!xdr_bool(xdrs, &objp->eof))
    return FALSE;
  if (!xdr_bytes(xdrs, (char **)&objp->data.data_val, (u_int *) &objp->data.data_len, ~0))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_READ3resfail(XDR *xdrs, am_READ3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READ3resfail:");

  if (!xdr_am_post_op_attr(xdrs, &objp->file_attributes))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_READ3res(XDR *xdrs, am_READ3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READ3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_READ3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_READ3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_FSINFO3args(XDR *xdrs, am_FSINFO3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_FSINFO3args:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->fsroot))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_FSINFO3resok(XDR *xdrs, am_FSINFO3resok *objp)
{
  register int32_t *buf;

  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_FSINFO3resok:");

  if (xdrs->x_op == XDR_ENCODE) {
    if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
      return FALSE;
    buf = XDR_INLINE(xdrs, 7 * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_u_int(xdrs, &objp->rtmax))
        return FALSE;
      if (!xdr_u_int(xdrs, &objp->rtpref))
        return FALSE;
      if (!xdr_u_int(xdrs, &objp->rtmult))
        return FALSE;
      if (!xdr_u_int(xdrs, &objp->wtmax))
        return FALSE;
      if (!xdr_u_int(xdrs, &objp->wtpref))
        return FALSE;
      if (!xdr_u_int(xdrs, &objp->wtmult))
        return FALSE;
      if (!xdr_u_int(xdrs, &objp->dtpref))
        return FALSE;
    } else {
      IXDR_PUT_U_LONG(buf, objp->rtmax);
      IXDR_PUT_U_LONG(buf, objp->rtpref);
      IXDR_PUT_U_LONG(buf, objp->rtmult);
      IXDR_PUT_U_LONG(buf, objp->wtmax);
      IXDR_PUT_U_LONG(buf, objp->wtpref);
      IXDR_PUT_U_LONG(buf, objp->wtmult);
      IXDR_PUT_U_LONG(buf, objp->dtpref);
    }
    if (!xdr_am_size3(xdrs, &objp->maxfilesize))
      return FALSE;
    if (!xdr_am_nfstime3(xdrs, &objp->time_delta))
      return FALSE;
    if (!xdr_u_int(xdrs, &objp->properties))
      return FALSE;
    return TRUE;
  } else if (xdrs->x_op == XDR_DECODE) {
    if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
      return FALSE;
    buf = XDR_INLINE(xdrs, 7 * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_u_int (xdrs, &objp->rtmax))
        return FALSE;
      if (!xdr_u_int (xdrs, &objp->rtpref))
        return FALSE;
      if (!xdr_u_int (xdrs, &objp->rtmult))
        return FALSE;
      if (!xdr_u_int (xdrs, &objp->wtmax))
        return FALSE;
      if (!xdr_u_int(xdrs, &objp->wtpref))
        return FALSE;
      if (!xdr_u_int(xdrs, &objp->wtmult))
        return FALSE;
      if (!xdr_u_int(xdrs, &objp->dtpref))
        return FALSE;
    } else {
      objp->rtmax = IXDR_GET_U_LONG(buf);
      objp->rtpref = IXDR_GET_U_LONG(buf);
      objp->rtmult = IXDR_GET_U_LONG(buf);
      objp->wtmax = IXDR_GET_U_LONG(buf);
      objp->wtpref = IXDR_GET_U_LONG(buf);
      objp->wtmult = IXDR_GET_U_LONG(buf);
      objp->dtpref = IXDR_GET_U_LONG(buf);
    }
    if (!xdr_am_size3(xdrs, &objp->maxfilesize))
      return FALSE;
    if (!xdr_am_nfstime3(xdrs, &objp->time_delta))
      return FALSE;
    if (!xdr_u_int(xdrs, &objp->properties))
      return FALSE;
    return TRUE;
  }

  if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->rtmax))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->rtpref))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->rtmult))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->wtmax))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->wtpref))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->wtmult))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->dtpref))
   return FALSE;
  if (!xdr_am_size3(xdrs, &objp->maxfilesize))
    return FALSE;
  if (!xdr_am_nfstime3(xdrs, &objp->time_delta))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->properties))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_FSINFO3resfail(XDR *xdrs, am_FSINFO3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_FSINFO3resfail:");

  if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_FSINFO3res(XDR *xdrs, am_FSINFO3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_FSINFO3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_FSINFO3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_FSINFO3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_FSSTAT3args(XDR *xdrs, am_FSSTAT3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_FSSTAT3args:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->fsroot))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_FSSTAT3resok(XDR *xdrs, am_FSSTAT3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_FSSTAT3resok:");

  if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
    return FALSE;
  if (!xdr_am_size3(xdrs, &objp->tbytes))
    return FALSE;
  if (!xdr_am_size3(xdrs, &objp->fbytes))
    return FALSE;
  if (!xdr_am_size3(xdrs, &objp->abytes))
    return FALSE;
  if (!xdr_am_size3(xdrs, &objp->tfiles))
    return FALSE;
  if (!xdr_am_size3(xdrs, &objp->ffiles))
    return FALSE;
  if (!xdr_am_size3(xdrs, &objp->afiles))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->invarsec))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_FSSTAT3resfail(XDR *xdrs, am_FSSTAT3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_FSSTAT3resfail:");

  if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_FSSTAT3res(XDR *xdrs, am_FSSTAT3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_FSSTAT3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_FSSTAT3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_FSSTAT3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_PATHCONF3args(XDR *xdrs, am_PATHCONF3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_PATHCONF3args:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->object))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_PATHCONF3resok(XDR *xdrs, am_PATHCONF3resok *objp)
{
  register int32_t *buf;

  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_PATHCONF3resok:");

  if (xdrs->x_op == XDR_ENCODE) {
    if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
      return FALSE;
    buf = XDR_INLINE(xdrs, 6 * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_u_int(xdrs, &objp->linkmax))
        return FALSE;
      if (!xdr_u_int(xdrs, &objp->name_max))
        return FALSE;
      if (!xdr_bool(xdrs, &objp->no_trunc))
        return FALSE;
      if (!xdr_bool(xdrs, &objp->chown_restricted))
        return FALSE;
      if (!xdr_bool(xdrs, &objp->case_insensitive))
        return FALSE;
      if (!xdr_bool(xdrs, &objp->case_preserving))
        return FALSE;
    } else {
      IXDR_PUT_U_LONG(buf, objp->linkmax);
      IXDR_PUT_U_LONG(buf, objp->name_max);
      IXDR_PUT_BOOL(buf, objp->no_trunc);
      IXDR_PUT_BOOL(buf, objp->chown_restricted);
      IXDR_PUT_BOOL(buf, objp->case_insensitive);
      IXDR_PUT_BOOL(buf, objp->case_preserving);
    }
    return TRUE;
  } else if (xdrs->x_op == XDR_DECODE) {
    if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
      return FALSE;
    buf = XDR_INLINE(xdrs, 6 * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_u_int(xdrs, &objp->linkmax))
        return FALSE;
      if (!xdr_u_int(xdrs, &objp->name_max))
        return FALSE;
      if (!xdr_bool(xdrs, &objp->no_trunc))
        return FALSE;
      if (!xdr_bool(xdrs, &objp->chown_restricted))
        return FALSE;
      if (!xdr_bool(xdrs, &objp->case_insensitive))
        return FALSE;
      if (!xdr_bool(xdrs, &objp->case_preserving))
        return FALSE;
    } else {
      objp->linkmax = IXDR_GET_U_LONG(buf);
      objp->name_max = IXDR_GET_U_LONG(buf);
      objp->no_trunc = IXDR_GET_BOOL(buf);
      objp->chown_restricted = IXDR_GET_BOOL(buf);
      objp->case_insensitive = IXDR_GET_BOOL(buf);
      objp->case_preserving = IXDR_GET_BOOL(buf);
    }
    return TRUE;
  }

  if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->linkmax))
    return FALSE;
  if (!xdr_u_int(xdrs, &objp->name_max))
    return FALSE;
  if (!xdr_bool(xdrs, &objp->no_trunc))
    return FALSE;
  if (!xdr_bool(xdrs, &objp->chown_restricted))
    return FALSE;
  if (!xdr_bool(xdrs, &objp->case_insensitive))
    return FALSE;
  if (!xdr_bool(xdrs, &objp->case_preserving))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_PATHCONF3resfail(XDR *xdrs, am_PATHCONF3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_PATHCONF3resfail:");

  if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_PATHCONF3res(XDR *xdrs, am_PATHCONF3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_PATHCONF3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_PATHCONF3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_PATHCONF3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_nfspath3(XDR *xdrs, am_nfspath3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_nfspath3:");

  if (!xdr_string(xdrs, objp, ~0))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_symlinkdata3(XDR *xdrs, am_symlinkdata3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_symlinkdata3:");

  if (!xdr_am_sattr3(xdrs, &objp->symlink_attributes))
    return FALSE;
  if (!xdr_am_nfspath3(xdrs, &objp->symlink_data))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_SYMLINK3args(XDR *xdrs, am_SYMLINK3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_SYMLINK3args:");

  if (!xdr_am_diropargs3(xdrs, &objp->where))
    return FALSE;
  if (!xdr_am_symlinkdata3(xdrs, &objp->symlink))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_SYMLINK3resok(XDR *xdrs, am_SYMLINK3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_SYMLINK3resok:");

  if (!xdr_am_post_op_fh3(xdrs, &objp->obj))
    return FALSE;
  if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
    return FALSE;
  if (!xdr_am_wcc_data(xdrs, &objp->dir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_SYMLINK3resfail(XDR *xdrs, am_SYMLINK3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_SYMLINK3resfail:");

  if (!xdr_am_wcc_data(xdrs, &objp->dir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_SYMLINK3res(XDR *xdrs, am_SYMLINK3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_SYMLINK3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_SYMLINK3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_SYMLINK3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_READLINK3args(XDR *xdrs, am_READLINK3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READLINK3args:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->symlink))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_READLINK3resok(XDR *xdrs, am_READLINK3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READLINK3resok:");

  if (!xdr_am_post_op_attr(xdrs, &objp->symlink_attributes))
    return FALSE;
  if (!xdr_am_nfspath3(xdrs, &objp->data))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_READLINK3resfail(XDR *xdrs, am_READLINK3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READLINK3resfail:");

  if (!xdr_am_post_op_attr(xdrs, &objp->symlink_attributes))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_READLINK3res(XDR *xdrs, am_READLINK3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READLINK3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_READLINK3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_READLINK3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_devicedata3(XDR *xdrs, am_devicedata3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_devicedata3:");

  if (!xdr_am_sattr3(xdrs, &objp->dev_attributes))
    return FALSE;
  if (!xdr_am_specdata3(xdrs, &objp->spec))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_mknoddata3(XDR *xdrs, am_mknoddata3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_mknoddata3:");

  if (!xdr_am_ftype3(xdrs, &objp->type))
    return FALSE;
  switch (objp->type) {
  case AM_NF3CHR:
    if (!xdr_am_devicedata3(xdrs, &objp->am_mknoddata3_u.chr_device))
      return FALSE;
    break;
  case AM_NF3BLK:
    if (!xdr_am_devicedata3(xdrs, &objp->am_mknoddata3_u.blk_device))
      return FALSE;
    break;
  case AM_NF3SOCK:
    if (!xdr_am_sattr3(xdrs, &objp->am_mknoddata3_u.sock_attributes))
      return FALSE;
    break;
  case AM_NF3FIFO:
    if (!xdr_am_sattr3(xdrs, &objp->am_mknoddata3_u.pipe_attributes))
      return FALSE;
    break;
  default:
    break;
  }
  return TRUE;
}

bool_t
xdr_am_MKNOD3args(XDR *xdrs, am_MKNOD3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_MKNOD3args:");

  if (!xdr_am_diropargs3(xdrs, &objp->where))
    return FALSE;
  if (!xdr_am_mknoddata3(xdrs, &objp->what))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_MKNOD3resok(XDR *xdrs, am_MKNOD3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_MKNOD3resok:");

  if (!xdr_am_post_op_fh3(xdrs, &objp->obj))
    return FALSE;
  if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
    return FALSE;
  if (!xdr_am_wcc_data(xdrs, &objp->dir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_MKNOD3resfail(XDR *xdrs, am_MKNOD3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_MKNOD3resfail:");

  if (!xdr_am_wcc_data(xdrs, &objp->dir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_MKNOD3res(XDR *xdrs, am_MKNOD3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, ":");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_MKNOD3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_MKNOD3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_MKDIR3args(XDR *xdrs, am_MKDIR3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, ":");

  if (!xdr_am_diropargs3(xdrs, &objp->where))
    return FALSE;
  if (!xdr_am_sattr3(xdrs, &objp->attributes))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_MKDIR3resok(XDR *xdrs, am_MKDIR3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_MKDIR3resok:");

  if (!xdr_am_post_op_fh3(xdrs, &objp->obj))
    return FALSE;
  if (!xdr_am_post_op_attr(xdrs, &objp->obj_attributes))
    return FALSE;
  if (!xdr_am_wcc_data(xdrs, &objp->dir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_MKDIR3resfail(XDR *xdrs, am_MKDIR3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_MKDIR3resfail:");

  if (!xdr_am_wcc_data(xdrs, &objp->dir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_MKDIR3res(XDR *xdrs, am_MKDIR3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_MKDIR3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_MKDIR3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_MKDIR3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_RMDIR3args(XDR *xdrs, am_RMDIR3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_RMDIR3args:");

  if (!xdr_am_diropargs3(xdrs, &objp->object))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_RMDIR3resok(XDR *xdrs, am_RMDIR3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_RMDIR3resok:");

  if (!xdr_am_wcc_data(xdrs, &objp->dir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_RMDIR3resfail(XDR *xdrs, am_RMDIR3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_RMDIR3resfail:");

  if (!xdr_am_wcc_data(xdrs, &objp->dir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_RMDIR3res(XDR *xdrs, am_RMDIR3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_RMDIR3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_RMDIR3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_RMDIR3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_RENAME3args(XDR *xdrs, am_RENAME3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_RENAME3args:");

  if (!xdr_am_diropargs3(xdrs, &objp->from))
    return FALSE;
  if (!xdr_am_diropargs3(xdrs, &objp->to))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_RENAME3resok(XDR *xdrs, am_RENAME3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_RENAME3resok:");

  if (!xdr_am_wcc_data(xdrs, &objp->fromdir_wcc))
    return FALSE;
  if (!xdr_am_wcc_data(xdrs, &objp->todir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_RENAME3resfail(XDR *xdrs, am_RENAME3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_RENAME3resfail:");

  if (!xdr_am_wcc_data(xdrs, &objp->fromdir_wcc))
    return FALSE;
  if (!xdr_am_wcc_data(xdrs, &objp->todir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_RENAME3res(XDR *xdrs, am_RENAME3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_RENAME3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_RENAME3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_RENAME3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_READDIRPLUS3args(XDR *xdrs, am_READDIRPLUS3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READDIRPLUS3args:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->dir))
    return FALSE;
  if (!xdr_am_cookie3(xdrs, &objp->cookie))
    return FALSE;
  if (!xdr_am_cookieverf3(xdrs, objp->cookieverf))
    return FALSE;
  if (!xdr_am_count3(xdrs, &objp->dircount))
    return FALSE;
  if (!xdr_am_count3(xdrs, &objp->maxcount))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_entryplus3(XDR *xdrs, am_entryplus3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_entryplus3:");

   if (!xdr_am_fileid3(xdrs, &objp->fileid))
     return FALSE;
   if (!xdr_am_filename3(xdrs, &objp->name))
     return FALSE;
   if (!xdr_am_cookie3(xdrs, &objp->cookie))
     return FALSE;
   if (!xdr_am_post_op_attr(xdrs, &objp->name_attributes))
     return FALSE;
   if (!xdr_am_post_op_fh3(xdrs, &objp->name_handle))
     return FALSE;
   if (!xdr_pointer(xdrs, (char **)&objp->nextentry,
                   sizeof(am_entryplus3), (xdrproc_t) xdr_am_entryplus3))
     return FALSE;
  return TRUE;
}

bool_t
xdr_am_dirlistplus3(XDR *xdrs, am_dirlistplus3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_dirlistplus3:");

  if (!xdr_pointer(xdrs, (char **)&objp->entries,
                   sizeof(am_entryplus3), (xdrproc_t) xdr_am_entryplus3))
    return FALSE;
  if (!xdr_bool(xdrs, &objp->eof))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_READDIRPLUS3resok(XDR *xdrs, am_READDIRPLUS3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READDIRPLUS3resok:");

  if (!xdr_am_post_op_attr(xdrs, &objp->dir_attributes))
    return FALSE;
  if (!xdr_am_cookieverf3(xdrs, objp->cookieverf))
    return FALSE;
  if (!xdr_am_dirlistplus3(xdrs, &objp->reply))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_READDIRPLUS3resfail(XDR *xdrs, am_READDIRPLUS3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READDIRPLUS3resfail:");

  if (!xdr_am_post_op_attr(xdrs, &objp->dir_attributes))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_READDIRPLUS3res(XDR *xdrs, am_READDIRPLUS3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READDIRPLUS3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_READDIRPLUS3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_READDIRPLUS3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_READDIR3args(XDR *xdrs, am_READDIR3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READDIR3args:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->dir))
    return FALSE;
  if (!xdr_am_cookie3(xdrs, &objp->cookie))
    return FALSE;
  if (!xdr_am_cookieverf3(xdrs, objp->cookieverf))
    return FALSE;
  if (!xdr_am_count3(xdrs, &objp->count))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_entry3(XDR *xdrs, am_entry3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_entry3:");

  if (!xdr_am_fileid3(xdrs, &objp->fileid))
    return FALSE;
  if (!xdr_am_filename3(xdrs, &objp->name))
    return FALSE;
  if (!xdr_am_cookie3(xdrs, &objp->cookie))
    return FALSE;
  if (!xdr_pointer(xdrs, (char **)&objp->nextentry,
                   sizeof(am_entry3), (xdrproc_t) xdr_am_entry3))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_dirlist3(XDR *xdrs, am_dirlist3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_dirlist3:");

  if (!xdr_pointer(xdrs, (char **)&objp->entries,
                   sizeof(am_entry3), (xdrproc_t) xdr_am_entry3))
    return FALSE;
  if (!xdr_bool (xdrs, &objp->eof))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_READDIR3resok(XDR *xdrs, am_READDIR3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READDIR3resok:");

  if (!xdr_am_post_op_attr(xdrs, &objp->dir_attributes))
    return FALSE;
  if (!xdr_am_cookieverf3(xdrs, objp->cookieverf))
    return FALSE;
  if (!xdr_am_dirlist3(xdrs, &objp->reply))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_READDIR3resfail(XDR *xdrs, am_READDIR3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READDIR3resfail:");

  if (!xdr_am_post_op_attr(xdrs, &objp->dir_attributes))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_READDIR3res(XDR *xdrs, am_READDIR3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_READDIR3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_READDIR3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_READDIR3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_LINK3args(XDR *xdrs, am_LINK3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_LINK3args:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->file))
    return FALSE;
  if (!xdr_am_diropargs3(xdrs, &objp->link))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_LINK3resok(XDR *xdrs, am_LINK3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_LINK3resok:");

  if (!xdr_am_post_op_attr(xdrs, &objp->file_attributes))
    return FALSE;
  if (!xdr_am_wcc_data(xdrs, &objp->linkdir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_LINK3resfail(XDR *xdrs, am_LINK3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_LINK3resfail:");

  if (!xdr_am_post_op_attr(xdrs, &objp->file_attributes))
    return FALSE;
  if (!xdr_am_wcc_data(xdrs, &objp->linkdir_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_LINK3res(XDR *xdrs, am_LINK3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_LINK3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_LINK3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_LINK3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_am_sattrguard3(XDR *xdrs, am_sattrguard3 *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_sattrguard3:");

  if (!xdr_bool(xdrs, &objp->check))
    return FALSE;
  switch (objp->check) {
  case TRUE:
    if (!xdr_am_nfstime3(xdrs, &objp->am_sattrguard3_u.obj_ctime))
      return FALSE;
    break;
  case FALSE:
    break;
  default:
    return FALSE;
  }
  return TRUE;
}

bool_t
xdr_am_SETATTR3args(XDR *xdrs, am_SETATTR3args *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_SETATTR3args:");

  if (!xdr_am_nfs_fh3(xdrs, &objp->object))
    return FALSE;
  if (!xdr_am_sattr3(xdrs, &objp->new_attributes))
    return FALSE;
  if (!xdr_am_sattrguard3(xdrs, &objp->guard))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_SETATTR3resok(XDR *xdrs, am_SETATTR3resok *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_SETATTR3resok:");

  if (!xdr_am_wcc_data(xdrs, &objp->obj_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_SETATTR3resfail(XDR *xdrs, am_SETATTR3resfail *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_SETATTR3resfail:");

  if (!xdr_am_wcc_data(xdrs, &objp->obj_wcc))
    return FALSE;
  return TRUE;
}

bool_t
xdr_am_SETATTR3res(XDR *xdrs, am_SETATTR3res *objp)
{
  if (amuDebug(D_XDRTRACE))
    plog(XLOG_DEBUG, "xdr_am_SETATTR3res:");

  if (!xdr_am_nfsstat3(xdrs, &objp->status))
    return FALSE;
  switch (objp->status) {
  case AM_NFS3_OK:
    if (!xdr_am_SETATTR3resok(xdrs, &objp->res_u.ok))
      return FALSE;
    break;
  default:
    if (!xdr_am_SETATTR3resfail(xdrs, &objp->res_u.fail))
      return FALSE;
    break;
  }
  return TRUE;
}
#endif /* HAVE_FS_NFS3 */
