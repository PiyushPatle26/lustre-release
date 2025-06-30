/* SPDX-License-Identifier: GPL-2.0 */

/*
 * Copyright (c) 2010, Oracle and/or its affiliates. All rights reserved.
 *
 * Copyright (c) 2012, 2017, Intel Corporation.
 */

/*
 * This file is part of Lustre, http://www.lustre.org/
 *
 * Basic library routines.
 *
 * Author: liang@whamcloud.com
 */

#ifndef __LIBCFS_LINUX_CPU_H__
#define __LIBCFS_LINUX_CPU_H__

#include <linux/cpu.h>
#include <linux/cpumask.h>
#include <linux/topology.h>
#include <linux/sched.h>

/* Use kernel's CPU functions directly */
#define topology_sibling_cpumask(cpu) topology_thread_cpumask(cpu)
#define cpus_read_lock() cpus_read_lock()
#define cpus_read_unlock() cpus_read_unlock()

#endif /* __LIBCFS_LINUX_CPU_H__ */
