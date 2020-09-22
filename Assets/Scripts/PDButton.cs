using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PDButton : MonoBehaviour
{
    public GameObject childPanel;
    GameObject fatherPanel;

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
        Debug.Log(gameObject.name);
        foreach (Transform child in fatherPanel.transform)
        {
            child.gameObject.SetActive(false);
        }
        childPanel.SetActive(true);
    }
}
