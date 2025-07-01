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

#ifdef HAVE_LINUX_6_14_API
#include <linux/cpu.h>
#else
#ifndef HAVE_TOPOLOGY_SIBLING_CPUMASK
# define topology_sibling_cpumask(cpu)	topology_thread_cpumask(cpu)
#endif /* HAVE_TOPOLOGY_SIBLING_CPUMASK */

#ifndef HAVE_CPUS_READ_LOCK
# define cpus_read_lock		get_online_cpus
# define cpus_read_unlock	put_online_cpus
#endif
#endif /* HAVE_LINUX_6_14_API */

#endif /* __LIBCFS_LINUX_CPU_H__ */
