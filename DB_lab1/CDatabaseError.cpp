#include "stdafx.h"
#include "CDatabaseError.h"

CDatabaseError::CDatabaseError(std::string const& message)
	:std::ios_base::failure(message)
{
}