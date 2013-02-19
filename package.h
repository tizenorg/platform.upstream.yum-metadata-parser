/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/* This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License,
 * version 2, as published by the Free Software Foundation
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef __YUM_PACKAGE_H__
#define __YUM_PACKAGE_H__

#include <glib.h>

typedef struct {
    char *name;
    char *flags;
    char *epoch;
    char *version;
    char *release;
    gboolean pre;
} Dependency;

typedef struct {
    char *type;
    char *name;
} PackageFile;

typedef struct {
    char *author;
    gint64 date;
    char *changelog;
} ChangelogEntry;

typedef struct {
    gint64 pkgKey;
    char *pkgId;
    char *name;
    char *arch;
    char *version;
    char *epoch;
    char *release;
    char *summary;
    char *description;
    char *url;
    gint64 time_file;
    gint64 time_build;
    char *rpm_license;
    char *rpm_vendor;
    char *rpm_group;
    char *rpm_buildhost;
    char *rpm_sourcerpm;
    gint64 rpm_header_start;
    gint64 rpm_header_end;
    char *rpm_packager;
    gint64 size_package;
    gint64 size_installed;
    gint64 size_archive;
    char *location_href;
    char *location_base;
    char *checksum_type;

    GSList *requires;
    GSList *provides;
    GSList *conflicts;
    GSList *obsoletes;

    GSList *files;
    GSList *changelogs;

    GStringChunk *chunk;
} Package;

typedef void (*PackageFn) (Package *pkg, gpointer data);

Dependency     *dependency_new      (void);
PackageFile    *package_file_new    (void);
ChangelogEntry *changelog_entry_new (void);
Package        *package_new         (void);
void            package_free        (Package *package);

#endif /* __YUM_PACKAGE_H__ */
