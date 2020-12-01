using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using UnityEngine.UI;
using System;
using UnityEngine.SceneManagement;

public class selectFile : MonoBehaviour
{
    public GameObject parent;
    public GameObject listPrefab;
    void Start()
    {
        getFileName();
    }

    public void refresh()
    {
        foreach (Transform child in parent.transform)
        {
            Destroy(child.gameObject);
        }
        getFileName();
    }
    public void back()
    {
        SceneManager.LoadScene("MainMenu");
    }
    public void getFileName()
    {
        string filePath = Application.dataPath + "/Tracker/Output/";
        List<string> allFiles = new List<string>();
        DirectoryInfo dir = new DirectoryInfo(filePath);
        if (!dir.Exists)
        {
            return;
        }

        // get all the output folder names
        foreach (DirectoryInfo subdir in dir.GetDirectories())
        {
            if (!subdir.Name.StartsWith("run"))
            {
                continue;
            }
            Debug.Log("filename is:" + subdir.Name);
            allFiles.Add(subdir.Name);
            string time = subdir.CreationTime.ToString("MM/dd/yyyy");
            GameObject listMember = Instantiate(listPrefab);
            listMember.transform.parent = parent.transform;
            listMember.transform.GetChild(0).GetComponent<Text>().text = subdir.Name;
            listMember.transform.GetChild(1).GetComponent<Text>().text = time;


        }
    }

    }
