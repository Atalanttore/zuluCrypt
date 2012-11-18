/*
 * 
 *  Copyright (c) 2011
 *  name : mhogo mchungu 
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 * 
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libcryptsetup.h>   
#include <stdlib.h>

#include "../utility/string/String.h"
#include "../utility/string/StringList.h"
#include "../utility/process/process.h"
#include "../constants.h"
#include "libzuluCrypt.h"
#include "../bin/bash_special_chars.h"

/*
 * below header is created at build time,it is set by CMakeLists.txt located in the root folder
 */
#include "version.h"

string_t zuluCryptCreateMapperName( const char * device,const char * mapping_name,uid_t uid,int i ) ;

/*
 * this function checks if path exists or not.
 * return 1 if the path exists
 * return 0 if it does not
 */
int zuluCryptPathIsValid( const char * path ) ;

/*
 * this function checks if a path exists or not
 * return 1 if the path does not exists
 * return 0 if the path exist
 */
int zuluCryptPathIsNotValid( const char * path ) ;

/*
 * this function is deined in ../lib/print_mountd_volumes.c
 * return 1 if mtab is a file and is located at /etc
 * return 0 otherwise
 */
int zuluCryptMtabIsAtEtc( void ) ;

/*
 * this is defined in print_mounted_volumes.c
 */
int zuluCryptPartitionIsMounted( const char * device ) ;

/*
 *  parse "/etc/fstab" and return a field at position "pos" on a line
 *  that corresponds to device "device".  
 */
#define MOUNTPOINT   1
#define FILESYSTEM   2
#define MOUNTOPTIONS 3
#define DUMPOPTION   4
#define FSCKOPTION   5
string_t zuluCryptGetMountOptionsFromFstab( const char * device,int pos ) ;

/*
 * this function is defined in print_mounted_volumes.c
 * It return an entry of a partition if it is found in /etc/mtab
 * It return StringVoid otherwise
 */
string_t zuluCryptGetMtabEntry( const char * path ) ;

/*
 * this function is defined in is_luks.c
 */
int zuluCryptVolumeIsNotLuks( const char * dev ) ;

/*
 * this function is defined in ./create_loop_device.c
 */
int zuluCryptAttachLoopDeviceToFile( const char * path,int mode,int * fd,string_t * loop_device ) ;
