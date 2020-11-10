using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System;
public class agentTI : MonoBehaviour
{
    public GameObject IN;
    public GameObject IW;
    public GameObject IS;
    public GameObject IE;
    public GameObject TN;
    public GameObject TW;
    public GameObject TS;
    public GameObject TE;
    public GameObject Center;
    public float min;
    public float max;

    public float INMax;
    public float IWMax;
    public float ISMax;
    public float IEMax;
    public float TNMax;
    public float TWMax;
    public float TSMax;
    public float TEMax;


    void Start()
    {
        max = 120;
        min=25f;

    }

    public void Set(float iN, float iE, float iS, float iW, float tN, float tE, float tS, float tW,
        float iNMax, float iEMax, float iSMax, float iWMax, float tNMax, float tEMax, float tSMax, float tWMax, int center)
    {
        INMax = iNMax;
        IWMax = iWMax;
        ISMax = iSMax;
        IEMax = iEMax;
        TNMax = tNMax;
        TWMax = tWMax;
        TSMax = tSMax;
        TEMax = tEMax;

        SetBar("IN", iN);
        SetBar("TN", tN);
        SetBar("IE", iE);
        SetBar("TE", tE);
        SetBar("IS", iS);
        SetBar("TS", tS);
        SetBar("IW", iW);
        SetBar("TW", tW);
        Center.transform.GetChild(0).GetComponent<Text>().text = "" + center;
}

    public void Set(agent age)
    {
        INMax = age.INMax;
        IWMax = age.IWMax;
        ISMax = age.ISMax;
        IEMax = age.IEMax;
        TNMax = age.TNMax;
        TWMax = age.TWMax;
        TSMax = age.TSMax;
        TEMax = age.TEMax;

        SetBar("IN", age.IN);
        SetBar("TN", age.TN);
        SetBar("IE", age.IE);
        SetBar("TE", age.TE);
        SetBar("IS", age.IS);
        SetBar("TS", age.TS);
        SetBar("IW", age.IW);
        SetBar("TW", age.TW);
        Center.transform.GetChild(0).GetComponent<Text>().text = "" + age.id;
    }
    public void SetBar(string name, float length)
    {
        float l = 0f;
        switch (name)
        {
            case "IN":
                l = length / INMax;
                IN.GetComponent<RectTransform>().sizeDelta = new Vector2(10f,l*max + min);
                IN.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length,2);
                break;
            case "IE":
                l = length / IEMax;
                IE.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, l* max + min);
                IE.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            case "IW":
                l = length / IWMax;
                IW.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, l * max + min);
                IW.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            case "IS":
                l = length / ISMax;
                IS.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, l * max + min);
                IS.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            case "TN":
                l = length / TNMax;
                TN.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, l * max + min);
                TN.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            case "TE":
                l = length / TEMax;
                TE.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, l * max + min);
                TE.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            case "TW":
                l = length / TWMax;
                TW.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, l * max + min);
                TW.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            case "TS":
                l = length / TSMax;
                TS.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, l * max + min);
                TS.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            default:
                break;
        }
    }

}
