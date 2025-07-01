# SPDX-License-Identifier: GPL-2.0

#
# This file is part of Lustre, http://www.lustre.org/
#

# Only build xarray.o if not building for Linux 6.14+
ifneq ($(HAVE_LINUX_6_14_API),1)
lib_objs += xarray.o
endif

lib_objs += glob.o generic-radix-tree.o
