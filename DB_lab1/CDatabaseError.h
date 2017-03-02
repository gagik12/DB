#pragma once

class CDatabaseError : public std::ios_base::failure
{
public:
	CDatabaseError(std::string const& message);
};