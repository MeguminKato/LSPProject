#pragma once

#ifdef LIB_SPEED_EXPORT
#define LIB_SPEED_CONTROL __declspec(dllexport)
#else
#define LIB_SPEED_CONTROL  __declspec(dllimport)
#endif // LIB_SPEED_EXPORT


class SpeedControl
{
public:
	SpeedControl() {}
	~SpeedControl() {}

	


};


LIB_SPEED_CONTROL SpeedControl* CreateInstance();

LIB_SPEED_CONTROL void DeleteInstance(SpeedControl*);
