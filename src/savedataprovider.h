#ifndef SAVEDATAPROVIDER
#define SAVEDATAPROVIDER

#include "chesscontext.h"

#include <QString>

class SaveDataProvider
{
public:

	SaveDataProvider();
	virtual ~SaveDataProvider();
	virtual LoadData load(const QString& aFileName);
	virtual bool save(const QString &tFileName, const ChessContext& aContext);
};

#endif // SAVEDATAPROVIDER

