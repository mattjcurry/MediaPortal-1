#pragma once
/*
 *      Copyright (C) 2005-2010 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "..\source\stdafx.h"

#include "AEChannelInfo.h"

/**
 * The various data formats
 * LE = Little Endian, BE = Big Endian, NE = Native Endian
 * @note This is ordered from the worst to best preferred formats
 */
enum AEDataFormat
{
  AE_FMT_INVALID = -1,

  AE_FMT_U8,
  AE_FMT_S8,

  AE_FMT_S16BE,
  AE_FMT_S16LE,
  AE_FMT_S16NE,

  AE_FMT_S32BE,
  AE_FMT_S32LE,
  AE_FMT_S32NE,

  AE_FMT_S24BE4,
  AE_FMT_S24LE4,
  AE_FMT_S24NE4, /* S24 in 4 bytes */

  AE_FMT_S24BE3,
  AE_FMT_S24LE3,
  AE_FMT_S24NE3, /* S24 in 3 bytes */

  AE_FMT_DOUBLE,
  AE_FMT_FLOAT,

  /* Bitstream formats */
  AE_FMT_AC3,
  AE_FMT_DTS,
  AE_FMT_EAC3,
  AE_FMT_TRUEHD,
  AE_FMT_DTSHD,

  AE_FMT_MAX
};

#define AE_IS_RAW(x) ((x) >= AE_FMT_AC3 && (x) < AE_FMT_MAX)
#define AE_IS_RAW_HD(x) ((x) >= AE_FMT_EAC3 && (x) < AE_FMT_MAX)

/**
 * The audio format structure that fully defines a stream's audio information
 */
typedef struct {
  /**
   * The stream's data format (eg, AE_FMT_S16LE)
   */
  enum AEDataFormat  m_dataFormat;

  /**
   * The stream's sample rate (eg, 48000)
   */
  unsigned int       m_sampleRate;

  /**
   * The stream's channel layout
   */
  CAEChannelInfo     m_channelLayout;

  /**
   * The number of frames per period
   */
  unsigned int       m_frames;

  /**
   * The number of samples in one frame
   */
  unsigned int       m_frameSamples;

  /**
   * The size of one frame in bytes
   */
  unsigned int       m_frameSize;
} AEAudioFormat;

