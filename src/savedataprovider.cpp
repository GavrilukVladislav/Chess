#include "savedataprovider.h"

#include <QTextStream>
#include <QFile>

SaveDataProvider::SaveDataProvider()
{
}
SaveDataProvider::~SaveDataProvider()
{
}

bool SaveDataProvider::save(const QString& tFileName, const ChessContext& aContext)
{
	QFile tFile(tFileName + ".save");
	if(tFile.open(QIODevice::Truncate | QIODevice::WriteOnly))
	{
		QTextStream fout(&tFile);

		std::vector<MoveRecord> tData = aContext.getHistory();
		for(MoveRecord& aRecord : tData)
		{
			fout << aRecord.oldX << " " << aRecord.oldY << " " <<
					aRecord.newX << " " << aRecord.newY << "\n";
		}
		return true;
	}
	else
	{
		return false;
	}
}

LoadData SaveDataProvider::load(const QString &aFileName)
{
	QFile tFile(aFileName);
	if(tFile.open(QIODevice::ReadOnly))
	{
		QTextStream fin(&tFile);

		std::vector<MoveRecord> tData;
		while(!fin.atEnd())
		{
			unsigned int oldX;
			unsigned int oldY;
			unsigned int newX;
			unsigned int newY;
			fin >> oldX >> oldY >> newX >> newY;
			tData.push_back({oldX, oldY, newX, newY});
		}
		return tData;
	}
	else
	{
		return std::vector<MoveRecord>();
	}
}
