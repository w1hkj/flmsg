// ----------------------------------------------------------------------------
// threads.cxx
//
// Copyright (C) 2007-2009
//		Stelios Bounanos, M0GLD
// ----------------------------------------------------------------------------
// Copyright (C) 2014
//              David Freese, W1HKJ
//
// This file is part of flmsg
//
// flrig is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// flrig is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#include <stdio.h>

#include <config.h>
#include <stdexcept>
#include <string.h>
#include <errno.h>
#include "threads.h"

#include "timeops.h"

guard_lock::guard_lock(pthread_mutex_t* m) : mutex(m)
{
	pthread_mutex_lock(mutex);
}

guard_lock::~guard_lock(void)
{
	pthread_mutex_unlock(mutex);
}

