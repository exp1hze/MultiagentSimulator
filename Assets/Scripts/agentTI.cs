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
    public float mul;

    void Start()
    {
        mul = 20f;
        SetBar("IN",5.3f);
        SetBar("TN", 7.6f);
        SetBar("IE", 8.5f);
        SetBar("TE", 3.3f);
        SetBar("IS", 4.6f);
        SetBar("TS", 7.3f);
        SetBar("IW", 8.2f);
        SetBar("TW", 2.6f);
    }

    public void Set(float iN, float iE, float iS, float iW, float tN, float tE, float tS, float tW,int center)
    {
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
    public void SetBar(string name, float length)
    {

        switch (name)
        {
            case "IN":
                IN.GetComponent<RectTransform>().sizeDelta = new Vector2(10f,length*mul);
                IN.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length,2);
                break;
            case "IE":
                IE.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, length * mul);
                IE.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            case "IW":
                IW.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, length * mul);
                IW.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            case "IS":
                IS.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, length * mul);
                IS.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            case "TN":
                TN.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, length * mul);
                TN.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            case "TE":
                TE.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, length * mul);
                TE.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            case "TW":
                TW.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, length * mul);
                TW.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            case "TS":
                TS.GetComponent<RectTransform>().sizeDelta = new Vector2(10f, length * mul);
                TS.transform.GetChild(0).GetComponent<Text>().text = "" + Math.Round(length, 2);
                break;
            default:
                break;
        }
    }

}
