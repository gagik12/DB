#pragma once
//id,file,description,date,author,platform,type,port
enum class Field
{
	ID,
	FILE,
	DESCRIPTION,
	DATE,
	AUTOR,
	PLATFORM,
	TYPE,
	PORT
};

class CDatabase
{
public:
	CDatabase(std::string const& dbName);
	std::vector<std::string> GetUserInfo(std::string const& userName, Field infoType) const;
private:
	typedef std::vector<std::string> Fields;
	std::ifstream m_dbFile;
	Fields m_fieldsNames;
	std::map<std::string, std::vector<Fields>> m_autors;

	void InitFields();
	void InitDatabaseFromFile();
	Fields GetFields(std::string const& strFields);
};