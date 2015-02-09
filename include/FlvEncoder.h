#ifndef _FLV_MUXER_H_
#define _FLV_MUXER_H_
#include "FlvCommon.h"
#include "BaseWriter.h"

namespace BrightLib{namespace Media{

#define CHECK(x)\
do {\
    if( (x) < 0 )\
        return -1;\
} while( 0 )



namespace Flv
{

class LIBFLV_API FlvEncoder
{
protected:
	bool m_bSentHeader;
	bool m_bSentParameters;
	BaseWriter *m_pWriter;
	void *m_pFlvBuffer;
	int flush();
public:
	FlvEncoder(BaseWriter *pWriter);
	virtual ~FlvEncoder();
	int init(BaseWriter *pWriter);
	int write_header();
	int write_video(uint8_t *pBuf, size_t len, int64_t pts, int64_t dts);
	int write_audio();
};

class LIBFLV_API H264FlvEncoder : public FlvEncoder
{
private:
	uint8_t *m_pSEI;
	size_t  m_uiSEILen;
	uint8_t *m_pSPS;
	size_t  m_uiSPSLen;
	uint8_t *m_pPPS;
	size_t  m_uiPPSLen;
	uint64_t m_uiFrameNum;
	uint64_t m_uiDelayTime;
	bool m_bCompressDTS;
	double m_dTimeBase;
	int m_iDelayFrames;
	uint64_t m_uiInitDelta;

	int write_sps_pps();
	int write_nalu(uint8_t *pBuf, size_t len, int64_t pts, int64_t dts);
	int write_frame(uint8_t *pBuf, size_t len, int64_t pts, int64_t dts, bool bKeyFrame);
public:
	H264FlvEncoder(BaseWriter *pWriter);
	virtual ~H264FlvEncoder();
	int write_video(uint8_t *pBuf, size_t len, int64_t pts, int64_t dts);
};

}; //namespace FLV

}};

#endif //_FLV_MUXER_H_

