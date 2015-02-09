#include "BaseWriter.h"

namespace BrightLib{namespace Media{

	StreamWriter::StreamWriter(std::ostream& st):m_output(st)
	{

	}

	int StreamWriter::write(uint8_t *buf, size_t len)
	{
		m_output.write((char*)buf, len);
		return 0;
	}

}}
