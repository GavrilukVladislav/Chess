#ifndef DEFINES
#define DEFINES

#define SAFE_DELETE( X ) \
	delete X; \
	X = nullptr

#define SAFE_ARR_DELETE( X ) \
	delete[] X; \
	X = nullptr

#endif // DEFINES

