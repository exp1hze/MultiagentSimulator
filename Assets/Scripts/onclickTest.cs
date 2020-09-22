using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class onclickTest : MonoBehaviour
{

    public GameObject canvas;
    GameObject fatherPanel ;

    void Awake()
    {
        fatherPanel = GameObject.Find("rightPanel");
        foreach (Transform child in fatherPanel.transform)
        {
            child.gameObject.SetActive(false);
        }
    }
    public void onclick()
    {
        foreach (Transform child in fatherPanel.transform)
        {
            child.gameObject.SetActive(false);
        }
        canvas.SetActive(true);
    }
}
