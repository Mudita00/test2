#ifndef "BMS_H"
#define "BMS_H"
class BMS{
	private:

	float UV;
	float uvmin;
	float uvmax;
	float OV;
	float ovmin;
	float ovmax;
	const float defaultUndervoltage= ;
	const float defaultOvervoltage=;

	float UT;
	float utmin;
	float utmax;
	float OT;
	float otmin;
	float otmax;
	const float defaultUndertemperature=;
	const float defaultOvertemperature=;

	float UC;
	float ucmin;
	float ucmax;
	float OC;
	float ocmin;
	float ocmax;
	const float defaultUndercurrent=;
	const float defaultOvercurrent=;

	uint8_t readVoltage();
	bool setUndervoltage(float Undervoltage);
	bool setOvervoltage(float Overvoltage);
	float getUndervoltage();
	float getOvervoltage();


	uint8_t readTemperature();
	bool setUndertemperature(float Undertemperature);
	bool setOvertemperature(float Overtemperature);
	float getUndertemperature();
	float getOvertemperature();


	uint8_t readCurrent();
	bool setUndercurrent(float Undercurrent);
	bool setOvercurrent(float Overcurrent);
	float getUndercurrent();
	float getOvercurrent();
		

	bool checkfunc(float input,inputmin,inputmax);
 

#endif
