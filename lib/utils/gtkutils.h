/*****************************************************************************
 *   Copyright 2013 - 2014 Yichao Yu <yyc1992@gmail.com>                     *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU Lesser General Public License as          *
 *   published by the Free Software Foundation; either version 2.1 of the    *
 *   License, or (at your option) version 3, or any later version accepted   *
 *   by the membership of KDE e.V. (or its successor approved by the         *
 *   membership of KDE e.V.), which shall act as a proxy defined in          *
 *   Section 6 of version 3 of the license.                                  *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU       *
 *   Lesser General Public License for more details.                         *
 *                                                                           *
 *   You should have received a copy of the GNU Lesser General Public        *
 *   License along with this library. If not,                                *
 *   see <http://www.gnu.org/licenses/>.                                     *
 *****************************************************************************/

#ifndef __QTC_UTILS_GTK_UTILS_H__
#define __QTC_UTILS_GTK_UTILS_H__

#include "utils.h"
#include <gtk/gtk.h>

static inline cairo_rectangle_int_t
qtcWidgetGetAllocation(GtkWidget *widget)
{
    cairo_rectangle_int_t alloc;
    // Binary compatible
    gtk_widget_get_allocation(widget, (GdkRectangle*)&alloc);
    return alloc;
}

static inline GtkRequisition
qtcWidgetGetRequisition(GtkWidget *widget)
{
    GtkRequisition req;
#if GTK_CHECK_VERSION(3, 0, 0)
    gtk_widget_get_preferred_size(widget, &req, NULL);
#else
    gtk_widget_get_requisition(widget, &req);
#endif
    return req;
}

static inline float
qtcFrameGetLabelYAlign(GtkFrame *f)
{
    float x, y;
    gtk_frame_get_label_align(f, &x, &y);
    return y;
}

static inline GtkOrientation
qtcWidgetGetOrientation(GtkWidget *widget)
{
    return gtk_orientable_get_orientation(GTK_ORIENTABLE(widget));
}

static inline bool
qtcWidgetIsHorizontal(GtkWidget *widget)
{
    return qtcWidgetGetOrientation(widget) == GTK_ORIENTATION_HORIZONTAL;
}

static inline bool
qtcIsProgressBar(GtkWidget *w)
{
#if GTK_CHECK_VERSION(3, 0, 0)
    if (!GTK_IS_PROGRESS_BAR(w)) {
        return false;
    }
#else
    if (!GTK_IS_PROGRESS(w)) {
        return false;
    }
#endif
    GtkAllocation alloc;
    gtk_widget_get_allocation(w, &alloc);
    return alloc.x != -1 && alloc.y != -1;
}

#endif
