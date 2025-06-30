/* SPDX-License-Identifier: GPL-2.0 */

/*
 * Copyright (c) 2003, 2010, Oracle and/or its affiliates. All rights reserved.
 * Use is subject to license terms.
 *
 * Copyright (c) 2011, 2017, Intel Corporation.
 */

/*
 * This file is part of Lustre, http://www.lustre.org/
 */

#ifndef _LUSTRE_COMPAT_H
#define _LUSTRE_COMPAT_H

#include <linux/aio.h>
#include <linux/fs.h>
#include <linux/namei.h>
#include <linux/pagemap.h>
#include <linux/posix_acl_xattr.h>
#include <linux/bio.h>
#include <linux/xattr.h>
#include <linux/workqueue.h>
#include <linux/blkdev.h>
#include <linux/backing-dev.h>
#include <linux/slab.h>
#include <linux/security.h>
#include <linux/pagevec.h>
#include <linux/workqueue.h>
#include <linux/time64.h>
#include <linux/timekeeping.h>
#include <linux/xarray.h>
#include <linux/mm.h>
#include <linux/uio.h>
#include <linux/fs_struct.h>
#include <linux/mount.h>
#include <linux/netlink.h>
#include <linux/sched/signal.h>
#include <linux/cred.h>
#include <linux/key.h>
#include <linux/key-type.h>
#include <linux/keyctl.h>
#include <linux/init_task.h>
#include <linux/bio.h>
#include <linux/blkdev.h>
#include <linux/crypto.h>
#include <linux/scatterlist.h>
#include <crypto/hash.h>
#include <crypto/skcipher.h>
#include <libcfs/linux/linux-fs.h>
#include <libcfs/linux/linux-time.h>
#include <libcfs/linux/linux-mem.h>
#include <libcfs/linux/linux-misc.h>
#include <libcfs/linux/linux-fs.h>
#include <libcfs/linux/linux-tcpip.h>
#include <libcfs/linux/linux-crypto.h>
#include <obd_support.h>

/* Use kernel's xarray implementation directly */
#define ll_xa_is_value(entry) xa_is_value(entry)
#define ll_xa_to_value(entry) xa_to_value(entry)
#define ll_xa_mk_value(entry) xa_mk_value(entry)

/* Use kernel's bio functions directly */
#define cfs_bio_alloc(gfp_mask, nr_iovecs) bio_alloc(NULL, nr_iovecs, gfp_mask, GFP_NOIO)
#define cfs_bio_set_op_attrs(bio, op, flags) bio_set_op_attrs(bio, op, flags)

/* Time compatibility declarations */
void ktime_get_ts64(struct timespec64 *ts);
void ktime_get_real_ts64(struct timespec64 *ts);

/* Compatibility functions for xattr */
static inline int ll_vfs_getxattr(struct dentry *dentry, const char *name,
                                 void *value, size_t size)
{
    return __vfs_getxattr(dentry, dentry->d_inode, name, value, size);
}

static inline int ll_vfs_setxattr(struct dentry *dentry, const char *name,
                                 const void *value, size_t size, int flags)
{
    return __vfs_setxattr(&nop_mnt_idmap, dentry, dentry->d_inode,
                         name, value, size, flags);
}

static inline int ll_vfs_removexattr(struct dentry *dentry, const char *name)
{
    return __vfs_removexattr(&nop_mnt_idmap, dentry, name);
}

#endif /* _LUSTRE_COMPAT_H */
