// Copyright (C) 2005-2012 Team MediaPortal
// http://www.team-mediaportal.com
// 
// MediaPortal is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
// 
// MediaPortal is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with MediaPortal. If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include "stdafx.h"
#include <MMReg.h>  //must be before other Wasapi headers
#include <ks.h>
#include <ksmedia.h>
#include "BaseAudioSink.h"
#include "Settings.h"
#include "..\AE_mixer\AERemap.h"

class CChannelMixer : public CBaseAudioSink
{
public:
  CChannelMixer(AudioRendererSettings* pSettings);
  virtual ~CChannelMixer();

// IAudioSink implementation
public:
  // Initialization
  HRESULT Init();
  HRESULT Cleanup();

  // Format negotiation
  HRESULT NegotiateFormat(const WAVEFORMATEXTENSIBLE* pwfx, int nApplyChangesDepth);

  // Processing
  HRESULT PutSample(IMediaSample* pSample);
  HRESULT EndOfStream();

// Internal implementation
protected:
  // Initialization
  HRESULT OnInitAllocatorProperties(ALLOCATOR_PROPERTIES* properties);
  
  HRESULT SetupConversion();
  HRESULT ProcessData(const BYTE* pData, long cbData, long* pcbDataProcessed);

  HRESULT FlushStream();

protected:
  bool m_bPassThrough;

  CAERemap* m_pRemap;

  int m_nInFrameSize;     // Bytes in a frame. A frame contains a sample for each channel
  int m_nOutFrameSize;     

  REFERENCE_TIME m_rtNextIncomingSampleTime;
  REFERENCE_TIME m_rtInSampleTime;

  AudioRendererSettings* m_pSettings;
};

