/**
  @file     gnuplot_i.h
  @author   N. Devillard
  @date	    Sep 1998, Oct 2004, Sept 2005, Nov 2005, Apr 2006
  @version  $Revision: 1.11.3 $
  @brief    C header file to gnuplot interface.
*/

/*
  $Id:       gnuplot_i.h,v 1.11 2003/01/27 08:58:04 ndevilla Exp $
  $Author:   ndevilla $
  $Date:     2003/01/27 08:58:04 $
  $Revision: 1.11.2 $
*/

#ifndef _GNUPLOT_PIPES_H_
#define _GNUPLOT_PIPES_H_

/*---------------------------------------------------------------------------
  Includes
 ---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <time.h>

/** Maximum number of simultaneous temporary files */
#define GP_MAX_TMP_FILES 64
/** Maximum amount of characters of a temporary file name */
#define GP_TMP_NAME_SIZE 512

/*---------------------------------------------------------------------------
  New Types
 ---------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/**
  @typedef  gnuplot_ctrl
  @brief    gnuplot session handle.
  @param    gnucmd
  @param    nplots
  @param    pstyle
  @param    term
  @param    to_delete
  @param    ntmp

  This structure holds all necessary information to talk to a gnuplot session.
  It is built and returned by gnuplot_init() and later used by all functions
  in this module to communicate with the session, then meant to be closed by 
  gnuplot_close().
*/

typedef struct _GNUPLOT_CTRL_ {
  FILE *gnucmd;       /*!< Pipe to gnuplot process. */
  int nplots;         /*!< Number of currently active plots. */
  char pstyle[32];    /*!< Current plotting style. */
  char term[32];      /*!< Save terminal name (used by `gnuplot_hardcopy()` function). */
  char to_delete[GP_MAX_TMP_FILES][GP_TMP_NAME_SIZE];   /*!< Names of temporary files. */
  int ntmp;           /*!< Number of temporary files in the current session. */
} gnuplot_ctrl;

/*-------------------------------------------------------------------------*/
/**
  @typedef  gnuplot_point
  @brief    gnuplot point structure, ie set of [x,y,z] coordinates.
  @param    x
  @param    y
  @param    z

  gnuplot_point is a point struct to allow the return of points to the
  `gnuplot_plot_obj_xy` function by callback functions.
*/

typedef struct _GNUPLOT_POINT_ {
  double x; /*!< X-coodinate */
  double y; /*!< Y-coodinate */
  double z; /*!< Z-coodinate */
} gnuplot_point;

/*---------------------------------------------------------------------------
  Function ANSI C prototypes
 ---------------------------------------------------------------------------*/

/* Auxiliary function */

char *gnuplot_get_program_path (char *pname);

/* gnuplot interface handling functions */

gnuplot_ctrl *gnuplot_init (void);
void print_gnuplot_handle (gnuplot_ctrl *handle);
void gnuplot_close (gnuplot_ctrl *handle);
void gnuplot_cmd (gnuplot_ctrl *handle, char *cmd, ...);
void gnuplot_setstyle (gnuplot_ctrl *handle, char *plot_style);
void gnuplot_setterm (gnuplot_ctrl *handle, char *terminal, int width, int height);
void gnuplot_set_axislabel (gnuplot_ctrl *handle, char *label, char *axis);
void gnuplot_resetplot (gnuplot_ctrl *handle);

/* gnplot plotting functions */

void gnuplot_plot_x (gnuplot_ctrl *handle, double *x, int n, char *title);
void gnuplot_plot_xy (gnuplot_ctrl *handle, double *x, double *y, int n, char *title);
void gnuplot_splot (gnuplot_ctrl *handle, double *x, double *y, double *z, int n, char *title);
void gnuplot_splot_grid (gnuplot_ctrl *handle, double *points, int rows, int cols, char *title);
void gnuplot_contour_plot (gnuplot_ctrl *handle, double *x, double *y, double *z, int nx, int ny, char *title);
void gnuplot_splot_obj (gnuplot_ctrl *handle, void *obj, void (*getPoint)(void *, gnuplot_point *, int, int), int n, char *title);
void gnuplot_plot_obj_xy (gnuplot_ctrl *handle, void *obj, void (*getPoint)(void *, gnuplot_point *, int, int), int n, char *title);
void gnuplot_plot_once (char *title, char *style, char *label_x, char *label_y, double *x, double *y, int n);
void gnuplot_plot_equation (gnuplot_ctrl *handle, char *equation, char *title);
void gnuplot_hardcopy (gnuplot_ctrl *handle, char *filename, char *color);

#endif
