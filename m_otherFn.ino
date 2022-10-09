void initialCheck()
{
    int timesArraySize = sizeof(pathTimes);
    if ((timesArraySize != strlen(path) - 1))
    {
        // signal error
        isPathTimesArrayCorrect = false;
        isPathArrayCorrect = false;
        myledwhiteon();
        delay(1000);
    }
    if (path[0] != 'B' && path[0] != 'W')
    {
        isPathTimesArrayCorrect = false;
        isPathArrayCorrect = false;
        myledwhiteon();
        delay(1000);
    }
}
void initialCalcTimes()
{
    /* 8S NANO
    speed 200 : 77 CM/S
    speed 170 : 69 CM/S
    v=d/t=> t=d/v=(pathDistances/69)*1000
    t=pathDistances*14.4 (14.4=1000/69)
    */
    /* 5s integ
    speed  :  CM/S
    speed  :  CM/S
    */
    int cmToMsFactor = 14.4;
    int ArraySize = sizeof(pathDistances);
    for (int i = 0; i < ArraySize; i++)
    {
        pathTimes[i] = pathDistances[i] * cmToMsFactor;
    }
}