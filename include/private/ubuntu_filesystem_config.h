/*
 * Copyright 2014 Canonical Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* This file is used to define the properties of the filesystem
** images generated by build tools (mkbootfs and mkyaffs2image) and
** by the device side of adb.
*/

#ifndef _UBUNTU_FILESYSTEM_CONFIG_H_
#define _UBUNTU_FILESYSTEM_CONFIG_H_

#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdint.h>


/* This is the master Users and Groups config for the platform.
 * DO NOT EVER RENUMBER
 */

#define UBUNTU_ID_ROOT             0  /* traditional unix root user */
#define UBUNTU_PHABLET         32011  /* Ubuntu phone phablet user */

#define U_CLICKPKG_UID           103
#define U_CLICKPKG_GID           107

#define U_LIGHTDM_UID            108
#define U_LIGHTDM_GID            111

#define U_MESSAGEBUS_U           102
#define U_MESSAGEBUS_G           106
#define U_UBUNTU_TMP_G            43

#define U_WHOOPSIE_G             110

#define U_USERMETRICS_U          101
#define U_USERMETRICS_G          104

#define U_STAFF_GID               50
#define U_SYSLOG_GID             103
#define U_MAIL_GID                 8
#define U_CRONTAB_GID            102

#define U_SYSLOG_UID             100
#define U_ADM_GID                  4

#define U_LIBUUID_GID            101

#define U_DNSMASQ_UID            104
#define U_NOGROUP_GID            65534

#define U_SHADOW_GID              42
#define U_SSH_GID                108
#define U_TTY_GID                  5

typedef struct ubuntu_fs_path_config {
    unsigned mode;
    unsigned uid;
    unsigned gid;
    uint64_t capabilities;
    const char *prefix;
} ubuntu_fs_path_config;

static struct ubuntu_fs_path_config* ubuntu_files_c;
static struct ubuntu_fs_path_config* ubuntu_dirs_c;

/* Rules for directories.
** These rules are applied based on "first match", so they
** should start with the most specific path and work their
** way up to the root. Prefixes ending in * denotes wildcard
** and will allow partial matches.
*/

static const struct ubuntu_fs_path_config ubuntu_dirs[] = {
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "android" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "bin" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "boot" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "dev" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "etc" },
    { 00700, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "etc/polkit-1/localauthority" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "etc/*" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "home" },
    { 00755, UBUNTU_PHABLET,   UBUNTU_PHABLET,  0, "home/phablet" },
    { 00755, UBUNTU_PHABLET,   UBUNTU_PHABLET,  0, "home/phablet/*" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "lib" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "lib/*" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "media" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "mnt" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "opt" },
    { 00755, U_CLICKPKG_UID,   U_CLICKPKG_GID,  0, "opt/click.ubuntu.com" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "proc" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "root" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "run" },
    { 00755, U_MESSAGEBUS_U,   U_MESSAGEBUS_G,  0, "run/dbus" },
    { 00755, U_DNSMASQ_UID,    U_NOGROUP_GID,   0, "run/dnsmasq" },
    { 00755, UBUNTU_ID_ROOT,   U_LIBUUID_GID,   0, "run/network" },
    { 01777, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "run/lock" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "run/*" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "sbin" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "srv" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "sys" },
    { 01777, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "tmp" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "usr" },
    { 02775, UBUNTU_ID_ROOT,   U_STAFF_GID,     0, "usr/local/lib/python3.4" },
    { 02775, UBUNTU_ID_ROOT,   U_STAFF_GID,     0, "usr/local/lib/python3.4/dist-packages" },
    { 02775, UBUNTU_ID_ROOT,   U_STAFF_GID,     0, "usr/local/share/ca-certificates" },
    { 02775, UBUNTU_ID_ROOT,   U_STAFF_GID,     0, "usr/local/share/emacs" },
    { 02775, UBUNTU_ID_ROOT,   U_STAFF_GID,     0, "usr/local/share/emacs/site-lisp" },
    { 02775, UBUNTU_ID_ROOT,   U_STAFF_GID,     0, "usr/local/share/fonts" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "usr/share/click/preinstalled/.click/users/@all" },
    { 00755, U_CLICKPKG_UID,   U_CLICKPKG_GID,  0, "usr/share/click/preinstalled" },
    { 00755, U_CLICKPKG_UID,   U_CLICKPKG_GID,  0, "usr/share/click/preinstalled/*" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "usr/*" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "var" },
    { 03777, UBUNTU_ID_ROOT,   U_WHOOPSIE_G,    0, "var/crash" },
    { 00750, U_LIGHTDM_UID,    U_LIGHTDM_GID,   0, "var/lib/lightdm" },
    { 02775, UBUNTU_ID_ROOT,   U_STAFF_GID,     0, "var/local" },
    { 00775, UBUNTU_ID_ROOT,   U_SYSLOG_GID,    0, "var/log" },
    { 02775, UBUNTU_ID_ROOT,   U_MAIL_GID,      0, "var/mail" },
    { 03777, UBUNTU_ID_ROOT,   U_WHOOPSIE_G,    0, "var/metrics" },
    { 01777, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "var/tmp" },
    { 02770, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "var/lib/system-image" },
    { 02775, U_LIGHTDM_UID,    U_LIGHTDM_GID,   0, "var/lib/libuuid" },
    { 00750, U_USERMETRICS_U,  U_USERMETRICS_G, 0, "var/lib/usermetrics" },
    { 01730, UBUNTU_ID_ROOT,   U_CRONTAB_GID,   0, "var/spool/cron/crontabs" },
    { 00700, U_SYSLOG_UID,     U_ADM_GID,       0, "var/spool/rsyslog" },
    { 02770, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "var/log/system-image" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "var/*" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "userdata" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "custom" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, "custom/*" },
    { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, 0 },
};

