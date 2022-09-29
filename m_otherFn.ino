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