/* SPDX-License-Identifier: GPL-2.0 */

/*
 * Copyright (c) 2008, 2010, Oracle and/or its affiliates. All rights reserved.
 * Use is subject to license terms.
 *
 * Copyright (c) 2014, Intel Corporation.
 */

/*
 * This file is part of Lustre, http://www.lustre.org/
 *
 * Implementation of portable time API for Linux (kernel and user-level).
 *
 * Author: Nikita Danilov <nikita@clusterfs.com>
 */

#ifndef __LIBCFS_LINUX_TIME_H__
#define __LIBCFS_LINUX_TIME_H__

#include <linux/time.h>
#include <linux/time64.h>
#include <linux/timekeeping.h>
#include <linux/ktime.h>

/* Use kernel's time functions directly */
#define timespec_to_timespec64(ts) (ts)
#define timespec64_to_timespec(ts) (ts)
#define ns_to_timespec64(ns) ns_to_timespec64(ns)
#define timespec64_sub(later, earlier) timespec64_sub(later, earlier)
#define timespec64_to_ktime(ts) timespec64_to_ktime(ts)

/* Use kernel's ktime functions directly */
#define ktime_get_ts64(ts) ktime_get_ts64(ts)
#define ktime_get_real_ts64(ts) ktime_get_real_ts64(ts)
#define ktime_get_real_seconds() ktime_get_real_seconds()
#define ktime_get_seconds() ktime_get_seconds()
#define ktime_ms_delta(later, earlier) ktime_ms_delta(later, earlier)

#endif /* __LIBCFS_LINUX_TIME_H__ */
