using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class agent : MonoBehaviour
{
    public int id;
    public float IN;
    public float IW;
    public float IS;
    public float IE;
    public float TN;
    public float TW;
    public float TS;
    public float TE;

    public float INMax;
    public float IWMax;
    public float ISMax;
    public float IEMax;
    public float TNMax;
    public float TWMax;
    public float TSMax;
    public float TEMax;

    public agent(int id,float iN, float iW, float iS, float iE, float tN, float tW, float tS, float tE, float iNMax, float iWMax, float iSMax, float iEMax, float tNMax, float tWMax, float tSMax, float tEMax)
    {
        IN = iN;
        IW = iW;
        IS = iS;
        IE = iE;
        TN = tN;
        TW = tW;
        TS = tS;
        TE = tE;
        INMax = iNMax;
        IWMax = iWMax;
        ISMax = iSMax;
        IEMax = iEMax;
        TNMax = tNMax;
        TWMax = tWMax;
        TSMax = tSMax;
        TEMax = tEMax;
    }
}