/* Rules for files.
** These rules are applied based on "first match", so they
** should start with the most specific path and work their
** way up to the root. Prefixes ending in * denotes wildcard
** and will allow partial matches.
*/
static const struct ubuntu_fs_path_config ubuntu_files[] = {
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "bin/ping" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "bin/umount" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "bin/ping6" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "bin/mount" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "bin/su" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "bin/*" },
    { 00600, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/apparmor.d/cache/lightdm-guest-session" },
    { 00600, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/apparmor.d/cache/lightdm-guest-session" },
    { 00600, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/apparmor.d/cache/lxc-containers" },
    { 00600, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/apparmor.d/cache/sbin.dhclient" },
    { 00600, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/apparmor.d/cache/usr.bin.lxc-start" },
    { 00600, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/apparmor.d/cache/usr.bin.media-hub-server" },
    { 00600, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/apparmor.d/cache/usr.bin.mediascanner-service-2.0" },
    { 00600, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/apparmor.d/cache/usr.lib.telepathy" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/apm/*" },
    { 00644, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/init.d/README" },
    { 00644, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/init.d/skeleton" },
    { 00644, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/init.d/.*" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/init.d/*" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/initramfs/post-update.d/zz-flash-touch-initrd" },
    { 00440, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/sudoers.d/README" },
    { 00440, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/sudoers" },
    { 00600, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/security/opasswd" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/cron.daily/logrotate" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/cron.daily/upstart" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/cron.daily/dpkg" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/cron.daily/passwd" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/cron.daily/apport" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/cron.daily/apt" },
    { 00640, UBUNTU_ID_ROOT,      U_SHADOW_GID,        0, "etc/gshadow" },
    { 00640, UBUNTU_ID_ROOT,      U_SHADOW_GID,        0, "etc/shadow" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/gtk-3.0/settings.ini" },
    { 00600, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/security/opasswd" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/wpa_supplicant/*" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/security/namespace.init" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/network/if-pre-up.d/*" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/network/if-post-down.d/*" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/network/if-down.d/*" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/network/if-up.d/*" },
    { 00644, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "etc/*" },
    { 00644, UBUNTU_PHABLET,      UBUNTU_PHABLET,      0, "home/phablet/*" },
    { 00644, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "lib/*" },
    { 00644, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "root/*" },
    { 00644, UBUNTU_ID_ROOT,      U_UBUNTU_TMP_G,      0, "run/utmp" },
    { 00444, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "run/resolvconf/*" },
    { 00644, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "run/*" },
    { 02755, UBUNTU_ID_ROOT,      U_SHADOW_GID,        0, "sbin/pam_extrausers_chkpwd" },
    { 02755, UBUNTU_ID_ROOT,      U_SHADOW_GID,        0, "sbin/unix_chkpwd" },
    { 00755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "sbin/*" },
    { 02755, UBUNTU_ID_ROOT,      U_SHADOW_GID,        0, "usr/bin/chage" },
    { 02755, UBUNTU_ID_ROOT,      U_CRONTAB_GID,       0, "usr/bin/crontab" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/bin/chfn" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/bin/chsh" },
    { 02755, UBUNTU_ID_ROOT,      U_MAIL_GID,          0, "usr/bin/dotlockfile" },
    { 02755, UBUNTU_ID_ROOT,      U_SHADOW_GID,        0, "usr/bin/expiry" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/bin/gpasswd" },
    { 02755, UBUNTU_ID_ROOT,      U_MAIL_GID,          0, "usr/bin/mail-lock" },
    { 02755, UBUNTU_ID_ROOT,      U_MAIL_GID,          0, "usr/bin/mail-touchlock" },
    { 02755, UBUNTU_ID_ROOT,      U_MAIL_GID,          0, "usr/bin/mail-unlock" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/bin/newgrp" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/bin/passwd" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/bin/pkexec" },
    { 02755, UBUNTU_ID_ROOT,      U_SSH_GID,           0, "usr/bin/ssh-agent" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/bin/sudo" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/bin/tcptraceroute.mt" },
    { 02755, UBUNTU_ID_ROOT,      U_TTY_GID,           0, "usr/bin/wall" },
    { 02755, UBUNTU_ID_ROOT,      U_TTY_GID,           0, "usr/bin/*" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/lib/arm-linux-gnueabihf/lxc/lxc-user-nic" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/lib/arm-linux-gnueabihf/oxide-qt/chrome-sandbox" },
    { 04754, UBUNTU_ID_ROOT,      U_MESSAGEBUS_G,      0, "usr/lib/dbus-1.0/dbus-daemon-launch-helper" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/lib/eject/dmcrypt-get-device" },
    { 02755, UBUNTU_ID_ROOT,      U_MAIL_GID,          0, "usr/lib/evolution/camel-lock-helper-1.2" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/lib/openssh/ssh-keysign" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/lib/policykit-1/polkit-agent-helper-1" },
    { 04755, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/lib/pt_chown" },
    { 00777, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/share/click/preinstalled/.click/users/@all/*" },
    { 00644, U_CLICKPKG_UID,      U_CLICKPKG_GID,      0, "usr/share/click/preinstalled/*" },
    { 00644, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "usr/*" },
    { 00640, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "var/cache/apt/archives/lock" },
    { 00640, UBUNTU_ID_ROOT,      U_SHADOW_GID,        0, "var/lib/extrausers/shadow" },
    { 00664, UBUNTU_ID_ROOT,      U_UBUNTU_TMP_G,      0, "var/log/btmp" },
    { 00640, UBUNTU_ID_ROOT,      U_ADM_GID,           0, "var/log/dmesg" },
    { 00640, UBUNTU_ID_ROOT,      U_ADM_GID,           0, "var/log/fsck/checkfs" },
    { 00640, UBUNTU_ID_ROOT,      U_ADM_GID,           0, "var/log/fsck/checkroot" },
    { 00664, UBUNTU_ID_ROOT,      U_UBUNTU_TMP_G,      0, "var/log/lastlog" },
    { 00664, UBUNTU_ID_ROOT,      U_UBUNTU_TMP_G,      0, "var/log/wtmp" },
    { 00644, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "var/*" },
    { 00777, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "cache" },
    { 00777, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "data" },
    { 00777, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "factory" },
    { 00777, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "firmware" },
    { 00777, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "persist" },
    { 00777, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "system" },
    { 00777, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "vendor" },
    { 00644, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "custom/build_id" },
    { 00644, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, "custom/*" },
    { 00644, UBUNTU_ID_ROOT,      UBUNTU_ID_ROOT,      0, 0 },
};


static inline void ubuntu_set_fs_content(const char *fs_content) {
    // lrwxrwxrwx 0/0               0 2014-05-21 16:15 system/bin/ypdomainname -> hostname
    // first letter is type
        // Socket            's' : 0xC000
        // Symbolic Link     'l' : 0xA000
        // Regular           '-' : 0x8000
        // Block special     'b' : 0x6000
        // Directory         'd' : 0x4000
        // Character special 'c' : 0x2000
        // FIFO pipe         'p' : 0x1000

   // Owner
        // 'r' : 0x0100
        // 'w' : 0x0080
        // 'x' : 0x0040
        // 's' : 0x0040 | 0x0800
        // 'S' : 0x0800

    // Group
        // 'r' : 0x0020
        // 'w' : 0x0010
        // 'x' : 0x0008
        // 's' : 0x0008 | 0x0400
        // 'S' : 0x0400

    // Others
        // 'r' : 0x0004
        // 'w' : 0x0002
        // 'x' : 0x0001
        // 't' : 0x0001 | 0x0200
        // 'T' : 0x0200
    FILE* file = NULL;
    file = fopen(fs_content, "r");
    if (NULL != file) {
        char line[512];
        char number[10];
        int fileNum = 0;
        int dirNum = 0;
        unsigned numberOfFiles = 0;
        unsigned numberOfDirs = 0;
        int fd = fileno(file);

        // first count numner of files and dirs and allocate needed arrays
        while (fgets(line, sizeof(line), file)) {
            switch (line[0]) {
                case 'd': numberOfDirs++; break;
                default: numberOfFiles++;
            }
        }
        printf("fs contains %lu directories and %lu files\n", numberOfDirs, numberOfFiles);
        // we do memory allocation, but we don't get signal when to free memory, instead we have to rely on process running exiting once task is done
        // at the same time, rules are needed while tool is running, so no harm done.
        ubuntu_files_c = (struct ubuntu_fs_path_config*) malloc(sizeof(ubuntu_files) * numberOfFiles + 1);
        ubuntu_dirs_c  = (struct ubuntu_fs_path_config*) malloc(sizeof(ubuntu_files) * numberOfDirs + 1);
        rewind(file);
        while (fgets(line, sizeof(line), file)) {
            unsigned mode = 0;
            unsigned owner = 0;
            unsigned group = 0;
            int index, size;
            char* parsed = NULL;
            // ignore type for now
            // owner
            if ( line[1] == 'r') mode|= 0x0100;
            if ( line[2] == 'w') mode|= 0x0080;
            switch (line[3]) {
                case 'x' : mode|= 0x0040; break;
                case 's' : mode|= 0x0840; break;
                case 'S' : mode|= 0x0800; break;
            }
            // group
            if ( line[4] == 'r') mode|= 0x0020;
            if ( line[5] == 'w') mode|= 0x0010;
            switch (line[6]) {
                case 'x' : mode|= 0x0008; break;
                case 's' : mode|= 0x0408; break;
                case 'S' : mode|= 0x0400; break;
            }
            // Others
            if ( line[7] == 'r') mode|= 0x0004;
            if ( line[8] == 'w') mode|= 0x0002;

            switch (line[9]) {
                case 'x' : mode|= 0x0001; break;
                case 't' : mode|= 0x0201; break;
                case 'T' : mode|= 0x0200; break;
            }
            // OWNER_ID/GROUP_ID
            parsed = strchr(&line[10], '/');
            if (parsed == NULL){
                printf("Failed to parse line: %s", line);
                continue;
            }
            memset(number, 0, sizeof(number));
            strncpy(number, &line[11], parsed - &line[11]);
            owner = atoi(number);
            char* space = strchr(parsed, ' ');
            if (space == NULL){
                printf("Failed to parse line: %s", line);
                continue;
            }
            memset(number, 0, sizeof(number));
            strncpy(number, ++parsed, space - parsed);
            group = atoi(number);

            // parse file/dir name
            char* fileName = strstr(parsed, " system/");
            if (fileName == NULL){
                printf("Failed to parse line: %s", line);
                continue;
            }
            fileName+=8;
            // if file is link, remove "->" part
            if (line[0] == 'l') {
                parsed =  strstr(fileName, " ->");
                if (parsed != NULL) {
                    size = parsed - fileName;
                } else {
                    printf("Failed to parse line:%s\n", line);
                    continue;
                }
            } else if (line[0] == 'h') {
                parsed =  strstr(fileName, " link to ");
                if (parsed != NULL) {
                   size = parsed - fileName;
                } else {
                    printf("Failed to parse line:%s\n", line);
                    continue;
                }
            } else {
                parsed = strchr(fileName, '\n');
                // if last characted is "/" remove it
                if ( parsed == NULL) {
                    printf("Failed to parse content file: does content file end with empty line?");
                    return;
                }
                if  (*(parsed -1) == '/') {
                   --parsed;
                }
                size = parsed - fileName;
            }
            // same thing applies here and array mem allocation
            char* fileNamebuf = malloc(sizeof(char) * (size +1));
            strncpy(fileNamebuf, fileName, size);
            // add entry to the compare tables
            ubuntu_fs_path_config entry = { mode, owner, group, 0, fileNamebuf };
             if (line[0] == 'd') {
                 ubuntu_dirs_c[dirNum++]=entry;
                 // printf("dir:%04o--%d/%d--%d-:%s\n",  mode, owner, group, size, fileNamebuf);
             } else {
                 ubuntu_files_c[fileNum++]= entry;
                 // printf("file:%04o--%d/%d--%d-:%s\n",  mode, owner, group, size, fileNamebuf);
             }
             memset(line, 0, sizeof(line));
        }
        fclose(file);
        ubuntu_fs_path_config lastDir = { 00755, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, 0 };
        ubuntu_dirs_c[dirNum]=lastDir;
        ubuntu_fs_path_config lastFile = { 00644, UBUNTU_ID_ROOT,   UBUNTU_ID_ROOT,  0, 0 };
        ubuntu_files_c[fileNum]= lastFile;
    }
}

static inline const struct fs_path_config* findConfig(const char *path, const struct fs_path_config* pc) {
    int plen = strlen(path);
    for(; pc->prefix; pc++){
        int len = strlen(pc->prefix);
        // user same patern matching for files and directories
        if (pc->prefix[len -1] == '*') {
            if(!strncmp(pc->prefix, path, len - 1)) break;
        } else if (plen == len){
            if(!strncmp(pc->prefix, path, len)) break;
        } else {
        }
    }
    return pc;
}

static inline void ubuntu_fs_config(const char *path, int dir, const char *target_out_directory,
                             unsigned *uid, unsigned *gid, unsigned *mode, uint64_t *capabilities)
{
    const struct fs_path_config *pc;
    int cfr;

    if (path[0] == '/') {
        path++;
    }
    // if there are content array used those instead
    if (dir) {
        pc = ubuntu_dirs_c ? ubuntu_dirs_c : ubuntu_dirs;
    } else {
        pc = ubuntu_files_c ? ubuntu_files_c : ubuntu_files;
    }
    pc = findConfig( path, pc);
    cfr = (dir && ubuntu_dirs_c || ubuntu_files_c);
    if ( 0 == pc->prefix ) {
        if (cfr) {
            cfr = 0;
            // check if we have rule in default set
            if (dir) {
                pc = ubuntu_dirs;
            } else {
                pc = ubuntu_files;
            }
            pc = findConfig( path, pc);
            if ( 0 == pc->prefix ) {
                printf("Permission rule not found for %s:%s\n", dir ? "dir": "file", path);
            } else {
                printf("Using permission rule from default set for %s:%s\n", dir ? "dir": "file", path);
            }
        } else {
            printf("Permission rule not found for %s:%s\n", dir ? "dir": "file", path);
        }
    }
    *uid = pc->uid;
    *gid = pc->gid;
    // if permissions are comming from content file use those, if permissions are from default set
    // then use those from host filesystem itself since prebuild files are unpacked from tar,
    // permissions should be mostly right correct only permissions which are in 4th octet
    if (cfr) {
        *mode = pc->mode;
    } else {
        if (pc->mode & 07000) {
            *mode = (*mode & (~07000)) | pc->mode;
        }
    }
    *capabilities = pc->capabilities;
}

#endif
