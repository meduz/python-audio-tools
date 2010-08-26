#include <Python.h>
#include <stdint.h>
#include "../bitstream_w.h"
#include "../array.h"

/********************************************************
 Audio Tools, a module and set of tools for manipulating audio data
 Copyright (C) 2007-2010  Brian Langenberger

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*******************************************************/

typedef enum {OK, ERROR} status;

void
WavPackEncoder_write_frame(Bitstream *bs,
                           struct ia_array *samples,
                           long channel_mask);

/*given a channel count and channel mask (which may be 0),
  build a list of 1 or 2 channel count values
  for each left/right pair*/
void
WavPackEncoder_channel_splits(struct i_array *counts,
                              int channel_count,
                              long channel_mask);

void
WavPackEncoder_write_block(Bitstream *bs,
                           struct i_array *channel_A,
                           struct i_array *channel_B,
                           int channel_count,
                           int first_block,
                           int last_block);
