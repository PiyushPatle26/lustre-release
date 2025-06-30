/* SPDX-License-Identifier: GPL-2.0 */

/*
 * Copyright (c) 2008, 2010, Oracle and/or its affiliates. All rights reserved.
 * Use is subject to license terms.
 *
 * Copyright (c) 2011, 2014, Intel Corporation.
 */

/*
 * This file is part of Lustre, http://www.lustre.org/
 *
 * Basic library routines.
 */

#ifndef __LIBCFS_LINUX_MEM_H__
#define __LIBCFS_LINUX_MEM_H__

#include <linux/mm.h>
#include <linux/vmalloc.h>
#include <linux/slab.h>
#include <linux/percpu.h>
#include <linux/mm_inline.h>
#include <linux/pagemap.h>
#include <linux/mmap_lock.h>

/* Use kernel's memory management functions directly */
#define memalloc_noreclaim_save() memalloc_noreclaim_save()
#define memalloc_noreclaim_restore(flags) memalloc_noreclaim_restore(flags)

/* Use kernel's bitmap functions directly */
#define bitmap_alloc(nbits, flags) bitmap_alloc(nbits, flags)
#define bitmap_zalloc(nbits, flags) bitmap_zalloc(nbits, flags)
#define bitmap_free(bitmap) bitmap_free(bitmap)

/* Use kernel's mmap functions directly */
#define mmap_write_lock(mm) mmap_write_lock(mm)
#define mmap_write_unlock(mm) mmap_write_unlock(mm)
#define mmap_read_lock(mm) mmap_read_lock(mm)
#define mmap_read_unlock(mm) mmap_read_unlock(mm)
#define mmap_write_trylock(mm) mmap_write_trylock(mm)
#define mmap_read_trylock(mm) mmap_read_trylock(mm)

unsigned long cfs_totalram_pages(void);

#ifdef HAVE_VMALLOC_2ARGS
#define __ll_vmalloc(size, flags) __vmalloc(size, flags)
#else
#define __ll_vmalloc(size, flags) __vmalloc(size, flags, PAGE_KERNEL)
#endif

void init_libcfs_vfree_atomic(void);
void exit_libcfs_vfree_atomic(void);

/* atomic-context safe vfree */
void libcfs_vfree_atomic(const void *addr);

#ifndef HAVE_KFREE_SENSITIVE
#define kfree_sensitive(x)      kzfree(x)
#endif

#endif /* __LIBCFS_LINUX_MEM_H__ */
