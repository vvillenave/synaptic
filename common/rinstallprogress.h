/* rinstallprogress.h
 *
 * Copyright (c) 2000, 2001 Conectiva S/A
 *                     2002 Michael Vogt
 *
 * Author: Alfredo K. Kojima <kojima@conectiva.com.br>
 *         Michael Vogt <mvo@debian.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */


#ifndef _RINSTALLPROGRESS_H_
#define _RINSTALLPROGRESS_H_

#include "config.h"
#include <pthread.h>
#include <apt-pkg/packagemanager.h>


class RInstallProgress {
protected:
   static void *loop(void *data);
   
   int _stdout;
   int _stderr;
   int _childin;
   
   int _thread_id;
   pthread_t _thread;

   int _numPackages;

   virtual void startUpdate() {};
   virtual void updateInterface() {};
   virtual void finishUpdate() {};

public:
   virtual pkgPackageManager::OrderResult start(pkgPackageManager *pm,
		   				int numPackages = 0);

};


#endif
