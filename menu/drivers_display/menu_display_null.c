/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2011-2016 - Daniel De Matteis
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#include <time.h>

#include <queues/message_queue.h>
#include <retro_miscellaneous.h>

#include "../../config.def.h"
#include "../../gfx/font_driver.h"
#include "../../gfx/video_context_driver.h"

#include "../menu_display.h"

static void *menu_display_null_get_default_mvp(void)
{
   return NULL;
}

static void menu_display_null_blend_begin(void)
{
}

static void menu_display_null_blend_end(void)
{
}

static void menu_display_null_draw(void *data)
{
   (void)data;
}

static void menu_display_null_draw_bg(void *data)
{
   (void)data;
}

static void menu_display_null_restore_clear_color(void)
{
}

static void menu_display_null_clear_color(void *data)
{
   (void)data;
}

static const float *menu_display_null_get_tex_coords(void)
{
   static float floats[1] = {1.00f};
   return &floats[0];
}

static bool menu_display_null_font_init_first(
      void **font_handle, void *video_data,
      const char *font_path, float font_size)
{
   return true;
}

menu_display_ctx_driver_t menu_display_ctx_null = {
   menu_display_null_draw,
   menu_display_null_draw_bg,
   menu_display_null_blend_begin,
   menu_display_null_blend_end,
   menu_display_null_restore_clear_color,
   menu_display_null_clear_color,
   menu_display_null_get_default_mvp,
   menu_display_null_get_tex_coords,
   menu_display_null_font_init_first,
   MENU_VIDEO_DRIVER_GENERIC,
   "menu_display_null",
};
