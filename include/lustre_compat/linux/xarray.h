/* SPDX-License-Identifier: GPL-2.0+ */

#ifndef _LUSTRE_COMPAT_XARRAY_H
#define _LUSTRE_COMPAT_XARRAY_H

#include <linux/xarray.h>

/* Use kernel's xarray implementation directly */
#define ll_xa_is_value(entry) xa_is_value(entry)
#define ll_xa_to_value(entry) xa_to_value(entry)
#define ll_xa_mk_value(entry) xa_mk_value(entry)

#endif /* _LUSTRE_COMPAT_XARRAY_H */
