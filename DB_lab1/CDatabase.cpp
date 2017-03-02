#include "stdafx.h"
#include "CDatabase.h"
#include "CDatabaseError.h"

static const std::string ERROR_OPENING_FILE = "Error opening file!";

CDatabase::CDatabase(std::string const& dbName)
{
	m_dbFile.open(dbName);
	if (!m_dbFile.is_open())
	{
		throw CDatabaseError(ERROR_OPENING_FILE);
	}
	InitFields();
	InitDatabaseFromFile();
}

std::vector<std::string> CDatabase::GetFields(std::string const& strFields)
{
	std::vector<std::string> tokens;
	const boost::char_separator<char> delimiters(",\"");
	boost::tokenizer<boost::char_separator<char>> tokenizer(strFields, delimiters);
	std::copy(tokenizer.begin(), tokenizer.end(), std::back_inserter(tokens));
	return tokens;
}

void CDatabase::InitFields()
{
	std::string line;
	std::getline(m_dbFile, line);
	m_fieldsNames = GetFields(line);
}

void CDatabase::InitDatabaseFromFile()
{
	typedef std::vector<std::string> FieldsValues;

	std::string line;
	while (std::getline(m_dbFile, line))
	{
		FieldsValues fieldsValues = GetFields(line);
		std::string userName = fieldsValues[4];
		m_autors[userName].push_back(fieldsValues);
	}
}

std::vector<std::string> CDatabase::GetUserInfo(std::string const& userName, Field infoType) const
{
	std::vector<std::string> idVec;
	auto it = m_autors.find(userName);
	if (it != m_autors.end())
	{
		for (auto const& fields : it->second)
		{
			idVec.push_back(fields[static_cast<unsigned>(infoType)]);
		}
	}
	return idVec;
}