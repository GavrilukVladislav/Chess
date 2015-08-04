#ifndef DEFINES
#define DEFINES

typedef unsigned int uint;

#define SAFE_DELETE( X ) \
	delete X; \
	X = nullptr

#define SAFE_ARR_DELETE( X ) \
	delete[] X; \
	X = nullptr

#endif // DEFINES

